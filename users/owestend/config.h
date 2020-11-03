#pragma once

 #ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_ANIMATIONS
#endif // RGBLIGHT_ENABLE

// Detail settings for various features
// Tap-Hold-Configuration
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM            200
#define TAPPING_TERM_SPC        400
#define TAPPING_TERM_ARROWS     150
#define TAPPING_TERM_CTL_ESC    400

// Delay for macro taps
#define MACRO_DELAY             5
