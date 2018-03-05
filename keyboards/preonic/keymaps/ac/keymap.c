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
  _HOME,
  _LOWER,
  _RAISE,
  _NUMBERS,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE, // Kept as a reminder if I ever use this feature
};

enum funtions {
  ULTRA_KEY,
  S_ENT,
  S_1a,
  S_2a,
  S_3a,
  S_4a,
  S_5a,
  S_6a,
  S_7a,
  S_8a,
  S_9a,
  S_0a,
};

const uint16_t PROGMEM fn_actions[] = {
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [S_ENT] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [S_1a] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [S_2a] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [S_3a] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [S_4a] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [S_5a] = ACTION_MODS_KEY(MOD_LGUI, KC_5),
  [S_6a] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [S_7a] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [S_8a] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [S_9a] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [S_0a] = ACTION_MODS_KEY(MOD_LGUI, KC_0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* HOME */
[_HOME] = {
  {KC_GRV,       KC_1,    KC_2,         KC_3,    KC_4,                  KC_5,    KC_6,    KC_7,                  KC_8,    KC_9,    KC_0,    KC_EQL },
  {KC_TAB,       KC_Q,    KC_W,         KC_E,    KC_R,                  KC_T,    KC_Y,    KC_U,                  KC_I,    KC_O,    KC_P,    KC_BSPC},
  {F(ULTRA_KEY), KC_A,    KC_S,         KC_D,    KC_F,                  KC_G,    KC_H,    KC_J,                  KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,      KC_Z,    KC_X,         KC_C,    KC_V,                  KC_B,    KC_N,    KC_M,                  KC_COMM, KC_DOT,  KC_SLSH, F(S_ENT)},
  {KC_LCTL,      KC_LALT, TG(_NUMBERS), KC_LGUI, LT(_LOWER, KC_LBRC),   KC_SPC,  KC_SPC,  LT(_RAISE, KC_RBRC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* RAISE */
[_RAISE] = {
  {KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12},
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE},
  {_______, F(S_1a), F(S_2a), F(S_3a), F(S_4a), F(S_5a), F(S_6a), F(S_7a), F(S_8a), F(S_9a), F(S_0a), _______},
  {_______, _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, KC_NO,   KC_VOLD, KC_VOLU, KC_MPLY}
},

/* LOWER */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
  {_______, _______, _______, _______, KC_PERC, _______, _______, KC_PLUS, _______, _______, _______, KC_DEL},
  {_______, KC_F1,   _______, KC_LPRN, KC_RPRN, _______, KC_EQL,  KC_MINS, KC_LCBR, KC_RCBR, _______, KC_BSLS},
  {_______, F(S_1a), F(S_2a), F(S_3a), F(S_4a), F(S_5a), F(S_6a), F(S_7a), F(S_8a), F(S_9a), F(S_0a), _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MUTE, KC_NO,   KC_MNXT}
},

/* NUMBERS */
[_NUMBERS] = {
  {KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_SLSH , KC_ASTR, KC_MINS, KC_NO, KC_NO, KC_DEL},
  {_______, KC_TAB,  KC_UP,   KC_ENT,   KC_NO, KC_7,  KC_8,     KC_9,    KC_PLUS, KC_NO, KC_NO, KC_BSPC},
  {_______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_4,  KC_5,     KC_6,    KC_PLUS, KC_NO, KC_NO, KC_NO},
  {_______, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_1,  KC_2,     KC_3,    KC_ENT,  KC_NO, KC_NO, KC_ENT},
  {_______, _______, _______, _______,  KC_NO, KC_0,  KC_0,     KC_DOT,  KC_ENT,  KC_NO, KC_NO, KC_NO}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};
