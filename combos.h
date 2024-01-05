#include "quantum.h"
#include "hrm.h"

/**
 * Num row symbols.
 */
#define COMBO_DEF(var, ...) \
  const uint16_t PROGMEM var[] = {__VA_ARGS__, COMBO_END}

COMBO_DEF(c_at, KC_W, HM_R);
COMBO_DEF(c_pound, KC_F, HM_S);
COMBO_DEF(c_dollar, KC_P, HM_T);
COMBO_DEF(c_percent, KC_B, KC_G);

COMBO_DEF(c_carat, KC_J, KC_M);
COMBO_DEF(c_and, KC_L, HM_N);
COMBO_DEF(c_star, KC_U, HM_E);
COMBO_DEF(c_slash, KC_Y, HM_I);

/**
 * Parenthesis.
 *
 * Open on left hand, close on right hand.
 */
COMBO_DEF(c_lparen, HM_T, HM_S);
COMBO_DEF(c_rparen, HM_N, HM_E);

COMBO_DEF(c_lbracket, HM_T, HM_R);
COMBO_DEF(c_rbracket, HM_N, HM_I);

COMBO_DEF(c_lbrace, HM_S, HM_R);
COMBO_DEF(c_rbrace, HM_E, HM_I);

COMBO_DEF(c_langle, HM_T, HM_S, HM_R);
COMBO_DEF(c_rangle, HM_N, HM_E, HM_I);

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

enum COMBO_INDICES {
  C_LPAREN,
  C_RPAREN,
  C_LBRACKET,
  C_RBRACKET,
  C_LBRACE,
  C_RBRACE,
  C_LANGLE,
  C_RANGLE,
};


combo_t key_combos[] = {
  // Parenthesis
  [C_LPAREN] = COMBO(c_lparen, LSFT(KC_9)),
  [C_RPAREN] = COMBO(c_rparen, LSFT(KC_0)),

  [C_LBRACKET] = COMBO(c_lbracket, KC_LEFT_BRACKET),
  [C_RBRACKET] = COMBO(c_rbracket, KC_RIGHT_BRACKET),

  [C_LBRACE] = COMBO(c_lbrace, LSFT(KC_LEFT_BRACKET)),
  [C_RBRACE] = COMBO(c_rbrace, LSFT(KC_RIGHT_BRACKET)),

  [C_LANGLE] = COMBO(c_langle, LSFT(KC_COMMA)),
  [C_RANGLE] = COMBO(c_rangle, LSFT(KC_DOT)),

  // Upper Symbols
  COMBO(c_at,      LSFT(KC_2)),
  COMBO(c_pound,   LSFT(KC_3)),
  COMBO(c_dollar,  LSFT(KC_4)),
  COMBO(c_percent, LSFT(KC_5)),
  COMBO(c_carat,   LSFT(KC_6)),
  COMBO(c_and,     LSFT(KC_7)),
  COMBO(c_star,    LSFT(KC_8)),
  COMBO(c_slash,   LSFT(KC_9)),

  // Common symbols
  COMBO(c_hyphen, KC_MINUS),
  COMBO(c_equals, KC_EQUAL),
  COMBO(c_underscore, LSFT(KC_MINUS)),

  COMBO(c_backspace, KC_BACKSPACE),
  COMBO(c_delete, KC_DELETE),
};

