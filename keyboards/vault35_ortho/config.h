#pragma once

#include "config_common.h"

#define VENDOR_ID       0x1234
#define PRODUCT_ID      0x5678
#define DEVICE_VER      0x0001
#define MANUFACTURER    glavh
#define PRODUCT         VAULT35_ORTHO

#define MATRIX_ROWS 4
#define MATRIX_COLS 11

#define MATRIX_ROW_PINS { F1, B2, F6, F4 }
#define MATRIX_COL_PINS { F5, F7, D4, B3, B1, C6, B4, D7, D6, D3, D2 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// ENCODER
#define ENCODER_RESOLUTION 4
