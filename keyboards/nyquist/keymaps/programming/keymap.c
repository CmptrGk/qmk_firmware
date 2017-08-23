#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NUMBERS 1
#define _SYMBOLS 2
#define _FKEYS 3

enum custom_keycodes {
    NUMBER = SAFE_RANGE,
    FKEYS,
    SYMBOLS
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#ifdef TAP_DANCE_ENABLE

enum {
    TD_QUOT = 0,
    TD_BRL,
    TD_BRR,
    TD_CLN
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
    [TD_BRL] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_BRR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)
};

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KEYMAP(
#ifdef TAP_DANCE_ENABLE
    KC_ESC,       TD(TD_QUOT), KC_F5,   KC_F6,      KC_LPRN,      TD(TD_BRL),   TD(TD_BRR), KC_RPRN,  KC_SLSH, KC_BSLS,  KC_EQL,     KC_BSPC,
#else
    KC_ESC,       KC_QUOT,     KC_F5,   KC_F6,      KC_LPRN,      KC_LBRC,      KC_RBRC,    KC_RPRN,  KC_SLSH, KC_BSLS,  KC_EQL,     KC_BSPC,
#endif
    KC_TAB,       KC_Q,        KC_W,    KC_E,       KC_R,         KC_T,         KC_Y,       KC_U,     KC_I,    KC_O,     KC_P,       KC_DEL,
#ifdef TAP_DANCE_ENABLE
    TO(_NUMBERS), KC_A,        KC_S,    KC_D,       KC_F,         KC_G,         KC_H,       KC_J,     KC_K,    KC_L,     TD(TD_CLN), KC_ENT,
#else
    TO(_NUMBERS), KC_A,        KC_S,    KC_D,       KC_F,         KC_G,         KC_H,       KC_J,     KC_K,    KC_L,     KC_SCLN,    KC_ENT,
#endif
    KC_LSFT,      KC_Z,        KC_X,    KC_C,       KC_V,         KC_B,         KC_N,       KC_M,     KC_COMM, KC_DOT,   KC_SLSH,    KC_RSFT,
    KC_LCTRL,     KC_LALT,     KC_LGUI, MO(_FKEYS), MO(_SYMBOLS), MO(_NUMBERS), KC_SPACE,   KC_SPACE, KC_LEFT, KC_RIGHT, KC_UP,      KC_DOWN
  ),

  [_NUMBERS] = KEYMAP(
    KC_1,         KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    TO(_SYMBOLS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SYMBOLS] = KEYMAP(
    KC_EXLM,    KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPERSAND, KC_ASTR, KC_MINS, KC_PLUS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    TO(_FKEYS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FKEYS] = KEYMAP(
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,
    TO(_BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

