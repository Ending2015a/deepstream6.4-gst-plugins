/*
 * SPDX-FileCopyrightText: Copyright (c) 2021-2023 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _GST_NVSTREAMMUX_DEBUG_H_
#define _GST_NVSTREAMMUX_DEBUG_H_

#include <stdio.h>
#include "nvstreammux_debug.h"
#include <stdarg.h>
#include <gst/gstinfo.h>

#if 1
#define LOGD(...)
#else
#define LOGD(fmt, ...) printf("[DEBUG %s %d] " fmt, __func__, __LINE__, ## __VA_ARGS__)
#endif

#define LOGV(fmt, ...) printf("[VERBOSE %s %d] " fmt, __func__, __LINE__, ## __VA_ARGS__)
#define LOGE(fmt, ...) printf("[ERROR %s %d] " fmt, __func__, __LINE__, ## __VA_ARGS__)

#endif /**< _GST_NVSTREAMMUX_DEBUG_H_ */
