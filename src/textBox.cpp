#include "../include/textBox.h"

void renderTextBox(textBox_t box) {
    TTF_Font *mainFont = TTF_OpenFont("../res/fonts/Amiko-Regular.ttf", 35);
    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage =
    TTF_RenderText_Blended(mainFont, box.text, Color3ToSDLColor(textColor)); 

    // now you can convert it into a texture
    SDL_Texture* text = SDL_CreateTextureFromSurface(mainProgram::mainRenderer, surfaceMessage);

    SDL_Rect *textRect = new SDL_Rect {
        .x = box.textBox_Box->x,
        .y = box.textBox_Box->y + (box.textBox_Box->h / 2) - surfaceMessage->h / 2,
        .w = surfaceMessage->w,
        .h = surfaceMessage->h
    };

    SDL_SetRenderDrawColor(mainProgram::mainRenderer, box.boxColor.r, box.boxColor.g, box.boxColor.b, box.boxColor.a);

    SDL_RenderFillRect(mainProgram::mainRenderer, box.textBox_Box);
    SDL_RenderCopy(mainProgram::mainRenderer, text, NULL, textRect);
    SDL_FreeSurface(surfaceMessage);
}

void updateTextBox(textBox_t box, const char* textToUpdate) {
    box.text = textToUpdate;
    renderTextBox(box);
}