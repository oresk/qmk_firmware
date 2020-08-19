/* Copyright 2020 Lovro Oreskovic lovro@oreskovic.me
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

#include "process_braille.h"
#include "keymap_braille.h"
#include "quantum_keycodes.h"

uint8_t braille_to_keycode_mapping[] = {
    KC_A,
    KC_B,
    KC_C,
    KC_D,
    KC_E,
    KC_F,
    KC_G,
    KC_H,
    KC_I,
    KC_J,
    KC_K,
    KC_L,
    KC_M,  // 0x10
    KC_N,
    KC_O,
    KC_P,
    KC_Q,
    KC_R,
    KC_S,
    KC_T,
    KC_U,
    KC_V,
    KC_W,
    KC_X,
    KC_Y,
    KC_Z,
    KC_1,
    KC_2,
    KC_3,  // 0x20
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_0,
};

#define MAX_STATE_SIZE 6

static uint8_t state   = 0;
static uint8_t pressed = 0;

void braille_init() {}

void send_braille_key(void);

void send_braille_key(){
    // map braille dot to regular keycodes
    if(state < 35){
        tap_code16(braille_to_keycode_mapping[state]);
    } else {
        tap_code16(KC_I);
    }
    state = 0;
}

void update_state_braille(uint16_t dot, bool is_pressed){
    if (is_pressed && dot < (BRL__MAX - BRL__MIN)){
        state |= (1 << dot);
    }
}

/* override to intercept chords right before they get sent.
 * return zero to suppress normal sending behavior.
 */

__attribute__((weak)) bool process_braille_kb(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool process_braille_user(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_braille(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BRL__MIN ... BRL__MAX:
            if (!process_braille_kb(keycode, record)) {
                return false;
            }
            if (!process_braille_user(keycode, record)) {
                return false;
            }
            if (IS_PRESSED(record->event)) {
                update_state_braille(keycode - BRL__MIN + 1, IS_PRESSED(record->event));
                pressed++;
            } else {
                pressed--;
                if (pressed <= 0) {
                    pressed = 0;
                    send_braille_key();
                }
            }
            return false;
    }
    return true;
}
