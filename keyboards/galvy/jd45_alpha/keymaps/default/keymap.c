#include QMK_KEYBOARD_H

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
  VIMSV,VIMQT, // vim macros
  TD_ALT_GUI = 0
};
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for ALT, twice for GUI
  [TD_ALT_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI)
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
  [L_DEF] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
LT(L_TRP,KC_ESC), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,LT(L_TRP,KC_I),KC_O,  KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
TD(TD_ALT_GUI),LT(L_NAV,KC_Z),KC_X, KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M, KC_COMM, LT(L_NAV,KC_DOT),KC_ENT,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                      MO(L_NAV),  KC_TAB,MO(L_LOW),KC_LSFT,           KC_SPC,MO(L_RAI),LT(L_SPC,KC_RALT),KC_MUTE
                    //|--------+--------+--------+--------|--------|--------+--------+--------+--------|

  ), [L_TRP] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, KC_LSFT, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, KC_BTN1, KC_BTN3,          KC_BTN2, _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_LOW] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______,  KC_F10,  KC_F11,  KC_F12, _______,          _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______, _______,          _______, _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_RAI] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUES,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______, _______,          _______, _______, _______, _______
                    //|--------+--------+--------+-------|        |--------+--------+--------+--------|
  ), [L_SPC] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                      TG(L_SPC), _______, _______, QK_LOCK,        TG(L_NUM), _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_NAV] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______,   VIMQT,   VIMSV, _______, _______, _______,          _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   RPIPE, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,  KC_DEL, KC_BSPC,          _______, _______, _______,   RASGN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                        _______, _______, _______, _______,          _______,TG(L_SPC),  KORLN, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
  ), [L_NUM] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,           KC_F12,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          _______,    KC_0,    KC_1,    KC_2,    KC_3, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                      TG(L_NUM), _______, _______, _______,          _______, _______, _______, _______
                    //|--------+--------+--------+--------|        |--------+--------+--------+--------|
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
        case LT(L_TRP,KC_I):
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
        case LT(L_TRP,KC_I):
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
        case LT(L_NAV,KC_Z):
            return false;
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
        case LT(L_TRP,KC_I):
            return 175;
        case LT(L_TRP,KC_ESC):
            return 175;
        case TD(TD_ALT_GUI):
            return 200;
        // default
        default:
            return 150;
    }
}

/*
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
*/

