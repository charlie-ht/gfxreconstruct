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

#include "format/descriptor_update_template_decoder.h"
#include "format/pointer_decoder.h"
#include "format/vulkan_consumer.h"
#include "format/vulkan_decoder.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

void VulkanDecoder::DecodeFunctionCall(ApiCallId             call_id,
                                       const ApiCallOptions& call_options,
                                       const uint8_t*        parameter_buffer,
                                       size_t                buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(call_options);

    switch (call_id)
    {
#include "generated/generated_api_call_decode_cases.inc"
        case ApiCallId_vkUpdateDescriptorSetWithTemplate:
            Decode_vkUpdateDescriptorSetWithTemplate(parameter_buffer, buffer_size);
            break;
        case ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR:
            Decode_vkCmdPushDescriptorSetWithTemplateKHR(parameter_buffer, buffer_size);
            break;
        case ApiCallId_vkUpdateDescriptorSetWithTemplateKHR:
            Decode_vkUpdateDescriptorSetWithTemplateKHR(parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

void VulkanDecoder::DispatchDisplayMessageCommand(const std::string& message)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void VulkanDecoder::DispatchFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void VulkanDecoder::DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand(surface_id, width, height);
    }
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        device;
    HandleId                        descriptorSet;
    HandleId                        descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        commandBuffer;
    HandleId                        descriptorUpdateTemplate;
    HandleId                        layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &set);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(
            commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandleId                        device;
    HandleId                        descriptorSet;
    HandleId                        descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#include "generated/generated_decoded_struct_types.inc"
#include "generated/generated_struct_decoders.inc"
#include "generated/generated_decode_pnext_struct.inc"
#include "generated/generated_api_call_decoders.inc"
