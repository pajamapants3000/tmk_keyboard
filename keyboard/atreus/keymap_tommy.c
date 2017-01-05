#include "keymap_common.h"

enum my_func_ids {
    MOUSE_ACCEL_CYCLE = 2,
};

#define MOUSE_ACCEL_LVLS 3

/* ALL Action keys! Including Mouse, Media (except vol), and WWW keys
 * This is what we get instead of what we want (same for all! note that
 * we are getting caps lock, but I have LCtrl <-> caps lock; I tried removing
 * that setting, and while the keys still didn't work, they registered
 * LCtrl and LShift instead of Caps and shift)
KeyPress event, serial 44, synthetic NO, window 0x7200001,
    root 0x1e1, subw 0x7200002, time 35604860, (54,43), root:(1976,768),
    state 0x12, keycode 37 (keysym 0xffe5, Caps_Lock), same_screen YES,
    XLookupString gives 0 bytes: 
    XmbLookupString gives 0 bytes: 
    XFilterEvent returns: False

KeyPress event, serial 44, synthetic NO, window 0x7200001,
    root 0x1e1, subw 0x7200002, time 35604860, (54,43), root:(1976,768),
    state 0x12, keycode 50 (keysym 0xffe1, Shift_L), same_screen YES,
    XLookupString gives 0 bytes: 
    XmbLookupString gives 0 bytes: 
    XFilterEvent returns: False
*/

/* Menu key
KeyPress event, serial 41, synthetic NO, window 0x7200001,
    root 0x1e1, subw 0x0, time 35963588, (903,-383), root:(2825,342),
    state 0x10, keycode 138 (keysym 0x1005ff70, SunProps), same_screen YES,
    XLookupString gives 0 bytes: 
    XmbLookupString gives 0 bytes: 
    XFilterEvent returns: False

KeyRelease event, serial 41, synthetic NO, window 0x7200001,
    root 0x1e1, subw 0x0, time 35963664, (903,-383), root:(2825,342),
    state 0x10, keycode 138 (keysym 0x1005ff70, SunProps), same_screen YES,
    XLookupString gives 0 bytes: 
    XFilterEvent returns: False
*/

/*
 * Customized ATREUS Layout
 * Layer 1: Similar to default, but with super and alt keys switched
 * Layer 2: Puncutation and numbers, some small changes to default
 * Layer 3: Arrows, F-keys and other function keys; macros?
 * Layer 4: Mouse keys, Media keys; more macros?
 */

/*              Define layouts              */

// Main/Alpahet Layout - Same as default but with super <-> alt
// K*L0
// http://www.keyboard-layout-editor.com/#/gists/8ef00a0e901ad4ade2606f169a1c20de
#define LAYER_ALPHA KEYMAP(                                                 \
/* R1 */KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,         \
/* R2 */KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,      \
/* R3 */KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
/* R4 */KC_ESC, KC_TAB, KC_LALT, KC_LSFT, KC_BSPC, KC_LGUI, KC_RCTL,        \
                KC_SPC, KC_FN1, KC_MINS, KC_QUOT, KC_ENT                    )

// Function-Layer Layout (Punctuation, numbers, arrows)
// K1L1
// http://www.keyboard-layout-editor.com/#/gists/aa83cdcb86b63a1f9f24780b04031ce8
#define LAYER_PUCT_NUM KEYMAP(                                              \
/* LH */SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_3),    \
/* RH */SHIFT(KC_4), KC_7, KC_8, KC_9, SHIFT(KC_8),                         \
/* LH */SHIFT(KC_BSLS), SHIFT(KC_5), SHIFT(KC_LBRC), SHIFT(KC_RBRC),        \
                SHIFT(KC_6),                                                \
/* RH */KC_MINUS, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),                        \
/* LH */KC_GRAVE, SHIFT(KC_GRAVE), KC_LBRC, KC_RBRC, SHIFT(KC_7),           \
/* RH */KC_COMMA, KC_1, KC_2, KC_3, KC_BSLS,                                \
/* LH */KC_FN0, KC_FN4, KC_LALT, KC_LSFT, KC_BSPC, KC_RCTL,                 \
/* RH */KC_LGUI, KC_SPC, KC_TRNS, KC_0, KC_DOT, KC_EQUAL                    )

// Function-Layer Layout - Take 2 (Punctuation and Symbols, Numpad, Arrows)
// K2L1
// http://www.keyboard-layout-editor.com/#/gists/5b3c6a88994b20673fe8b1e95c07a87a
#define LAYER_NUM_FKEY KEYMAP(                              \
/* LH */KC_F10, KC_F7, KC_F8, KC_F9, KC_HOME,               \
/* RH */KC_END, KC_7, KC_8, KC_9, KC_0,                     \
/* LH */KC_F11, KC_F4, KC_F5, KC_F6, KC_INS,                \
/* RH */KC_PGUP, KC_4, KC_5, KC_6, KC_LBRC,                 \
/* LH */KC_F12, KC_F1, KC_F2, KC_F3, KC_DELETE,             \
/* RH */KC_PGDN, KC_1, KC_2, KC_3, KC_RBRC,                 \
/* LH */KC_GRV, KC_FN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
/* RH */KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_EQL, KC_TRNS )

