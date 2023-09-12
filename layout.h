#pragma once

#define L_BASE 0
#define L_NAV 1
#define L_SYM 2
#define L_NUM 3

/**
 * Control tap key definitions
 */
#define CT_C LT(0, KC_C)
#define CT_V LT(0, KC_V)
#define CT_X LT(0, KC_X)
#define CT_Z LT(0, KC_Z)

#define _BASE \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, \
  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , \
  CT_Z   , CT_X   , CT_C   , KC_D   , CT_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, \
                           MO(L_NAV), KC_SPC , KC_LSFT, MO(L_SYM)

#define _NAV \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ESC , KC_DEL , KC_HOME, KC_PGDN, KC_PGUP, KC_END , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TAB , KC_ENT , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_BSPC, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, \
                             KC_TRNS, KC_TRNS, KC_TRNS, MO(L_SYM)

#define _SYM \
  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_COLN, \
  KC_TILD, KC_GRV , KC_DQUO, KC_QUOT, KC_NO  , KC_ENT , KC_PIPE, KC_PLUS, KC_MINS, KC_QUES, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_NO  , KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, \
                           MO(L_NAV), KC_TRNS, KC_TRNS, KC_TRNS

#define _NUM \
  KC_NO  , KC_F7  , KC_F8  , KC_F9  , KC_F12 , KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , \
  KC_NO  , KC_F4  , KC_F5  , KC_F6  , KC_F11 , KC_0   , KC_4   , KC_5   , KC_6   , KC_NO  , \
  KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F10 , KC_UNDS, KC_1   , KC_2   , KC_3   , KC_NO  , \
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_a_dux_wrap(...) LAYOUT_split_3x5_2(__VA_ARGS__)
