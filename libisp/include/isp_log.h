#ifndef _ISPLOG_H
#define _ISPLOG_H

#include <stdio.h>

#define ALOG(level, ...) \
        ((void)printf("cutils:" level "/" LOG_TAG ": " __VA_ARGS__))
#define ALOGV(...)   ALOG("V", __VA_ARGS__)
#define ALOGD(...)   ALOG("D", __VA_ARGS__)
#define ALOGI(...)   ALOG("I", __VA_ARGS__)
#define ALOGW(...)   ALOG("W", __VA_ARGS__)
#define ALOGE(...)   ALOG("E", __VA_ARGS__)
#define LOG_ALWAYS_FATAL(...)   do { ALOGE(__VA_ARGS__); exit(1); } while (0)

#endif
