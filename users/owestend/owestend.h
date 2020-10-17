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
#include "version.h"
#include "quantum.h"

#ifdef VIM_MODE_ENABLE
    #include "vim_mode.h"
#endif

#ifndef SEC_MACROS
    #define SEC_MACROS  10
#endif

#if (SEC_MACROS > 0)
    #define SEC_M(x)    (KC_SEC + x)
#endif

// define layers in this userspace, I use this layers in all my ansi boards
enum userspace_layers {
    _BASE = 0,      // Base Layer
#ifdef GAME_LAYER_ENABLE
    _GAME,          // Gaming Layer; no fancy features
#endif
    _NAV,           // Navigation layer with some vim key bindings
    _FNC,           // Function Layer
    _ADJ,           // Control Layer
#ifdef VIM_MODE_ENABLE
    _VIM,           // VIM CMD layer
#endif
    _RESET
};

//define user keycodes
enum userspace_keycodes {
    KC_VRSN = SAFE_RANGE,
    KC_MAKE,
    KC_SEC,
    KC_SEC_MAX = KC_SEC + SEC_MACROS - 1,
    NEW_SAFE_RANGE
};

#define CTL_ESC     CTL_T(KC_ESC)

#define MO_NAV      MO(_NAV)
#define MO_FNC      MO(_FNC)
#define MO_ADJ      MO(_ADJ)
#define MO_RST      MO(_RESET)

#ifdef GAME_LAYER_ENABLE
    #define TG_GAME TG(_GAME)
#else
    #define TG_GAME KC_NO
#endif

#define BS_SPC1     LT(_NAV,KC_SPC)
#define BS_SPC2     LT(_NUM,KC_ENT)
#define BS_SPC3     SH_T(KC_BSPC)

#define NV_SPC1     KC_SPC
#define NV_SPC2     KC_ENT
#define NV_SPC3     KC_SPC

#define FN_SPC1     LT(_ADJ,KC_SPC)
#define FN_SPC2     KC_ENT
#define FN_SPC3     KC_SPC

#define AD_SPC1     KC_SPC
#define AD_SPC2     KC_ENT
#define AD_SPC3     KC_SPC

#define MY_PST      LSFT(KC_INS)
#define MY_CPY      LCTL(KC_INS)
#define MY_WFWD     LCTL(KC_RGHT)
#define MY_WBKW     LCTL(KC_LEFT)

#ifdef VIM_MODE_ENABLE
    #define MY_ESC  VIM_START
#else
    #define MY_ESC  KC_GESC
#endif

#ifndef TEMPLATE
    #define _X_ KC_NO
    #define TEMPLATE( \
        K50, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K00, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      \
        K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, \
        K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D       \
    ) TEMPLATE_TKL( \
        K50,      _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_,   _X_, _X_, K3E, \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   _X_, _X_, _X_, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   _X_, _X_, _X_, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,                  \
        K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,        _X_,      \
        K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D,   _X_, _X_, _X_  \
    )
#endif

#ifndef TEMPLATE_TKL
    #define TEMPLATE_TKL( \
        K50,      K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D,   K60, K61, K3E, \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K63, K64, K65, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K66, K67, K68, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,                  \
        K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,        K75,      \
        K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D,   K76, K77, K78  \
    ) TEMPLATE( \
        K50, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K00, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      \
        K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, \
        K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D       \
    )
#endif

