#include QMK_KEYBOARD_H
#include <stdio.h>
#include <math.h>

#define L_DEF 0
#define L_GAM 1
#define L_LOW 2
#define L_RAI 3
#define L_SPC 4
#define L_NAV 5
#define L_NUM 6

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
};

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer\n"), false);
    switch (layer_state) {
        case L_DEF:
            oled_write_ln_P(PSTR("-Def-"), false);
            break;
        case (int)pow(2,L_GAM):
            oled_write_ln_P(PSTR("-Gam-"), false);
            break;
        case (int)pow(2,L_LOW):
            oled_write_ln_P(PSTR("-Low-"), false);
            break;
        case (int)pow(2,L_RAI):
            oled_write_ln_P(PSTR("-Rai-"), false);
            break;
        case (int)pow(2,L_SPC):
            oled_write_ln_P(PSTR("-Spc-"), false);
            break;
        case (int)pow(2,L_NAV):
            oled_write_ln_P(PSTR("-Nav-"), false);
            break;
        case (int)pow(2,L_NUM):
        case (int)pow(2,L_NUM)|(int)pow(2,L_GAM):
            oled_write_ln_P(PSTR("-Num-"), false);
            break;
        default :
            oled_write_ln_P(PSTR("-MUL-"), false);
    }
}

void oled_render_logo(void) {
//    static const char PROGMEM forty_logo[] = { 
//      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x30, 0x9c, 0x8e, 0xff, 0xe0, 0x40, 0x40, 0x60, 
//      0x60, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//      0x80, 0xe0, 0xf0, 0x98, 0x8e, 0xe3, 0xf9, 0x8e, 0x87, 0x81, 0x81, 0xff, 0x80, 0x80, 0x80, 0x80, 
//      0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x83, 0x8e, 0xbc, 0xf0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
//      0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x71, 0xe0, 0x80, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 
//      0x01, 0x01, 0x3d, 0x25, 0x2d, 0xbd, 0xc1, 0x71, 0x3d, 0x8f, 0xe1, 0x39, 0x1d, 0x07, 0x03, 0x00, 
//      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x7f, 0x7f, 0x02, 0x02, 0x06, 0x06, 
//      0x06, 0x06, 0x02, 0x03, 0x03, 0x61, 0x38, 0x1c, 0x07, 0x03, 0x00, 0x30, 0x78, 0x48, 0x78, 0x30
//    };
    static const char PROGMEM phoenix[] = { 
      0x00, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x98, 0xcc, 0xec, 0x7c, 0x3e, 
      0x06, 0x06, 0x06, 0x03, 0x83, 0x83, 0xc3, 0xc3, 0xc3, 0xe3, 0x63, 0x73, 0x3b, 0x1f, 0x1e, 0x06, 
      0x01, 0x01, 0x00, 0x80, 0xc0, 0xc0, 0xf0, 0x78, 0x3c, 0x3e, 0x3f, 0x1f, 0x1d, 0x0c, 0x0c, 0x0e, 
      0x06, 0x06, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x08, 0x0e, 0x07, 0x03, 0x01, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x60, 
      0x20, 0x30, 0x30, 0x30, 0x18, 0x18, 0x98, 0x98, 0x8c, 0x8c, 0x8e, 0x06, 0x07, 0x03, 0x01, 0x00, 
      0x00, 0x1c, 0xfe, 0xfe, 0xff, 0x83, 0x1b, 0xf9, 0x79, 0x6d, 0x6c, 0x26, 0x36, 0x36, 0x36, 0x32, 
      0x13, 0x13, 0x13, 0x11, 0x11, 0x19, 0x19, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x07, 0x3f, 0x3f, 0x00, 0x10, 0x1a, 0x1b, 0x1b, 0x1b, 0x19, 0x19, 0x09, 0x09, 
      0x09, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(phoenix, sizeof(phoenix));
}

void oled_render_caps_state(void){
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("\n=CAPS\n") : PSTR("\n    \n\n"), false);
}

bool oled_task_user(void) {
    oled_render_layer_state();
    oled_render_caps_state();
    oled_render_logo();
    return true;
};
#endif // OLED_ENABLE

