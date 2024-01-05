#pragma once

#ifndef CAPS_WORD_ENABLE
#  define CAPS_WORD_ENABLE
#endif

#include "keycodes.h"
#include "layout.h"
#include "quantum.h"

#include "features/custom_shift_keys.h"

#include "hrm.h"
#include "combos.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  (void)combo;

  switch (index) {
  case C_LPAREN ... C_RANGLE:
    return 30;
  }

  return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  (void)combo;

  switch (index) {
  case C_LPAREN ... C_RANGLE:
    return true;
  }

  return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TH_LH:
  case TH_RA:
    return TAPPING_TERM + 200;

  // Pinkies are weak and I'm more likely to mis-fire with those keys
  case HM_A:
  case HM_O:
    return TAPPING_TERM + 50;

  default:
    return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TH_LA:
  case TH_LH:
  case TH_RA:
  case TH_RH:
    return false;

  default:
    return true;
  }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  case KC_A ... KC_Z:
    add_weak_mods(MOD_MASK_SHIFT);
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

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUESTION, KC_EXCLAIM},
  {KC_COMM, KC_SEMICOLON},
  {KC_DOT, KC_COLON},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Disable one shot mods for non-base keys
  if (record->event.pressed) {
    switch (keycode) {
#define HM_ITER(x) case x:
    HM_EACH()
#undef HRM_ITER
    case KC_A ... KC_Z:
    case KC_QUESTION:
    case KC_COMMA:
    case KC_DOT:
    case KC_QUOTE:
      break;

    default:
      del_oneshot_mods(MOD_MASK_SHIFT);
    }
  }

  if (!process_hrm(keycode, record)) { return false; }
  if (!process_custom_shift_keys(keycode, record)) { return false; }

  const uint8_t mods = get_mods();
  const uint8_t all_mods = get_mods() | get_weak_mods() | get_oneshot_mods();

  switch (keycode) {
    /* If shift is already being pressed and smart shift is pressed,
       then activate caps word */
  case OSM(MOD_LSFT):
    if (record->event.pressed && mods & MOD_MASK_SHIFT) {
      caps_word_toggle();
      return false;
    }
    break;

  case TH_LH:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        if (all_mods & MOD_MASK_SHIFT) {
          del_weak_mods(MOD_MASK_SHIFT);
          del_oneshot_mods(MOD_MASK_SHIFT);

          unregister_mods(MOD_MASK_SHIFT);

          SEND_STRING(". ");
          set_oneshot_mods(MOD_MASK_SHIFT);

          set_mods(mods);

          return false;
        }
      }
    }
  }

  return true;
}
