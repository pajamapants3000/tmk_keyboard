#include "keymap_common.h"

enum my_func_ids {
    MOUSE_ACCEL_CYCLE = 2,
    SMART_LOCK,
};

enum lock_keys {
    SHIFT_LOCK,
    CTRL_LOCK,
    ALT_LOCK,
    GUI_LOCK,
    FN_LOCK,
    L2_LOCK,
    L3_LOCK,
    L4_LOCK,
};


#define MOUSE_ACCEL_LVLS 3
const uint16_t mouse_accel_keys[ MOUSE_ACCEL_LVLS ] = {
    KC_ACL0,
    KC_ACL1,
    KC_ACL2
};

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
// http://www.keyboard-layout-editor.com/#/gists/8ef00a0e901ad4ade2606f169a1c20de
#define LAYER_ALPHA KEYMAP(                     \
/* R1 */Q, W, E, R, T, Y, U, I, O, P,           \
/* R2 */A, S, D, F, G, H, J, K, L, SCLN,        \
/* R3 */Z, X, C, V, B, N, M, COMM, DOT, SLSH,   \
/* R4 */ESC, TAB, LALT, LSFT, BSPC, LGUI, RCTL, \
                SPC, FN1, MINS, QUOT, ENT       )

// Function-Layer Layout - Punctuation and Symbols, Numpad
// http://www.keyboard-layout-editor.com/#/gists/5b3c6a88994b20673fe8b1e95c07a87a
#define LAYER_NUM_FKEY KEYMAP(              \
/* LH */F10, F7, F8, F9, HOME,              \
/* RH */END, 7, 8, 9, 0,                    \
/* LH */F11, F4, F5, F6, INS,               \
/* RH */PGUP, 4, 5, 6, LBRC,                \
/* LH */F12, F1, F2, F3, DELETE,            \
/* RH */PGDN, 1, 2, 3, RBRC,                \
/* LH */GRV, FN2, TRNS, TRNS, TRNS, TRNS,   \
/* RH */TRNS, TRNS, TRNS, BSLS, EQL, TRNS   )

// "Layer 3" - Persistent/Locking Layout - Arrow, Media/WWW Keys
// http://www.keyboard-layout-editor.com/#/gists/0df144f05f028850b3cc37c750543e0f
#define LAYER_ARROW_MEDIA KEYMAP(                   \
/* LH */_VOLUP, MRWD, MSEL, MFFD, WHOM,             \
/* RH */WSCH, UNDO, UP, CTRL(Y), MYCM,              \
/* LH */_VOLDOWN, MPRV, MPLY, MNXT, WBAK,           \
/* RH */WFWD, LEFT, DOWN, RIGHT, CALC,              \
/* LH */_MUTE, CTRL(LEFT), MSTP, CTRL(RIGHT), WSTP, \
/* RH */WREF, CUT, COPY, PASTE, MAIL,               \
/* LH */FN3, NO, TRNS, TRNS, TRNS, TRNS,            \
/* RH */TRNS, TRNS, FN5, APP, FN0, TRNS             )

// "Layer 3" - Mouse-Keys (doesn't work!)
// http://www.keyboard-layout-editor.com/#/gists/c4d0e2ca81c7300fd4c9751759247d59
#define LAYER_MOUSE KEYMAP(                 \
/* LH */TRNS, TRNS, TRNS, TRNS, TRNS,       \
/* RH */TRNS, BTN1, MS_U, BTN2, WH_U,       \
/* LH */TRNS, TRNS, TRNS, TRNS, TRNS,       \
/* RH */TRNS, MS_L, MS_D, MS_R, WH_D,       \
/* LH */TRNS, TRNS, TRNS, TRNS, TRNS,       \
/* RH */TRNS, BTN4, BTN3, BTN4, FN6,        \
/* LH */TRNS, FN0, TRNS, TRNS, TRNS, TRNS,  \
/* RH */TRNS, TRNS, TRNS, APP, WH_L, WH_R   )


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
  [0] = ACTION_FUNCTION(BOOTLOADER),            // reset for uploading new code
  [1] = ACTION_LAYER_MOMENTARY(1),              // Hold for L1
  [2] = ACTION_LAYER_ON(2, 1),                  // switch to layer 2
  [3] = ACTION_LAYER_MOMENTARY(3),              // Hold for Mouse-keys
  [4] = ACTION_LAYER_MOMENTARY(4),              // Reserved for layer 4
  [5] = ACTION_LAYER_CLEAR(1),                  // switch back to layer 0
  [6] = ACTION_FUNCTION(MOUSE_ACCEL_CYCLE),     // toggle mouse acceleration
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint8_t mouse_accel_lvl = 0;
    uint16_t key = 0;

    switch ( id )
    {
        case BOOTLOADER:
            bootloader();
            break;
        case MOUSE_ACCEL_CYCLE:
            if (record->event.pressed)
            {
                add_key( mouse_accel_keys[mouse_accel_lvl] );
                send_keyboard_report();
            }
            else
            {
                del_key( mouse_accel_keys[mouse_accel_lvl] );
                send_keyboard_report();
                mouse_accel_lvl = ( mouse_accel_lvl + 1 ) % MOUSE_ACCEL_LVLS;
            }
            break;
        // the idea here is to toggle on press, and toggle back IFF another
        // key was pressed in the meantime.
        // I need to find a way to detect when events occur WITHOUT having
        // to pass every single key through a handler.
        case SMART_LOCK:
            switch ( opt )
            {
                case SHIFT_LOCK:
                    key = KC_LSFT;
                    break;
                case CTRL_LOCK:
                    key = KC_RCTL;
                    break;
                case GUI_LOCK:
                    key = KC_LGUI;
                    break;
                case ALT_LOCK:
                    key = KC_LALT;
                    break;
                case FN_LOCK:
                    key = KC_FN1;
                    break;
                case L2_LOCK:
                    key = KC_FN2;
                    break;
                case L3_LOCK:
                    key = KC_FN3;
                    break;
                case L4_LOCK:
                    key = KC_FN4;
                    break;
            }
            if (record->event.pressed)
            {
                add_key( key  );
                send_keyboard_report();
            }
            else
            {
                del_key( key );
                send_keyboard_report();
            }
            break;
    }
}

