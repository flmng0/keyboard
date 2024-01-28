#include "quantum.h"
#include "hrm.h"

/**
 * Num row symbols.
 */
#define COMBO_DEF(var, ...) \
  const uint16_t PROGMEM var[] = {__VA_ARGS__, COMBO_END}

COMBO_DEF(c_at, HM_R, KC_X);
COMBO_DEF(c_pound, HM_S, KC_C);
COMBO_DEF(c_dollar, HM_T, KC_D);
COMBO_DEF(c_percent, HM_G, KC_V);

COMBO_DEF(c_carat, HM_M, KC_K);
COMBO_DEF(c_plus, HM_N, KC_H);
COMBO_DEF(c_star, HM_E, KC_COMM);
COMBO_DEF(c_and, HM_I, KC_DOT);

/**
 * Alternate symbols.
 */
COMBO_DEF(c_grave, KC_W, HM_R);
COMBO_DEF(c_underscore, KC_P, HM_T);
COMBO_DEF(c_backslash, KC_F, HM_S);
COMBO_DEF(c_tilde, KC_B, HM_G);

COMBO_DEF(c_equals, HM_M, KC_J);
COMBO_DEF(c_hyphen, KC_L, HM_N);
COMBO_DEF(c_slash, KC_U, HM_E);
COMBO_DEF(c_pipe, KC_Y, HM_I);

/**
 * Parenthesis.
 *
 * Open on left hand, close on right hand.
 */
COMBO_DEF(c_lparen, HM_T, HM_S);
COMBO_DEF(c_rparen, HM_N, HM_E);

COMBO_DEF(c_lbrace, HM_S, HM_R);
COMBO_DEF(c_rbrace, HM_E, HM_I);

COMBO_DEF(c_langle, HM_G, HM_T);
COMBO_DEF(c_rangle, HM_M, HM_N);

COMBO_DEF(c_lbracket, HM_T, HM_R);
COMBO_DEF(c_rbracket, HM_N, HM_I);

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
  [C_LPAREN] = COMBO(c_lparen, KC_LEFT_PAREN),
  [C_RPAREN] = COMBO(c_rparen, KC_RIGHT_PAREN),

  [C_LBRACKET] = COMBO(c_lbracket, KC_LEFT_BRACKET),
  [C_RBRACKET] = COMBO(c_rbracket, KC_RIGHT_BRACKET),

  [C_LBRACE] = COMBO(c_lbrace, KC_LEFT_CURLY_BRACE),
  [C_RBRACE] = COMBO(c_rbrace, KC_RIGHT_CURLY_BRACE),

  [C_LANGLE] = COMBO(c_langle, KC_LEFT_ANGLE_BRACKET),
  [C_RANGLE] = COMBO(c_rangle, KC_RIGHT_ANGLE_BRACKET),

  // Upper Symbols
  COMBO(c_at,      KC_AT),
  COMBO(c_pound,   KC_HASH),
  COMBO(c_dollar,  KC_DOLLAR),
  COMBO(c_percent, KC_PERCENT),

  COMBO(c_carat,   KC_CIRCUMFLEX),
  COMBO(c_and,     KC_AMPERSAND),
  COMBO(c_star,    KC_ASTERISK),
  COMBO(c_plus,    KC_PLUS),

  // Alternate symbols
  COMBO(c_grave, KC_GRAVE),
  COMBO(c_equals, KC_EQUAL),
  COMBO(c_backslash, KC_BACKSLASH),
  COMBO(c_tilde, KC_TILDE),

  COMBO(c_underscore, KC_UNDERSCORE),
  COMBO(c_hyphen, KC_MINUS),
  COMBO(c_slash, KC_SLASH),
  COMBO(c_pipe, KC_PIPE),
  
  // Common symbols
  COMBO(c_backspace, KC_BACKSPACE),
  COMBO(c_delete, KC_DELETE),
};

