#include "xd75.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_extras/keymap_bepo.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

void set_lower_color(void);
void set_raise_color(void);
void save_current_color(void);
void restore_color(void);

extern keymap_config_t keymap_config;
rgblight_config_t previous_color;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _BEPO 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  BEPO = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

enum tap_dance_keys {
  ESC_CALC = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ESC_CALC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CALC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BEPO
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | $      | "      | «      | »      | (      | )      |        | @      | +      | -      | /      | *      | =      | %      |ESC/CALC|
 * |--------+--------+--------+--------+--------+--------+ Back   +--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | B      | É      | P      | O      | È      | Space  | ^      | V      | D      | L      | J      | Z      | W      | PG UP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | A      | U      | I      | E      | ,      |        | C      | T      | S      | R      | N      | M      |     RSHIFT      |
 * | LSHIFT +--------+--------+--------+--------+--------+ Enter  +--------+--------+--------+--------+--------------------------+--------|
 * |        | À      | Y      | X      | .      | K      |        | '      | Q      | G      | H      | F      | Ç      | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | RAISE  |  META  | ALT    |     Space       | Delete |      Space      | ALT GR | LOWER  | RCTRL  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_BEPO] = {
  { BP_DLR,  BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN, KC_BSPC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,  BP_PERC, TD(ESC_CALC) },
  { KC_TAB,  BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, XXXXXXX, BP_DCRC, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,    BP_W,    KC_PGUP      },
  { KC_LSFT, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, KC_ENT,  BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,    KC_RSFT, XXXXXXX      },
  { XXXXXXX, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    XXXXXXX, BP_APOS, BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED, KC_UP,   KC_PGDN      },
  { KC_LCTL, RAISE,   KC_LGUI, KC_LALT, KC_SPC,  XXXXXXX, KC_DEL,  XXXXXXX, KC_SPC,  KC_RALT, LOWER,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT      },
 },

/* LOWERED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     |        | F6     | F7     | F8     | F9     | F10    | F11    | F12    | NUM    |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
 * |        +--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        | HOME   |        | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |  PREV  |  PLAY  |  NEXT  |                 |        |                 |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_LOWER] = { /* LOWERED */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NLCK  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END   },
  { _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

/* RAISED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        | Power  | Sleep  | Wake   | Pr. Sc.| Scroll | Pause  |        |
 * |--------+--------+--------+--------+--------+--------+ VOL UP +--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | Back   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
 * |        +--------+--------+--------+--------+--------+ VOL DN +--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | Forward|
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        | Copy   | Paste  |      MUTE       |        |      MUTE       |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_RAISE] = { /* RAISED */
  { _______, _______, _______, _______, _______, _______, KC_VOLU, _______,  KC_PWR, KC_SLEP, KC_WAKE, KC_PSCR, KC_SLCK, KC_PAUS, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WBAK  },
  { _______, _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WFWD  },
  { _______, _______, KC_COPY, KC_PASTE, KC_MUTE, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, },
 },

/* ADJUST (LOWER + RAISE)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  |        |        |        |        |        | Breath |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+ Speed  +--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |  inc   |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        | Breath |        |        |        |        |        |        |                 |
 * |        +--------+--------+--------+--------+--------+ Speed  +--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |  dec   |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |   Backlight     | Breath |   Backlight     |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_ADJUST] = { /* ADJUST */
  { RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, _______, _______, _______, BEPO, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEPO:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BEPO);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        set_lower_color();
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        restore_color();
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        set_raise_color();
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        restore_color();
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case RGB_HUI:
      if (record->event.pressed) {
        rgblight_increase_hue();
        save_current_color();
      }
      return false;
      break;
    case RGB_HUD:
      if (record->event.pressed) {
        rgblight_decrease_hue();
        save_current_color();
      }
      return false;
      break;
    case RGB_SAI:
      if (record->event.pressed) {
        rgblight_increase_sat();
        save_current_color();
      }
      return false;
      break;
    case RGB_SAD:
      if (record->event.pressed) {
        rgblight_decrease_sat();
        save_current_color();
      }
      return false;
      break;
    case RGB_VAI:
      if (record->event.pressed) {
        rgblight_increase_val();
        save_current_color();
      }
      return false;
      break;
    case RGB_VAD:
      if (record->event.pressed) {
        rgblight_decrease_val();
        save_current_color();
      }
      return false;
      break;
  }
  return true;
}
;

void matrix_init_user(void) {
  persistent_default_layer_set(1UL<<_BEPO);
}

void save_current_color(void) {
  previous_color.hue = rgblight_get_hue();
  previous_color.sat = rgblight_get_sat();
  previous_color.val = rgblight_get_val();
}

void restore_color(void) {
  rgblight_sethsv(previous_color.hue, previous_color.sat, previous_color.val);
}

void set_lower_color(void) {
  uint16_t hue;
  save_current_color();
  hue = previous_color.hue - 50;
  if (hue < 0) { hue += 360; }
  hue %= 360;
  rgblight_sethsv(hue, previous_color.sat, previous_color.val);
}

void set_raise_color(void) {
  uint16_t hue;
  save_current_color();
  hue = (previous_color.hue + 50) % 360;
  rgblight_sethsv(hue, previous_color.sat, previous_color.val);
}
