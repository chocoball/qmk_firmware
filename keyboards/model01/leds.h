/* Copyright 2018 James Laird-Wah
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
#pragma once

#include <quantum.h>
<<<<<<< HEAD

int set_all_leds_to(uint8_t r, uint8_t g, uint8_t b);
int set_led_to(uint8_t led, uint8_t r, uint8_t g, uint8_t b);

/* Raw (gamma uncorrected) LED values */
int set_all_leds_to_raw(uint8_t r, uint8_t g, uint8_t b);
int set_led_to_raw(uint8_t led, uint8_t r, uint8_t g, uint8_t b);
=======
#include <rgb_matrix.h>

void set_all_leds_to(uint8_t r, uint8_t g, uint8_t b);
void set_led_to(int led, uint8_t r, uint8_t g, uint8_t b);
>>>>>>> 834b555eca47392ec0bf367b7f20694919d79a00
