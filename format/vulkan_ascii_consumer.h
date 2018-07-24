/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_VULKAN_ASCII_CONSUMER_H
#define BRIMSTONE_VULKAN_ASCII_CONSUMER_H

#include <cstdio>
#include <string>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/vulkan_consumer.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class VulkanAsciiConsumer : public VulkanConsumer
{
public:
    VulkanAsciiConsumer();

    virtual ~VulkanAsciiConsumer();

    bool Initialize(const std::string& filename);

    void Destroy();

    bool IsValid() const { return (m_file != nullptr); }

    const std::string& GetFilename() const { return m_filename; }

#include "generated/generated_api_call_ascii_consumer_declarations.inc"

private:
    FILE*           m_file;
    std::string     m_filename;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_VULKAN_CONSUMER_H