#include QMK_KEYBOARD_H
<<<<<<< HEAD

enum marianas_layers {
  BASE,
  NAV_CLUSTER,
  RGB,
  MOUSE,
  GAMING,
  FN_LAYER,
  LAYER_SEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSPO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_LGUI, KC_NO, KC_APP, KC_RCTL),

  [NAV_CLUSTER]=
    LAYOUT(
      KC_TRNS, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_INSERT, KC_HOME, KC_PGUP, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_END, KC_PGDOWN, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_UP, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_TRNS, KC_TRNS, KC_TRNS),

  [RGB]=
    LAYOUT(
      KC_TRNS, RGB_TOG, RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_SPD, RGB_SPI, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [MOUSE]=
    LAYOUT(
      KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [GAMING]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSHIFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT, KC_NO,
      KC_LCTL, KC_NO, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RCTL, KC_NO, KC_NO, TO(BASE)),

  [FN_LAYER]=
    LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
      KC_CAPSLOCK, KC_MPRV, KC_MPLY, KC_MNXT, LWIN(KC_R), KC_TRNS, KC_CALC, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_SLCK, KC_BRK, KC_TRNS,
      KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS, KC_DEL, MO(LAYER_SEL),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HYPR, KC_TRNS, KC_MEH, KC_TRNS),

  [LAYER_SEL]=
    LAYOUT(
      TO(BASE), TO(NAV_CLUSTER), TO(RGB), TO(MOUSE), TO(GAMING), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

=======
#include "keymap.h"
#include "relativity.h"
#include "keyDefinitions.h"
#include "customLogic.h"

// planned change: store previous table names and abbreviations to allow scrolling for inner joins on table name+id and abbreviation+id.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY]=
    LAYOUT_60_ansi(
      ESCAP,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  MNUS,  EQUL,  BACKSPC,
      KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  LBRC,  RBRC,  BSLASH,
      FN_QT,    KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  COLN,  QUOT,  ENTER_OR_SQL,
      LEFTSHFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  CMMA,  PRRD,  SLSH,  RIGHT_SHIFT__PAREN,
      CTLL,  WINL,  ALTL,  SPAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACE,  ALTR,  WINR,  APPR,  CTLR),

  [NAV_CLUSTER]=
    LAYOUT_60_ansi(
      _____,  PSCR,  SCRL,  PAUS,  NSRT,  HOME,  PGUP,  NMLK,  KSSH,  STAR,  KMIN,  ____,  ____,  ______,
      ______,  ____,  ____,  ____,  DELT,  END_,  PGDN,  KP_7,  KP_8,  KP_9,  PLUS,  ____,  ____,  _____,
      _______,  ____,  ____,  ____,  ____,  UPUP,  UPUP,  KP_4,  KP_5,  KP_6,  PLUS,  ____,  ___________,
      ________,  ____,  ____,  ____,  LEFT,  D_WN,  RGHT,  KP_1,  KP_2,  KP_3,  KNTR,  _________________,
      ____,  ____,  ____,  /*-----------------*/KC_KP_0/*-----------------*/,  KDOT,  KNTR,  ____,  ____),

  [GAMING]=
    LAYOUT_60_ansi(
      _____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ______,
      ______,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  _____,
         KCNO,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ___________,
      ________,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  _________________,
      ____,  KCNO,  ____,  /*------------------*/_____/*------------------*/,  ____,  KCNO,  ____,  QWRTY),

  [SQLMACROS]=
    LAYOUT_60_ansi(
      S_ALTER, ____, ____, ____, ____, ____, ____, ____, S_ASTRK, ____, ____, ____, ____,    ___________,
      ______,    ____, S_WHERE, ____, ____, ____, ____, ____, S_INRJN, S_ORDER, ____, ____, ____, ______,
      _______, KC_LBRC, S_SLCT, S_ASTRK ,S_FROM, ____, ____, ____, ____, S_LFTJN, ____, RBRC, ___________,
      ________,  RGB_VAI, RGB_VAD, ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,  _________________,
      ____,  ____,  ____,  /*------------------*/_____/*------------------*/,  ____,  ____,  ____,  ____),

  [FN_LAYER]=
    LAYOUT_60_ansi(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
      KC_CAPSLOCK, KC_MPRV, KC_MPLY, KC_MNXT, LWIN(KC_R), ____, KC_CALC, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_SLCK, KC_BRK, ____,
      ____, KC_VOLD, KC_MUTE, KC_VOLU, ____, ____, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS, KC_DEL, ____,
      ____, RGB_HUI, RGB_SAI, RGB_SAD, ____,  ____, KC_END, QWRTY, GAME, NAVS, ____, ____,
      ____, ____, ____, _________________, ____, KC_HYPR, KC_MEH, RESET)
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
};
