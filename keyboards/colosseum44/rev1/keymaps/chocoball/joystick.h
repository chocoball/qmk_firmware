#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <stdint.h>

enum MOUSEBUTTONS
{
  MOUSE_BUTTON1 = 0x01,
  MOUSE_BUTTON2 = 0x02,
};

void mouse_button_on(uint8_t flag);
void mouse_button_off(uint8_t flag);
uint8_t get_mouse_button(void);

void reset_mouse(void);

#endif  // JOYSTICK_H_
