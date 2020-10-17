/*
Copyright 2020 Ole Westendorff owestend@gmail.com @owestend

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include QMK_KEYBOARD_H

enum vim_mode_keycodes {
    VIM_START = SAFE_RANGE,
    VIM_SHIFT,
// Movements
    VIM_H,
    VIM_J,
    VIM_K,
    VIM_L,
    VIM_E,
    VIM_W,
    VIM_B,
    VIM_X,
    VIM_G,
//    VIM_GG,
// Numbers
    VIM_0,
    VIM_1,
    VIM_2,
    VIM_3,
    VIM_4,
    VIM_5,
    VIM_6,
    VIM_7,
    VIM_8,
    VIM_9,
// Commands
    VIM_C,
    VIM_D,
    VIM_Y,
    VIM_V,
    VIM_CI,
    VIM_DI,
    VIM_YI,
    VIM_VI,
// Insert Mode
    VIM_A,
    VIM_I,
    VIM_O,
    VIM_S,
// Others
    VIM_P,
    VIM_U,
    VIM_ESC,
    VIM_MODE_END
};

#undef  SAFE_RANGE
#define SAFE_RANGE VIM_MODE_END

#define TEMPLATE_VIM_MODE   TEMPLATE(   \
        VIM_ESC, VIM_1  , VIM_2  , VIM_3  , VIM_4  , VIM_5  , VIM_6  , VIM_7  , VIM_8  , VIM_9  , VIM_0  , _______, _______, _______, _______,  \
        _______, _______, VIM_W  , VIM_E  , _______, _______, VIM_Y  , VIM_U  , VIM_I  , VIM_O  , VIM_P  , _______, _______, _______,           \
        _______, VIM_A  , VIM_S  , VIM_D  , _______, VIM_G  , VIM_H  , VIM_J  , VIM_K  , VIM_L  , _______, _______,          _______,           \
        VIM_SHIFT,        _______, VIM_X  , VIM_C  , VIM_V  , _______, _______, _______, _______, _______, _______,        VIM_SHIFT, _______,  \
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______)

