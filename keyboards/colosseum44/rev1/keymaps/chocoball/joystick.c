#include <stdint.h>
#include <stdlib.h>
#include "joystick.h"

#define REVERSE_Y

typedef struct {
  int16_t x, y;
} IVECTOR2;
typedef struct {
  float x, y;
} VECTOR2;

// 移動開始までの遊び
static const int MOUSE_MOVE_THRESHOLD = 32;

static uint8_t mouseButtons = 0;
static VECTOR2 mouseMove = { 0, 0 };
static IVECTOR2 mouseCenter = { 512, 512 };
static IVECTOR2 mouseLastAxises = { 0, 0 };

void mouse_button_on(uint8_t flag)
{
  mouseButtons |= flag;
}

void mouse_button_off(uint8_t flag)
{
  mouseButtons &= ~flag;
}

uint8_t get_mouse_button(void)
{
  return mouseButtons;
}

void mouse_reset(void)
{
  mouseCenter = mouseLastAxises;
}

void set_move(float *mov, int16_t sub)
{
  if (abs(sub) >= MOUSE_MOVE_THRESHOLD)
  {
    *mov = sub * 0.05f;
  }
  else
  {
    *mov = 0;
  }
}

void mouse_update(int16_t x, int16_t y)
{
  int16_t sub_x, sub_y;

  sub_x = x - mouseCenter.x;
#ifdef REVERSE_Y
  sub_y = mouseCenter.y - y;
#else
  sub_y = y - mouseCenter.y;
#endif

  set_move(&mouseMove.x, sub_x);
  set_move(&mouseMove.y, sub_y);

  mouseLastAxises.x = x;
  mouseLastAxises.y = y;
}

int16_t mouse_x(void)
{
  return (int16_t)mouseMove.x;
}

int16_t mouse_y(void)
{
  return (int16_t)mouseMove.y;
}
