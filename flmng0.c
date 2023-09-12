#pragma once

#include "quantum.h"
#include "layout.h"

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
 * FP => Esc
 * ST => Tab
 *
 * Right Side:
 * LU => Delete
 * NE => Return
 * H, = Backspace
 */
const uint16_t PROGMEM c_escape[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM c_delete[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM c_return[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM c_backspace[] = {KC_H, KC_COMMA, COMBO_END};

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
  COMBO(c_return, CT_RETN),
  COMBO(c_backspace, KC_BACKSPACE),
};

#define CT_IMPL(key)                                   \
  case LT(0, KC_##key):                                \
    if (!record->tap.count && record->event.pressed) { \
      tap_code16(C(KC_##key));                         \
      return false;                                    \
    }                                                  \
    return true;

#define IS_CT(code) (code & QK_LAYER_TAP) && (((code >> 8) & 0xF) == 0)
#define CT_KC(code) (code & 0xFF)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (IS_CT(keycode)) {
    if (!record->tap.count && record->event.pressed) {
      tap_code16(C(CT_KC(keycode)));
      return false;
    }
  }

  return true;

  /**/
  /* switch (keycode) { */
  /*   CT_IMPL(C) */
  /*   CT_IMPL(V) */
  /*   CT_IMPL(X) */
  /*   CT_IMPL(Z) */
  /*   CT_IMPL(RETN) */
  /* } */
  /**/
  /* return true; */
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, ID_NAV, ID_SYM, ID_NUM);
}
