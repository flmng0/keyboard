#pragma once
#include "quantum.h"

#ifndef COMBO_END
#warning "COMBO_END not defined?"
#define COMBO_END 0
#endif

/**
 * Parenthesis.
 *
 * Open on left hand, close on right hand.
 */
const uint16_t PROGMEM c_lparen[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM c_rparen[] = {KC_N, KC_H, COMBO_END};

const uint16_t PROGMEM c_lbracket[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM c_rbracket[] = {KC_E, KC_COMMA, COMBO_END};

const uint16_t PROGMEM c_lbrace[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM c_rbrace[] = {KC_M, KC_K, COMBO_END};

const uint16_t PROGMEM c_langle[] = {KC_R, KC_X, COMBO_END};
const uint16_t PROGMEM c_rangle[] = {KC_I, KC_DOT, COMBO_END};

/**
 * Common symbols.
 */
const uint16_t PROGMEM c_hyphen[] = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM c_equals[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM c_underscore[] = {KC_V, KC_K, COMBO_END};

/**
 * Left Side:
 * PB => Esc
 * TG => Tab
 * 
 * Right Side:
 * JL => Delete
 * MN => Return
 * KH = Backspace
 */
const uint16_t PROGMEM c_escape[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_T, KC_G, COMBO_END};

const uint16_t PROGMEM c_delete[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM c_return[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM c_backspace[] = {KC_K, KC_H, COMBO_END};


combo_t key_combos[] = {
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

  // Functional buttons
  COMBO(c_escape, KC_ESCAPE),
  COMBO(c_tab, KC_TAB),

  COMBO(c_delete, KC_DELETE),
  COMBO(c_return, KC_ENTER),
  COMBO(c_backspace, KC_BACKSPACE),
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, L_NAV, L_SYM, L_NUM);
}
