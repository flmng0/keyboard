#pragma once

#include "quantum_keycodes.h"

enum USER_KEYS {
  START_SENTENCE_CASE = SAFE_RANGE,
};

#define UK_SENT START_SENTENCE_CASE

#define ID_BASE 0
#define ID_NAV 1
#define ID_NUM 2
#define ID_GAME 3

#define D_BASE DF(ID_BASE)
#define D_GAME DF(ID_GAME)

#define LT_NAV(code) LT(ID_NAV, code)
#define LT_NUM(code) LT(ID_NUM, code)

#define TH_LA LT_NUM(KC_TAB)
#define TH_LH LT_NAV(KC_SPACE)

#define TH_RH OSM(MOD_LSFT)
#define TH_RA KC_ENTER

#define NV_LEFT LT(0, KC_LEFT)
#define NV_RGHT LT(0, KC_RGHT)
#define NV_UP   LT(0, KC_UP)
#define NV_DOWN LT(0, KC_DOWN)

#ifndef HRM_USE_INNER
#  define HM_A LGUI_T(KC_A)
#  define HM_R LALT_T(KC_R)
#  define HM_S LSFT_T(KC_S)
#  define HM_T LCTL_T(KC_T)
#  define HM_G KC_G
#  define HM_M KC_M
#  define HM_N RCTL_T(KC_N)
#  define HM_E RSFT_T(KC_E)
#  define HM_I LALT_T(KC_I)
#  define HM_O RGUI_T(KC_O)
#else
#  define HM_A KC_A
#  define HM_R LALT_T(KC_R)
#  define HM_S LSFT_T(KC_S)
#  define HM_T LCTL_T(KC_T)
#  define HM_G LGUI_T(KC_G)
#  define HM_M RGUI_T(KC_M)
#  define HM_N RCTL_T(KC_N)
#  define HM_E RSFT_T(KC_E)
#  define HM_I LALT_T(KC_I)
#  define HM_O KC_O
#endif

#define _BASE \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUES, \
  HM_A   , HM_R   , HM_S   , HM_T   , HM_G   , HM_M   , HM_N   , HM_E   , HM_I   , HM_O   , \
  KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, \
                             TH_LA  , TH_LH  , TH_RH  , TH_RA

#define _NAV \
  KC_ESC , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_PGUP, KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_PGDN, NV_LEFT, NV_DOWN, NV_UP  , NV_RGHT, \
  UK_SENT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_H   , KC_J   , KC_K   , KC_L   , \
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

/*
#define _SYM \
  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_COLN, \
  KC_TILD, KC_GRV , KC_DQUO, KC_BSLS, KC_NO  , KC_NO  , KC_PIPE, KC_PLUS, KC_MINS, KC_QUES, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO  , KC_ENT , KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, \
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
*/

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

// TODO: finish off the gaming alternate layer
/* #define _GAME_ALT \ */
/*   KC_ESC , KC_5   , KC_6   , KC_7   , KC_8   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \ */


#define LAYOUT_a_dux_wrap(...) LAYOUT_split_3x5_2(__VA_ARGS__)
