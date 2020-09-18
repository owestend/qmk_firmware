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

#include QMK_KEYBOARD_H

#include "owestend.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = TEMPLATE_75(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PSCR, KC_PAUS, KC_DEL ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,          KC_HOME,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CTCP, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,                   KC_PGDN,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          KC_UP  ,          KC_END ,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC2, KC_SPC1, KCSPC3,                    KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

}

/*
    [_FL] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL,    KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,            _______,   _______,
        _______,          RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,   KC_PGUP,   _______,
        _______, _______, _______,                            MO(_CL),                   _______, _______, _______, KC_HOME,   KC_PGDN,   KC_END
    ),

    [_CL] = LAYOUT_65_ansi(
        _______,KC_SEC_1,KC_SEC_2,KC_SEC_3,KC_SEC_4,KC_SEC_5,KC_SEC_6,KC_SEC_7,KC_SEC_8,KC_SEC_9,KC_SEC_10,_______, _______,   _______,   _______,
        _______, _______, _______, EEP_RST, RESET,   _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,   _______,
        _______,          _______, _______, _______, KC_VRSN, _______, _______, KC_MAKE, _______, _______, _______, _______,   _______,   _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,   _______,   _______
    ),
};
*/