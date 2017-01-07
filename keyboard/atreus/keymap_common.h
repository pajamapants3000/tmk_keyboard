/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_code.h"
#include "action_layer.h"
#include "action_macro.h"
#include "action_util.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "bootloader.h"

#include "config.h"

#define KC_SHIFT(key) (ACT_MODS << 12 | ((MOD_LSFT << 8) | (KC_##key)))
#define KC_CTRL(key) (ACT_MODS << 12 | ((MOD_RCTL << 8) | (KC_##key)))
#define KC_ALT(key) (ACT_MODS << 12 | ((MOD_LALT << 8) | (KC_##key)))
#define KC_RALT(key) (ACT_MODS << 12 | ((MOD_RALT << 8) | (KC_##key)))
#define KC_GUI(key) (ACT_MODS << 12 | ((MOD_LGUI << 8) | (KC_##key)))

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const action_t fn_actions[];

#define KEYMAP_PCBDOWN( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,             \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,             \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,        \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A         \
) {                                                             \
  { KC_##K09, KC_##K08, KC_##K07, KC_##K06, KC_##K05, KC_NO,    \
      KC_##K04, KC_##K03, KC_##K02, KC_##K01, KC_##K00 },       \
  { KC_##K19, KC_##K18, KC_##K17, KC_##K16, KC_##K15, KC_NO,    \
      KC_##K14, KC_##K13, KC_##K12, KC_##K11, KC_##K10 },       \
  { KC_##K29, KC_##K28, KC_##K27, KC_##K26, KC_##K25, KC_##K35, \
      KC_##K24, KC_##K23, KC_##K22, KC_##K21, KC_##K20 },       \
  { KC_##K3A, KC_##K39, KC_##K38, KC_##K37, KC_##K36, KC_##K34, \
      KC_##K33, KC_##K32, KC_##K31, KC_##K30, KC_##K2A }        \
}

#define KEYMAP_PCBUP( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,             \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,             \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,        \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A         \
) {                                                             \
  { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_NO,    \
      KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09 },       \
  { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_NO,    \
      KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19 },       \
  { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K34, \
      KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29 },       \
  { KC_##K2A, KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K35, \
      KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A }        \
}

#ifdef PCBDOWN
#define KEYMAP KEYMAP_PCBDOWN
#else
#define KEYMAP KEYMAP_PCBUP
#endif

/* Default Atreus Layout */
#define ALPHA_LAYER KEYMAP(                     \
        Q, W, E, R, T, Y, U, I, O, P,           \
        A, S, D, F, G, H, J, K, L, SCLN,        \
        Z, X, C, V, B, N, M, COMM, DOT, SLSH,   \
        ESC, TAB, LGUI, LSFT, BSPC, LCTL, LALT, \
        SPC, FN0, MINS, QUOT, ENT,              \
    )

#define FN_LAYER KEYMAP(                                            \
        SHIFT(1), SHIFT(2), SHIFT(LBRC), SHIFT(RBRC), SHIFT(BSLS),  \
            PGUP, 7, 8, 9, SHIFT(8),                                \
        SHIFT(3), SHIFT(4), SHIFT(9), SHIFT(0), GRAVE,              \
            PGDN, 4, 5, 6, SHIFT(EQUAL),                            \
        SHIFT(5), SHIFT(6), LBRC, RBRC, SHIFT(GRAVE),               \
            SHIFT(7), 1, 2, 3, BSLS,                                \
        FN1, SHIFT(INS), LGUI, LSFT, BSPC, LCTL, LALT,              \
            SPC, FN0, DOT, 0, EQUAL                                 \
        )

/*
 *  !    @     up     {    }        ||     pgup    7     8     9    *
 *  #  left   down  right  $        ||     pgdn    4     5     6    +
 *  [    ]      (     )    &        ||       `     1     2     3    \
 * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
 */
#define FN_ARROW_LAYER KEYMAP(                              \
        SHIFT(1), SHIFT(2), UP, SHIFT(LBRC), SHIFT(RBRC),   \
            PGUP, 7, 8, 9, SHIFT(8),                        \
        SHIFT(3), LEFT, DOWN, RIGHT, SHIFT(4),              \
            PGDN, 4, 5, 6, SHIFT(EQUAL),                    \
        LBRC, RBRC, SHIFT(9), SHIFT(0), SHIFT(7),           \
            GRV, 1, 2, 3, BSLS,                             \
        FN1, SHIFT(INS), LGUI, LSFT, BSPC, LCTL,            \
            LALT, SPC, FN0, DOT, 0, EQUAL                   \
        )

/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 * mouse volup             reset      ||             F1    F2    F3   F12
 *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
 */
#define LAYER_TWO KEYMAP(                           \
        INS, HOME, UP, END, PGUP,                   \
            UP, F7, F8, F9, F10,                    \
        DEL, LEFT, DOWN, RIGHT, PGDN,               \
            DOWN, F4, F5, F6, F11,                  \
        NO, _VOLUP, NO, NO, FN3,                    \
            NO, F1, F2, F3, F12,                    \
        NO, _VOLDOWN, LGUI, LSFT, BSPC, LCTL,       \
            LALT, SPC, FN2, PSCREEN, SLCK, PAUSE    \
        )

enum function_id {
  BOOTLOADER,
};

void bootloader(void);

#endif
