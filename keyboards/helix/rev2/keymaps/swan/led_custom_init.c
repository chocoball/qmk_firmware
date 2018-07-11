#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
extern keymap_config_t keymap_config;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif
extern uint8_t is_master;

struct keybuf {
  char col, row;
  char frame;
};
struct keybuf keybufs[256];
unsigned char keybuf_begin, keybuf_end;

int col, row;

void led_custom_init(void) {
    static int scan_count = -10;
    if (scan_count == -1) {
      rgblight_enable_noeeprom();
      rgblight_mode(0);
    } else if (scan_count == 0) {
      static int keys[] = { 6, 6, 6, 7, 7 };
      unsigned char rgb[7][5][3] = { 0 };
      for (unsigned char c=keybuf_begin; c!=keybuf_end; c++) {
        int i = c;
        // FIXME:
        int color = (keybufs[i].row*3 + keybufs[i].col) % 7 + 1;
        char r = (color & 0x4) ? 1 : 0;
        char g = (color & 0x2) ? 1 : 0;
        char b = (color & 0x1) ? 1 : 0;

        for (int y=0; y<5; y++) {
          for (int x=0; x<keys[y]; x++) {
            int dist = abs(x - keybufs[i].col) + abs(y - keybufs[i].row);
            if (dist <= keybufs[i].frame) {
              int elevation = MAX(0, (8 + dist - keybufs[i].frame))<<2;
              if (elevation) {
                if (r) { rgb[x][y][0] = MIN(255, elevation + rgb[x][y][0]); }
                if (g) { rgb[x][y][1] = MIN(255, elevation + rgb[x][y][1]); }
                if (b) { rgb[x][y][2] = MIN(255, elevation + rgb[x][y][2]); }
              }
            }
          }
        }
        if (keybufs[i].frame < 18) {
          keybufs[i].frame ++;
        } else {
          keybuf_begin ++;
        }
      }
      for (int y=0; y<5; y++) {
        for (int x=0; x<keys[y]; x++) {
          int at = 0;
          for (int i=0; i<y; i++) {
            at += keys[i];
          }
          at += (y & 1) ? x : (keys[y] - x - 1);

          rgblight_setrgb_at(rgb[x][y][0], rgb[x][y][1], rgb[x][y][2], at);
        }
      }
    }
    scan_count++;
    if (scan_count >= 10) { scan_count = 0; }
}
