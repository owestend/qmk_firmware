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
#pragma once

#define END_CMD()       { no_buf = 0; cmd_buf = KC_NO; }
#define INSERT_MODE()   { END_CMD(); layer_off(_VIM); }

// move char
#define OS_KC_RIGHT     KC_RIGHT
#define OS_KC_DOWN      KC_DOWN
#define OS_KC_UP        KC_UP
#define OS_KC_LEFT      KC_LEFT

// move word
#define OS_KC_END      LCTL(KC_RIGHT)
#define OS_KC_WORD     LCTL(KC_RIGHT)
#define OS_KC_BACK     LCTL(KC_LEFT)

// del
#define OS_KC_DEL       KC_DEL

// undo redo
#define OS_KC_UNDO      LCTL(KC_Z)
#define OS_KC_REDO      LCTL(KC_Y)

#define OS_MARK(OS_MOV) { register_code(KC_LSFT); OS_MOV; unregister_code(KC_LSFT); }
#define OS_MARK_ON()    { register_code(KC_LSFT); }
#define OS_MARK_OFF()   { unregister_code(KC_LSFT); }

// move
#define OS_LEFT()       { tap_code16(OS_KC_LEFT); }
#define OS_RIGHT()      { tap_code16(OS_KC_RIGHT); }
#define OS_DOWN()       { tap_code16(OS_KC_DOWN); }
#define OS_UP()         { tap_code16(OS_KC_UP); }
// word move
#define OS_END()        { tap_code16(OS_KC_RIGHT); }
#define OS_WORD()       { tap_code16(OS_KC_RIGHT); tap_code16(OS_KC_RIGHT); tap_code16(OS_KC_LEFT); }
#define OS_BACK()       { tap_code16(OS_KC_LEFT); }
// line move
#define OS_LEND()       { tap_code(KC_END); }
#define OS_LBEGIN()     { tap_code(KC_HOME); }
// file move
#define OS_FEND()       { tap_code(LCTL(KC_END)); }
#define OS_FBEGIN()     { tap_code(LCTL(KC_HOME)); }

//mark
#define OS_ACHAR()      { OS_MARK(OS_RIGHT()); }
#define OS_AWORD()      { OS_END(); OS_BACK(); OS_MARK(OS_END()); }

// line mark
#define OS_LTEND()      { OS_MARK(OS_LEND()); }
#define OS_LTBEGIN()    { OS_MARK(OS_LBEGIN()); }
#define OS_LWHOLE()     { OS_LBEGIN(); OS_MARK(OS_LEND()); }

// cut/copy/paste
#define OS_CUT()        { tap_code16(LSFT(KC_DEL)); }
#define OS_COPY()       { tap_code16(LCTL(KC_INS)); }
#define OS_PASTE()      { tap_code16(LSFT(KC_INS)); }
/*
#define OS_CUT()        { tap_code16(LCTL(KC_X)); }
#define OS_COPY()       { tap_code16(LCTL(KC_C)); }
#define OS_PASTE()      { tap_code16(LCTL(KC_V)); }
*/


// undo/redo
#define OS_UNDO()       { tap_code16(LCTL(KC_Z)); }
#define OS_REDO()       { tap_code16(LCTL(KC_Y)); }

#define OS_UNMARK()     { OS_LEFT(); OS_RIGHT(); }

