/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for(uint8_t i = led_min; i < led_max; ++i) {
    if (!(g_led_config.flags[i] & LED_FLAG_UNDERGLOW))
      continue;
    switch(get_highest_layer(layer_state|default_layer_state)) {
      case 0:
        rgb_matrix_set_color(i, RGB_OFF);
        break;
      case 1:
        rgb_matrix_set_color(i, RGB_PURPLE);
        break;
      case 2:
        rgb_matrix_set_color(i, RGB_CORAL);
        break;
      case 3:
        rgb_matrix_set_color(i, RGB_YELLOW);
        break;
    }
  }
  return false;
}

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_reload_from_eeprom();
#elif RGBLIGHT_ENABLE
  rgblight_reload_from_eeprom();
#endif
}

    /*
    14, 10,  6,  3,  0,              43, 40, 37, 34, 30, \
    15, 11,  5,  4,  1,              44, 41, 38, 35, 31, \
    16, 12,  8,  5,  2,              45, 42, 39, 36, 32, \
    17, 13,  9,  0,  0,  0,    0, 0,                33\
    */
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  {   14,   10,    6,    3,    0, NO_LED }, \
  {   15,   11,    7,    4,    1, NO_LED }, \
  {   16,   12,    8,    5,    2, NO_LED }, \
  {   17,   13,    9, NO_LED, NO_LED, NO_LED}, \
  {   30,   34,   37,   40,   43, NO_LED }, \
  {   31,   35,   38,   41,   44, NO_LED }, \
  {   32,   36,   39,   42,   45, NO_LED }, \
  {   33, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}, \
}, {
  {81, 0}, {81, 21}, {81, 42},
  {61, 0}, {61, 21}, {61, 42},
  {40, 0}, {40, 21}, {40, 42}, {40, 64},
  {20, 0}, {20, 21}, {20, 42}, {20, 64},
  {0, 0}, {0, 21}, {0, 42}, {0, 64},
  {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
  {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
  {224, 0}, {224, 21}, {224, 42}, {224, 64},
  {203, 0}, {203, 21}, {203, 42},
  {183, 0}, {183, 21}, {183, 42},
  {162, 0}, {162, 21}, {162, 42},
  {142, 0}, {142, 21}, {142, 42},
}, {
  4, 4, 4,
  4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2,
  4, 4, 4, 4,
  4, 4, 4,
  4, 4, 4,
  4, 4, 4,
  4, 4, 4,
} };
#endif

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
