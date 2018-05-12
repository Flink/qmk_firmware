#include "xd75.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_extras/keymap_bepo.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

void set_default_rgb_color(void);
void set_lower_color(void);
void set_raise_color(void);

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom
#define CT_SPC CTL_T(KC_SPC)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Bepo
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |   $  |   "  |   «  |   »  |   (  |   )  |  Del |   @  |   +  |   -  |   /  |   *  |   =  | Calc |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Tab  |   B  |   É  |   P  |   O  |   È  | Bksp |   ^  |   V  |   D  |   L  |   J  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Esc  |   A  |   U  |   I  |   E  |   ,  |      |   C  |   T  |   S  |   R  |   N  |   M  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Ê  |   À  |   Y  |   X  |   .  |   K  | Enter|   '  |   Q  |   G  |   H  |   F  |   Ç  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | Play | Next |Lower | Meta |Sp/Ctl| Shift| AltGr|Raise | Alt  |   %  |   W  |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_BEPO] = {
  {XXXXXXX, BP_DLR,  BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN, KC_DEL,  BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,  KC_CALC},
  {XXXXXXX, KC_TAB,  BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, KC_BSPC, BP_DCRC, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,    XXXXXXX},
  {XXXXXXX, KC_ESC,  BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, XXXXXXX, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,    XXXXXXX},
  {XXXXXXX, BP_ECRC, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    KC_ENT,  BP_APOS, BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED, XXXXXXX},
  {XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, LOWER,   KC_LGUI, CT_SPC,  OSM_SFT, BP_ALGR, RAISE,   KC_LALT, BP_PERC, BP_W,    XXXXXXX, XXXXXXX}
},

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |n.lock|   /  |   *  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   7  |   8  |   9  |   -  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   1  |   2  |   3  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______},
  {_______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______},
  {_______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, _______, _______, _______, _______}
},

/* Raise
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |  F1  |  F2  |  F3  |  F4  |  F5  | Mute |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F6  |  F7  |  F8  |  F9  |  F10 | Vol+ |      | HOME |  UP  | END  | PGUP |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      |  F11 |  F12 |      |      |      |      |      | LEFT | DOWN | RIGHT| PGDN |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Vol- |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MUTE, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______},
  {_______, _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Bépo |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  {
  { RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, BEPO,    _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
},
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
        set_default_rgb_color();
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
        set_default_rgb_color();
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
        set_default_rgb_color();
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
  }
  return true;
}

void matrix_init_user(void) {
  persistent_default_layer_set(1UL<<_BEPO);
  set_default_rgb_color();
}

void set_default_rgb_color(void) {
  // purple-ish
  rgblight_sethsv(270, 241, 238);
}

void set_lower_color(void) {
  // bluish
  rgblight_sethsv(220, 241, 238);
}

void set_raise_color(void) {
  // redish
  rgblight_sethsv(326, 241, 238);
}
