#pragma once

#include "quantum.h"
#include "layout.h"

/**
 * Parenthesis.
 *
 * Open on left hand, close on right hand.
 */
const uint16_t PROGMEM c_lparen[] = {CC_T, CC_D, COMBO_END};
const uint16_t PROGMEM c_rparen[] = {CC_N, CC_H, COMBO_END};

const uint16_t PROGMEM c_lbracket[] = {CC_S, CC_C, COMBO_END};
const uint16_t PROGMEM c_rbracket[] = {CC_E, CC_COMM, COMBO_END};

const uint16_t PROGMEM c_lbrace[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM c_rbrace[] = {KC_M, KC_K, COMBO_END};

const uint16_t PROGMEM c_langle[] = {CC_R, CC_X, COMBO_END};
const uint16_t PROGMEM c_rangle[] = {CC_I, CC_DOT, COMBO_END};

/**
 * Common symbols.
 */
const uint16_t PROGMEM c_hyphen[] = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM c_equals[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM c_underscore[] = {KC_V, KC_K, COMBO_END};

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

/* bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*   #ifdef HOME_ROW_MODS */
/*     case HM_A: */
/*     case HM_R: */
/*     case HM_S: */
/*     case HM_T: */
/*     case HM_N: */
/*     case HM_E: */
/*     case HM_I: */
/*     case HM_O: */
/*       return true; */
/**/
/*   #else */
/*     case BM_Z: */
/*     case BM_X: */
/*     case BM_C: */
/*     case BM_D: */
/*     case BM_H: */
/*     case BM_COMM: */
/*     case BM_DOT: */
/*     case BM_QUOT: */
/*       return true; */
/*   #endif */
/**/
/*     case KC_A ... KC_Z: */
/*     case KC_TAB: */
/*       return true; */
/*   } */
/**/
/*   return false; */
/* } */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  #ifdef HOME_ROW_MODS
    case HM_A:
    case HM_R:
    case HM_S:
    case HM_T:
    case HM_N:
    case HM_E:
    case HM_I:
    case HM_O:
      return true;

  #else
    case BM_Z:
    case BM_X:
    case BM_C:
    case BM_D:
    case BM_H:
    case BM_COMM:
    case BM_DOT:
    case BM_QUOT:
      return true;

  #endif

    case KC_SCLN:
      return true;
  }

  return false;
}

#ifdef HOME_ROW_MODS
#define ROLLOVER(kca, kcb, modded_b, mod_a) \
  case modded_b: \
    if (record->event.pressed && record->tap.count > 0) { \
      if (mods & MOD_BIT(mod_a)) { \
        unregister_mods(MOD_BIT(mod_a)); \
        tap_code(kca); \
        tap_code(kcb); \
        add_mods(MOD_BIT(mod_a)); \
        return false; \
      } \
    } \
    return true;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef HOME_ROW_MODS
  uint8_t mods = get_mods();

  switch (keycode) {
    ROLLOVER(KC_A, KC_R, HM_R, KC_LGUI);
    ROLLOVER(KC_R, KC_S, HM_S, KC_LALT);
    ROLLOVER(KC_S, KC_T, HM_T, KC_LSFT);
    ROLLOVER(KC_T, KC_G, KC_G, KC_LCTL);

    ROLLOVER(KC_N, KC_M, KC_M, KC_RCTL);
    ROLLOVER(KC_E, KC_N, HM_N, KC_RSFT);
    ROLLOVER(KC_I, KC_E, HM_E, KC_LALT);
    ROLLOVER(KC_O, KC_I, HM_I, KC_RGUI);
  }
  #endif

  return true;
}
