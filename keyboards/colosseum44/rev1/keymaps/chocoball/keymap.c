#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#include "analog.h"
#include "joystick.h"
#endif
#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  KC_00,
  LCLK,
  RCLK,
  MOUSE_RESET,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Qwerty
     * ,-----------------------------------------.                ,-------------------------------------------.
     * |   =  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |    \   |
     * |------+------+------+------+------+------|                |------+------+------+------+------+--------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  |   ;  | ' / Cmd|
     * |------+------+------+------+------+------|                |------+------+------+------+------+--------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  |  Shift |
     * `-------------------------------------------------. ,--------------------------------------------------'
     *               |   Alt    |  Cmd | spc/LOWER|  Bsp | | Tab | Enter/RAISE |  Alt  |       |
     *               `-----------------------------------' `-----------------------------------'
     */
  [_QWERTY] = LAYOUT(
        KC_EQL,  KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSLS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,   GUI_T(KC_QUOT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,
          KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), KC_BSPC,      KC_TAB, LT(_RAISE, KC_ENT), KC_LALT, KC_NO
  ),
    /* Lower
     * ,-----------------------------------------.                ,------------------------------------------.
     * |  Esc |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |   -   |
     * |------+------+------+------+------+------|                |------+------+------+------+------+-------|
     * |      |   {  |   }  |   (  |   )  |   `  |                |      |      |      |      |      |   |   |
     * |------+------+------+------+------+------|                |------+------+------+------+------+-------|
     * |      |      |      |   [  |   ]  |   ~  |                |      |      |      |      |      |       |
     * `-------------------------------------------------. ,-------------------------------------------------'
     *                      |      |      | LOWER|       | |      | RAISE|      |      |
     *                      `----------------------------' `---------------------------'
     */
  [_LOWER] = LAYOUT(
         KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_GRV,       KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_TRNS, KC_PIPE,
        KC_TRNS, KC_NO,   KC_LBRC, KC_LBRC, KC_RBRC, KC_TILD,      KC_NO,  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,  KC_TRNS, KC_LOWER, KC_TRNS,     KC_TRNS, KC_RAISE, KC_TRNS, KC_TRNS
  ),
    /* Raise
     * ,----------------------------------------.                ,------------------------------------------.
     * |     |      |      |      |      |      |                |      |      |      |      | PGUP |  HOME |
     * |-----+------+------+------+------+------|                |------+------+------+------+------+-------|
     * |     |      |      |      |      |      |                |  ←   |  ↓   |  ↑   |  →   |PGDOWN|  END  |
     * |-----+------+------+------+------+------|                |------+------+------+------+------+-------|
     * |     |      |      |      |      |      |                |MRESET|LCLICK|RCLICK|      |      |       |
     * `------------------------------------------------. ,-------------------------------------------------'
     *                      |      |      | LOWER|      | |       |RAISE |      |      |
     *                      `---------------------------' `----------------------------'
     */

  [_RAISE] = LAYOUT(
      KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,         KC_NO,       KC_NO,   KC_NO, KC_NO,    KC_PGUP, KC_HOME,
      KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,         KC_LEFT,     KC_DOWN, KC_UP, KC_RIGHT, KC_PGDN, KC_END,
      KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,         MOUSE_RESET, LCLK,    RCLK,  KC_NO,    KC_NO,   KC_NO,
              KC_TRNS, KC_TRNS,  KC_LOWER, KC_TRNS,       KC_TRNS,KC_RAISE, KC_TRNS, KC_TRNS
  ),

    /* Adjust
     * ,-----------------------------------------.                ,------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  |  F11  |
     * |------+------+--------+------+--------+--|                |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |                | LTOG | LMOD |      | C A D| A Prt|  F12  |
     * |------+------+--------+------+--------+--|                |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |                |  VAD |  VAI |  HUD |  HUI |  SAD |  SAI  |
     * `------------------------------------------------. ,-------------------------------------------------'
     *                      |      |      | LOWER|      | |       | RAISE|      |      |
     *                      `---------------------------' `----------------------------'
     */

  [_ADJUST] = LAYOUT(
   KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,       KC_F10,        KC_F11,
   KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       RGB_TOG, RGB_MOD, RGBRST,  LCA(KC_DEL), LALT(KC_PSCR), KC_F12,
   KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI,     RGB_SAD,       RGB_SAI,
              KC_TRNS,KC_TRNS,KC_LOWER, KC_TRNS,    KC_TRNS, KC_RAISE, KC_TRNS,KC_TRNS
   )
};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          rgblight_mode(14);
        }
      #endif
      break;
    case KC_00:
      if (record->event.pressed) {
        SEND_STRING("00");
      }
      return false;
      break;
#ifdef POINTING_DEVICE_ENABLE
    case LCLK:
      if (record->event.pressed) {
        mouse_button_on(MOUSE_BUTTON1);
      }
      else {
        mouse_button_off(MOUSE_BUTTON1);
      }
      return false;
      break;
    case RCLK:
      if (record->event.pressed) {
        mouse_button_on(MOUSE_BUTTON2);
      }
      else {
        mouse_button_off(MOUSE_BUTTON2);
      }
      return false;
      break;
    case MOUSE_RESET:
      mouse_reset();
      return false;
      break;
#endif
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_task(void)
{
    report_mouse_t r = pointing_device_get_report();

    int16_t x = analogRead(8);  // pin  8
    int16_t y = analogRead(6);  // pin 10

    // uprintf("master=%d pin(%d)=%d pin(%d)=%d\r\n", is_master, 8, axisx, 6, axisy);

    mouse_update(x, y);
    r.x = mouse_x();
    r.y = mouse_y();
    r.buttons = get_mouse_button();
    pointing_device_set_report(r);
    pointing_device_send();
}
#endif
