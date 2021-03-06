/*
 * Copyright (c) 2016, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <hardware/hardware.h>
#include <hardware/thermal.h>
#include <limits.h>
#include "thermal.h"

const char *CPU_LABEL[] = {"CPU0", "CPU1", "CPU2", "CPU3"};

/*
 * This list should fully describe sensors on the platform that provide the
 * temperatures for CPU, GPU, skin, and battery.  Use UNKNOWN_TEMPERATURE for
 * undefined/unused thresholds.
 */
thermal_desc_t platform_data[] = {
    {
        .name = "CPU",
        .type = DEVICE_TEMPERATURE_CPU,
        .sensor_label = "CPU-therm",
        .throttling_threshold = 89,
        .shutdown_threshold = 101,
        .multiplier = 0.001,
        .vr_throttling_threshold = UNKNOWN_TEMPERATURE,
        .cores = 4,
        .core_names = CPU_LABEL,
        .read_temperature = read_cluster_temperature,
    },
    {
        .name = "GPU",
        .type = DEVICE_TEMPERATURE_GPU,
        .sensor_label = "GPU-therm",
        .throttling_threshold = 91,
        .shutdown_threshold = 103,
        .multiplier = 0.001,
    },
    {
        .name = "BATTERY",
        .type = DEVICE_TEMPERATURE_BATTERY,
        .sensor_label = "Battery",
        .throttling_threshold = UNKNOWN_TEMPERATURE,
        .shutdown_threshold = UNKNOWN_TEMPERATURE,
        .multiplier = 0.001,
        .vr_throttling_threshold = UNKNOWN_TEMPERATURE,
    },
    {
        .name = "SKIN",
        .type = DEVICE_TEMPERATURE_SKIN,
        .sensor_label = "Tdiode",
        .throttling_threshold = UNKNOWN_TEMPERATURE,
        .shutdown_threshold = UNKNOWN_TEMPERATURE,
        .multiplier = 0.001,
        .vr_throttling_threshold = UNKNOWN_TEMPERATURE,
    },
};

int platform_data_count = sizeof(platform_data)/sizeof(platform_data[0]);

int num_cpus_total = 4;
