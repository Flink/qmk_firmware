#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_french.h"

#define BASE 0 // default layer
#define SPFN 1 // space fn layer
#define NUML 2 // numeric layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   "  |   «  |   »  |   (  |   )  | Del  |           | Del  |   @  |   +  |   -  |   /  |   *  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   B  |   É  |   P  |   O  |   È  | BkSp |           | BkSp |   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------| Enter|           |Enter |------+------+------+------+------+--------|
 * | Ê/Shift|   À  |   Y  |   X  |   .  |   K  |      |           |      |   '  |   Q  |   G  |   H  |   F  |   Ç    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   $  |      |      |      |                                       |   W  |   %  |      |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | AltGr|       | Calc |  LGui  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |TMP L2|       |TMP L2|        |      |
 *                                 | Space| Ctrl |------|       |------| LShift | AltGr|
 *                                 |      |      |TMP L1|       |TMP L1|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,          KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_DELT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        KC_ESC,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        SFT_T(FR_LESS), KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_ENT,
        KC_NO,          KC_GRV,       KC_NO,  KC_NO,  KC_NO,
                                                    KC_LALT,  KC_RALT,
                                                           MO(NUML),
                                          KC_SPC, KC_LCTL, MO(SPFN),
        // right hand
             KC_DELT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_NO,
             KC_BSPC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_ENT,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          FR_ASTR,
                                  FR_DLR, FR_EQL, KC_NO,  KC_MINS,          KC_NO,
             KC_CALC,     KC_LGUI,
             MO(NUML),
             MO(SPFN), KC_LSFT,KC_RALT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mute |      |      |      |      |      | DEBUG  |
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
       RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
       KC_TRNS,KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_MUTE, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, DEBUG,
       KC_VOLU, KC_TRNS, KC_HOME,KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
                KC_TRNS, KC_LEFT,KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
       KC_VOLD, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Numeric Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  (   |  )   |      |      |      |           |      |      |  7   |  8   |  9   |  *   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  [   |  ]   |  <   |  >   |------|           |------|      |  4   |  5   |  6   |  +   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  {   |  }   |      |      |      |           |      |      |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |n.lock|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  .   |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// numeric layer
[NUML] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_4,   KC_5,   KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,RALT(KC_4),RALT(KC_5),RALT(KC_2),RALT(KC_3),
       KC_TRNS,KC_TRNS,RALT(KC_X),RALT(KC_C),KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P7,  KC_P8,   KC_P9,   KC_PAST, KC_TRNS,
                KC_TRNS, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
       KC_TRNS, KC_TRNS, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_NLCK,
       KC_TRNS,
       KC_TRNS, KC_PDOT, KC_P0
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
