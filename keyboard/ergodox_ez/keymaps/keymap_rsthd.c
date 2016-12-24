// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

// Comment out the below line to use OS X-style modifiers.
// #define USE_LINUX_MODIFIERS

#ifndef USE_LINUX_MODIFIERS
#define RSTHD     0
#define DVORAK    1
#define QWERTY    2
#define NUMPAD    3
#define MEDIA     4
#define SLATE     5
#define SPECIAL   6
#else
#define LINUX_MOD 0
#define DVORAK    1
#define QWERTY    2
#define NUMPAD    3
#define MEDIA_LIN 4
#define SLATE     5
#define SPECIAL   6
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#ifndef USE_LINUX_MODIFIERS

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
 *   | ^Spc |Dvorak|  *<- | Down |  Up  |                                       | Left | Right|  *-> |QWERTY| ^Spc |
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
        KC_GRV,             KC_7,       KC_8,                      KC_9,  KC_0,   KC_5,   KC_LCTL,
        KC_TAB,             KC_J,       KC_C,                      KC_Y,  KC_F,   KC_K,   KC_LALT,
        KC_ESC,             KC_R,       KC_S,                      KC_T,  KC_H,   KC_D,
        KC_LSFT,            KC_SLSH,    KC_V,                      KC_G,  KC_P,   KC_B,   KC_LGUI,
        LALT(LSFT(KC_SPC)), TG(DVORAK), LCTL(LALT(LSFT(KC_LEFT))), KC_DOWN, KC_UP,
                                        MO(NUMPAD), MO(MEDIA),
                                                    MO(SLATE),
                                    KC_E,  KC_BSPC, MO(SPECIAL),
        // right hand
        KC_RCTL, KC_6,   KC_1,    KC_2,     KC_3,      KC_4,       KC_BSLS,
        KC_RALT, KC_Z,   KC_L,    KC_COMM,  KC_U,      KC_Q,       KC_EQUAL,
                 KC_M,   KC_N,    KC_A,     KC_I,      KC_O,       KC_QUOTE,
        KC_RGUI, KC_X,   KC_W,    KC_DOT,   KC_SCOLON, KC_MINS,    KC_RSFT,
                       KC_LEFT, KC_RIGHT, LCTL(LALT(LSFT(KC_RIGHT))), TG(QWERTY), LCTL(KC_SPC),
        MO(MEDIA),   MO(NUMPAD),
        MO(SLATE),
        MO(SPECIAL), KC_ENT, KC_SPC
    ),
/* Keymap 0: RSTHD, with Linux-style modifiers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   7  |   8  |   9  |   0  |   5  | LGui |           | RGui |   6  |   1  |   2  |   3  |   4  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   J  |   C  |   Y  |   F  |   K  | LAlt |           | RAlt |   Z  |   L  |   ,  |   U  |   Q  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   R  |   S  |   T  |   H  |   D  |------|           |------|   M  |   N  |   A  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------| LCtl |           | RCtl |------+------+------+------+------+--------|
 * | LShift |   /  |   V  |   G  |   P  |   B  |      |           |      |   X  |   W  |   .  |   ;  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ^W   |Dvorak|   [  | Down |  Up  |                                       | Left | Right|   ]  |QWERTY| ^Spc |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,--------------.
 *                                       | Numpad| Media|       | Media| Numpad|
 *                                ,------|-------|------|       |------+-------+-------.
 *                                |      |       | Slate|       | Slate|       |       |
 *                                |  E   | Bksp  |------|       |------| Enter | Space |
 *                                |      |       | Speci|       | Speci|       |       |
 *                                `---------------------'       `----------------------'
 */

#else // #ifndef USE_LINUX_MODIFIERS

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[LINUX_MOD] = KEYMAP(  // layer 1: alternate default
        // left hand
        KC_GRV,     KC_7,       KC_8,    KC_9,  KC_0,   KC_5,   KC_LGUI,
        KC_TAB,     KC_J,       KC_C,    KC_Y,  KC_F,   KC_K,   KC_LALT,
        KC_ESC,     KC_R,       KC_S,    KC_T,  KC_H,   KC_D,
        KC_LSFT,    KC_SLSH,    KC_V,    KC_G,  KC_P,   KC_B,   KC_LCTL,
        LCTL(KC_W), TG(DVORAK), KC_LBRC, KC_DOWN, KC_UP,
                                        MO(NUMPAD), MO(MEDIA_LIN),
                                                    MO(SLATE),
                                    KC_E,  KC_BSPC, MO(SPECIAL),
        // right hand
        KC_RGUI, KC_6,   KC_1,    KC_2,     KC_3,      KC_4,       KC_BSLS,
        KC_RALT, KC_Z,   KC_L,    KC_COMM,  KC_U,      KC_Q,       KC_EQUAL,
                 KC_M,   KC_N,    KC_A,     KC_I,      KC_O,       KC_QUOTE,
        KC_RCTL, KC_X,   KC_W,    KC_DOT,   KC_SCOLON, KC_MINS,    KC_RSFT,
                       KC_LEFT, KC_RIGHT, KC_RBRC,   TG(QWERTY), LCTL(LALT(KC_SPC)),
        MO(MEDIA_LIN), MO(NUMPAD),
        MO(SLATE),
        MO(SPECIAL),   KC_ENT, KC_SPC
    ),

#endif // #ifndef USE_LINUX_MODIFIERS

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

#ifndef USE_LINUX_MODIFIERS

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

#else // #ifndef USE_LINUX_MODIFIERS

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

#endif // #ifndef USE_LINUX_MODIFIERS

/* Keymap 5: Slate
 *
 * This is a magical layer. Its significance is unknown to those who do not know
 * the ways of the Dark Side.
 */
[SLATE] = KEYMAP(
       // left hand
       LGUI(KC_F13), KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,
       LGUI(KC_F1),  LGUI(KC_F2), LGUI(KC_F3), LGUI(KC_F10), LCTL(KC_F1), LCTL(KC_F2), KC_TRNS,
       LGUI(KC_F7),  LGUI(KC_F8), LGUI(KC_F9), LGUI(KC_F12), LCTL(KC_F5), LCTL(KC_F6),
       LGUI(KC_F4),  LGUI(KC_F5), LGUI(KC_F6), LGUI(KC_F11), LCTL(KC_F3), LCTL(KC_F4), KC_TRNS,
       KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, LCTL(LGUI(KC_F1)), LCTL(LGUI(KC_F2)),  LCTL(LGUI(KC_F3)),  LCTL(LGUI(KC_F4)),  LCTL(KC_F7), LCTL(KC_F10),
                LCTL(LGUI(KC_F9)), LCTL(LGUI(KC_F10)), LCTL(LGUI(KC_F11)), LCTL(LGUI(KC_F12)), LCTL(KC_F9), LCTL(KC_F12),
       KC_TRNS, LCTL(LGUI(KC_F5)), LCTL(LGUI(KC_F6)),  LCTL(LGUI(KC_F7)),  LCTL(LGUI(KC_F8)),  LCTL(KC_F8), LCTL(KC_F11),
                                   KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,     KC_TRNS,
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
#ifndef USE_LINUX_MODIFIERS
      case RSTHD:
#else
      case LINUX_MOD:
#endif
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
