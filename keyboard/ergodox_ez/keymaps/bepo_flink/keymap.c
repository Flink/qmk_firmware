#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_french.h"

#define BASE 0 // default layer
#define SPFN 1 // space fn layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   $    |   "  |   «  |   »  |   (  |   )  | Del  |           | Del  |   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   B  |   É  |   P  |   O  |   È  | BkSp |           | BkSp |   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Sft |   A  |   S  |   D  |   F  |   G  |------|           |------|   C  |   T  |   S  |   R  |   N  | M/Shift|
 * |--------+------+------+------+------+------| Enter|           |Enter |------+------+------+------+------+--------|
 * | Ê/Shift|   À  |   Y  |   X  |   .  |   K  |      |           |      |   '  |   Q  |   G  |   H  |   F  | Ç/Shift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      |      | Alt  |                                       |   W  |   %  |      |      | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | LGui |       | LGui |  Calc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| Ctrl |------|       |------|  Ctrl  | AltGr|
 *                                 |      |      |TMP L1|       |TMP L1|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_DELT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        SFT_T(KC_ESC),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        SFT_T(FR_LESS), KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_ENT,
        KC_LCTL,        KC_NO,        KC_NO,  KC_NO,  KC_LALT,
                                                    KC_NO,    KC_LGUI,
                                                              KC_NO,
                                          KC_SPC, KC_LCTL, MO(SPFN),
        // right hand
             KC_DELT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_BSPC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          SFT_T(KC_QUOT),
             KC_ENT,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(FR_ASTR),
                                  FR_DLR, FR_EQL, KC_NO,  KC_NO,            KC_RCTL,
             KC_LGUI,     KC_CALC,
             KC_NO,
             MO(SPFN), KC_RCTL,KC_RALT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mute |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           | VolUp|      | Home |  Up  | End  | PgUp |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |------|           |------|      | Left | Down | Right| PgDn |        |
 * |--------+------+------+------+------+------|      |           | VolDn|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Space Fn layer
[SPFN] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_F6  ,KC_F7,  KC_F8  ,KC_F9  ,KC_F10 ,KC_TRNS,
       KC_TRNS,KC_F11 ,KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_MUTE, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_VOLU, KC_TRNS, KC_HOME,KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
                KC_TRNS, KC_LEFT,KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
       KC_VOLD, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SPFN)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
