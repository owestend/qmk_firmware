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

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_vim_mode(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_VRSN:  // Prints firmware version
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                // uint8_t temp_osm = get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
                set_mods(temp_mod);
            }
            return false;
            break;
        case KC_MAKE: // Compile the firmware
            if (!record->event.pressed) {
                bool reset = false;
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    SEND_STRING(":flash");
                    reset = true;
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    SEND_STRING(" -j8 --output-sync");
                }
                tap_code(KC_ENT);
                set_mods(temp_mod);
                if (reset) reset_keyboard();
            }
            return false;
            break;
        case KC_B:  // reset keyboard with both shift and b
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                if ((temp_mod & MOD_BIT(KC_LSHIFT)) && (temp_mod & MOD_BIT(KC_RSHIFT))) {
                    reset_keyboard();
                    return false;
                }
            }
            break;
    }
    return (
        process_record_keymap(keycode, record)
            &&
        process_record_secrets(keycode, record)
            &&
        process_record_vim_mode(keycode, record)
    );
}
