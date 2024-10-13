#include "../include/button.h"
#include "../include/main.h"

namespace mainProgram
{
    void textButton::loadText(SDL_Renderer *renderer) {
        if (textTexture != nullptr)
                SDL_DestroyTexture(textTexture); // destroy the texture to create a new one

            SDL_Surface *textSurface = TTF_RenderText_Blended(textFont, text.c_str(), textColor);
            if (textSurface == nullptr) {
                std::cerr << "Cannot create surface for text, error:" << TTF_GetError() << "\n";
                return;
            }

            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); // creating the text texture that can be rendered
            SDL_FreeSurface(textSurface); // we don't want to make a thousand duplicates of a same surface and cause a memory leak, right?

            if (textTexture == nullptr) {
                std::cerr << "Cannot create text. Error: " << TTF_GetError() << "\n";
                return;
            }
    }

    void textButton::render(SDL_Renderer *renderer) {
        // set the color to draw for the button and also set the settings to render the button
        SDL_Color drawColor = hovered ? hoverColor : buttonColor; // using the barely-readable ternary operator to specify the color of the button
        SDL_SetRenderDrawColor(renderer, drawColor.r, drawColor.g, drawColor.b, drawColor.a);
        SDL_RenderFillRect(renderer, &buttonRect);

        if (textTexture != nullptr) {
            int textWidth, textHeight;
            // querying the texture to attempt to align the text
            SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
            // now create a rect for the text
            SDL_Rect textRect;

            // align the text
            switch (TextAlign) {
                case LEFT:
                    textRect = { buttonRect.x + 5, buttonRect.y + (buttonRect.h - textHeight) / 2, textWidth, textHeight };
                    break;
                case CENTER:
                    textRect = { buttonRect.x + (buttonRect.w - textWidth) / 2, buttonRect.y + (buttonRect.h - textHeight) / 2, textWidth, textHeight };
                    break;
                case RIGHT:
                    textRect = { buttonRect.x + buttonRect.w - textWidth - 5, buttonRect.y + (buttonRect.h - textHeight) / 2, textWidth, textHeight };
                    break;
            }
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        }
    }

    bool textButton::isClicked(int x, int y) {
        return (x > buttonRect.x &&
                x < (buttonRect.x + buttonRect.w) &&
                y > buttonRect.y && 
                y < (buttonRect.y + buttonRect.h));
    }

    void textButton::checkHover(int mouseX, int mouseY) {
        hovered = isClicked(mouseX, mouseY);
    }

    bool textButton::isVisible() const {
        return visible;
    }
} // namespace mainProgram