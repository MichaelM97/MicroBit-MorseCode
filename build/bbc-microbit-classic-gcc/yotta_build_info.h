#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 7 // UTC day 1-31
#define YOTTA_BUILD_HOUR 19 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 47 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 7 // UTC second 0-61
#define YOTTA_BUILD_UUID d8287869-f6ec-4107-9bdb-3c5dd247fb14 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID bbe466502fcaf46ecede9ec19a63fea16caca3e1 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION bbe4665 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
