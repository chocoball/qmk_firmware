#include <stdint.h>
#include "joystick.h"

static uint8_t mouseButtons = 0;

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

void reset_mouse(void)
{

}
