#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_extras/keymap_bepo.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _MAIN 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum preonic_keycodes {
  MAIN = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main (bepo)
 * ,-----------------------------------------------------------------------------------.
 * |   $  |   "  |   «  |   »  |   (  |   )  |   @  |   +  |   -  |   /  |   *  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |  Z   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bksp |   À  |   Y  |   X  |   .  |   K  |   '  |   Q  |   G  |   H  |   F  |  Ç   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meta | Ctrl | Alt  | Lower|Shift |    Space    |AltGr | Raise|   %  |   W  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_MAIN] = {
  {BP_DLR,  BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL },
  {KC_TAB,  BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, BP_DCRC, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z  },
  {KC_ESC,  BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M   },
  {KC_BSPC, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    BP_APOS, BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED},
  {KC_LGUI, KC_LCTL, KC_LALT, LOWER,   KC_LSFT, KC_SPC,  KC_SPC,  BP_ALGR, RAISE,   BP_PERC, BP_W,    KC_ENT }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Del  |      |      |      |      |n.lock|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   (  |   )  |      |      | Bksp |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   [  |   ]  |   <  |   >  | Enter|   4  |   5  |   6  |   +  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   {  |   }  |      |      |      |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______,  KC_DEL, _______, _______, _______, _______, KC_NLCK},
  {_______, _______, BP_LPRN, BP_RPRN, _______, _______, KC_BSPC, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______},
  {_______, _______, BP_LBRC, BP_RBRC, BP_LESS, BP_GRTR,  KC_ENT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PMNS},
  {_______, _______, BP_LCBR, BP_RCBR, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_P0,   _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | Del  |      |      |      |      | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp | HOME |  UP  | END  | PGUP | VolUp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      | Enter| LEFT | DOWN | RIGHT| PGDN | VolDn|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,  KC_F1,   KC_F1,   KC_F3,   KC_F4,   KC_F5,   KC_DEL, _______, _______, _______, _______, KC_MUTE},
  {_______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_BSPC, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU},
  {_______,  KC_F1,   KC_F2,  _______, _______, _______,  KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_VOLD},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
