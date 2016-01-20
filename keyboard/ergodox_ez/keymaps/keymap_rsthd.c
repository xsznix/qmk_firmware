// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define RSTHD   0
#define DVORAK  1
#define QWERTY  2
#define COLEMAK 3
#define NUMPAD  4
#define MEDIA   5
#define SLATE   6
#define SPECIAL 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: RSTHD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   4  |   3  |   2  |   1  |   5  |  L6  |           |  L6  |   6  |   0  |   9  |   8  |   7  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   J  |   C  |   Y  |   F  |   K  |  L5  |           |  L5  |   Z  |   L  |   ,  |   U  |   Q  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   R  |   S  |   T  |   H  |   D  |------|           |------|   M  |   N  |   A  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|  L4  |           |  L4  |------+------+------+------+------+--------|
 * | LShift |   /  |   V  |   G  |   P  |   B  |      |           |      |   X  |   W  |   ,  |   ;  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  fn  |Dvorak| Down |  Up  |   [  |                                       |   ]  | Left | Right|QWERTY| L9?? |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       | LCtrl | LAlt |       | RAlt | RCtrl |
 *                                ,------|-------|------|       |------+-------+------.
 *                                |      |       | LGui |       | RGui |       |      |
 *                                |  E   | Bksp  |------|       |------| Enter |Space |
 *                                |      |       |  L7  |       |  L7  |       |      |
 *                                `---------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[RSTHD] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,  KC_4,       KC_3,    KC_2,  KC_1,   KC_5,   MO(6),
        KC_TAB,  KC_J,       KC_C,    KC_Y,  KC_F,   KC_K,   MO(5),
        KC_ESC,  KC_R,       KC_S,    KC_T,  KC_H,   KC_D,
        KC_LSFT, KC_SLSH,    KC_V,    KC_G,  KC_P,   KC_B,   MO(4),
        KC_APP,  TG(DVORAK), KC_DOWN, KC_UP, KC_LBRC,
                                             KC_LCTRL, KC_LALT,
                                                       KC_LGUI,
                                             KC_E,     KC_BSPC, MO(7),
        // right hand
        MO(6), KC_6,   KC_0,    KC_9,    KC_8,      KC_7,       KC_BSLS,
        MO(5), KC_Z,   KC_L,    KC_COMM, KC_U,      KC_Q,       KC_EQUAL,
               KC_M,   KC_N,    KC_A,    KC_I,      KC_O,       KC_QUOTE,
        MO(4), KC_X,   KC_W,    KC_DOT,  KC_SCOLON, KC_MINS,    KC_RSFT,
                       KC_RBRC, KC_LEFT, KC_RIGHT,  TG(QWERTY), KC_FN1,
        KC_RALT, KC_RCTRL,
        KC_RGUI,
        MO(7),   KC_ENT, KC_SPC
    ),
/* Keymap 1: Dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   '  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |    -   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |   \  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  L3  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVORAK] = KEYMAP(
       // left hand
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,
       KC_TRNS, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y, KC_TRNS,
       KC_TRNS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
       KC_TRNS, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        TG(COLEMAK), KC_TRNS,
                                                     KC_TRNS,
                               KC_TRNS, KC_TRNS,     KC_TRNS,
       // right hand
       KC_TRNS, KC_6, KC_7,    KC_8,   KC_9,    KC_0,     KC_EQUAL,
       KC_TRNS, KC_F, KC_G,    KC_C,   KC_R,    KC_L,     KC_SLASH,
                KC_D, KC_H,    KC_T,   KC_N,    KC_S,     KC_MINUS,
       KC_TRNS, KC_B, KC_M,    KC_W,   KC_V,    KC_Z,     KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |    -   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   \  |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  L3  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[QWERTY] = KEYMAP(
       // left hand
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,
       KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TRNS,
       KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
       KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_TRNS,
       KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        TG(COLEMAK), KC_TRNS,
                                                     KC_TRNS,
                               KC_TRNS, KC_TRNS,     KC_TRNS,
       // right hand
       KC_TRNS, KC_6, KC_7,    KC_8,   KC_9,    KC_0,     KC_EQUAL,
       KC_TRNS, KC_Y, KC_U,    KC_I,   KC_O,    KC_P,     KC_SLASH,
                KC_H, KC_J,    KC_K,   KC_L,    KC_SCLN,  KC_MINUS,
       KC_TRNS, KC_N, KC_M,    KC_COMM,KC_DOT,  KC_SLSH,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 3: Colemak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |    -   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   \  |      |      |      |                                       |      |      |      |   \  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  L3  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[COLEMAK] = KEYMAP(
       // left hand
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,
       KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, KC_TRNS,
       KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
       KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_TRNS,
       KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_6, KC_7,    KC_8,   KC_9,    KC_0,     KC_EQUAL,
       KC_TRNS, KC_J, KC_L,    KC_U,   KC_Y,    KC_SCLN,  KC_SLASH,
                KC_H, KC_N,    KC_E,   KC_I,    KC_O,     KC_MINUS,
       KC_TRNS, KC_K, KC_M,    KC_COMM,KC_DOT,  KC_SLSH,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,KC_BSLS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap X: Template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// [NAME] = KEYMAP(
//        // left hand
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                                         KC_TRNS, KC_TRNS,
//                                                  KC_TRNS,
//                                KC_TRNS, KC_TRNS, KC_TRNS,
//        // right hand
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//        KC_TRNS, KC_TRNS,
//        KC_TRNS,
//        KC_TRNS, KC_TRNS, KC_TRNS
//     ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
