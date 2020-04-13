/*
* Copyright (c) 2008-2018 Allwinner Technology Co. Ltd.
* All rights reserved.
*
* File : isp_version.h
* Description :
* History :
* Author  : surya <xuyu@dreame.tech>
* Date    : 2020/04/13
*
*/

#ifndef ISP_VERSION_H
#define ISP_VERSION_H

#include "include/isp_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ISP_VERSION "V1.01"
#define REPO_TAG "v5-sdv-v1.0-1.0.1"
#define REPO_BRANCH "libisp-dev"
#define REPO_COMMIT "5880a1ab280b686d027614b556aee783a0c8ccac"
#define REPO_DATE "Thu April 13 09:39:56 2020 +0800"
#define RELEASE_AUTHOR "surya"

static inline void isp_version_info(void)
{
	ISP_PRINT("\n>>>>>>>>>>>>>>>>>>>> ISP VERSION INFO <<<<<<<<<<<<<<<<<<<\n"
		"version:%s\n"
		"tag   : %s\n"
		"branch: %s\n"
		"commit: %s\n"
		"date  : %s\n"
		"author: %s\n"
		"--------------------------------------------------------\n\n",
		ISP_VERSION, REPO_TAG, REPO_BRANCH, REPO_COMMIT, REPO_DATE, RELEASE_AUTHOR);
}

#ifdef __cplusplus
}
#endif

#endif

