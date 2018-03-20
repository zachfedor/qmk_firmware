/* Copyright 2015-2017 Jack Humbert
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
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

#define ZC_CESC CTL_T(KC_ESC)   // Ctrl if held, Esc if tapped
#define ZC_GUI MAGIC_UNNO_GUI   // Enable GUI key
#define ZC_NGUI MAGIC_NO_GUI    // Disable GUI key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \   |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | *Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Brite |  Alt  |  GUI  | Lower | Enter | Space | Raise | Left  | Down  |  Up   | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
  {ZC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   Q   |   W   |   F   |   P   |   G   |   J   |   L   |   U   |   Y   |   ;   |   \   |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | *Esc  |   A   |   R   |   S   |   T   |   D   |   H   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   K   |   M   |   ,   |   .   |   /   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Brite |  Alt  |  GUI  | Lower | Enter | Space | Raise | Left  | Down  |  Up   | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS},
  {ZC_CESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   "   |   ,   |   .   |   P   |   Y   |   F   |   G   |   C   |   R   |   L   |   \   |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | *Esc  |   A   |   O   |   E   |   U   |   I   |   D   |   H   |   T   |   N   |   S   |   /   |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * | Shift |   ;   |   Q   |   J   |   K   |   X   |   B   |   M   |   W   |   V   |   Z   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Brite |  Alt  |  GUI  | Lower | Enter | Space | Raise | Left  | Down  |  Up   | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS},
  {ZC_CESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT},
  {KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   ~   |       |       |       |       |       |       |   &   |   *   |   (   |   )   |   \   |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * |       | BTN1  | MS_U  | BTN2  | WH_U  |       |   _   |   $   |   %   |   ^   |   )   |   \   |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * |       | MS_L  | MS_D  | MS_R  | WH_D  |       |   +   |   !   |   @   |   #   | PgUp  | Insrt |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       | *___* |       |       |       |       | Home  | PgDwn |  End  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  {KC_TILD, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS},
  {_______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, KC_UNDS, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN, KC_BSLS},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_PGUP, KC_INS },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   `   |       |       |       |       |       |       |   7   |   8   |   9   |   0   |   /   |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | RCtrl |   [   |   ]   |   (   |   )   |       |   -   |   4   |   5   |   6   |   0   |   /   |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * |       |   <   |   >   |   {   |   }   |       |   =   |   1   |   2   |   3   | Vol + |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       | RAlt  | RGUI  |       |       |       | *___* |       | Mute  | Vol - |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {KC_GRV,  _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH},
  {KC_RCTL, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    KC_SLSH},
  {_______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    KC_VOLU, _______},
  {_______, _______, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------.
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F0   | Reset |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | Qwrty | Colmk | Dvrak |       |       |       |       |       |  F11  |  F12  |       |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * |       | Audio | AgSwp | GUI   | Midi  | Music | Voic+ |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * | Caps  | " Off | AgNrm | " Off | " Off | " Off | Voic- |       |       | Prev  | MPlay | Next  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       | *___* |       |       | *___* |       | Rewnd | MStop | FFwrd |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET  },
  {_______, QWERTY,  COLEMAK, DVORAK,  _______, _______, _______, _______, _______, KC_F11,  KC_F12,  _______},
  {_______, AU_ON,   AG_SWAP, ZC_GUI,  MI_ON,   MU_ON,   MUV_IN,  _______, _______, _______, _______, _______},
  {KC_CAPS, AU_OFF,  AG_NORM, ZC_NGUI, MI_OFF,  MU_OFF,  MUV_DE,  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MSTP, KC_MFFD}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};
