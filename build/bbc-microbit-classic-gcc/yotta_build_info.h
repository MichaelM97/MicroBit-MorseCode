#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 2 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 37 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 18 // UTC second 0-61
#define YOTTA_BUILD_UUID a398fea7-a229-4962-a8a4-047fc04a748a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID bf04b62e76443c397f625bc8837336bad86c9704 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION bf04b62 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
