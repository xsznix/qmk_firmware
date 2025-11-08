#include "config.h"
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// layers
#define AFTERBURNER 0
#define MONKEYTYPE  1
#define SYMBOLS     2
#define MACRO       3
#define FUNCT       4
#define AEROSPACE   5

// macros
#define KC_AERO  LM(AEROSPACE, MOD_LCTL | MOD_LALT)

enum custom_keycodes {
    KC_OU = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Afterburner
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  7   |  8   |  9   |  0   |  5   |M-Bksp|           |M-Del |  6   |  1   |  2   |  3   |  4   |  \     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  J   |  B   |  G   |  D   |  K   |Functn|           |Functn|  Z   |  C   |  O   |  U   |  ,   | Bksp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Q      |  H   |  N   |  S   |  T   |  M   |------|           |------|Magic |SkpMgc|  A   |  E   |  I   |  -     |
 * |--------+------+------+------+------+------|Symbol|           |Symbol|------+------+------+------+------+--------|
 * | LShift |  Y   |  P   |  F   |  V   |  X   |      |           |      |  '   |  W   |  /   |  ;   |  .   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Macro|  M1  |  M2  | Down |  Up  |                                       | Left | Right|  [   |  ]   |  =   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Home |       | PgUp | Ins  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 |  R   |  L   |------|       |------|Enter | Spc  |
 *                                 |      |      | Aero |       | Aero |      |      |
 *                                 `--------------------'       `--------------------'
 */
[AFTERBURNER] = LAYOUT_ergodox(
       // left hand
       KC_ESC,  KC_7,             KC_8,             KC_9,             KC_0, KC_5, LALT(KC_BSPC),
       KC_TAB,  KC_J,             KC_B,             KC_G,             KC_D, KC_K, MO(FUNCT),
       KC_Q,    KC_H,             KC_N,             KC_S,             KC_T, KC_M,
       KC_LSFT, MT(MOD_LGUI,KC_Y),MT(MOD_LALT,KC_P),MT(MOD_LCTL,KC_F),KC_V, KC_X, MO(SYMBOLS),
       MO(MACRO), KC_BTN1, KC_BTN2, KC_DOWN, KC_UP,
                                        KC_DEL,  KC_HOME,
                                                 KC_END,
                                  KC_R, KC_L,    KC_AERO,
       // right hand
       LALT(KC_DEL), KC_6,    KC_1,    KC_2,                KC_3,                KC_4,                KC_BSLS,
       MO(FUNCT),    KC_Z,    KC_C,    KC_O,                KC_U,                KC_COMM,             KC_BSPC,
                     QK_AREP, QK_SREP, KC_A,                KC_E,                KC_I,                KC_MINS,
       MO(SYMBOLS),  KC_QUOT, KC_W,    MT(MOD_RCTL,KC_SLSH),MT(MOD_RALT,KC_SCLN),MT(MOD_RGUI,KC_DOT), KC_RSFT,
                               KC_LEFT, KC_RIGHT,KC_LBRC, KC_RBRC, KC_EQL,
       KC_PGUP, KC_INS,
       KC_PGDN,
       KC_AERO, KC_ENT, KC_SPC
    ),
[MONKEYTYPE] = LAYOUT_ergodox(
       // left hand
       KC_ESC,  KC_7,             KC_8,             KC_9,             KC_0,             KC_5,         LALT(KC_BSPC),
       KC_TAB,  KC_J,             KC_B,             KC_G,             KC_D,             KC_K,         MO(FUNCT),
       KC_Q,    KC_H,             KC_N,             KC_S,             KC_T,             KC_M,
       KC_LSFT, KC_Y,             KC_P,             KC_F,             KC_V,             KC_X,         MO(SYMBOLS),
       MO(MACRO), KC_BTN1, KC_BTN2, KC_DOWN, KC_UP,
                                        KC_DEL,  KC_HOME,
                                                 KC_END,
                                  KC_R, KC_L,    KC_AERO,
       // right hand
       LALT(KC_DEL), KC_6,    KC_1,            KC_2,                KC_3,                KC_4,                KC_BSLS,
       MO(FUNCT),    KC_Z,    KC_C,            KC_O,                KC_U,                KC_COMM,             KC_BSPC,
                     QK_AREP, QK_SREP,         KC_A,                KC_E,                KC_I,                KC_MINS,
       MO(SYMBOLS),  KC_QUOT, KC_W,            KC_SLSH,             KC_SCLN,             KC_DOT,              KC_RSFT,
                               KC_LEFT, KC_RIGHT,KC_LBRC, KC_RBRC, KC_EQL,
       KC_PGUP, KC_INS,
       KC_PGDN,
       KC_AERO, KC_ENT, KC_SPC
    ),

/* Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  ^   |  >   |  <   |  =   |  @   |      |           |      |  _   |  &   |  +   |  #   |++--++|++ -- ++|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ~    |  (   |  {   |  }   |  )   |  $   |------|           |------|++--++|++--++|  ?   |  !   |  :   |++ -- ++|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  `   |  |   |  \   |  *   |  %   |      |           |      |++--++|  "   |++--++|++--++|++--++|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  [   |  ]   |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMBOLS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_RABK, KC_LABK, KC_EQL,  KC_AT,   KC_TRNS,
       KC_TILD, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_DLR,
       KC_TRNS, KC_GRV,  KC_PIPE, KC_BSLS, KC_ASTR, KC_PERC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_LBRC, KC_RBRC, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_UNDS, KC_AMPR, KC_PLUS, KC_HASH, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_QUES, KC_EXLM, KC_COLN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Macros
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | M <- | M -> | GM<- | GM-> |      |------|           |------|      | BOOT |Restart|     |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | X <- | X -> | C up | C dn |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | CSTab| CTab | G <- | G -> |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MACRO] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, LALT(LGUI(KC_LEFT)), LALT(LGUI(KC_RIGHT)), LCTL(KC_UP), LCTL(KC_DOWN), KC_TRNS,
       KC_TRNS, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LCTL(LALT(KC_LEFT)), LCTL(LALT(KC_RIGHT)), KC_TRNS, KC_TRNS,
       KC_TRNS, KC_BTN3, LALT(KC_TAB), LGUI(KC_LEFT), LGUI(KC_RIGHT),
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                    LCTL(LALT(KC_SPC)), KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, QK_BOOT, QK_RBT,  DF(AFTERBURNER), DF(MONKEYTYPE), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F19  |  F20 |  F21 |  F22 |  F23 |  F24 |      |           |      |Select| Stop | Again| Erase|SysReq| Cancel |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F13  |  F14 |  F15 |  F16 |  F17 |  F18 |      |           |      | Int7 | Int8 | Int9 | Lng7 | Lng8 | Lng9   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F7   |  F8  |  F9  |  F10 |  F11 |  F12 |------|           |------| Int4 | Int5 | Int6 | Lng4 | Lng5 | Lng6   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      | Int1 | Int2 | Int3 | Lng1 | Lng2 | Lng3   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |PrtScn| App  | Exec | Help | Menu |                                       | Cut  | Copy | Paste| Undo | Find |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mute | Vol+ |       | Brt+ |Search|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Vol- |       | Brt- |      |      |
 *                                 | Prev | Next |------|       |------|BrBack|BrFwd |
 *                                 |      |      | Play |       |BrHome|      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNCT] = LAYOUT_ergodox(
       // left hand
       KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_TRNS,
       KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_TRNS,
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,
       KC_PSCR, KC_APP,  KC_EXEC, KC_HELP, KC_MENU,
                                        KC_MUTE, KC_VOLU,
                                                 KC_VOLD,
                               KC_MPRV, KC_MNXT, KC_MPLY,
       // right hand
       KC_TRNS, KC_SLCT, KC_STOP, KC_AGAIN,KC_ERAS, KC_SYRQ, KC_CNCL,
       KC_TRNS, KC_INT7, KC_INT8, KC_INT9, KC_LNG7, KC_LNG8, KC_LNG9,
                KC_INT4, KC_INT5, KC_INT6, KC_LNG4, KC_LNG5, KC_LNG6,
       KC_TRNS, KC_INT1, KC_INT2, KC_INT3, KC_LNG1, KC_LNG2, KC_LNG3,
                         KC_CUT,  KC_COPY, KC_PSTE, KC_UNDO, KC_FIND,
       KC_BRMU, KC_WSCH,
       KC_BRMD,
       KC_WHOM, KC_WBAK, KC_WFWD
    ),

/* Aerospace
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |OS Cmd|      |      |      |        |
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
[AEROSPACE] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,
                                                 KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, OS_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Template
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
// [NAME] = LAYOUT_ergodox(
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

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // Pure repeat if any modifiers besides shift
    if ((mods & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) {
        return keycode;
    }

    // Get tap keycode for tap-hold keys
    if (IS_QK_MOD_TAP(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    // Optimal mappings:
    // PROTOC_INCLUDE='./proto/' pq --protofile proto/corpus.proto --msgtype corpus.Ngrams < corpora/reddit_small.ngrams.protobuf | jq '.bigrams | [ .[] | select(.key | test("[#]{2}")) ] | sort_by(.value)'
    switch (keycode) {
    case KC_A: return KC_O;
    case KC_G: return KC_S;
    case KC_H: return KC_Y;
    case KC_I: return KC_OU;
    case KC_U: return KC_E;
    case KC_Y: return KC_H;
    case KC_X: return KC_T;
    default: return keycode;
    }
}

uint16_t get_skip_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // Pure repeat if any modifiers besides shift
    if ((mods & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) {
        return keycode;
    }

    // Get tap keycode for tap-hold keys
    if (IS_QK_MOD_TAP(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    // Optimal mappings:
    // PROTOC_INCLUDE='./proto/' pq --protofile proto/corpus.proto --msgtype corpus.Ngrams < corpora/reddit_small.ngrams.protobuf | jq '.trigrams | [ .[] | select(.key | startswith("#")) | { skipgram: (.key[0:1] + .key[2:3]), v: .value } ] | group_by(.skipgram) | [ .[] | reduce .[] as $item ( { s: "", v: 0 }; { s: $item.skipgram, v: (.v + $item.v) } ) ] | sort_by(.v)'
    switch (keycode) {
    case KC_A: return KC_O;
    case KC_B: return KC_N;
    case KC_D: return KC_T;
    case KC_F: return KC_S;
    case KC_G: return KC_S;
    case KC_H: return KC_Y;
    case KC_J: return KC_Y;
    case KC_K: return KC_T;
    case KC_L: return KC_R;
    case KC_M: return KC_K;
    case KC_O: return KC_A;
    case KC_P: return KC_N;
    case KC_Q: return KC_E;
    case KC_R: return KC_L;
    case KC_U: return KC_E;
    case KC_V: return KC_T;
    case KC_X: return KC_T;
    case KC_Y: return KC_H;
    case KC_COMM: return KC_I;
    case KC_DOT: return KC_I;
    case KC_MINS: return KC_I;
    case KC_SLSH: return KC_A;
    case KC_SCLN: return KC_E;
    default: return keycode;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) return true;

    switch (keycode) {
        case KC_OU: SEND_STRING("ou"); break;
    }
    return true;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    return true;
}

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    // Add minus to the default list
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case KC_MINS:
            return true;
    }
    return false;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Make shifts and MO keys work better for hotkeys
    switch (other_keycode) {
        case KC_LSFT:
        case KC_RSFT:
        case MO(SYMBOLS):
        case MO(FUNCT):
            return true;
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};
