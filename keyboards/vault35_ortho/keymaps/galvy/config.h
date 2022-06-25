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

// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_TIMEOUT 300000

// ENCODER
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_DIRECTION_FLIP

// Locking support
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
