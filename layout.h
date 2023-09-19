#pragma once

#define ID_BASE 0
#define ID_NAV 1
#define ID_SYM 2
#define ID_NUM 3
#define ID_GAME 4

#define D_BASE DF(ID_BASE)
#define D_GAME DF(ID_GAME)

#define LT_NAV(code) LT(ID_NAV, code)
#define LT_SYM(code) LT(ID_SYM, code)

#define L_NAV LT_NAV(KC_TAB)
#define L_SYM LT_SYM(KC_ENTER)

#define BM_Z LGUI_T(KC_Z)
#define BM_X LALT_T(KC_X)
#define BM_C LSFT_T(KC_C)
#define BM_D LCTL_T(KC_D)

#define BM_H    RCTL_T(KC_H)
#define BM_COMM RSFT_T(KC_COMM)
#define BM_DOT  LALT_T(KC_DOT)
#define BM_QUOT RGUI_T(KC_QUOT)

#define _BASE \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, \
  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , \
  BM_Z   , BM_X   , BM_C   , BM_D   , BM_V   , KC_K   , BM_H   , BM_COMM, BM_DOT , BM_QUOT, \
                             L_NAV  , KC_SPC , KC_BSPC, L_SYM

#define _NAV \
  KC_ESC , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_HOME, KC_PGDN, KC_PGUP, KC_END , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_NO  , KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, \
                             KC_TRNS, KC_TRNS, KC_TRNS, LT_SYM(KC_DEL)

#define _SYM \
  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_COLN, \
  KC_TILD, KC_GRV , KC_DQUO, KC_BSLS, KC_NO  , KC_NO  , KC_PIPE, KC_PLUS, KC_MINS, KC_QUES, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_ENT , KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, \
                             L_NAV  , KC_TRNS, KC_TRNS, KC_TRNS

#define _NUM \
  KC_NO  , KC_F7  , KC_F8  , KC_F9  , KC_F12 , KC_UNDS, KC_7   , KC_8   , KC_9   , D_GAME , \
  KC_NO  , KC_F4  , KC_F5  , KC_F6  , KC_F11 , KC_0   , KC_4   , KC_5   , KC_6   , KC_COMM, \
  KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F10 , KC_ENT , KC_1   , KC_2   , KC_3   , KC_DOT , \
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define _GAME \
  KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , D_BASE , \
  KC_LSFT, KC_A   , KC_W   , KC_D   , KC_E   , KC_R   , KC_T   , KC_NO  , KC_NO  , KC_NO  , \
  KC_LCTL, KC_Z   , KC_S   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_NO  , KC_NO  , \
                             KC_LALT, KC_SPC , KC_NO  , KC_NO


#define LAYOUT_a_dux_wrap(...) LAYOUT_split_3x5_2(__VA_ARGS__)
