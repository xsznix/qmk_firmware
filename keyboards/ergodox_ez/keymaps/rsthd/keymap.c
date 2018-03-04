#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"
#include "version.h"

#define RSTHD     0
#define LINUX_MOD 1
#define DVORAK    2
#define QWERTY    3
#define NUMPAD    4
#define MEDIA     5
#define MEDIA_LIN 6
#define SPECIAL   7
#define PLOVER    8

enum custom_keycodes {
  KC_CUSTOM_RGB_TOGG = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: RSTHD, with OS X-style modifiers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   7  |   8  |   9  |   0  |   5  | LCtl |           | RCtl |   6  |   1  |   2  |   3  |   4  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   J  |   C  |   Y  |   F  |   K  | LAlt |           | RAlt |   Z  |   L  |   ,  |   U  |   Q  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   R  |   S  |   T  |   H  |   D  |------|           |------|   M  |   N  |   A  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------| LGui |           | RGui |------+------+------+------+------+--------|
 * | LShift |   /  |   V  |   G  |   P  |   B  |      |           |      |   X  |   W  |   .  |   ;  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ^Spc |Dvorak|  ^B  | Down |  Up  |                                       | Left | Right|  ^W  |QWERTY| ^Spc |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       | Numpad| Media|       | Media| Numpad|
 *                                ,------|-------|------|       |------+-------+-------.
 *                                |      |       | Slate|       | Slate|       |       |
 *                                |  E   | Bksp  |------|       |------| Enter | Space |
 *                                |      |       | Speci|       | Speci|       |       |
 *                                `---------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[RSTHD] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,             KC_7,       KC_8,       KC_9,  KC_0,   KC_5,   KC_LCTL,
        KC_TAB,             KC_J,       KC_C,       KC_Y,  KC_F,   KC_K,   KC_LALT,
        KC_ESC,             KC_R,       KC_S,       KC_T,  KC_H,   KC_D,
        KC_LSFT,            KC_SLSH,    KC_V,       KC_G,  KC_P,   KC_B,   KC_LGUI,
        LALT(LSFT(KC_SPC)), TG(PLOVER), LALT(KC_TAB), KC_DOWN, KC_UP,
                                        MO(NUMPAD), MO(MEDIA),
                                                    KC_CUSTOM_RGB_TOGG,
                                    KC_E,  KC_BSPC, MO(SPECIAL),
        // right hand
        KC_RCTL, KC_6,   KC_1,    KC_2,     KC_3,      KC_4,       KC_BSLS,
        KC_RALT, KC_Z,   KC_L,    KC_COMM,  KC_U,      KC_Q,       KC_EQUAL,
                 KC_M,   KC_N,    KC_A,     KC_I,      KC_O,       KC_QUOTE,
        KC_RGUI, KC_X,   KC_W,    KC_DOT,   KC_SCOLON, KC_MINS,    KC_RSFT,
                       KC_LEFT, KC_RIGHT, LALT(KC_SPC), TG(QWERTY), LCTL(KC_SPC),
        MO(MEDIA),   MO(NUMPAD),
        TG(LINUX_MOD),
        MO(SPECIAL), KC_ENT, KC_SPC
    ),
/* Keymap 0: RSTHD, with Linux-style modifiers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   7  |   8  |   9  |   0  |   5  | LGui |           | RGui |   6  |   1  |   2  |   3  |   4  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   J  |   C  |   Y  |   F  |   K  | LAlt |           | LAlt |   Z  |   L  |   ,  |   U  |   Q  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   R  |   S  |   T  |   H  |   D  |------|           |------|   M  |   N  |   A  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------| LCtl |           | RCtl |------+------+------+------+------+--------|
 * | LShift |   /  |   V  |   G  |   P  |   B  |      |           |      |   X  |   W  |   .  |   ;  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ^K   |Dvorak|  ^B  | Down |  Up  |                                       | Left | Right|  ^W  |QWERTY| RAlt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       | Numpad| Media|       | Media| Numpad|
 *                                ,------|-------|------|       |------+-------+-------.
 *                                |      |       | Slate|       | Slate|       |       |
 *                                |  E   | Bksp  |------|       |------| Enter | Space |
 *                                |      |       | Speci|       | Speci|       |       |
 *                                `---------------------'       `----------------------'
 */

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[LINUX_MOD] = KEYMAP(  // layer 1: alternate default
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI,
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL,
        LCTL(KC_K), TG(DVORAK), LCTL(KC_B), KC_TRNS, KC_TRNS,
                                           KC_TRNS, MO(MEDIA_LIN),
                                                    KC_TRNS,
                                 KC_TRNS,  KC_TRNS, KC_TRNS,
        // right hand
        KC_RGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, LCTL(KC_W), TG(QWERTY), KC_RALT,
        MO(MEDIA_LIN), KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
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
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                                KC_SPC, KC_TRNS, KC_TRNS,
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
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                                KC_SPC, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_6, KC_7,    KC_8,   KC_9,    KC_0,     KC_EQUAL,
       KC_TRNS, KC_Y, KC_U,    KC_I,   KC_O,    KC_P,     KC_MINUS,
                KC_H, KC_J,    KC_K,   KC_L,    KC_SCLN,  KC_QUOT,
       KC_TRNS, KC_N, KC_M,    KC_COMM,KC_DOT,  KC_SLSH,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 3: Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F13  | F14  | F15  | F16  |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F9  | F10  | F11  | F12  |      |      |           |      |      |   4  |   5  |   6  |   +  |    *   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |------|           |------|      |   1  |   2  |   3  |   -  |    /   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |           |      |      |   0  |  LF  |   .  |   =  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | F17  | F18  | F19  | F20  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Ent  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMPAD] = KEYMAP(
       // left hand
       KC_TRNS, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F17,  KC_F18,  KC_F19,  KC_F20,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_PLUS,  KC_KP_ASTERISK,
                KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_MINUS, KC_KP_SLASH,
       KC_TRNS, KC_TRNS, KC_KP_0, KC_TRNS, KC_KP_DOT, KC_KP_EQUAL, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_KP_ENTER, KC_TRNS
    ),

/* Keymap 4: Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | **6  | **7  | **8  | **9  |  **0   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | INS  | HOM  | PGUP |C-S-tb|      |           |      |      | **1  | **2  | **3  | **4  |  **5   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | DEL  | END  | PGDN |C-tab |------|           |------|      |  *6  |  *7  |  *8  |  *9  |   *0   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ^z  |  ^x  |  ^c  |  ^v  |      |      |           |      |      |  *1  |  *2  |  *3  |  *4  |   *5   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Mute | Vol- | Vol+ |                                       | Back |Pause | Fwd  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MEDIA] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_INS,     KC_HOME,    KC_PGUP,    LCTL(LSFT(KC_TAB)), KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_DEL,     KC_END,     KC_PGDN,    LCTL(KC_TAB),
       KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_TRNS,            KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_MUTE,    KC_VOLD,    KC_VOLU,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, LCTL(LALT(LSFT(KC_6))), LCTL(LALT(LSFT(KC_7))), LCTL(LALT(LSFT(KC_8))), LCTL(LALT(LSFT(KC_9))), LCTL(LALT(LSFT(KC_0))),
       KC_TRNS, KC_TRNS, LCTL(LALT(LSFT(KC_1))), LCTL(LALT(LSFT(KC_2))), LCTL(LALT(LSFT(KC_3))), LCTL(LALT(LSFT(KC_4))), LCTL(LALT(LSFT(KC_5))),
                KC_TRNS, LCTL(LALT(KC_6)),       LCTL(LALT(KC_7)),       LCTL(LALT(KC_8)),       LCTL(LALT(KC_9)),       LCTL(LALT(KC_0)),
       KC_TRNS, KC_TRNS, LCTL(LALT(KC_1)),       LCTL(LALT(KC_2)),       LCTL(LALT(KC_3)),       LCTL(LALT(KC_4)),       LCTL(LALT(KC_5)),
                         KC_MPRV,                KC_MPLY,                KC_MNXT,                KC_TRNS,                KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 4: Media, with Linux-style modifiers for ^z, ^x, ^c, ^v
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |  M3  |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | INS  | HOM  | PGUP |C-S-tb|      |           |      |      |  M1  | M-up |  M2  |Scrl-u|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | DEL  | END  | PGDN |C-tab |------|           |------|      |M-left| M-dn |M-rght|Scrl-d|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ^z  |  ^x  |  ^c  |  ^v  |      |      |           |      |      | Mute | Vol- | Vol+ |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |bl-tog| bl - | bl + |                                       | Back |Pause | Fwd  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MEDIA_LIN] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_INS,     KC_HOME,    KC_PGUP,    LCTL(LSFT(KC_TAB)), KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_DEL,     KC_END,     KC_PGDN,    LCTL(KC_TAB),
       KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS,            KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS,
                KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
                         KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 6: Special
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   <  |   >  |   [  |   ]  |M-del |      |           |      |M-del |   :  |      |   {  |   }  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   ~  |   _  |   "  |   |  |      |           |      |   ?  |   +  |      |      |      |        |
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
[SPECIAL] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,       KC_TRNS,
       KC_TRNS, S(KC_COMM), S(KC_DOT), KC_LBRC, KC_RBRC,    LALT(KC_BSPC), KC_TRNS,
       KC_TRNS, KC_EXLM,    KC_AT,     KC_HASH,  KC_DLR,    KC_PERC,
       KC_TRNS, KC_TRNS,    KC_TILD,   KC_UNDS, S(KC_QUOT), KC_PIPE,       KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,       KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, LALT(KC_BSPC), KC_COLN,     KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,
                KC_CIRC,       KC_AMPR,     KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
       KC_TRNS, S(KC_SLSH),    S(KC_EQUAL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000
/* Keymap 7: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
[PLOVER] = KEYMAP(
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
       LALT(KC_BSPC),    M(NM),   M(NM),   M(NM),   M(NM),   M(NM),  KC_NO,  
       KC_BSPC, M(Sl),   M(Tl),   M(Pl),   M(Hl),   M(X),
       KC_NO,    M(Sl),   M(Kl),   M(Wl),   M(Rl),   M(X),   KC_NO,
       KC_NO,    TG(PLOVER),   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,  
                                                    KC_NO,  
                                  M(Al),   M(Ol),   KC_NO,  
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
       KC_TRNS,  M(NM),   M(NM),   M(NM),   M(NM),   M(NM),   M(NM),
                 M(X),    M(Fr),   M(Pr),   M(Lr),   M(Tr),   M(Dr),
       KC_NO,    M(X),    M(Rr),   M(Br),   M(Gr),   M(Sr),   M(Zr),
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
       KC_NO,   KC_NO,  
       KC_NO,  
       KC_NO,   M(Er),   M(Ur)
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
};

uint8_t chord[4] = {0,0,0,0};
uint8_t pressed_count = 0;

void send_chord(void)
{
  for(uint8_t i = 0; i < 4; i++)
  {
    if(chord[i])
      virtser_send(chord[i]);
  }
  virtser_send(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // We need to track keypresses in all modes, in case the user
  // changes mode whilst pressing other keys.
  if (record->event.pressed) {
    pressed_count++;
    if (keycode == KC_CUSTOM_RGB_TOGG) {
      rgblight_toggle();
    }
  } else if (--pressed_count == 0) {
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function

  if (record->event.pressed) {
    uint8_t grp = (id & GRPMASK) >> 6;
    chord[grp] |= id;
  }
  else {
    if (pressed_count == 0) {
      send_chord();
      chord[0] = chord[1] = chord[2] = chord[3] = 0;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_set_enabled(true);
  rgblight_sethsv(0, 255, 255);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
      case RSTHD:
      break;

      case LINUX_MOD:
      ergodox_right_led_3_on();
      break;

      case DVORAK:
      ergodox_right_led_1_on();
      break;

      case QWERTY:
      ergodox_right_led_2_on();
      break;

      default:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
    }
};
