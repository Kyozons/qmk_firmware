#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _FN3_LAYER,
};

//* ------------------------TAP DANCE----------------------- *
// Declare the tap dance functions first and appart from other
// enum declarations.
enum {
   TD_SPC_ENT,
};

// Tap dance array, to declare different behaviours of TD.
// Must be declared before keymaps, NOT AFTER.
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Space, twice for Enter:
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
};
//* -------------------------------------------------------- *
/*
* Layer
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab/FN2 |  - |  ,  |  .  |  p  |  y  |  f  |  g  |  c  |  r  |  l  |  Bksp  |  ´ |  }   |
* |-----------------------------------------------------------------------------------------+
* | esc/FN1 |  a  |  o  |  e  |  u  |  i  |  d  |  h  |  t  |  n  |  s  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  <>  |  q  |  j  |  k  |  x  |  b  |  m  |  w  |  v  |  z  |    Shift      |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  | SUPER |  Alt  |            space/enter          |  Alt  |  FN3  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    LT(_FN2_LAYER,KC_TAB), KC_SLSH, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_LBRC, KC_BSLS,
    LT(_FN1_LAYER,KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, TD(TD_SPC_ENT), KC_RALT, LT(_FN3_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  -  | UP  | .  |  p  |  y  |  f  |  g  |  c  |  r  | PS | HOME | END |   }    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  u  |  i  |  d  |  h  |  t  |  n  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  k  |  x  |  b  |  m  |  w  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  SUPER |  Alt  |              space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab | LCLICK | MOUSEU | RCLICK | SCRLUP | y  | + | 7 | 8  |  9  | -  | HOME | END |  }  |
  * |-----------------------------------------------------------------------------------------+
  * | NONE |MOUSEL |MOUSED |MOUSER|SCRLDWN| i |  *  |  4  |  5  |  6  | / |  PGDN |   Enter   |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  <>  |  q  |  j | MBUTTON3 |  x  |  b  |  1  |  2  |  3  |  0  |   Shift   |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | SUPER |  PREVTRACK  |      PLAY/PAUSE      |  NEXTTRACK |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, KC_RBRC, KC_7, KC_8, KC_9, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PSLS, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_0, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS
 ),
/*
* Layer _FN3_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  '  | + |  BACKSPACE |
* |-----------------------------------------------------------------------------------------+
* |  TAB/FN2 |   !  |  q   |  (   |   )  |   y  |  f  | g  | c | r | l |  BACKSPACE | ´ | } |
* |-----------------------------------------------------------------------------------------+
* |  ESC/FN1 |   a  |  o   |  {  |  }  | i | !  |  #   |  /   |  |   |  \   |  $   |  ENT   |
* |-----------------------------------------------------------------------------------------+
* | LSHIFT  |   <  | q   |  [   |  ]   | x | b |  q   |  w   |  v   |  z   |       UP       |
* |-----------------------------------------------------------------------------------------+
* | LCTRL | SUPER | LALT |        SPACE/ENTER            |  ALTGR   |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/

[_FN3_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    KC_TRNS, ALGR(KC_Q), KC_Q, LSFT(KC_8), LSFT(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_BSLS, KC_TRNS, KC_EXLM, KC_HASH, LSFT(KC_7), KC_GRV, KC_MINS, KC_DLR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_QUOT), LSFT(KC_BSLS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),

};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
     annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