// "Layer 2" - Persistent/Locking Layout - Arrow Keys, Special/Fn
// K1L2
// http://www.keyboard-layout-editor.com/#/gists/7fb4916e338828e4f12ca2f9f4e87262
#define LAYER_ARROW_FN KEYMAP(                              \
/* LH */KC_F10, KC_F7, KC_F8, KC_F9, KC_HOME,               \
/* RH */KC_END, KC_UNDO, KC_UP, KC_FN26, KC_CALC,           \
/* LH */KC_F11, KC_F4, KC_F5, KC_F6, KC_INS,                \
/* RH */KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MYCM,       \
/* LH */KC_F12, KC_F1, KC_F2, KC_F3, KC_DELETE,             \
/* RH */KC_PGDN, KC_CUT, KC_COPY, KC_PASTE, KC_MAIL,        \
/* LH */KC_NO, KC_NO, KC_LALT, KC_LSFT, KC_BSPC, KC_RCTL,   \
/* RH */KC_LGUI, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_PSCR      ) // two available special keys

// "Layer 3" - Persistent/Locking Layout - Mouse Keys, Media/WWW Keys
// K1L3, K2L2
// http://www.keyboard-layout-editor.com/#/gists/0df144f05f028850b3cc37c750543e0f
// missing RH row 3 is mouse accel togl
#define LAYER_ARROW_MEDIA KEYMAP(                           \
/* LH */KC__VOLUP, KC_FN22, KC_MSEL, KC_FN23, KC_WHOM,      \
/* RH */KC_WSCH, KC_UNDO, KC_UP, KC_FN26, KC_MYCM,          \
/* LH */KC__VOLDOWN, KC_MPRV, KC_MPLY, KC_MNXT, KC_WBAK,    \
/* RH */KC_WFWD, KC_LEFT, KC_DOWN, KC_RIGHT, KC_CALC,       \
/* LH */KC__MUTE, KC_FN24, KC_MSTP, KC_FN25, KC_WSTP,       \
/* RH */KC_WREF, KC_CUT, KC_COPY, KC_PASTE, KC_MAIL,        \
/* LH */KC_FN5, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
/* RH */KC_TRNS, KC_TRNS, KC_FN4, KC_APP, KC_FN0, KC_PSCR   )

// "Layer 3" - Take 2 - Mouse-Keys (doesn't work!)
// K2L3
// www.keyboard-layout-editor.com/#/gists/c4d0e2ca81c7300fd4c9751759247d59
#define LAYER_MOUSE KEYMAP(                                     \
/* LH */KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            \
/* RH */KC_TRNS, KC_FN14, KC_FN6, KC_FN15, KC_FN10,             \
/* LH */KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            \
/* RH */KC_TRNS, KC_FN8, KC_FN7, KC_FN9, KC_FN11,               \
/* LH */KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            \
/* RH */KC_TRNS, KC_FN17, KC_FN16, KC_FN18, KC_FN27,            \
/* LH */KC_TRNS, KC_FN0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    \
/* RH */KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_FN12, KC_FN13     )


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: mostly letters */
    LAYER_ALPHA,        \
    /* 1: punctuation, arrows, and numbers */
    LAYER_NUM_FKEY,     \
    /* 2: mouse, media */
    LAYER_ARROW_MEDIA,  \
    /* 3: F-keys */
    LAYER_MOUSE
};

const action_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(BOOTLOADER), // reset for uploading new code
  [1] = ACTION_LAYER_MOMENTARY(1),   // Hold for L1
  [2] = ACTION_LAYER_TOGGLE(1),    // tap to toggle L1
  [3] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [4] = ACTION_LAYER_CLEAR(1),  // switch back to layer 0
  [5] = ACTION_LAYER_MOMENTARY(3),    // Hold for Mouse-keys
  [6] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [7] = ACTION_MOUSEKEY(KC_MS_D),
  [8] = ACTION_MOUSEKEY(KC_MS_L),
  [9] = ACTION_MOUSEKEY(KC_MS_R),
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_WH_D),
  [12] = ACTION_MOUSEKEY(KC_WH_L),
  [13] = ACTION_MOUSEKEY(KC_WH_R),
  [14] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [15] = ACTION_MOUSEKEY(KC_BTN2),
  [16] = ACTION_MOUSEKEY(KC_BTN3),
  [17] = ACTION_MOUSEKEY(KC_BTN4),
  [18] = ACTION_MOUSEKEY(KC_BTN5),
  [19] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [20] = ACTION_MOUSEKEY(KC_ACL1),
  [21] = ACTION_MOUSEKEY(KC_ACL2),
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_LEFT),
  [23] = ACTION_MODS_KEY(MOD_LSFT, KC_RIGHT),
  [24] = ACTION_MODS_KEY(MOD_RCTL, KC_LEFT),
  [25] = ACTION_MODS_KEY(MOD_RCTL, KC_RIGHT),
  [26] = ACTION_MODS_KEY(MOD_RCTL, KC_Y),
  [27] = ACTION_FUNCTION(MOUSE_ACCEL_CYCLE),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static int8_t mouse_accel_lvl = 0;
    static int8_t tgl_tst_val = 0;

    switch ( id )
    {
        case BOOTLOADER:
            bootloader();
            break;
        case MOUSE_ACCEL_CYCLE:
            if (record->event.pressed)
            {
                add_key(KC_ACL0 + mouse_accel_lvl);
                send_keyboard_report();
            }
            else
            {
                del_key(KC_ACL0 + mouse_accel_lvl);
                send_keyboard_report();
                mouse_accel_lvl = ( mouse_accel_lvl + 1 ) % MOUSE_ACCEL_LVLS;
            }
            break;
    }
}

