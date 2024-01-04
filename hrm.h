#include "caps_word.h"
#ifndef HRM_LAYOUT_ONLY
#  include "keycode.h"
#  include "quantum.h"
#  include "timer.h"
#endif

#ifndef HRM_KCS_DEFINED
#define HRM_KCS_DEFINED

#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LSFT_T(KC_S)
#define HM_T LCTL_T(KC_T)

#define HM_N RCTL_T(KC_N)
#define HM_E RSFT_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

#define CC_T HM_T
#define CC_D KC_D

#define CC_N HM_N
#define CC_H KC_H

#define CC_S HM_S
#define CC_C KC_C

#define CC_E HM_E
#define CC_COMM KC_COMM

#define CC_R HM_R
#define CC_X KC_X

#define CC_I HM_I
#define CC_DOT KC_DOT

#define BASE_HRM \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, \
  HM_A   , HM_R   , HM_S   , HM_T   , KC_G   , KC_M   , HM_N   , HM_E   , HM_I   , HM_O   , \
  KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, \
                             TH_LA  , TH_LH  , TH_RH  , TH_RA

#endif

#ifndef HRM_LAYOUT_ONLY

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
  HM_ITER(HM_I)

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

#endif // HRM_LAYOUT_ONLY
