#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 4 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 1 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 57 // UTC second 0-61
#define YOTTA_BUILD_UUID 2c703212-d810-485b-aecd-833cf0d013d4 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID febda8b01c4ba171563c36560e89a3c1f5bc97d7 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION febda8b // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