// macros
enum custom_keycodes {
  RPIPE = SAFE_RANGE, RASGN, // R macros
  KORLN,
  CAPZ,CTRLB, // lower row mod alternatives
  VIMSV,VIMQT // vim macros
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {    
  switch (keycode) {    
    case RPIPE:        
      if (record->event.pressed){
        SEND_STRING("%>%");
      } 
      break;    
    case RASGN:        
      if (record->event.pressed){
        SEND_STRING("<-");        
      } 
      break;    
    case KORLN:        
      if (record->event.pressed){
        SEND_STRING(SS_LGUI(" ") SS_DELAY(200) SS_TAP(X_RALT));
      } 
      break;
    case VIMSV:        
      if (record->event.pressed){
        SEND_STRING(":w!");
      } 
      break;
    case VIMQT:        
      if (record->event.pressed){
        SEND_STRING(":q!");
      } 
      break;
    case CAPZ:
      if (record->event.pressed){
        SEND_STRING("Z");
      }
      break;
    case CTRLB:
      if (record->event.pressed){
        SEND_STRING(SS_LCTL("B"));
      }
      break;
  }    
  return true;
};
 
// combos
const uint16_t PROGMEM GUI_combo[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM ESC_combo[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM BSL_combo[] = {KC_O, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ENT_combo[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM QUO_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM FTW_combo[] = {KC_MINS, KC_RBRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(GUI_combo,KC_LGUI),
  COMBO(ESC_combo,KC_ESC),
  COMBO(BSL_combo,KC_BSLS),
  COMBO(ENT_combo,KC_ENT),
  COMBO(QUO_combo,KC_QUOT),
  COMBO(FTW_combo,KC_F12),
};
layer_state_t layer_state_set_user(layer_state_t state) {
    combo_enable();
    if (layer_state_cmp(state, L_GAM)) {
        combo_disable();
    }
    return state;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,LSFT_T(KC_Z),KC_X,    KC_C,    KC_V,LCTL_T(KC_B),                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
               _______, KC_LALT,LT(L_LOW,KC_TAB),LT(L_NAV,KC_BSPC),KC_MUTE,KC_SPC,MO(L_RAI),LT(L_SPC,KC_RALT), _______
                    //|--------+--------+--------+--------|--------|--------+--------+--------+--------|
  ), [L_LOW] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, _______, _______, _______, _______,          _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______,  KC_DEL, _______, _______, _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_RAI] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, _______, _______, _______, _______,          _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______,  KC_DEL, _______, _______, _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_SPC] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, _______, _______, _______, _______,          KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, KC_LOCK, KC_RSFT, KC_LCTL, KC_SPC,TG(L_NUM),_______,TG(L_SPC), _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_NAV] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______,   VIMQT,   VIMSV, _______, _______, _______,          _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,_______,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   RPIPE, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    CAPZ, _______, _______, _______,   CTRLB,           _______, _______,   RASGN, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______,TG(L_SPC),_______, _______, KC_PSCR, KC_BSPC, _______,   KORLN, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_NUM] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,           KC_F12,    KC_4,    KC_5,    KC_6, KC_BSPC, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______, _______, _______, _______, _______,TG(L_NUM), _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  )

};
// ENCODER
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
      switch(biton32(layer_state)){
        case L_NAV:
          if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
          break;
        case L_SPC:
          if (clockwise) {
              tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
        case L_GAM:
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
          break;
        default:
          if (clockwise) {
              tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
      }
    }
    return false;
}

// MOD TAP settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping 
        case LCTL_T(KC_N):
            return false;
        case LCTL_T(KC_B):
            return false;
        case LSFT_T(KC_Z):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping
        case LT(5,KC_BSPC):
            return false;
        case LCTL_T(KC_N):
            return false;
        case LCTL_T(KC_B):
            return false;
        case LSFT_T(KC_Z):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_B):
            return false;
        // default true - no auto-hold with double tap, but allow using hold right after using tap
        default:
            return true;
    }
}
// retro tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3,KC_RALT):
            return true;
        case LT(L_LOW,KC_TAB):
            return true;
        // default false - nothing happens when you exceed tapping term but not use hold
        case LSFT_T(KC_Z):
            return false;
        case LCTL_T(KC_B):
            return false;
        default:
            return false;
    }
}
// tapping term 
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { 
        // low tapping term favors hold
        // high tapping term favors tap
        case LALT_T(KC_ESC):
            return 200;
        case LCTL_T(KC_B):
            return 125;
        case LCTL_T(KC_N):
            return 125;
        case LSFT_T(KC_Z):
            return 125;
        case LSFT_T(KC_X):
            return 125;
        // default
        default:
            return 150;
    }
}

