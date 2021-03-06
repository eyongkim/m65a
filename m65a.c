/* Copyright 2018 Eyong Kim <eyongkim@gmail.com>
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
#include "m65a.h"

/**
 * @brief   put your keyboard start-up code here
 *          runs once when the firmware starts up
 */
void matrix_init_kb(void)
{
    matrix_init_user();
}

/**
 * @brief   put your looping keyboard code here
 *          runs every cycle (a lot)
 */
void matrix_scan_kb(void)
{
    matrix_scan_user();
}

/**
 * @brief   put your per-action keyboard code here
 *          runs for every action, just before processing by the firmware
 */
bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    return process_record_user(keycode, record);
}

/**
 * @brief   put your keyboard LED indicator toggling code here
 *          (e.g., Caps Lock LED)
 */
void led_set_kb(uint8_t usb_led)
{
    led_set_user(usb_led);
}
