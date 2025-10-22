#include QMK_KEYBOARD_H

#define L_DEF 0
#define L_LOW 1
#define L_RAI 2
#define L_SPC 3
#define L_NAV 4
#define L_NUM 5

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
};

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer\n"), false);
    switch (layer_state) {
        case L_DEF:
            oled_write_ln_P(PSTR("-Def-"), false);
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
		 	 KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
TD(TD_ALT_GUI),LT(L_NAV,KC_Z),KC_X, KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M, KC_COMM, LT(L_NAV,KC_DOT),KC_ENT,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
                			MO(L_NAV),  KC_TAB,MO(L_LOW),KC_LSFT,           KC_SPC,MO(L_RAI),LT(L_SPC,KC_RALT),KC_MUTE
                    //|--------+--------+--------+--------|--------|--------+--------+--------+--------|
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
        // default true
        default:
            return true;
    }
}
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(L_NAV,KC_Z):
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
        case TD(TD_ALT_GUI):
            return 200;
        // default
        default:
            return 150;
    }
}

