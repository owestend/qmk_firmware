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

#include "quantum.h"
#include "version.h"

// define layers in this userspace, I use this layers in all my ansi boards
enum userspace_layers {
    _BL = 0,    // Base Layer
    _FL,        // Function Layer
//  _AL,        // Arrow Layer
    _CL         // Control Layer
};

//define user keycodes
enum userspace_keycodes {
    KC_VRSN = SAFE_RANGE,
    KC_MAKE,
    KC_SEC_1,
    KC_SEC_2,
    KC_SEC_3,
    KC_SEC_4,
    KC_SEC_5,
    KC_SEC_6,
    KC_SEC_7,
    KC_SEC_8,
    KC_SEC_9,
    KC_SEC_10,
    NEW_SAFE_RANGE
};

#define LCTL_ESC MT(MOD_LCTL, KC_ESC)
