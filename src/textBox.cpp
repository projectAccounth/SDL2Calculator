#include "../include/textBox.h"

void renderTextBox(textBox_t box) {
    SDL_Rect *textRect = box.textBox_Box;
    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(mainFont, box.text, Color3ToSDLColor(textColor)); 

    // now you can convert it into a texture
    SDL_Texture* text = SDL_CreateTextureFromSurface(mainProgram::mainRenderer, surfaceMessage);

    SDL_SetRenderDrawColor(mainProgram::mainRenderer, box.boxColor.r, box.boxColor.g, box.boxColor.b, box.boxColor.a);

    SDL_RenderCopy(mainProgram::mainRenderer, text, NULL, textRect);
    SDL_RenderDrawRect(mainProgram::mainRenderer, box.textBox_Box);
}

void updateTextBox(textBox_t box, const char* textToUpdate) {
    box.text = textToUpdate;
    renderTextBox(box);
}