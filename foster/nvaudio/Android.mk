# Copyright (C) 2012 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

ifeq ($(BOARD_USES_TEGRA_HDMI),true)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

##################################
# Audio Policy Manager
##################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    ATVAudioPolicyManager.cpp

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog \
    libutils \
    libmedia \
    libbinder \
    libaudiopolicymanagerdefault

LOCAL_C_INCLUDES := \
    external/tinyalsa/include \
    $(TOPDIR)frameworks/av/services/audiopolicy \
    $(TOPDIR)frameworks/av/services/audiopolicy/common/include \
    $(TOPDIR)frameworks/av/services/audiopolicy/common/managerdefinitions/include \
    $(TOPDIR)frameworks/av/services/audiopolicy/engine/interface

ifeq ($(TARGET_PRODUCT),foster)
LOCAL_C_INCLUDES += \
    vendor/google_athome/services/RemoteControlService/include

LOCAL_SHARED_LIBRARIES += \
    libremotecontrolservice

LOCAL_CFLAGS += -DREMOTE_CONTROL_INTERFACE
endif

LOCAL_MODULE := libaudiopolicymanager
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

endif
