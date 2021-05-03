#include QMK_KEYBOARD_H
#include "animator.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
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
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_EQL, \
  KC_LCTRL, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LWIN, MO(_LOWER), KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_LALT, MO(_RAISE) \
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
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_7,   KC_8,   KC_9,  KC_F11,  KC_BSLASH, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_4, KC_5, KC_6, KC_RPRN, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_1, KC_2, KC_3, KC_RCBR, KC_RSFT, \
                             _______, _______, _______, _______, _______,  KC_0, _______, _______\
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
  _______, KC_F1, KC_F2, KC_F3, KC_F4, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_UP,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_LCTRL,  KC_F2,    KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_F6,              XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  KC_CLCK,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_HOME, KC_END,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             KC_LWIN, _______, KC_BSPC,  _______, _______,  _______, KC_LALT, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



static const char PROGMEM trainer[128]={0x00,0x00,0x00,0x00,0xc0,0xc0,0xf0,0xf0,0x0c,0x0c,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xcc,0xcc,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x3c,0x3c,0xfc,0xfc,0xf0,0xf0,0x30,0x30,0x30,0x30,0xfc,0xfc,0x0c,0x0c,0x0c,0x0c,0xfc,0xfc,0x0f,0x0f,0xff,0xff,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xf0,0x0f,0x0f,0x0c,0x0c,0xfc,0xfc,0xf0,0xf0,0xf0,0xf0,0x30,0x30,0xf0,0xf0,0x0c,0x0c,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x0c,0x0c,0x3c,0x3c,0xcf,0xcf,0xf0,0xf0,0xf0,0xf0,0xcf,0xcf,0xcc,0xcc,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
static const char PROGMEM trainer2[128]={0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,0x30,0x30,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x30,0x30,0xc0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0xf3,0xf3,0xf3,0xf3,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xf0,0xf0,0x30,0x30,0x30,0x30,0xf0,0xf0,0x3f,0x3f,0xff,0xff,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc3,0xc3,0x3f,0x3f,0xf0,0xf0,0xf0,0xf0,0x03,0x03,0xc0,0xc0,0xc0,0xc0,0xc3,0xc3,0x30,0x30,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x3c,0xc3,0xc3,0xcf,0xcf,0x30,0x30,0x30,0x30,0x0f,0x0f,0x30,0x30,0xfc,0xfc,0xcf,0xcf,0xc3,0xc3,0x33,0x33,0x0c,0x0c,0x00,0x00,0x00,0x00,};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  //return rotation;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
const char *message;
const char *spriteToDraw = trainer;

uint32_t frameDuration = 250;
void oled_task_user(void) {
  if (is_keyboard_master()) {
    animationTick();
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);  
    message = "";
    oled_write_ln(message, false);
    oled_write_ln(message, false);
    oled_write_ln(message, false);

    //if the elapsed time is greater than the frame duration
    if (timer_elapsed32(millisecondsSinceLastFrameChange) > frameDuration){
      //set timer to the current time
      millisecondsSinceLastFrameChange = timer_read32();
      //change frames. if spriteToDraw is frame 1, switch it to frame2.
      if (spriteToDraw == trainer) spriteToDraw = trainer2;
      //else if it's frame 2, switch it to frame 1
      else spriteToDraw = trainer;
    }
    //message = trainer;
    oled_write_raw_P(spriteToDraw, 128);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false); 
    //these were originally commented out
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
    oled_scroll_left();
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
