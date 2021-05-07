#include QMK_KEYBOARD_H
#include <stdio.h>

#include "animator.h"

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);

void update_oled(void){
  if (is_keyboard_master()) {
    //write layer state
    oled_write_ln(read_layer_state(), false);
    //write caps lock state
    oled_write("caps", host_keyboard_led_state().caps_lock);
    //show trainer animation
    animationTick();
    char wpm_str[8];
    sprintf(wpm_str, "%03d", current_wpm);
    oled_set_cursor(0, 12);
    char message[] = "wpm: ";
    oled_write_ln(message, false);
    oled_write_ln(wpm_str, false);
  } else {
    //draw lily logo and scroll
    oled_write(read_logo(), false);
    oled_scroll_left();
  }
}
