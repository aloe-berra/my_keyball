/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif
#ifdef RGB_MATRIX_MATRIX
#endif

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

#define HOLD_ON_OTHER_KEY_PRESS

#ifdef RGB_MATRIX_ENABLE
#   define DRIVER_LED_TOTAL 48
#   define RGB_MATRIX_LED_COUNT 48
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 125 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255

#   define RGB_MATRIX_DEFAULT_HUE 125 // Sets the default hue value, if none has been set
#   define RGB_MATRIX_DEFAULT_SAT 0 // Sets the default saturation value, if none has been set
#   define RGB_MATRIX_DEFAULT_VAL 125 // Sets the default brightness value, if none has been set
#   define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
#   define RGB_MATRIX_DEFAULT_SPD 40
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#   define ENABLE_RGB_MATRIX_SOLID_COLOR
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Sets the default mode, if none has been set
#   define SPLIT_LAYER_STATE_ENABLE // allows layer leds to be addressed on the second side
#   define SPLIT_MODS_ENABLE // allows mods to address leds on the second side.

#endif


#define RGB_DISABLE_WHEN_USB_SUSPENDED