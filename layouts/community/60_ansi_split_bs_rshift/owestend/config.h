#include QMK_KEYBOARD_CONFIG_H

#define SPLIT_BS        1
#define SPLIT_RSHIFT    1
#define SPC_COUNT       1
#define ARROW_KEYS      1

#define TEMPLATE_TKL( \
    K50,      K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D,   K60, K61, K3E, \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K63, K64, K65, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K66, K67, K68, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,                  \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,        K75,      \
    K40, K41, K42,           K45, K46, K47,           K4A, K4B, K4C, K4D,   K76, K77, K78  \
) LAYOUT_60_ansi_split_bs_rshift( \
    K50, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K00, K1D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K0D,      \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, \
    K40, K41, K42,                K46,                K4A, K4B, K4C, K4D      \
)
