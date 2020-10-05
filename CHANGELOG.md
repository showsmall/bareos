# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

#Fixed

- [Fixes #1039]: Can not login in webui [Pull request #591]
- Merge pull request #596 from bareos/dev/sduehr/fix_libcloud_plugin_filename_encoding
- Improve the behaviour of some console commands [Pull request #604]
- Several improvemens to the LDAP Plugin for filedaemon [Pull request #595]
- Avoid duplicate actions after submission of an action followed by a page refresh in the webui [Pull request #594]
- Fix several droplet timeout problems to enable connection retries [Pull request #561]
- Close connection pool sockets properly (client initiated connections) [Pull request #562]
- Check user ACL for status configuration [Pull request #570]
- Allow backup/restore of cephfs mounts [Pull request #554]
- Fix percona xtrabackup get last_lsn value [Pull request #551]
- Prevent director daemon crash by adding a nullptr-guard to CreateAttriburesRecord() [Pull request #566]
- Enable testing of deprecated databases (MySQL and SQLite) [Pull request #573]
- Fix hearbeat thread shutdown race condition [Pull request #565]
- Fix build problems for several distributions [Pull request #569]
- Prevent from unique key violations on .bvfs_update [Pull request #545]
- Fix "make install" and add "make uninstall" when building from source [Pull request #556]
- [Fix #1257]: Prune volume command may crash the director [Pull request #546]
- Remove compiler warnings [Pull request #543]
- python-plugins: improve statp handling in localfileset plugin [Pull request #530]
- Fix some issues in the tray-monitor configuration [Pull request #539]
- Avoid a memory double-free in a spool function of the storage daemin [Pull request #535]
- [Fixes #1246]: oVirt plugin fails to restore to local disk with KeyError [Pull request #534]
- Huge source code cleanup to reduce compiler warnings and increase readability [Pull request #479]
- Fix bscan handling of restore object data [Pull request #516]
- Adapt Python Bareos version number according to PEP-440 [Pull request #521]
- Fixed JobDetails joblog messages order [Pull request #509]
- Huge source code cleanup of storagedaemon Device Backend [Pull request #498]
- [Fixes #1227]: Fix fadvise bug [Pull request #496]
- Improve webui frontend login dialog [Pull request #505]
- Improve postgres-backup filedaemon plugin [Pull request #502]
- Fixed the use of a specified since time for the run command [Pull request #503]
- Fixed that the status scheduler command shows jobs for disabled clients [Pull request #499]
- Allow Python FD Plugins to set since time [Pull request #504]
- Fixed a bug when backup a VM by using VM id [Pull request #415]
- Fixed that droplet is waiting forever if flushing a file fails: [Pull request #468]
- [Fixes #1220]: default drive index not set to 0: [Pull request #472]
- Fixed a segmentation fault caused by deprecated OpenSSL functions
- [Fixes #1211]: Bareos director and bareos fd crash when regexwhere is specified
- Always Incremental: Address early prune problem when vol retentions are too small
- [Fixes #1206]: Form field restore job is not populated after client selection
- [Fixes #1192]: Authorization key rejected by Storage daemon since upgrading director and storage daemons
- Allow pathlengths of a messages recource to be longer that 128 bytes
- [Fixes #1190]: Schedules without a client will not be run
- Fixed a bug where hourly schedules fail on the general rule without a day
- [Fixes #1175]: bareos crashes with invalid character in ACL
- [Fixes #1184]: Using syslog or an invalid message type crashes a daemon
- [Fixes #1176]: Upgrade 18.2.5 to 19.2.5 failed while upgrading MySQL database
- [Fixes #1174]: Reversed sort order on the restore client selection
- Fixed errors in client only build
- Fixed checksum algorithm regarding byte order
- Avoid a race condition in job name creation

#Added


- Added documentation and background information for the new python 3 plugin support [Pull request #599]
- Added the libcloud filedaemon plugin to backup S3 buckets
- Allow terabytes, tebibytes, petabytes, pebibytes, exabytes and exbibytes unit symbols when specifying sizes [Pull request #600]
- Add some configuration warnings to the storagdaemon [Pull request #583]
- Add python3 support for filedaemon, storagedaemon and director plugins [Pull request #572]
- Use configurable OpenSSL "Protocol" parameter [Pull request #575]
- Extend bconsole show command to support JSON output format (API 2) [Pull request #574]
- Allow multiline quoted strings in the configuration [Pull request #578]
- Print toolchain details during cmake run [Pull request #567]
- Build libdroplet as submodule and use systemtest test [Pull request #560]
- Run systemtests during build, build packages from source root directory [Pull request #559]
- Add pkglists to documentation for all OS we build for [Pull request #557]
- Merge vmware plugin code into core subdirectories, add system test [Pull request #544]
- Add next pool selection to custom job run form in the webui [Pull request #518]
- In job reports display who triggered a job (scheduler, user, ..) [Pull request #532]
- Added VirtualFull option for manual defined Jobs [Pull request #508]
- Add support for Arch and Manjaro Linux [Pull request #513]
- Document Verify VolumeToCatalog limitation [Pull request #507]
- Document drawbacks for job intermixing [Pull request #506]
- Write job- and file-choice to audit log on restore [Pull request #493]
- Add infrastructure for configuration warnings [Pull request #492]
- Add logging parameters to gfapi backend [Pull request #455]
- Pre-fill restore form element "replace" according to selected restore job in the webui: [Pull request #456]
- Add documentation for a critical bscan limitation: [Pull request #460]
- Pre-fill restore location form element according to selected restore job in webui
- Add more logging messages to NDMP interface
- Add start and finish time in the webui-joblist
- Add a database ugrade test
- Add recommendation for PHP 7 to documentation
- Add encryption signature test
- Add percona extra backup
- Add test for client initiated backup

#Changed


- Updated many localization files [Pull request #609]
- Display archived jobs on list backups command [Pull request #581]
- Use a configurable VDI timeout when requesting the MSSQL config [Pull request #571]
- Improved the formatting of job log entries in the webui [Pull request #525 from tikoflano/Add-links-to-joblogs
- Cleanup unused images [Pull request #538]
- Use precise file names for public and private key files to make documentation clear [Pull request #537]
- Speed-up Bareos-dbcopy [Pull request #524]
- Publish PythonBareos to PyPI.org using Github Actions [Pull request #514]
- Updated documentation for tests [Pull request #497]
- Display numeric values of UID and GID in addition to user and group name in webui [Pull request #488]
- Display file permissions in restore dialog of webui [Pull request #477]
- Improve warnings on Maximum Block Size of the droplet backend: [Pull request #476]
- Improve the selection of a specific file version restore in the webui: [Pull request #471]
- Only allow configuration maximum concurrent jobs of 0 or 1 when using droplet: [Pull request #465]
- and f66f14fd9 Improve filtering on webui-jobs-bootstrap-table
- Allow systemtets to run on installed packaged
- Allow systemtests to be run in parallel
- Disable systemtests on non compatible systems
- Update ovirt plugin documentation
- Improve ovirt plugin

#Deprecated

- Add MySQL/SQLite deprecation notes to software [Pull request #564]
- Add MySQL/SQLite deprecation notes to documentation [Pull request #563]

#Removed

#Security

- Add SECURITY.d file: [Pull request #463]
- Do not accept cram challenge if own hostname is used [Pull request #536]


[20.2.1]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.1
[20.2.2]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.2
[unreleased]: https://github.com/bareos/bareos/tree/master
