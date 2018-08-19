#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "midi.h"
#include "qmk_midi.h"

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
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  KC_00,
  RGB_RIPPLE,
  CO_C_MAJ,
  CO_D_MIN,
  CO_E_MIN,
  CO_F_MAJ,
  CO_G_MAJ,
  CO_A_MIN,
  CO_B_DIM,
  CO_E_7
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 0:
                register_code(KC_LSFT);
                register_code(KC_SCLN);
                unregister_code(KC_9);
                register_code(KC_SCLN);
            case 1:
                return MACRO(T(CAPS), T(QUOT), T(CAPS));
        }
    }
    return MACRO_NONE;
};

#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  =   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Set  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |  /   |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctr  |  OS  | F12  | Alt  | Bksp |Space | Calc |Cursol|Enter | Del  |  Up  | Left | Down |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    MI_OCTU,  CO_E_7,   CO_D_MIN, CO_F_MAJ, CO_A_MIN, CO_C_MAJ,                      KC_6,           KC_7,   KC_8,    KC_9,    KC_0,    KC_BSLS, \
    MI_OCTD,  CO_A_MIN, CO_C_MAJ, CO_E_MIN, CO_G_MAJ, CO_B_DIM,                      KC_Y,           KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,  \
    MI_SUS,   MI_VEL_2, MI_VEL_4, MI_VEL_6, MI_VEL_8, MI_VEL_10,                     KC_H,           KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    MI_TRNSU, MI_B,     MI_D_1,   MI_F_1,   MI_A_1,   MI_C_2,    MI_E_2,  KC_RBRC,   KC_N,           KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
    MI_TRNSD, MI_A,     MI_C_1,   MI_E_1,   MI_G_1,   MI_B_1,    MI_D_2,    TT(1),   RCTL_T(KC_ENT), KC_DEL, KC_LEFT,  KC_UP,  KC_DOWN, KC_RGHT  \
  ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  | F10  |PrtSc |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | NmLk | ScLk | PgUp |Pouse |      |             |      |      |  Up  |      |      | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Ins  | Home | PgDw | End  |      |             |      | Left | Down |Right |      | F11  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | Undo | Cut  | Copy |Paste |      |      |      |      | OSL  | OSDw | OSR  |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,  KC_PSCR, \
    _______, KC_NLCK, KC_SLCK, KC_PGUP, KC_PAUS, _______,                   _______, _______,      KC_UP,        _______,      _______, KC_F12,  \
    _______, KC_INS,  KC_HOME, KC_PGDN, KC_END,  _______,                   _______, KC_LEFT,      KC_DOWN,      KC_RGHT,      _______, KC_F11,  \
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______, KC_LPRN, KC_RPRN, _______, LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_RGHT), _______, _______, \
    KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,      _______,      _______, _______  \
  ),
  /* Raise
   * 
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |NumLk |  /   |  *   |  -   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |RClick|MusUp |Lclick|      |             |      |  7   |  8   |  9   |  +   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |MusLft|MusDw |MusRgt|      |             |      |  4   |  5   |  6   |  ,   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |  1   |  2   |  3   |  =   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |  0   |  0   |  .   |Enter |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_TILD, _______, _______,    _______,    _______,     _______,                   _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, \
    _______, _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _______,                   _______, KC_7,    KC_8,    KC_9,    KC_PPLS, _______, \
    _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,                   _______, KC_4,    KC_5,    KC_6,    KC_PCMM, _______, \
    _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_PEQL, _______, \
    _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, KC_0,    KC_00,   KC_PDOT, KC_PENT, _______  \
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  | F10  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |HueUp |      |      |             |      |SpdDw |BriUp |SpdUp |      | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |SadUp |HueDw |SadDw |      |             |      |ModeDw|BriDw |ModeUp|      | F11  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Ripple|      |      |      |      |      |Reset |LEDTgl|      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
    RESET,      _______, _______, _______, _______, _______,                   _______, _______,  _______, _______, _______, DEBUG,   \
    _______,    _______, _______, RGB_HUI, _______, _______,                   _______, RGB_SPD,  RGB_VAI, RGB_SPI, _______, _______, \
    _______,    _______, RGB_SAD, RGB_HUD, RGB_SAI, _______,                   _______, RGB_RMOD, RGB_VAD, RGB_MOD, _______, _______, \
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
    RGB_RIPPLE, _______, _______, _______, _______, _______, RGBRST,  RGB_TOG, _______, _______,  _______, _______, _______, _______  \
  )
};
#else
#error "undefined keymaps"
#endif

#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

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

struct keybuf {
  char col, row;
  char frame;
};
struct keybuf keybufs[256];
unsigned char keybuf_begin, keybuf_end;

int col, row;
bool ripple = false;
unsigned char rgb[7][5][3];

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  col = record->event.key.col;
  row = record->event.key.row;
  if (record->event.pressed && ((row < 5 && is_master) || (row >= 5 && !is_master))) {
    int end = keybuf_end;
    keybufs[end].col = col;
    keybufs[end].row = row % 5;
    keybufs[end].frame = 0;
    keybuf_end ++;
  }

  switch (keycode) {
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          ripple = false;
          eeconfig_update_rgblight_default();
          rgblight_enable();
          rgblight_mode(14);
        }
      #endif
      break;
    case KC_SCLN:
      if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
        if (record->event.pressed) {
          unregister_code(KC_LSFT);
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
          register_code(KC_LSFT);
        }
      } else if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
        if (record->event.pressed) {
          unregister_code(KC_RSFT);
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
          register_code(KC_RSFT);
        }
      } else {
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case KC_QUOT:
      if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
        if (record->event.pressed) {
          unregister_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          register_code(KC_LSFT);
        }
      } else if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
        if (record->event.pressed) {
          unregister_code(KC_RSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          register_code(KC_RSFT);
        }
      } else {
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case KC_00:
      if (record->event.pressed) {
        SEND_STRING("00");
      }
      return false;
      break;
    case RGB_RIPPLE:
      if (record->event.pressed) {
        rgblight_mode(0);
        ripple = true;
      }
      return false;
      break;
    case CO_C_MAJ:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_C);
        uint8_t three = midi_compute_note(MI_E);
        uint8_t five = midi_compute_note(MI_G);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_D_MIN:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_D);
        uint8_t three = midi_compute_note(MI_F);
        uint8_t five = midi_compute_note(MI_A);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_E_MIN:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_E);
        uint8_t three = midi_compute_note(MI_G);
        uint8_t five = midi_compute_note(MI_B);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_F_MAJ:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_F);
        uint8_t three = midi_compute_note(MI_A);
        uint8_t five = midi_compute_note(MI_C_1);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_G_MAJ:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_G);
        uint8_t three = midi_compute_note(MI_B);
        uint8_t five = midi_compute_note(MI_D_1);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_A_MIN:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_A);
        uint8_t three = midi_compute_note(MI_C);
        uint8_t five = midi_compute_note(MI_E);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
        }
      }
      return false;
    case CO_B_DIM:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_B);
        uint8_t three = midi_compute_note(MI_D_1);
        uint8_t five = midi_compute_note(MI_F_1);
        uint8_t seven = midi_compute_note(MI_A_1);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
          midi_send_noteon(&midi_device, channel, seven, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
          midi_send_noteoff(&midi_device, channel, seven, 96);
        }
      }
      return false;
    case CO_E_7:
      {
        uint8_t channel = midi_config.channel;
        uint8_t root = midi_compute_note(MI_E);
        uint8_t three = midi_compute_note(MI_Gs);
        uint8_t five = midi_compute_note(MI_B);
        uint8_t seven = midi_compute_note(MI_D_1);
        if (record->event.pressed) {
          midi_send_noteon(&midi_device, channel, root, 96);
          midi_send_noteon(&midi_device, channel, three, 96);
          midi_send_noteon(&midi_device, channel, five, 96);
          midi_send_noteon(&midi_device, channel, seven, 96);
        } else {
          midi_send_noteoff(&midi_device, channel, root, 96);
          midi_send_noteoff(&midi_device, channel, three, 96);
          midi_send_noteoff(&midi_device, channel, five, 96);
          midi_send_noteoff(&midi_device, channel, seven, 96);
        }
      }
      return false;
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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

