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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _QWERTY2,
  _COLEMAK,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY2,
  COLEMAK,
  GAMING,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |GrEsc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  | Ctrl | Win  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY2] = LAYOUT_preonic_grid(
  KC_EQL,   KC_1,   KC_2,          KC_3,         KC_4,           KC_5,    KC_6,          KC_7,          KC_8,         KC_9,         KC_0,       KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,          KC_E,         KC_R,           KC_T,    KC_Y,          KC_U,          KC_I,         KC_O,         KC_P,       KC_MINS,
  KC_GESC,  KC_A,   LCTL_T(KC_S),  LGUI_T(KC_D), LALT_T(KC_F),   KC_G,    KC_H,          RALT_T(KC_J),  RGUI_T(KC_K), RCTL_T(KC_L), KC_SCLN,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,          KC_C,         KC_V,           KC_B,    KC_N,          KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,    KC_SFTENT,
  KC_BSLS,  KC_GRV, KC_LBRC,       KC_RBRC,      LOWER,          KC_SPC,  KC_SPC,        RAISE,         KC_LEFT,      KC_DOWN,      KC_UP,      KC_RGHT
),

[_QWERTY] = LAYOUT_preonic_grid(
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_BSLS, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |GrEsc |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SFTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  | Ctrl | Win  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_EQL,  KC_1,    KC_2,         KC_3,         KC_4,         KC_5,   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,     KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,         KC_F,         KC_P,         KC_G,   KC_J,   KC_L,         KC_U,         KC_Y,         KC_SCLN,  KC_MINS,
  KC_GESC, KC_A,    KC_R,         KC_S,         KC_T,         KC_D,   KC_H,   KC_N,         KC_E,         KC_I,         KC_O,     KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,         KC_C,         KC_V,         KC_B,   KC_K,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,  KC_SFTENT,
  KC_BSLS, KC_LCTL, KC_LGUI,      KC_LALT,      LOWER,        KC_SPC, KC_SPC, RAISE,        KC_LEFT,      KC_DOWN,      KC_UP,    KC_RGHT

),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
*/

[_GAMING] = LAYOUT_preonic_grid(
  KC_EQL,     KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,       KC_BSPC,
  KC_TAB,     KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,       KC_MINS,
  KC_GESC,     KC_A,     KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   RALT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), KC_SCLN,    KC_QUOT,
  KC_LSFT,    KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,    KC_SFTENT,
  KC_BSLS,    KC_PSCR,  KC_NO,  KC_M,   LOWER,  KC_SPC, KC_SPC, RAISE,        KC_LEFT,      KC_DOWN,      KC_UP,      KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |  Up  |      |      |      |   7  |   8  |   9  |   -  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  F1  | Left | Down |Right |      |      |   4  |   4  |   6  |   +  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Pause |Insert|ScrLck|      | Reset|  0   |   1  |   2  |   3  |   =  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   :  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_TRNS,    KC_NO,    KC_NO,    KC_UP,    KC_NO,    KC_NO,    KC_NO,    KC_7,     KC_8,     KC_9,     KC_MINS,  KC_F12,
  KC_CAPS,    KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_NO,    KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_ASTR,
  KC_TRNS,    KC_BRK,   KC_INS,   KC_SLCK,  KC_NO,    RESET,    KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,   KC_SLSH,
  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_COLN,  KC_DOT,   KC_NO,    KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  | Home |      |  Up  |      | PGUP |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  | End  | Left | Down |Right | PGDN |      |      |      |      |      |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  `   |   [  |   ]  |      |      |      |      |      |      |      |SFTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |C-A-D |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DEL,
  KC_TAB,   KC_HOME,  KC_NO,    KC_UP,        KC_NO,    KC_PGUP,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
  KC_ESC,   KC_END,   KC_LEFT,  KC_DOWN,      KC_RGHT,  KC_PGDN,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_QUOT,
  KC_LSFT,  KC_GRV,   KC_LBRC,  KC_RBRC,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SFTENT,
  KC_NO,    KC_NO,    KC_NO,    LCA(KC_DEL),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|GAMING|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB  | RGB+ | RGB- |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,    KC_F2,     KC_F3,    KC_F4,   KC_F5,      KC_F6,      KC_F7,   KC_F8,    KC_F9,      KC_F10,     KC_F11,     KC_F12,
  KC_TRNS,  RESET,     DEBUG,    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, TERM_ON,  TERM_OFF,   KC_TRNS,    KC_TRNS,    KC_DEL,
  KC_TRNS,  KC_TRNS,   MU_MOD,   AU_ON,   AU_OFF,     AG_NORM,    AG_SWAP, QWERTY,   COLEMAK,    GAMING,     QWERTY2,    KC_TRNS,
  KC_TRNS,  MUV_DE,    MUV_IN,   MU_ON,   MU_OFF,     MI_ON,      MI_OFF,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  RGB_TOG,  RGB_MOD,   RGB_RMOD, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS

  )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case QWERTY2:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY2);
          }
          return false;
          break;
       case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case GAMING:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAMING);
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
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
