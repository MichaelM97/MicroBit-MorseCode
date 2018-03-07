#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 7 // UTC day 1-31
#define YOTTA_BUILD_HOUR 23 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 18 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 20 // UTC second 0-61
#define YOTTA_BUILD_UUID ffdb994b-d3ed-47a8-9a6e-f59a630b750d // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID eb37f98afa8c8fce3f831bac33b0e0f5c7021641 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION eb37f98 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
