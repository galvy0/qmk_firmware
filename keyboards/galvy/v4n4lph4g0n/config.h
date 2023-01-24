#pragma once

#include "config_common.h"


#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { B7, D2, B6, C6, C7 }
#define MATRIX_COL_PINS { E6, F0, F1, F4, F5, F6, B5, B4, D7, D6, D4, D3 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_TIMEOUT 300000


// mod tap setting
// global
#define IGNORE_MOD_TAP_INTERRUPT

// per key
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY
#define RETRO_TAPPING_PER_KEY

// combo
#define COMBO_COUNT 6
#define COMBO_TERM 50

// auto shift
#define AUTO_SHIFT_TIMEOUT_PER_KEY
