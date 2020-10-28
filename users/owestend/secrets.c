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
#include "owestend.h"

#if (__has_include("secret_macros.h") && !defined(NO_SECRETS))
#include "secret_macros.h"
#endif

#ifndef SEC_00
    #define SEC_00  "sec00"
#endif
#ifndef SEC_01
    #define SEC_01  "sec01"
#endif
#ifndef SEC_02
    #define SEC_02  "sec02"
#endif
#ifndef SEC_03
    #define SEC_03  "sec03"
#endif
#ifndef SEC_04
    #define SEC_04  "sec04"
#endif
#ifndef SEC_05
    #define SEC_05  "sec05"
#endif
#ifndef SEC_06
    #define SEC_06  "sec06"
#endif
#ifndef SEC_07
    #define SEC_07  "sec07"
#endif
#ifndef SEC_08
    #define SEC_08  "sec08"
#endif
#ifndef SEC_09
    #define SEC_09  "sec09"
#endif

const char sec00[] PROGMEM = SEC_00;
const char sec01[] PROGMEM = SEC_01;
const char sec02[] PROGMEM = SEC_02;
const char sec03[] PROGMEM = SEC_03;
const char sec04[] PROGMEM = SEC_04;
const char sec05[] PROGMEM = SEC_05;
const char sec06[] PROGMEM = SEC_06;
const char sec07[] PROGMEM = SEC_07;
const char sec08[] PROGMEM = SEC_08;
const char sec09[] PROGMEM = SEC_09;

const char * const secrets[] =
{
    sec00,
    sec01,
    sec02,
    sec03,
    sec04,
    sec05,
    sec06,
    sec07,
    sec08,
    sec09
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SEC ... KC_SEC_MAX: // Secrets!  Externally defined strings, not stored in repo
        if (!record->event.pressed) {
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            send_string_with_delay_P(secrets[keycode - KC_SEC], MACRO_DELAY);
        }
        return false;
        break;
    }
    return true;
}
