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

// layers definition
enum
{
    _BL = 0,    // Base layer
    _FL,        // Function layer
    _CL         // Control layer
};

// macros definition
#define ____    KC_TRNS
#define XXXX    KC_NO

// keymaps definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    // Base Layer
    // +---------------------------------------------------------------+
    // |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bspc   |Del|
    // |---------------------------------------------------------------|
    // |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|PgU|
    // |---------------------------------------------------------------|
    // |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |PgD|
    // |---------------------------------------------------------------|
    // |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |Fn |
    // |---------------------------------------------------------------|
    // |Ctrl|Gui |Alt | Space                  |Alt  |Ctrl |Lft|Dwn|Rgt|
    // +---------------------------------------------------------------+
    //
    [_BL] = LAYOUT
    (
        KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, XXXX,   KC_BSPC,KC_DEL,
        KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,KC_PGUP,
        KC_CAPS,        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,         KC_PGDN,
        KC_LSFT,XXXX,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,KC_UP,  MO(_FL),
        KC_LCTL,KC_LGUI,        KC_LALT,KC_SPC,         KC_SPC,         KC_SPC,         KC_RALT,XXXX   ,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    ),

    // Function Layer
    // +---------------------------------------------------------------+
    // |ToC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |Ins|
    // |---------------------------------------------------------------|
    // |     |   |Wak|   |   |   |   |   |   |   |   |   |   |     |Hme|
    // |---------------------------------------------------------------|
    // |      |   |Slp|   |   |   |   |   |   |   |   |   |        |End|
    // |---------------------------------------------------------------|
    // |        |   |   |   |   |   |   |   |   |   |   |      |VUp|   |
    // |---------------------------------------------------------------|
    // |    |    |    |                        |     |     |WBk|VDn|WFd|
    // +---------------------------------------------------------------+
    //
    [_FL] = LAYOUT
    (
        TG(_CL),KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, ____,   ____,   KC_INS,
        ____,   ____,   KC_WAKE,____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,           ____,   KC_HOME,
        ____,   ____,   KC_SLEP,____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,                   ____,   KC_END,
        ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,   ____,           ____,   KC_VOLU,____,
        ____,   ____,   ____,           ____,           ____,           ____,           ____,   ____,   ____,   KC_WBAK,KC_VOLD,KC_WFWD
    ),

    // Control Layer
    // +---------------------------------------------------------------+
    // |ToB|   |   |   |   |   |   |   |   |   |   |   |   |       |Rst|
    // |---------------------------------------------------------------|
    // |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
    // |---------------------------------------------------------------|
    // |      |   |S+ |   |V+ |   |H+ |   |   |   |   |   |        |   |
    // |---------------------------------------------------------------|
    // |        |   |S- |   |V- |   |H- |   |   |   |   |      |   |   |
    // |---------------------------------------------------------------|
    // |    |    |    | Toggle                 |     |     |M- |   |M+ |
    // +---------------------------------------------------------------+
    //
    [_CL] = LAYOUT
    (
        TO(_BL),XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   RESET,
        XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,   XXXX,           XXXX,   XXXX,
        XXXX,   XXXX,   RGB_SAI,XXXX,   RGB_VAI,XXXX,   RGB_HUI,XXXX,   XXXX,   XXXX,   XXXX,   XXXX,                   XXXX,   XXXX,
        XXXX,   XXXX,   XXXX,   RGB_SAD,XXXX,   RGB_VAD,XXXX,   RGB_HUD,XXXX,   XXXX,   XXXX,   XXXX,           XXXX,   XXXX,   XXXX,
        XXXX,   XXXX,   XXXX,           XXXX,           RGB_TOG,        XXXX,           XXXX,   XXXX,   XXXX,   RGB_RMOD,XXXX,  RGB_MOD
    )
};
