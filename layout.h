#pragma once

#define ID_BASE 0
#define ID_NAV 1
#define ID_SYM 2
#define ID_NUM 3
#define ID_GAME 4

#define D_BASE DF(ID_BASE)
#define D_GAME DF(ID_GAME)

#define L_NAV MO(ID_NAV)
#define L_SYM MO(ID_SYM)

#define CT(code) LT(0, code)

/**
 * Control tap key definitions
 */
#define CT_C CT(KC_C)
#define CT_V CT(KC_V)
#define CT_X CT(KC_X)
#define CT_Z CT(KC_Z)

#define CT_RETN CT(KC_RETN)

#define _BASE \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, \
  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , \
  CT_Z   , CT_X   , CT_C   , KC_D   , CT_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, \
                             L_NAV  , KC_SPC , KC_LSFT, L_SYM

#define _NAV \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ESC , KC_DEL , KC_HOME, KC_PGDN, KC_PGUP, KC_END , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TAB , CT_RETN, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_BSPC, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, \
                             KC_TRNS, KC_TRNS, KC_TRNS, L_SYM

#define _SYM \
  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_COLN, \
  KC_TILD, KC_GRV , KC_DQUO, KC_BSLS, KC_NO  , CT_RETN, KC_PIPE, KC_PLUS, KC_MINS, KC_QUES, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_NO  , KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, \
                             L_NAV  , KC_TRNS, KC_TRNS, KC_TRNS

#define _NUM \
  KC_NO  , KC_F7  , KC_F8  , KC_F9  , KC_F12 , KC_NO  , KC_7   , KC_8   , KC_9   , D_GAME , \
  KC_NO  , KC_F4  , KC_F5  , KC_F6  , KC_F11 , KC_0   , KC_4   , KC_5   , KC_6   , KC_COMM, \
  KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F10 , KC_UNDS, KC_1   , KC_2   , KC_3   , KC_DOT , \
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define _GAME \
  KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , D_BASE , \
  KC_LSFT, KC_A   , KC_W   , KC_D   , KC_E   , KC_R   , KC_T   , KC_NO  , KC_NO  , KC_NO  , \
  KC_LCTL, KC_Z   , KC_S   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_NO  , KC_NO  , \
                             KC_LALT, KC_SPC , KC_NO  , KC_NO


#define LAYOUT_a_dux_wrap(...) LAYOUT_split_3x5_2(__VA_ARGS__)
