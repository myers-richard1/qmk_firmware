#pragma once

#include QMK_KEYBOARD_H

void animationTick(void){
    return;
}
uint32_t millisecondsSinceLastFrameChange = 0;
