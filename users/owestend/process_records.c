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
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_DELAY);
                set_mods(temp_mod);
            }
            break;
        case KC_MAKE: // Compile the firmware
            if (!record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();
                send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), MACRO_DELAY);
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    send_string_with_delay_P(PSTR(":flash"), MACRO_DELAY);
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    send_string_with_delay_P(PSTR(" -j8 --output-sync"), MACRO_DELAY);
                }
                tap_code(KC_ENT);
                set_mods(temp_mod);
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
