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

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
const char secret01[] PROGMEM = "test1";
const char secret02[] PROGMEM = "test2";
const char secret03[] PROGMEM = "test3";
const char secret04[] PROGMEM = "test4";
const char secret05[] PROGMEM = "test5";
const char secret06[] PROGMEM = "test6";
const char secret07[] PROGMEM = "test7";
const char secret08[] PROGMEM = "test8";
const char secret09[] PROGMEM = "test9";
const char secret10[] PROGMEM = "test10";

const char * const secrets[] PROGMEM =
{
  secret01,
  secret02,
  secret03,
  secret04,
  secret05,
  secret06,
  secret07,
  secret08,
  secret09,
  secret10
};
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SEC_1 ... KC_SEC_10: // Secrets!  Externally defined strings, not stored in repo
      if (!record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        send_string_with_delay_P((char *)pgm_read_word(&(secrets[keycode - KC_SEC_1])), MACRO_DELAY);
      }
      return false;
      break;
  }
  return true;
}
