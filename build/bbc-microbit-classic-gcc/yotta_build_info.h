#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 7 // UTC day 1-31
#define YOTTA_BUILD_HOUR 18 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 0 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 28 // UTC second 0-61
#define YOTTA_BUILD_UUID fb1f166b-e402-4e32-a59b-1b1802c2a3e1 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 4141287bd6d7bdbb8cc9c8330b8230657f91a87c // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 4141287 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
