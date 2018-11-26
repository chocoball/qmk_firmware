#include "lily58.h"

<<<<<<< HEAD
/*
#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    led_set_user(usb_led);
}
#endif
*/

=======
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);

	matrix_init_user();
<<<<<<< HEAD
};

=======
};
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
