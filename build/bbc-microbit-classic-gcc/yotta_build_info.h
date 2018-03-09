#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 9 // UTC day 1-31
#define YOTTA_BUILD_HOUR 3 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 1 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 51 // UTC second 0-61
#define YOTTA_BUILD_UUID 65b7db93-43da-4823-9bc3-8def148c1d29 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 31591b00b09797b07ac3d27bc7441f25a7e6e846 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 31591b0 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
