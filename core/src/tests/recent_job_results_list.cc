/*
   BAREOS® - Backup Archiving REcovery Open Sourced

   Copyright (C) 2019-2019 Bareos GmbH & Co. KG

   This program is Free Software; you can redistribute it and/or
   modify it under the terms of version three of the GNU Affero General Public
   License as published by the Free Software Foundation and included
   in the file LICENSE.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/
#if defined(HAVE_MINGW)
#include "include/bareos.h"
#include "gtest/gtest.h"
#else
#include "gtest/gtest.h"
#include "include/bareos.h"
#endif

#include "lib/bsys.h"
#include "lib/recent_job_results_list.h"

#include <iostream>
#include <fstream>

static inline bool Is32BitWordsize()
{
#if defined HAVE_WIN32 and defined HAVE_MINGW
  return false;  // wincross always 64Bit
#else
  return sizeof(void*) == 4;
#endif
};

TEST(recent_job_results_list, check_header_padding_bytes)
{
  std::string detected;

  if (Is32BitWordsize()) {
    detected = "32Bit wordsize";
    EXPECT_EQ(offsetof(StateFileHeader, version), 16);
    EXPECT_EQ(offsetof(StateFileHeader, last_jobs_addr), 20);
    EXPECT_EQ(offsetof(StateFileHeader, end_of_recent_job_results_list), 28);
    EXPECT_EQ(offsetof(StateFileHeader, reserved), 36);
  } else {
    detected = "64Bit wordsize";
    EXPECT_EQ(offsetof(StateFileHeader, version), 16);
    EXPECT_EQ(offsetof(StateFileHeader, last_jobs_addr), 24);
    EXPECT_EQ(offsetof(StateFileHeader, end_of_recent_job_results_list), 32);
    EXPECT_EQ(offsetof(StateFileHeader, reserved), 40);
  }

#if HAVE_WIN32
  detected += ", Windows";
#endif
  detected += " detected";

  std::cout << " <<< " << detected << " >>> " << std::endl;
}

TEST(recent_job_results_list, read_job_results_from_file)
{
  OSDependentInit();
  RecentJobResultsList::Cleanup();

  char orig_path[]{TEST_ORIGINAL_FILE_DIR};

  const char* fname = Is32BitWordsize() ? "bareos-dir-32bit" : "bareos-dir";

  ReadStateFile(orig_path, fname, 42001);

  static std::vector<RecentJobResultsList::JobResult> recent_jobs =
      RecentJobResultsList::Get();

  ASSERT_EQ(recent_jobs.size(), 2);

  EXPECT_EQ(recent_jobs[0].JobId, 1);
  EXPECT_STREQ(recent_jobs[0].Job, "backup-bareos-fd.2019-08-08_22.38.13_04");

  EXPECT_EQ(recent_jobs[1].JobId, 2);
  EXPECT_STREQ(recent_jobs[1].Job, "RestoreFiles.2019-08-08_22.38.17_05");
}

TEST(recent_job_results_list, write_job_results_to_file)
{
  OSDependentInit();
  RecentJobResultsList::Cleanup();

  const char* fname = Is32BitWordsize() ? "bareos-dir-32bit" : "bareos-dir";

  char orig_path[]{TEST_ORIGINAL_FILE_DIR};
  ReadStateFile(orig_path, fname, 42001);

  char path[]{TEST_TEMP_DIR};
  WriteStateFile(path, fname, 42001);

  RecentJobResultsList::Cleanup();

  ReadStateFile(path, fname, 42001);

  static std::vector<RecentJobResultsList::JobResult> recent_jobs =
      RecentJobResultsList::Get();

  ASSERT_EQ(recent_jobs.size(), 2);

  EXPECT_EQ(recent_jobs[0].JobId, 1);
  EXPECT_STREQ(recent_jobs[0].Job, "backup-bareos-fd.2019-08-08_22.38.13_04");

  EXPECT_EQ(recent_jobs[1].JobId, 2);
  EXPECT_STREQ(recent_jobs[1].Job, "RestoreFiles.2019-08-08_22.38.17_05");
}

// create truncated files that will be deleted from ReadStateFile
static bool create_file(std::string path, std::string filename)
{
  OSDependentInit();
  std::string filename1(path);
  filename1 += "/";
  filename1 += filename;
  std::string filename1_orig(filename1);
  filename1_orig += ".original";

  std::ifstream file1_orig;
  std::ofstream file1;

  file1_orig.exceptions(std::ios::badbit | std::ios::failbit);
  file1.exceptions(std::ios::badbit | std::ios::failbit);

  try {
    file1_orig.open(filename1_orig, std::ios::binary);
    file1.open(filename1, std::ios::binary);
    file1 << file1_orig.rdbuf();
  } catch (const std::system_error& e) {
    std::cout << e.code().message().c_str() << std::endl;
    return false;
  } catch (const std::exception& e) {
    std::cout << "Unspecific error occurred: " << e.what() << std::endl;
    return false;
  }
  return true;
}

TEST(recent_job_results_list, read_job_results_from_file_truncated_jobs)
{
  OSDependentInit();
  RecentJobResultsList::Cleanup();

  char orig_path[]{TEST_ORIGINAL_FILE_DIR};

  const char* fname = Is32BitWordsize() ? "bareos-dir-truncated-jobs-32bit"
                                        : "bareos-dir-truncated-jobs";

  ASSERT_TRUE(create_file(orig_path, std::string(fname) + ".42001.state"));
  ReadStateFile(orig_path, fname, 42001);

  static std::vector<RecentJobResultsList::JobResult> recent_jobs =
      RecentJobResultsList::Get();

  ASSERT_EQ(recent_jobs.size(), 1);

  EXPECT_EQ(recent_jobs[0].JobId, 1);
  EXPECT_STREQ(recent_jobs[0].Job, "backup-bareos-fd.2019-08-08_22.38.13_04");
}

TEST(recent_job_results_list, read_job_results_from_file_truncated_header)
{
  OSDependentInit();
  RecentJobResultsList::Cleanup();

  char orig_path[]{TEST_ORIGINAL_FILE_DIR};
  ASSERT_TRUE(
      create_file(orig_path, "bareos-dir-truncated-header.42001.state"));
  ReadStateFile(orig_path, "bareos-dir-truncated-header", 42001);

  static std::vector<RecentJobResultsList::JobResult> recent_jobs =
      RecentJobResultsList::Get();

  ASSERT_EQ(recent_jobs.size(), 0);
}

TEST(recent_job_results_list, read_job_results_from_file_not_exist)
{
  OSDependentInit();
  RecentJobResultsList::Cleanup();

  char orig_path[]{TEST_ORIGINAL_FILE_DIR};
  ReadStateFile(orig_path, "file-does-not-exist", 42001);

  static std::vector<RecentJobResultsList::JobResult> recent_jobs =
      RecentJobResultsList::Get();

  ASSERT_EQ(recent_jobs.size(), 0);
}
