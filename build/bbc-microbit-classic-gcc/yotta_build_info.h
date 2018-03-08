#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 8 // UTC day 1-31
#define YOTTA_BUILD_HOUR 22 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 15 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 44 // UTC second 0-61
#define YOTTA_BUILD_UUID 3e5edeb7-4053-409f-916f-e7169c8d5c3d // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 977ea91febf463ae1b6806988dc2d0bf91aa0605 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 977ea91 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
