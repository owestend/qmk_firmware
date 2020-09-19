#include QMK_KEYBOARD_CONFIG_H


#define TEMPLATE_TKL( \
    K50,      K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D,   K60, K61, K3E, \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K63, K64, K65, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K66, K67, K68, \
    K20, K21, K22, K23, K24, K25, K26, K27, K58, K29, K2A, K2B,      K2D,                  \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,        K75,      \
    K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D,   K76, K77, K78, \
) LAYOUT_65_ansi( \
    K50, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K2D, K64,     \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K65,     \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      K68,     \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,      K75, K67,     \
    K40, K41, K42,                K46,                K4A, K4B, K4D, K76, K77, K78      \
)

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgD│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │           Space        │Alt│FN │Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
    [_BL] = LAYOUT_65_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,   KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,   KC_PGUP,
        LCTL_ESC,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,    KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   KC_UP,     KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FL), KC_RCTL, KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
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