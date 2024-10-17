#include "../include/textBox.h"

namespace mainProgram {
    void textBox::render(SDL_Renderer *renderer) {
        // as TTF_RenderText_Solid could only be used on
        // SDL_Surface then you have to create the surface first
        textSurface = TTF_RenderText_Blended(textFont, text.c_str(), textColor); 

        // now you can convert it into a texture
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect *textRect = new SDL_Rect {
            .x = textBoxRect.x,
            .y = textBoxRect.y + (textBoxRect.h / 2) - textSurface->h / 2,
            .w = textSurface->w,
            .h = textSurface->h
        };

        SDL_SetRenderDrawColor(renderer, boxColor.r, boxColor.g, boxColor.b, boxColor.a);

        SDL_RenderFillRect(renderer, &textBoxRect);
        SDL_RenderCopy(renderer, textTexture, NULL, textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    void textBox::update(SDL_Renderer *renderer, const char* textToUpdate) {
        text = textToUpdate;
        render(renderer);
    }
}