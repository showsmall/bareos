# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

#Fixed

- [Issue #1039]: Can not login in webui [PR #591]
- Improve the behaviour of some console commands [PR #604]
- Several improvemens to the LDAP Plugin for filedaemon [PR #595]
- Avoid duplicate actions after submission of an action followed by a page refresh in the webui [PR #594]
- Fix several droplet timeout problems to enable connection retries [PR #561]
- Close connection pool sockets properly (client initiated connections) [PR #562]
- Check user ACL for status configuration [PR #570]
- Allow backup/restore of cephfs mounts [PR #554]
- Fix percona xtrabackup get last_lsn value [PR #551]
- Prevent director daemon crash by adding a nullptr-guard to CreateAttriburesRecord() [PR #566]
- Enable testing of deprecated databases (MySQL and SQLite) [PR #573]
- Fix hearbeat thread shutdown race condition [PR #565]
- Fix build problems for several distributions [PR #569]
- Prevent from unique key violations on .bvfs_update [PR #545]
- Fix "make install" and add "make uninstall" when building from source [PR #556]
- [Issue #1257]: Prune volume command may crash the director [PR #546]
- Remove compiler warnings [PR #543]
- python-plugins: improve statp handling in localfileset plugin [PR #530]
- Fix some issues in the tray-monitor configuration [PR #539]
- Avoid a memory double-free in a spool function of the storage daemin [PR #535]
- [Issue #1246]: oVirt plugin fails to restore to local disk with KeyError [PR #534]
- Huge source code cleanup to reduce compiler warnings and increase readability [PR #479]
- Fix bscan handling of restore object data [PR #516]
- Adapt Python Bareos version number according to PEP-440 [PR #521]
- Fixed JobDetails joblog messages order [PR #509]
- Huge source code cleanup of storagedaemon Device Backend [PR #498]
- [Issue #1227]: Fix fadvise bug [PR #496]
- Improve webui frontend login dialog [PR #505]
- Improve postgres-backup filedaemon plugin [PR #502]
- Fixed the use of a specified since time for the run command [PR #503]
- Fixed that the status scheduler command shows jobs for disabled clients [PR #499]
- Allow Python FD Plugins to set since time [PR #504]
- Fixed a bug when backup a VM by using VM id [PR #415]
- Fixed that droplet is waiting forever if flushing a file fails: [PR #468]
- [Issue #1220]: default drive index not set to 0: [PR #472]
- Fixed a segmentation fault caused by deprecated OpenSSL functions [PR #453]
- [Issue #1211]: Bareos director and bareos fd crash when regexwhere is specified [PR #451]
- Always Incremental: Address early prune problem when vol retentions are too small [PR #423]
- [Issue #1206]: Form field restore job is not populated after client selection [PR #438]
- [Issue #1192]: Authorization key rejected by Storage daemon since upgrading director and storage daemons [PR #431]
- Allow pathlengths of a messages recource to be longer that 128 bytes [PR #433]
- [Issue #1190]: Schedules without a client will not be run
- Fixed a bug where hourly schedules fail on the general rule without a day [PR #422]
- [Issue #1175]: bareos crashes with invalid character in ACL [PR #410]
- [Issue #1184]: Using syslog or an invalid message type crashes a daemon [PR #414]
- [Issue #1176]: Upgrade 18.2.5 to 19.2.5 failed while upgrading MySQL database [PR #409]
- [Issue #1174]: Reversed sort order on the restore client selection [PR #411]
- Fixed errors in client only build [PR #413]
- Fixed checksum algorithm regarding byte order [PR #412]
- Avoid a race condition in job name creation [PR #385]

#Added


- Added documentation and background information for the new python 3 plugin support [PR #599]
- Added the libcloud filedaemon plugin to backup S3 buckets
- Allow terabytes, tebibytes, petabytes, pebibytes, exabytes and exbibytes unit symbols when specifying sizes [PR #600]
- Add some configuration warnings to the storagdaemon [PR #583]
- Add python3 support for filedaemon, storagedaemon and director plugins [PR #572]
- Use configurable OpenSSL "Protocol" parameter [PR #575]
- Extend bconsole show command to support JSON output format (API 2) [PR #574]
- Allow multiline quoted strings in the configuration [PR #578]
- Print toolchain details during cmake run [PR #567]
- Build libdroplet as submodule and use systemtest test [PR #560]
- Run systemtests during build, build packages from source root directory [PR #559]
- Add pkglists to documentation for all OS we build for [PR #557]
- Merge vmware plugin code into core subdirectories, add system test [PR #544]
- Add next pool selection to custom job run form in the webui [PR #518]
- In job reports display who triggered a job (scheduler, user, ..) [PR #532]
- Added VirtualFull option for manual defined Jobs [PR #508]
- Add support for Arch and Manjaro Linux [PR #513]
- Document Verify VolumeToCatalog limitation [PR #507]
- Document drawbacks for job intermixing [PR #506]
- Write job- and file-choice to audit log on restore [PR #493]
- Add infrastructure for configuration warnings [PR #492]
- Add logging parameters to gfapi backend [PR #455]
- Pre-fill restore form element "replace" according to selected restore job in the webui: [PR #456]
- Add documentation for a critical bscan limitation: [PR #460]
- Pre-fill restore location form element according to selected restore job in webui [PR #454]
- Add more logging messages to NDMP interface [PR #448]
- Add start and finish time in the webui-joblist [PR #429]
- Add a database ugrade test [PR #406]
- Add recommendation for PHP 7 to documentation [PR #420]
- Add encryption signature test [PR #404]
- Add percona extra backup [PR #386]
- Add test for client initiated backup [PR #383]

#Changed


- Updated many localization files [PR #609]
- Display archived jobs on list backups command [PR #581]
- Use a configurable VDI timeout when requesting the MSSQL config [PR #571]
- Improved the formatting of job log entries in the webui [PR #525 from tikoflano/Add-links-to-joblogs
- Cleanup unused images [PR #538]
- Use precise file names for public and private key files to make documentation clear [PR #537]
- Speed-up Bareos-dbcopy [PR #524]
- Publish PythonBareos to PyPI.org using Github Actions [PR #514]
- Updated documentation for tests [PR #497]
- Display numeric values of UID and GID in addition to user and group name in webui [PR #488]
- Display file permissions in restore dialog of webui [PR #477]
- Improve warnings on Maximum Block Size of the droplet backend: [PR #476]
- Improve the selection of a specific file version restore in the webui: [PR #471]
- Only allow configuration maximum concurrent jobs of 0 or 1 when using droplet: [PR #465]
- and f66f14fd9 Improve filtering on webui-jobs-bootstrap-table [PR #444]
- Allow systemtets to run on installed packaged [PR #400]
- Allow systemtests to be run in parallel [PR #392]
- Disable systemtests on non compatible systems [PR #387]
- Update ovirt plugin documentation [PR #384]
- Improve ovirt plugin

#Deprecated

- Add MySQL/SQLite deprecation notes to software [PR #564]
- Add MySQL/SQLite deprecation notes to documentation [PR #563]

#Removed

#Security

- Add SECURITY.d file: [PR #463]
- Do not accept cram challenge if own hostname is used [PR #536]


[20.2.1]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.1
[20.2.2]: https://github.com/bareos/bareos/releases/tag/Release%2F20.2.2
[unreleased]: https://github.com/bareos/bareos/tree/master
