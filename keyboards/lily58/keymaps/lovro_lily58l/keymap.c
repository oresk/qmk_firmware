#include QMK_KEYBOARD_H

#define SPLASH_SEC 3

enum LAYERS {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MAX_LAYER,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CLR_LOG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /  Enter/       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      KC_LBRC,  KC_RBRC, KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_PIPE),
                               KC_LALT, KC_LGUI, MO(_LOWER), KC_ENT,   KC_SPC, MO(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | INS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /  Enter/       \Space \  |RAISE |DELETE| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_INS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    _______, _______, _______, _______, _______, _______, _______,  _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                               _______, _______, _______, _______,  _______, _______, KC_DEL,  _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /  Enter/       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                               _______, _______, _______, _______,  _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | MUTE |V_DOWN| V_UP |      |      |                    |      |      |      |      |      |CL_LOG|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |RGB ON| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MODE | HUE- | SAT- | VAL- |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /  Enter/       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_ADJUST] = LAYOUT(
    XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLR_LOG,
    XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
                                    _______,   _______, _______, _______,   _______, _______, _______, _______
)
};

//OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE
// functions from lib/keylogger.c
void init_keylog(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_logo(void);

const char layer_names [_MAX_LAYER][6] = {
  " DFL ",
  "LOWER",
  "RAISE",
  " ADJ ",
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()){
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

const char *print_layer(void) {
    int layer = get_highest_layer(layer_state);
    if (layer < _MAX_LAYER) {
        return layer_names[layer];
    } else {
        return "UNDEF";
    }
}

#include <stdio.h>
const char *print_wpm(void) {
    static char wpm[11] = {0};
    snprintf(wpm, sizeof(wpm), " WPM: %3d", get_current_wpm());
    return wpm;
}
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);

        switch(keycode){
            case CLR_LOG:
            // clear keylog from oled display
                init_keylog();
                return false;
                break;
        }
    }

    return true;
}

void oled_task_user(void) {
    static bool splash = true;
    static uint16_t timer = 0;

    if (is_keyboard_master()) { // TEST if we are blocking side without OLED
    //if (1) {
        if(splash){
            if(!timer){ // do this once
              timer = timer_read();
              oled_write(read_logo(), false);
            }
            oled_scroll_left();
            if (timer_elapsed(timer) > (SPLASH_SEC * 1000)){
              splash = false;
              oled_scroll_off();
              oled_clear();
            }
        } else {
            // If you want to change the display of OLED, you need to change here
            oled_write(print_layer(), false);
            oled_write("-----", false);
            oled_write_ln(print_wpm(),false);
            oled_write("-----", false);
            oled_set_cursor(0,11);
            oled_write("-----", false);
            oled_write(read_keylogs(), false);
            //oled_write_ln(read_keylog(), false);
        }
    }
}
#endif // OLED_DRIVER_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#   ifdef OLED_DRIVER_ENABLE
    if(!process_record_user_oled(keycode, record)){
      return false;
    }
#   endif

  return true;
}

void keyboard_post_init_user(void) {
#   ifdef OLED_DRIVER_ENABLE
    if(is_keyboard_master()) {
        init_keylog();
    }
#   endif
}
