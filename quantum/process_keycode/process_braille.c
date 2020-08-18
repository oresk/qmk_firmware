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

#define MAX_STATE_SIZE 6

static uint8_t state   = 0;
static uint8_t pressed = 0;

void braille_init() {}

void send_braille_key(void);

void send_braille_key(){
    // map braille dot to regular keycodes
    tap_code16(braille_to_keycode_mapping[state]);
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

__attribute__((weak)) bool process_braille_user(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_braille(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BRL__MIN ... BRL__MAX:
            if (!process_braille_user(keycode, record)) {
                return false;
            }
            if (IS_PRESSED(record->event)) {
                update_state_braille(keycode - BRL__MIN, IS_PRESSED(record->event));
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
