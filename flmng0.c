#pragma once

#ifndef CAPS_WORD_ENABLE
#  define CAPS_WORD_ENABLE
#endif

#include "keycodes.h"
#include "layout.h"
#include "quantum.h"

#ifdef HOME_ROW_MODS
#  ifdef HRM_LAYOUT_ONLY
#    undef HRM_LAYOUT_ONLY
#  endif
#  include "hrm.h"
#endif

/**
 * Num row symbols.
 */
#define COMBO_DEF(var, ...) \
  const uint16_t PROGMEM var[] = {__VA_ARGS__, COMBO_END}

COMBO_DEF(c_at, KC_W, CC_R);
COMBO_DEF(c_pound, KC_F, CC_S);
COMBO_DEF(c_dollar, KC_P, CC_T);
COMBO_DEF(c_percent, KC_B, KC_G);

COMBO_DEF(c_carat, KC_J, KC_M);
COMBO_DEF(c_and, KC_L, CC_N);
COMBO_DEF(c_star, KC_U, CC_E);
COMBO_DEF(c_slash, KC_Y, CC_I);

/**
 * Parenthesis.
 *
 * Open on left hand, close on right hand.
 */
COMBO_DEF(c_lparen, CC_T, CC_S);
COMBO_DEF(c_rparen, CC_N, CC_E);

COMBO_DEF(c_lbracket, CC_T, CC_R);
COMBO_DEF(c_rbracket, CC_N, CC_I);

COMBO_DEF(c_lbrace, CC_S, CC_R);
COMBO_DEF(c_rbrace, CC_N, CC_E);

COMBO_DEF(c_langle, CC_T, CC_S, CC_R);
COMBO_DEF(c_rangle, CC_N, CC_E, CC_I);

/**
 * Common symbols.
 */
COMBO_DEF(c_hyphen, KC_B, KC_J);
COMBO_DEF(c_equals, KC_G, KC_M);
COMBO_DEF(c_underscore, KC_V, KC_K);

/**
 * Functional keys.
 */
COMBO_DEF(c_backspace, KC_L, KC_U);
COMBO_DEF(c_delete, KC_U, KC_Y);

combo_t key_combos[] = {
  // Upper Symbols
  COMBO(c_at,      LSFT(KC_2)),
  COMBO(c_pound,   LSFT(KC_3)),
  COMBO(c_dollar,  LSFT(KC_4)),
  COMBO(c_percent, LSFT(KC_5)),
  COMBO(c_carat,   LSFT(KC_6)),
  COMBO(c_and,     LSFT(KC_7)),
  COMBO(c_star,    LSFT(KC_8)),
  COMBO(c_slash,   LSFT(KC_9)),

  // Parenthesis
  COMBO(c_lparen, LSFT(KC_9)),
  COMBO(c_rparen, LSFT(KC_0)),

  COMBO(c_lbracket, KC_LEFT_BRACKET),
  COMBO(c_rbracket, KC_RIGHT_BRACKET),

  COMBO(c_lbrace, LSFT(KC_LEFT_BRACKET)),
  COMBO(c_rbrace, LSFT(KC_RIGHT_BRACKET)),

  COMBO(c_langle, LSFT(KC_COMMA)),
  COMBO(c_rangle, LSFT(KC_DOT)),

  // Common symbols
  COMBO(c_hyphen, KC_MINUS),
  COMBO(c_equals, KC_EQUAL),
  COMBO(c_underscore, LSFT(KC_MINUS)),

  COMBO(c_backspace, KC_BACKSPACE),
  COMBO(c_delete, KC_DELETE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case L_NAV:
  case L_SYM:
    return TAPPING_TERM + 200;

  default:
    return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case L_NAV:
  case L_SYM:
  case L_NUM:
    return false;

  default:
    return true;
  }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  case KC_A ... KC_Z:
    add_weak_mods(MOD_BIT(KC_LSFT));
    return true;

  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case KC_UNDS:
  case KC_MINS:
    return true;

  default:
    return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef HOME_ROW_MODS
  if (!process_hrm(keycode, record)) {
    return false;
  }
#endif

  const uint8_t mods = get_mods();
  switch (keycode) {
    /* If shift is already being pressed and smart shift is pressed,
       then activate caps word */
  case OSM(MOD_LSFT):
    if (mods & MOD_BIT(KC_LSFT)) {
      caps_word_toggle();
      return false;
    }
  }

  return true;
}
