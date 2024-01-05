#pragma once

#include "caps_word.h"
#include "keycode.h"
#include "quantum.h"
#include "timer.h"

#include "layout.h"

#ifndef HRM_IDLE_DELAY
#define HRM_IDLE_DELAY (150)
#endif

#define HM_EACH()                                                              \
  HM_ITER(HM_A)                                                                \
  HM_ITER(HM_R)                                                                \
  HM_ITER(HM_S)                                                                \
  HM_ITER(HM_T)                                                                \
  HM_ITER(HM_N)                                                                \
  HM_ITER(HM_E)                                                                \
  HM_ITER(HM_I)                                                                \
  HM_ITER(HM_O)

static uint32_t idle_timer;

// Alias to get tap code of HRM keycode
#define HRM_TAP_CODE(kc) (QK_MOD_TAP_GET_TAP_KEYCODE(kc))

bool process_hrm(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#define HM_ITER(x) case x:
    HM_EACH()
#undef HM_ITER
    if (record->event.pressed) {
      if (timer_elapsed32(idle_timer) < HRM_IDLE_DELAY) {
        if (is_caps_word_on()) {
          add_weak_mods(MOD_BIT(KC_LSFT));
        }
        tap_code(HRM_TAP_CODE(keycode));
        return false;
      }
    }
    else if ((get_mods() & MOD_BIT(keycode)) == 0) {
      idle_timer = timer_read32();
    }
    break;

  default:
    if (!record->event.pressed) 
      idle_timer = timer_read32();
  }

  return true;
}

#define IS_IDLE (timer_elapsed32(idle_timer) >= HRM_IDLE_DELAY)
