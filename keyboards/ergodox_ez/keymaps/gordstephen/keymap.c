#include QMK_KEYBOARD_H
#include "version.h"

#define _COLEMAK_DH 0
#define _QWERTY 1
#define _NAV 2

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* COLEMAK_DH layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   [    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  '   | RShift |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    ,   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  ;   |    .   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Home | End  | Ins  | Super|  Del |                                       |  Tab |Super |   /  | PgUp | PgDn |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bksp | Esc/ |------|       |------| Entr | Spc  |
 *                                 |      | Ctrl |      |       |      | Alt  | Fn   |
 *                                 `--------------------'       `--------------------'
 */
[_COLEMAK_DH] = LAYOUT_ergodox(

  // left hand
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,    XXXXXXX,
  KC_LBRC, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,    XXXXXXX,
  KC_LSPO, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,
  KC_COMM, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,    XXXXXXX,
  KC_HOME, KC_END , KC_INS , KC_LGUI, KC_DEL ,

                                                              XXXXXXX, XXXXXXX,
                                                                       XXXXXXX,
                                              KC_BSPC, LCTL_T(KC_ESC), XXXXXXX,

  // right hand
  XXXXXXX, KC_6   , KC_7,    KC_8   , KC_9   , KC_0,    KC_BSLS,
  XXXXXXX, KC_J   , KC_L,    KC_U   , KC_Y   , KC_QUOT, KC_RBRC,
           KC_M   , KC_N,    KC_E   , KC_I   , KC_O,    KC_RSPC,
  XXXXXXX, KC_K   , KC_H,    KC_MINS, KC_EQL , KC_SCLN, KC_DOT ,
                    KC_TAB , KC_RGUI, KC_SLSH, KC_PGUP, KC_PGDN,

  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, RALT_T(KC_ENT), LT(_NAV,KC_SPC)

),

/* QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   D  |   F  |      |------|           |------|   H  |   J  |   K  |   L  |  P   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_QWERTY] = LAYOUT_ergodox(

  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_E   , KC_R   , KC_T   , _______,
  _______, _______, KC_S   , KC_D   , KC_F   , _______,
  _______, _______, _______, _______, KC_V   , KC_B   , _______,
  _______, _______, _______, _______, _______,

                                                        _______, _______,
                                                                 _______,
                                               _______, _______, _______,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_Y   , KC_U   , KC_I   , KC_O   , _______, _______,
           KC_H   , KC_J   , KC_K   , KC_L   , KC_P   , _______,
  _______, KC_N   , KC_M   , _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, _______, _______

),

/* Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| LEFT | DOWN |  UP  | RGHT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LAYOUT|      |      |      |      |                                       |      |      |      |      | RSET |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAV] = LAYOUT_ergodox(
  // left hand
  _______,    KC_F1,   KC_F2,   KC_F3  , KC_F4  , KC_F5  , _______,
  _______,    _______, _______, _______, _______, _______, _______,
  _______,    _______, _______, _______, _______, _______,
  _______,    _______, _______, _______, _______, _______, _______,
  TG(_QWERTY),_______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,
  // right hand
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, KC_F12,
           KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, QK_BOOT,
  _______, _______,
  _______,
  _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
