/* Copyright 2018 wanleg
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
#include QMK_KEYBOARD_H
#include "wanleg.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( /* Base */
TD(CAD_TD) \
),
<<<<<<< HEAD
};

void led_set_user(uint8_t usb_led) {

}
=======
[1] = LAYOUT( /*Secondary*/
TD(BSW_TAP_DANCE) \
),
};
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
