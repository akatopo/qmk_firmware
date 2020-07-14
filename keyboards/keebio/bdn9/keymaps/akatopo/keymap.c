/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

/*
    | Knob 1 (_LEFT)     | -                 | -             |
    | Knob press         | -                 | -             |
    | UL square cluster  | UR square cluster | -             |
    | LL square cluster  | LR square cluster | Below Knob 1  |
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | N/A            | -          | -          |
        | Media Play     | Mute       | -          |
        | Media Previous | Media Next | To layer 1 |
     */
    [0] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,
        KC_MPLY, KC_MUTE, KC_NO,
        KC_MRWD, KC_MFFD, TO(1)
    ),
    /*
        | N/A | -   | -          |
        | F13 | F14 | -          |
        | F15 | F16 | To Layer 0 |
     */
    [1] = LAYOUT(
        KC_NO, KC_NO, KC_NO,
        KC_F13, KC_F14, KC_NO,
        KC_F15, KC_F16, TO(0)
    ),
};

// bentō only has _LEFT encoder
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT && layer_state_is(0)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == _LEFT && layer_state_is(1)) {
        if (clockwise) {
            tap_code(KC_F17);
        } else {
            tap_code(KC_F18);
        }
    } else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
