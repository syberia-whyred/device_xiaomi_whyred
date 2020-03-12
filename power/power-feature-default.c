/*
 * Copyright (C) 2015 The CyanogenMod Project
 * Copyright (C) 2016-2019 Paranoid Android
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dlfcn.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <linux/input.h>
#include <hardware/power.h>
#include "power-common.h"
#include "power-feature.h"
#include "utils.h"

#ifndef LEGACY_QCOM_POWERHAL
void set_device_specific_feature(feature_t feature, int state)
#else
void set_device_specific_feature(struct power_module *module __unused,
    feature_t feature, int state)
#endif
{
    char tmp_str[NODE_MAX];
    snprintf(tmp_str, NODE_MAX, "%d", state);

#ifdef GESTURES_NODE
    if (feature == POWER_FEATURE_GESTURES) {
        sysfs_write(GESTURES_NODE, tmp_str);
        return;
    }
#endif

#ifdef TAP_TO_WAKE_NODE
    if (feature == POWER_FEATURE_DOUBLE_TAP_TO_WAKE) {
        sysfs_write(TAP_TO_WAKE_NODE, tmp_str);
        return;
    }
#endif

#ifdef TAP_TO_WAKE_EVENT_NODE
    if (feature == POWER_FEATURE_DOUBLE_TAP_TO_WAKE) {
            int fd = open(TAP_TO_WAKE_EVENT_NODE, O_RDWR);
            struct input_event ev;
            ev.type = EV_SYN;
            ev.code = SYN_CONFIG;
            ev.value = state ? INPUT_EVENT_WAKUP_MODE_ON : INPUT_EVENT_WAKUP_MODE_OFF;
            write(fd, &ev, sizeof(ev));
            close(fd);
            return;
    }
#endif

#ifdef DRAW_V_NODE
    if (feature == POWER_FEATURE_DRAW_V) {
        sysfs_write(DRAW_V_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_INVERSE_V_NODE
    if (feature == POWER_FEATURE_DRAW_INVERSE_V) {
        sysfs_write(DRAW_INVERSE_V_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_O_NODE
    if (feature == POWER_FEATURE_DRAW_O) {
        sysfs_write(DRAW_O_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_M_NODE
    if (feature == POWER_FEATURE_DRAW_M) {
        sysfs_write(DRAW_M_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_W_NODE
    if (feature == POWER_FEATURE_DRAW_W) {
        sysfs_write(DRAW_W_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_S_NODE
    if (feature == POWER_FEATURE_DRAW_S) {
        sysfs_write(DRAW_S_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_ARROW_LEFT_NODE
    if (feature == POWER_FEATURE_DRAW_ARROW_LEFT) {
        sysfs_write(DRAW_ARROW_LEFT_NODE, tmp_str);
        return;
    }
#endif

#ifdef DRAW_ARROW_RIGHT_NODE
    if (feature == POWER_FEATURE_DRAW_ARROW_RIGHT) {
        sysfs_write(DRAW_ARROW_RIGHT_NODE, tmp_str);
        return;
    }
#endif

#ifdef ONE_FINGER_SWIPE_UP_NODE
    if (feature == POWER_FEATURE_ONE_FINGER_SWIPE_UP) {
        sysfs_write(ONE_FINGER_SWIPE_UP_NODE, tmp_str);
        return;
    }
#endif

#ifdef ONE_FINGER_SWIPE_RIGHT_NODE
    if (feature == POWER_FEATURE_ONE_FINGER_SWIPE_RIGHT) {
        sysfs_write(ONE_FINGER_SWIPE_RIGHT_NODE, tmp_str);
        return;
    }
#endif

#ifdef ONE_FINGER_SWIPE_DOWN_NODE
    if (feature == POWER_FEATURE_ONE_FINGER_SWIPE_DOWN) {
        sysfs_write(ONE_FINGER_SWIPE_DOWN_NODE, tmp_str);
        return;
    }
#endif

#ifdef ONE_FINGER_SWIPE_LEFT_NODE
    if (feature == POWER_FEATURE_ONE_FINGER_SWIPE_LEFT) {
        sysfs_write(ONE_FINGER_SWIPE_LEFT_NODE, tmp_str);
        return;
    }
#endif

#ifdef TWO_FINGER_SWIPE_NODE
    if (feature == POWER_FEATURE_TWO_FINGER_SWIPE) {
        sysfs_write(TWO_FINGER_SWIPE_NODE, tmp_str);
        return;
    }
#endif
}
