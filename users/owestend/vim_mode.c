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
#include "os_macros.h"

uint16_t cmd_buf = KC_NO;
uint16_t no_buf = 0;
bool shifted = false;

uint16_t const move_kc[(1 + (VIM_X - VIM_H))] = {
    OS_KC_LEFT,
    OS_KC_DOWN,
    OS_KC_UP,
    OS_KC_RIGHT,
    OS_KC_END,
    OS_KC_WORD,
    OS_KC_BACK,
    OS_KC_DEL
};

#define END_CMD()       { no_buf = 0; cmd_buf = KC_NO; shifted = false;}
#define INSERT_MODE()   { END_CMD(); layer_off(_VIM); }

void do_command(void) {
    switch (cmd_buf) {
        case VIM_C:
            OS_CUT();
            INSERT_MODE();
            break;
        case VIM_D:
            OS_CUT();
            break;
        case VIM_V:
            return;
            break;
        case VIM_Y:
            OS_COPY();
            OS_UNMARK();
            break;
        default:
            break;
    }
    END_CMD();
    return;
}

bool process_record_vim_mode(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
// VIM_START
        case VIM_START:
            // switch to VIM command layer
            layer_on(_VIM);

            // reset state
            END_CMD();

            return false;
            break;
// Shift
        case VIM_SHIFT:
            shifted = record->event.pressed;
            return false;
            break;
// Movements            h j k l e w b x
        case VIM_H ... VIM_X:
            if (record->event.pressed) {

                 if (cmd_buf >= VIM_CI) {            // ci di vi yi
                    if (keycode == VIM_W) {         // iw
                        OS_END();
                        OS_BACK();
                        cmd_buf -= (VIM_CI - VIM_C);
                    } else {
                        END_CMD();
                    }
                }
                if (keycode == VIM_X) {         // x will done with d as command and l as movement
                    if (cmd_buf != KC_NO) {
                        END_CMD();
                    }
                    keycode = VIM_L;
                    cmd_buf = VIM_D;
                }
                if (no_buf < 1) {
                    no_buf = 1;
                }
                if (cmd_buf != KC_NO) {
                    OS_MARK_ON();
                }
                for ( ; no_buf > 1; no_buf -= 1) {
                    tap_code16(move_kc[keycode - VIM_H]);
                }
                no_buf = 0;

                register_code16(move_kc[keycode - VIM_H]);
            } else {
                if (keycode == VIM_W) {                  // no effect on Windows couse no different on WINDOWS between OS_WORD and OS_END
                    // OS_BACK();
                    // OS_WORD();
                }
                unregister_code16(move_kc[keycode - VIM_H]);
                if (cmd_buf != KC_NO) {
                    OS_MARK_OFF();
                    do_command();
                }
            }
            return false;
            break;
// Commands
        case VIM_C ... VIM_Y:
            if (record->event.pressed) {                // c d y C D Y
                clear_mods();
                clear_oneshot_mods();
                if (cmd_buf == KC_NO) {
                    if ( !shifted) {                    // c d y
                        cmd_buf = keycode;
                    } else {                            // C D Y
                        OS_LTEND();
                        OS_MARK(OS_RIGHT());
                        do_command();
                    }
                } else if (cmd_buf == keycode) {        // cc dd yy
                    OS_LWHOLE();
                    do_command();
                } else if (cmd_buf == VIM_V) {          // end of visual mode
                    cmd_buf = keycode;
                    do_command();
                }
            }
            return false;
            break;
// visual mode
        case VIM_V:                                     // v
            if (record->event.pressed) {
                if (cmd_buf != KC_NO) {
                    END_CMD();
                    return false;
                }
                cmd_buf = keycode;
            }
            return false;
            break;
// Numbers
        case VIM_0 ... VIM_9:
            if (record->event.pressed) {
                if (no_buf > 0) {
                    no_buf *= 10;
                } else if ( (keycode == KC_0 && !shifted ) || (keycode == KC_4 && shifted ) ) {      // $ or 0
                    clear_mods();
                    clear_oneshot_mods();
                    if (keycode == KC_0) {
                        if (cmd_buf != KC_NO) {
                            OS_MARK(OS_LBEGIN());
                        } else {
                            OS_LBEGIN();
                        }
                    }
                    else {
                        if (cmd_buf != KC_NO) {
                            OS_MARK(OS_LEND());
                        } else {
                            OS_LEND();
                        }
                    }
                    return false;
                }
                no_buf += (keycode - VIM_0);
            }
            return false;
            break;
// Insert Mode
        case VIM_I ... VIM_S:                       // a A i I o O s S
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (keycode == VIM_I && cmd_buf != KC_NO) {   //  ci di yi
                    cmd_buf += (VIM_CI - VIM_C);
                }
                if (keycode == VIM_A && cmd_buf != KC_NO) {  //  ca da ya
                    cmd_buf += (VIM_CI - VIM_C);
                }
                switch (keycode) {
                    case VIM_A:
                        if (shifted) {              // A
                            OS_LEND();
                        } else {                    // a
                            OS_RIGHT();
                        }
                        break;
                    case VIM_I:
                        if (shifted) {              // I
                            OS_LBEGIN();
                        }
                        break;
                    case VIM_O:
                        if (shifted) {              // O
                            OS_LEND();
                            tap_code(KC_ENTER);
                        } else {                    // o
                            OS_LBEGIN();
                            tap_code(KC_ENTER);
                            OS_UP();
                        }
                        break;
                    case VIM_S:
                        if (shifted) {              // S
                            OS_LWHOLE();
                            tap_code(KC_DEL);
                        } else {                    // s
                            OS_ACHAR();
                            tap_code(KC_DEL);
                        }
                        break;
                }
                INSERT_MODE();
                END_CMD();
            }
            return false;
            break;
// Paste
        case VIM_P:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (cmd_buf == KC_NO) {
                    if (!shifted) {
                        OS_RIGHT();
                    }
                    OS_PASTE();
                }
                END_CMD();
                return false;
            }
            return false;
            break;
// Undo
        case VIM_U:
            if (record->event.pressed) {
                END_CMD();
                register_code16(OS_KC_UNDO);
            } else {
                unregister_code16(OS_KC_UNDO);
            }
            return false;
            break;
// End
        default:
            return true;

    }
}

