#pragma once

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "main.h"

extern TTF_Font* mainFont;
extern Color3 textColor;
extern Color3 boxColor;

typedef struct textBox_t {
    SDL_Rect* textBox_Box;
    TTF_Font* textFont;
    SDL_Color boxColor;
    const char* text;
} textBox_t;


extern textBox_t displayBox;

void renderTextBox(textBox_t textBox);

void updateTextBox(textBox_t textBox, const char* textToUpdate);

#endif /* TEXTBOX_H */