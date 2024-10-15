#pragma once

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "main.h"

namespace mainProgram {

class textBox {
private:
    SDL_Rect textBoxRect;
    SDL_Color boxColor;
    const char* text;
    SDL_Color textColor;

    TTF_Font* textFont;

    SDL_Surface *textSurface;
    SDL_Texture* textTexture;
public:

    textBox(SDL_Rect br, SDL_Color bc, const char* t, SDL_Color tc, TTF_Font* tf) :
        textBoxRect(br),
        boxColor(bc),
        text(t),
        textColor(tc),
        textFont(tf) {}
    
    void render(SDL_Renderer *renderer);

    void update(SDL_Renderer *renderer, const char* textToUpdate);

    ~textBox() {
        if (textSurface != nullptr) {
            SDL_FreeSurface(textSurface);
        }
    }
};

}

#endif /* TEXTBOX_H */