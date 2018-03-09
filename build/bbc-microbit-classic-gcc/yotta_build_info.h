#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 4 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 30 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 26 // UTC second 0-61
#define YOTTA_BUILD_UUID 71edd796-9950-4869-80c5-eb2957eeb840 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 551753ce5802a436c22c9857daab38000eebba27 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 551753c // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
