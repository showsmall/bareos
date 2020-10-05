# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

#Fixed

- 2f25fbaa7 [Fixes #1039]: Can not login in webui [Pull request #591]
- 171f1b8b9 Merge pull request #596 from bareos/dev/sduehr/fix_libcloud_plugin_filename_encoding
- e36c4c01d Improve the behaviour of some console commands [Pull request #604]
- d90f4380f Several improvemens to the LDAP Plugin for filedaemon [Pull request #595]
- 8ab2ad5bb Avoid duplicate actions after submission of an action followed by a page refresh in the webui [Pull request #594]
- 867e5860c Fix several droplet timeout problems to enable connection retries [Pull request #561]
- 66a02b5fe Close connection pool sockets properly (client initiated connections) [Pull request #562]
- c4ec23301 Check user ACL for status configuration [Pull request #570]
- e6f679f2c Allow backup/restore of cephfs mounts [Pull request #554]
- d55806501 Fix percona xtrabackup get last_lsn value [Pull request #551]
- e749b992e Prevent director daemon crash by adding a nullptr-guard to CreateAttriburesRecord() [Pull request #566]
- c65b6b0cb Enable testing of deprecated databases (MySQL and SQLite) [Pull request #573]
- c59228e7b Fix hearbeat thread shutdown race condition [Pull request #565]
- f23c2c957 Fix build problems for several distributions [Pull request #569]
- fb7305d05 Prevent from unique key violations on .bvfs_update [Pull request #545]
- 170117af6 Fix "make install" and add "make uninstall" when building from source [Pull request #556]
- 94a0525e2 [Fix #1257]: Prune volume command may crash the director [Pull request #546]
- 99f3914b2 Remove compiler warnings [Pull request #543]
- 4b8cd151d python-plugins: improve statp handling in localfileset plugin [Pull request #530]
- d4ab4ddb7 Fix some issues in the tray-monitor configuration [Pull request #539]
- 0ec2c5b1a Avoid a memory double-free in a spool function of the storage daemin [Pull request #535]
- 8e364c2a9 [Fixes #1246]: oVirt plugin fails to restore to local disk with KeyError [Pull request #534]
- ca5d97b1e Huge source code cleanup to reduce compiler warnings and increase readability [Pull request #479]
- 7acc4d7a7 Fix bscan handling of restore object data [Pull request #516]
- 8bda99fe4 Adapt Python Bareos version number according to PEP-440 [Pull request #521]
- 5435ab924 Fixed JobDetails joblog messages order [Pull request #509]
- 3b2656583 Huge source code cleanup of storagedaemon Device Backend [Pull request #498]
- 8a1e69665 [Fixes #1227]: Fix fadvise bug [Pull request #496]
- 79bc0f8b0 Improve webui frontend login dialog [Pull request #505]
- b1a7943b0 Improve postgres-backup filedaemon plugin [Pull request #502]
- e87e0fcb9 Fixed the use of a specified since time for the run command [Pull request #503]
- 4645d7cc9 Fixed that the status scheduler command shows jobs for disabled clients [Pull request #499]
- 93b735a4d Allow Python FD Plugins to set since time [Pull request #504]
- 73cbe260a Fixed a bug when backup a VM by using VM id [Pull request #415]
- 39fbbdc54 Fixed that droplet is waiting forever if flushing a file fails: [Pull request #468]
- 1d80d3877 [Fixes #1220]: default drive index not set to 0: [Pull request #472]
- 43b9adcd9 Fixed a segmentation fault caused by deprecated OpenSSL functions
- 54cb434a3 [Fixes #1211]: Bareos director and bareos fd crash when regexwhere is specified
- 4d45f3908 Always Incremental: Address early prune problem when vol retentions are too small
- 57357bab4 [Fixes #1206]: Form field restore job is not populated after client selection
- 63ba1f5cf [Fixes #1192]: Authorization key rejected by Storage daemon since upgrading director and storage daemons
- e7e9368b1 Allow pathlengths of a messages recource to be longer that 128 bytes
- d0c9765ee [Fixes #1190]: Schedules without a client will not be run
- 9af9eb623 Fixed a bug where hourly schedules fail on the general rule without a day
- 3b6ebeac9 [Fixes #1175]: bareos crashes with invalid character in ACL
- cf046c8a2 [Fixes #1184]: Using syslog or an invalid message type crashes a daemon
- 29ac88ab6 [Fixes #1176]: Upgrade 18.2.5 to 19.2.5 failed while upgrading MySQL database
- 2b58f1715 [Fixes #1174]: Reversed sort order on the restore client selection
- a068797a9 Fixed errors in client only build
- bc70185fc Fixed checksum algorithm regarding byte order
- 472ceb9b5 Avoid a race condition in job name creation

#Added


- ac0e36a3f Added documentation and background information for the new python 3 plugin support [Pull request #599]
- Added the libcloud filedaemon plugin to backup S3 buckets
- 8aac63192 Allow terabytes, tebibytes, petabytes, pebibytes, exabytes and exbibytes unit symbols when specifying sizes [Pull request #600]
- 85e8ff3ee Add some configuration warnings to the storagdaemon [Pull request #583]
- bfd70531f Add python3 support for filedaemon, storagedaemon and director plugins [Pull request #572]
- de46d0b15 Use configurable OpenSSL "Protocol" parameter [Pull request #575]
- be8a1d876 Extend bconsole show command to support JSON output format (API 2) [Pull request #574]
- 1da9cb499 Allow multiline quoted strings in the configuration [Pull request #578]
- 74794e070 Print toolchain details during cmake run [Pull request #567]
- 799ea9ca2 Build libdroplet as submodule and use systemtest test [Pull request #560]
- 4c978108e Run systemtests during build, build packages from source root directory [Pull request #559]
- 7c199b269 Add pkglists to documentation for all OS we build for [Pull request #557]
- 0c7cc18c6 Merge vmware plugin code into core subdirectories, add system test [Pull request #544]
- a59af84dc Add next pool selection to custom job run form in the webui [Pull request #518]
- 2fb93beda In job reports display who triggered a job (scheduler, user, ..) [Pull request #532]
- 02ebd0621 Added VirtualFull option for manual defined Jobs [Pull request #508]
- 345b723c4 Add support for Arch and Manjaro Linux [Pull request #513]
- 1f2e9285c Document Verify VolumeToCatalog limitation [Pull request #507]
- 50ed450f7 Document drawbacks for job intermixing [Pull request #506]
- 544b82bcf Write job- and file-choice to audit log on restore [Pull request #493]
- 45aed685f Add infrastructure for configuration warnings [Pull request #492]
- acfa5c968 Add logging parameters to gfapi backend [Pull request #455]
- 56e12f9c9 Pre-fill restore form element "replace" according to selected restore job in the webui: [Pull request #456]
- 9aef75f4a Add documentation for a critical bscan limitation: [Pull request #460]
- d3ba475cf Pre-fill restore location form element according to selected restore job in webui
- 0762d29e7 Add more logging messages to NDMP interface
- d0bcbd00d Add start and finish time in the webui-joblist
- efc8496b6 Add a database ugrade test
- cce6df8fb Add recommendation for PHP 7 to documentation
- 44d0c51da Add encryption signature test
- 7c426c47d Add percona extra backup
- 1417cff72 Add test for client initiated backup

#Changed


- b297102a7 Updated many localization files [Pull request #609]
- 3743f10c1 Display archived jobs on list backups command [Pull request #581]
- c76007cfd Use a configurable VDI timeout when requesting the MSSQL config [Pull request #571]
- e4870841e Improved the formatting of job log entries in the webui [Pull request #525 from tikoflano/Add-links-to-joblogs
- 3e12c981a Cleanup unused images [Pull request #538]
- 8336bc8bc Use precise file names for public and private key files to make documentation clear [Pull request #537]
- cf7b6bf70 Speed-up Bareos-dbcopy [Pull request #524]
- 2e5fec635 Publish PythonBareos to PyPI.org using Github Actions [Pull request #514]
- 565315e44 Updated documentation for tests [Pull request #497]
- b3a7b940d Display numeric values of UID and GID in addition to user and group name in webui [Pull request #488]
- 2508c1c19 Display file permissions in restore dialog of webui [Pull request #477]
- f90b9226b Improve warnings on Maximum Block Size of the droplet backend: [Pull request #476]
- 0577bcfab Improve the selection of a specific file version restore in the webui: [Pull request #471]
- 238dc5342 Only allow configuration maximum concurrent jobs of 0 or 1 when using droplet: [Pull request #465]
- eb51625b8 and f66f14fd9 Improve filtering on webui-jobs-bootstrap-table
- ee457bb2d Allow systemtets to run on installed packaged
- e640cd65a Allow systemtests to be run in parallel
- c13ef6887 Disable systemtests on non compatible systems
- da934f4a0 Update ovirt plugin documentation
- fdd139cf9 Improve ovirt plugin

#Deprecated

- fd13940f9 Add MySQL/SQLite deprecation notes to software [Pull request #564]
- f3836775f Add MySQL/SQLite deprecation notes to documentation [Pull request #563]

#Removed

#Security

- e90483b74 Add SECURITY.d file: [Pull request #463]
- fd281913b Do not accept cram challenge if own hostname is used [Pull request #536]


[20.2.1]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.1
[20.2.2]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.2
[unreleased]: https://github.com/bareos/bareos/tree/master
