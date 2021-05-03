#pragma once

#include QMK_KEYBOARD_H

static const char PROGMEM trainer[128]={0x00,0x00,0x00,0x00,0xc0,0xc0,0xf0,0xf0,0x0c,0x0c,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xcc,0xcc,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x3c,0x3c,0xfc,0xfc,0xf0,0xf0,0x30,0x30,0x30,0x30,0xfc,0xfc,0x0c,0x0c,0x0c,0x0c,0xfc,0xfc,0x0f,0x0f,0xff,0xff,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xf0,0x0f,0x0f,0x0c,0x0c,0xfc,0xfc,0xf0,0xf0,0xf0,0xf0,0x30,0x30,0xf0,0xf0,0x0c,0x0c,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x0c,0x0c,0x3c,0x3c,0xcf,0xcf,0xf0,0xf0,0xf0,0xf0,0xcf,0xcf,0xcc,0xcc,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
static const char PROGMEM trainer2[128]={0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xc0,0x30,0x30,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x30,0x30,0xc0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0xf3,0xf3,0xf3,0xf3,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xf0,0xf0,0x30,0x30,0x30,0x30,0xf0,0xf0,0x3f,0x3f,0xff,0xff,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc3,0xc3,0x3f,0x3f,0xf0,0xf0,0xf0,0xf0,0x03,0x03,0xc0,0xc0,0xc0,0xc0,0xc3,0xc3,0x30,0x30,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x3c,0xc3,0xc3,0xcf,0xcf,0x30,0x30,0x30,0x30,0x0f,0x0f,0x30,0x30,0xfc,0xfc,0xcf,0xcf,0xc3,0xc3,0x33,0x33,0x0c,0x0c,0x00,0x00,0x00,0x00,};

uint32_t millisecondsSinceLastFrameChange = 0;
uint32_t frameDuration = 200;
const char *spriteToDraw = trainer;
int current_wpm = 0;
void animationTick(void){
    current_wpm = get_current_wpm();
    //if the elapsed time is greater than the frame duration
    if (timer_elapsed32(millisecondsSinceLastFrameChange) > frameDuration){
      //set timer to the current time
      millisecondsSinceLastFrameChange = timer_read32();
      //change frames. if spriteToDraw is frame 1, switch it to frame2.
      if (spriteToDraw == trainer) spriteToDraw = trainer2;
      //else if it's frame 2, switch it to frame 1
      else spriteToDraw = trainer;
    }
    oled_set_cursor(0, 6);
    oled_write_raw_P(spriteToDraw, 128);
}

