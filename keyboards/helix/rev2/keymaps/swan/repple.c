#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

struct keybuf {
  char col, row;
  char frame;
};
// key押したときに押したキーの行列を入れておく箱
struct keybuf keybufs[256];
// 過去256回分の履歴を配列に入れておく
unsigned char keybuf_begin, keybuf_end;
int col, row;
// 7列5行RGB(各座標のRGB値)入れとく3次元配列
unsigned char rgb[7][5][3];

void mod_repple(void) {
    // 各行のキーの数
    static int keys[] = { 6, 6, 6, 7, 7 };
    // キーの数の行数
    static int keys_sum[] = { 0, 6, 12, 18, 25 };
    // keyを押してからmatrix scan user(≒当該関数)の実行した数
    static int scan_count = -10;
    if (scan_count == -1) {
      // 初期化
      rgblight_enable_noeeprom();
      rgblight_mode(0);
    } else if (scan_count >= 0 && scan_count <= 4) {
      
      for (unsigned char c=keybuf_begin; c!=keybuf_end; c++) {
        int i = c;
        // FIXME:
        int color = (keybufs[i].row*3 + keybufs[i].col) % 7 + 1;
        char r = (color & 0x4) >> 2;
        char g = (color & 0x2) >> 1;
        char b = (color & 0x1);

        int y = scan_count;
        // 波の始点から終端までの距離
        int dist_y = abs(y - keybufs[i].row);
        // 左端から右端まで
        for (int x=0; x<keys[y]; x++) {
          //int at = keys_sum[y] + ((y & 1) ? x : (keys[y] - x - 1));
          // 波の始点から求める座標までの距離
          int dist = abs(x - keybufs[i].col) + dist_y;
          // 波の内側だったら
          if (dist <= keybufs[i].frame) {
            //窓関数的な？ ／￣＼
            int elevation = MAX(0, (8 + dist - keybufs[i].frame)) << 2;
            if (elevation) {
              if ((rgb[x][y][0] != 255) && r) { rgb[x][y][0] = MIN(255, elevation + rgb[x][y][0]); }
              if ((rgb[x][y][1] != 255) && g) { rgb[x][y][1] = MIN(255, elevation + rgb[x][y][1]); }
              if ((rgb[x][y][2] != 255) && b) { rgb[x][y][2] = MIN(255, elevation + rgb[x][y][2]); }
            }
          }
        }
      }
    } else if (scan_count == 5 ) {
      for (unsigned char c=keybuf_begin; c!=keybuf_end; c++) {
        int i = c;
        if (keybufs[i].frame < 18) {
          // 波の直径は18になるまでインクリメント
          keybufs[i].frame ++;
        } else {
          // 18になったkeybufは次回以降無視するためbeginをインクリメント
          keybuf_begin ++;
        }
      }
    } else if (scan_count >= 6 && scan_count <= 10) {
      int y = scan_count - 6;
      for (int x=0; x<keys[y]; x++) {
        int at = keys_sum[y] + ((y & 1) ? x : (keys[y] - x - 1));
        led[at].r = rgb[x][y][0];
        led[at].g = rgb[x][y][1];
        led[at].b = rgb[x][y][2];
      }
      rgblight_set();
    } else if (scan_count == 30) {
      memset(rgb, 0, sizeof(rgb));
    }
    scan_count++;
    if (scan_count >= 31) { scan_count = 0; }
}
