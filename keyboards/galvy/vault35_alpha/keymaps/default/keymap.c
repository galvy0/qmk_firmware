#include QMK_KEYBOARD_H
#include <stdio.h>
#include <math.h>

#if defined PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#endif

#if defined MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

#define L_DEF 0
#define L_TRP 1
#define L_LOW 2
#define L_RAI 3
#define L_SPC 4
#define L_NAV 5
#define L_NUM 6

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

// combos
const uint16_t PROGMEM ESC_combo[] = {LT(L_TRP,KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM CTL_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ALT_combo[] = {LT(L_NAV,KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM BSP_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM QUO_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ENT_combo[] = {KC_COMM, LT(L_NAV,KC_DOT), COMBO_END};

const uint16_t PROGMEM GRV_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM BSL_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM SLS_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};

const uint16_t PROGMEM TIL_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM PIP_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM QUE_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};

const uint16_t PROGMEM VDN_combo[] = {KC_MPRV, KC_MNXT, COMBO_END};

const uint16_t PROGMEM DEL_combo[] = {KC_PGUP, KC_PGDN, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(ESC_combo,KC_ESC),
  COMBO(CTL_combo,KC_LCTL),
  COMBO(ALT_combo,KC_LALT),
  COMBO(BSP_combo,KC_BSPC),
  COMBO(QUO_combo,KC_QUOT),
  COMBO(ENT_combo,KC_ENT),

  COMBO(GRV_combo,KC_GRV),
  COMBO(BSL_combo,KC_BSLS),
  COMBO(SLS_combo,KC_SLSH),

  COMBO(TIL_combo,KC_TILD),
  COMBO(PIP_combo,KC_PIPE),
  COMBO(QUE_combo,KC_QUES),

  COMBO(VDN_combo,KC_VOLD),

  COMBO(DEL_combo,KC_DEL),
};
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
LT(L_TRP,KC_Q),   KC_W,    KC_E,    KC_R,    KC_T,   KC_NO,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_NO,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
 LT(L_NAV,KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M, KC_COMM,LT(L_NAV,KC_DOT),
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        KC_LGUI,LT(L_LOW,KC_TAB),KC_LSFT,    KC_SPC,MO(L_RAI),LT(L_SPC,KC_RALT)
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_TRP] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        _______, KC_BTN1, KC_BTN3,          KC_BTN2, _______, _______
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_LOW] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        _______, _______, _______,          _______, _______, _______
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_RAI] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        _______, _______, _______,          _______, _______, _______
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_SPC] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
      _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, KC_MPRV, KC_MNXT,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        KC_LOCK, _______, _______,        TG(L_NUM),_______,TG(L_SPC)
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_NAV] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
        VIMQT,   VIMSV, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   RPIPE,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______,  KC_DEL, KC_BSPC,          _______, _______, _______,   RASGN, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        _______, _______, _______,          _______,TG(L_SPC),  KORLN
                    //|--------+--------+--------|        |--------+--------+--------|
  ), [L_NUM] = LAYOUT(
  //|--------------------------------------------|        |--------------------------------------------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, KC_BSPC,  KC_DEL,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,             KC_0,    KC_1,    KC_2,    KC_3, _______,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                        _______, _______, _______,          _______, _______,TG(L_NUM) 
                    //|--------+--------+--------|        |--------+--------+--------|
  )

};

// MOD TAP settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping 
        case LT(L_NAV,KC_Z):
            return false;
        case LT(L_NAV,KC_DOT):
            return false;
        case LT(L_TRP,KC_ESC):
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
        case LT(5,KC_BSPC):
            return false;
        case LT(L_TRP,KC_ESC):
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
        case LT(3,KC_RALT):
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
        case LT(L_TRP,KC_ESC):
            return 175;
        // default
        default:
            return 150;
    }
}

#if defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      layer_on(L_TRP);
      mh_auto_buttons_timer = timer_read();
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: on\n");
  #endif
    }
  }
}

void matrix_scan_user(void) {
  if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      layer_off(L_TRP);
      mh_auto_buttons_timer = 0;
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: off\n");
  #endif
    }
  }
}

#endif // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE

