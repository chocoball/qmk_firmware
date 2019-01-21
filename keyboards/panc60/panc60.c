/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "panc60.h"
<<<<<<< HEAD

#include <avr/pgmspace.h>
=======
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

#include <avr/pgmspace.h>

>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
#include "action_layer.h"
#include "i2c.h"
#include "quantum.h"

__attribute__ ((weak))
void matrix_scan_user(void) {
}
<<<<<<< HEAD
=======

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;

void rgblight_set(void) {
    if (!rgblight_config.enable) {
        for (uint8_t i = 0; i < RGBLED_NUM; i++) {
            led[i].r = 0;
            led[i].g = 0;
            led[i].b = 0;
        }
    }

    i2c_init();
    i2c_send(0xb0, (uint8_t*)led, 3 * RGBLED_NUM);
}
#endif

void backlight_init_ports(void) {
	DDRD |= (1<<0 | 1<<1 | 1<<4 | 1<<6);
	PORTD &= ~(1<<0 | 1<<1 | 1<<4 | 1<<6);
}

void backlight_set(uint8_t level) {
	if (level == 0) {
		// Turn out the lights
		PORTD &= ~(1<<0 | 1<<1 | 1<<4 | 1<<6);
	} else {
		// Turn on the lights
		PORTD |= (1<<0 | 1<<1 | 1<<4 | 1<<6);
	}
}
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
