#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom Keys
#define ZC_CESC CTL_T(KC_ESC)   // Ctrl if held, Esc if tapped
#define ZC_HYPR LCAG(KC_NO)     // Ctrl - Alt - GUI
#define ZC_GUI MAGIC_UNNO_GUI   // Enable GUI key
#define ZC_NGUI MAGIC_NO_GUI    // Disable GUI key


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Tab   | Q     | W     | E     | R     | T     |   | Y     | U     | I     | O     | P     | Bksp  |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | *Esc  | A     | S     | D     | F     | G     |   | H     | J     | K     | L     | ; \ : | ' \ " |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Shift | Z     | X     | C     | V     | B     |   | N     | M     | , \ < | . \ > | / \ ? | Enter |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Ctrl  | Func  | Alt   | Super | Lower | Hyper |   | Space | Raise | Left  | Down  | Up    | Right |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ZC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWER,   ZC_HYPR, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Tab   | Q     | W     | F     | P     | G     |   | J     | L     | U     | Y     | ; \ : | Bksp  |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | *Esc  | A     | R     | S     | T     | D     |   | H     | N     | E     | I     | O     | ' \ " |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Shift | Z     | X     | C     | V     | B     |   | K     | M     | , \ < | . \ > | / \ ? | Enter |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Ctrl  | Func  | Alt   | Super | Lower | Hyper |   | Space | Raise | Left  | Down  | Up    | Right |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_COLEMAK] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  ZC_CESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWER,   ZC_HYPR, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Dvorak
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Tab   | ' \ " | , \ < | . \ > | P     | Y     |   | F     | G     | C     | R     | L     | Bksp  |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | *Esc  | A     | O     | E     | U     | I     |   | D     | H     | T     | N     | S     | / \ ? |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Shift | ; \ : | Q     | J     | K     | X     |   | B     | M     | W     | V     | Z     | Enter |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Ctrl  | Func  | Alt   | Super | Lower | Hyper |   | Space | Raise | Left  | Down  | Up    | Right |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  ZC_CESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWER,   ZC_HYPR, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | `     | !     | @     | #     | $     | %     |   | ^     | &     | *     | (     | )     | Del   |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       | BTN1  | MS_U  | BTN2  | WH_U  |       |   | +     | {     | }     | [     | ]     |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       | MS_L  | MS_D  | MS_R  | WH_D  |       |   | =     | \     | Pipe  | <     | >     | Insrt |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       |       |       |       | **+** |       |   |       |       | Home  | Pg Dn | Pg Up | End   |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_LOWER] = KEYMAP( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELT, \
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_EQL,  KC_BSLS, KC_PIPE, KC_LT,   KC_GT,   KC_INS,  \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Raise
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | ~     | 1     | 2     | 3     | 4     | 5     |   | 6     | 7     | 8     | 9     | 0     |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       | F1    | F2    | F3    | F4    | F5    |   | F6    | 4     | 5     | 6     | -     |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | RShft | F7    | F8    | F9    | F10   | F11   |   | F12   | 1     | 2     | 3     | _     |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | RCtrl |       | RAlt  | RSupr |       |       |   |       | **+** | Mute  | Vol - | Vol + |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_RAISE] = KEYMAP( \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_MINS, _______, \
  KC_RSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_UNDS, _______, \
  KC_RCTL, _______, KC_RALT, KC_RGUI, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______  \
),

/* Adjust (Lower + Raise)
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       | Qwrty | Colmk | Dvork |       |       |   |       |       |       |       |       |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Reset | AuOn  | AgSwp | NoGUI |       |       |   |       |       |       |       |       |       |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * | Caps  | AuOff | AgNrm | EnGUI |       |       |   |       |       | Prev  | Stop  | Pause | Next  |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 * |       | **+** |       |       |       |       |   |       |       | FFwrd | MStop | MPlay | Rewnd |
 * | ----- | ----- | ----- | ----- | ----- | ----- |   | ----- | ----- | ----- | ----- | ----- | ----- |
 */
[_ADJUST] =  KEYMAP( \
  _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
  RESET,   AU_ON,   AG_SWAP, ZC_NGUI, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_CAPS, AU_OFF,  AG_NORM, ZC_GUI,  _______, _______, _______, _______, KC_MNXT, KC_STOP, KC_PAUS, KC_MPRV, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MFFD, KC_MSTP, KC_MPLY, KC_MRWD  \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
