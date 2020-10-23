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
#define SEC_MACROS  10

//define secret keycodes
enum secrets_keycodes {
    KC_SEC = SAFE_RANGE,
    KC_SEC_MAX = (KC_SEC + SEC_MACROS - 1),
    SEC_SAFE_RANGE
};

#undef  SAFE_RANGE
#define SAFE_RANGE  SEC_SAFE_RANGE

#if (SEC_MACROS > 0)
    #define SEC_M(x)    (KC_SEC + x)
#endif
