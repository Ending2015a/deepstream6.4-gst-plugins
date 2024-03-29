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

/**
 * @file GstNvStreamMuxCtx.h
 * @brief  StreamMux heler context class
 */


#ifndef _GST_NVSTREAMMUXCTX_H_
#define _GST_NVSTREAMMUXCTX_H_

#include "nvbufaudio.h"
#include <unordered_map>
#include <mutex>


class GstNvStreamMuxCtx
{
    public:
    GstNvStreamMuxCtx();
    void SaveAudioParams(uint32_t padId, uint32_t sourceId, NvBufAudioParams audioParams);
    NvBufAudioParams GetAudioParams(uint32_t padId);
    void SetMemTypeNVMM(uint32_t padId, bool isNVMM);
    bool IsMemTypeNVMM(uint32_t padId);

    private:
    std::mutex              mutex;
    std::unordered_map<uint32_t, NvBufAudioParams> audioParamsMap;
    std::unordered_map<uint32_t, bool> isNVMMMap;
};

#endif /**< _GST_NVSTREAMMUXCTX_H_ */

