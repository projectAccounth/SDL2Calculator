#pragma once

#include "main.h"

namespace mainProgram
{
    enum textAlign {
        LEFT,
        CENTER,
        RIGHT
    };

    class textButton {
    public:
        // dimension, size, position and initial RGB color for the button
        SDL_Rect buttonRect;
        SDL_Color buttonColor;

        SDL_Color textColor; // color for textButton
        SDL_Texture *textTexture;
        SDL_Color hoverColor; // color for hovering

        TTF_Font *textFont; // font for the text in the textButton
        std::string text; // text for the textButton

        textAlign TextAlign;

        bool hovered;
        bool visible, active;
        std::function<void()> buttonAction;

        textButton(int x, int y, int w, int h,
                    SDL_Color c, const std::string& t,
                    SDL_Color tc, TTF_Font* f,
                    textAlign align, SDL_Color hc)
            : buttonRect{ x, y, w, h },
              buttonColor(c),
              textColor(tc),
              textFont(f),
              text(t),
              TextAlign(align),
              textTexture(nullptr),
              hovered(false),
              hoverColor(hc),
              visible(true),
              active(true) {}
        /* you don't have to care much about these, this is just the constructor for the class */

        void loadText(SDL_Renderer* renderer);

        void render(SDL_Renderer *renderer);

        bool isClicked(int x, int y);

        void checkHover(int mouseX, int mouseY);

        bool isVisible() const;

        void toggleVisiblility(bool value);

        // destructor for the class
        ~textButton() {
            if (textTexture != nullptr)
                SDL_DestroyTexture(textTexture); // destroy the text's texture if it exists
        }
    };

} // namespace mainProgram