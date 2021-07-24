#include QMK_KEYBOARD_H
#include "oled_handler.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _FFXIV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_EQL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLASH, \
  KC_LCTRL, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LWIN,TT(_LOWER), KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_LALT, MO(_RAISE) \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */


//this is the layout used when the left modifier is down
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12,\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,  KC_8,  KC_9,   XXXXXXX, XXXXXXX, \
  KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_4,  KC_5,  KC_6,   XXXXXXX, XXXXXXX, \
  KC_CLCK, KC_LANG4, KC_LANG3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,  KC_2,  KC_3,   XXXXXXX, KC_RSFT, \
                        TG(_FFXIV), XXXXXXX, KC_BSPC, KC_DEL,          XXXXXXX,  KC_0, KC_LALT, XXXXXXX\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

//this is the layer activated by the right half of the board
[_RAISE] = LAYOUT( \
  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, \
  KC_GRV,   XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, \
  KC_LCTRL, XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RIGHT, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, \
  KC_LSFT,  KC_LANG4, KC_LANG3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_RSFT, \
                          KC_LWIN,  XXXXXXX,  KC_BSPC,  KC_DEL,             XXXXXXX,  XXXXXXX,  KC_LALT,  XXXXXXX \
),
[_FFXIV] = LAYOUT( \
 KC_F5,   KC_F1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, \
 KC_F6,   KC_F2,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLASH, \
 KC_F7,   KC_F3,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT, \
 KC_F8,   KC_F4,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  TG(_FFXIV),  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                       KC_J,KC_LCTRL, KC_LSFT, KC_LALT, KC_ENT, KC_SPC, KC_LALT, XXXXXXX \
)
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  //return rotation;
  return OLED_ROTATION_270;
}

// If you want to change the display of OLED, you need to change here
void oled_task_user(void) {
  update_oled();
}
#endif // OLED_DRIVER_ENABLE
