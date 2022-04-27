#pragma once

#include "config_common.h"

#define VENDOR_ID       0x1234
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    glavh
#define PRODUCT         glanck50

#define MATRIX_ROWS 7
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { F5, B1, B3, B2, B6, C6, F6 }
#define MATRIX_COL_PINS { F4, F7, D4, B5, D7, B4, E6 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_TIMEOUT 300000

// ENCODER
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 4


// mod tap setting
// global
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100
#define IGNORE_MOD_TAP_INTERRUPT

// per key
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY
#define RETRO_TAPPING_PER_KEY

// combo
#define COMBO_COUNT 2
#define COMBO_TERM 100

