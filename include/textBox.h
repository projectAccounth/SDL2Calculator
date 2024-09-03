#pragma once

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "main.h"

TTF_Font* mainFont = TTF_OpenFont("../res/fonts/Amiko-Regular.ttf", 15);
Color3 boxColor = {188, 188, 188, 255};

typedef struct textBox_t {
    SDL_Rect* textBox_Box;
    TTF_Font* textFont;
    SDL_Color boxColor;
    const char* text;
} textBox_t;

textBox_t displayBox = {
    .textBox_Box = new SDL_Rect {},
    .textFont = mainFont,
    .boxColor = Color3ToSDLColor(boxColor),
    .text = ""
};

void renderTextBox(textBox_t textBox);

#endif /* TEXTBOX_H */