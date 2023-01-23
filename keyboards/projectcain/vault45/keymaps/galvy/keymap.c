 /* Copyright 2021 projectcain 
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * */

#include QMK_KEYBOARD_H
enum layers{
  L_DEF,
  L_LOW,
  L_RAI,
  L_SPC,
  L_NAV,
  L_NUM
};

// macros
enum custom_keycodes {
  RPIPE = SAFE_RANGE, RASGN, // R macros
  KORLN,
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
  }    
  return true;
};
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_split_4space(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_MUTE,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOTE,
    KC_LALT,   LT(L_NAV,KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM, LT(L_NAV,KC_DOT),KC_ENT,KC_ENT,
         MO(L_NAV), KC_LGUI, LT(L_LOW,KC_TAB),      KC_LSFT,  KC_SPACE,  MO(L_RAI),     LT(L_SPC,KC_RALT), MO(L_NAV)
  ),
  [L_LOW] = LAYOUT_split_4space(
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS, _______,
    _______, _______,  KC_F10,  KC_F11,  KC_F12, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_SLSH,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [L_RAI] = LAYOUT_split_4space(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUES,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_SPC] = LAYOUT_split_4space(
    _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______, KC_ESC,
    KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD, _______,
                      KC_LOCK, _______, _______, _______,TG(L_NUM),KC_LCTL, KC_LSFT,TG(L_SPC)
  ),
  [L_NAV] = LAYOUT_split_4space(
    _______,   VIMQT,   VIMSV, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_DEL, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   RPIPE, _______,
    _______, _______, _______, _______,  KC_DEL, KC_BSPC, _______, _______,   RASGN, _______, _______, _______,
                      _______, _______, _______, _______, _______,TG(L_SPC),  KORLN, _______
  ),
  [L_NUM] = LAYOUT_split_4space(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, _______,
    KC_CAPS,    KC_7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_4,    KC_5,    KC_6, _______, _______,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______,TG(L_NUM) 
  ),
};
// Encoder
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_DEF] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_LOW] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_RAI] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_SPC] =   { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
    [L_NAV] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_NUM] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif


// MOD TAP settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping 
        case LT(L_NAV,KC_Z):
            return false;
        case LT(L_NAV,KC_DOT):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping
        case LT(L_NAV,KC_Z):
            return false;
        case LT(L_NAV,KC_DOT):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // default true - no auto-hold with double tap, but allow using hold right after using tap
        default:
            return true;
    }
}
// retro tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(L_SPC,KC_RALT):
            return true;
        // default false - nothing happens when you exceed tapping term but not use hold
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
        case LT(L_NAV,KC_Z):
            return 175;
        case LT(L_NAV,KC_DOT):
            return 175;
        // default
        default:
            return 150;
    }
}

