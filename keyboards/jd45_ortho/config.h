#pragma once

#include "config_common.h"

#define VENDOR_ID       0x1234
#define PRODUCT_ID      0x5678
#define DEVICE_VER      0x0001
#define MANUFACTURER    glavh
#define PRODUCT         JD45_ORTHO

#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { D2, F7, B5, B6 }
#define MATRIX_COL_PINS { E6, F0, F1, F4, F5, F6, B4, D7, D6, D4, D5, D3 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_TIMEOUT 300000

// ENCODER
#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { C7 }
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

