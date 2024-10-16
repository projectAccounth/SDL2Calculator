#include "../include/button.h"
#include "../include/main.h"

namespace mainProgram
{
    void textButton::loadText(SDL_Renderer *renderer) {
        if (textTexture != nullptr)
            SDL_DestroyTexture(textTexture); // destroy the texture to create a new one

        SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, text, textColor);
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
        // std::cout << SDL_GetError() << "whatever" << "\n";
        // std::cout << hovered << "\n";
        if (textTexture != nullptr) {
            int textWidth, textHeight;
            // querying the texture to attempt to align the text
            if (textTexture == nullptr) {
                std::cout << "Error: Texture is nullptr!" << std::endl;
            } else {
                SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
            }
            // now create a rect for the text
            SDL_Rect textRect;

            // align the text
            //textRect = { buttonRect.x + (buttonRect.w - textWidth) / 2, buttonRect.y + (buttonRect.h - textHeight) / 2, textWidth, textHeight };
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
            // std::cout << textRect.x << " " << textRect.y << " "<< textRect.w << " "<< textRect.h << " " << "\n";
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        }
    }

    void textButton::setAction(std::function<void()> actionFunction) {
        buttonAction = actionFunction;
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
    void textButton::toggleVisiblility(bool value) {
        visible = value;
    }
    void textButton::handleEvents(SDL_Event& e) {
        int x, y;
        SDL_PumpEvents();
        SDL_GetMouseState(&x, &y);

        // Check for mouse motion or button down events
        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
            if (x > buttonRect.x && x < (buttonRect.x + buttonRect.w) &&
                y > buttonRect.y && y < (buttonRect.y + buttonRect.h)) {
                hovered = true;  // Mouse is over button
                std::clog << "Hovering!" << "\n";
            } else {
                std::clog << "No longer hovering!" << "\n";
                hovered = false; // Mouse is not over button
            }

            // If mouse is clicked while hovering
            if (e.type == SDL_MOUSEBUTTONDOWN && hovered) {
                if (buttonAction) {
                    buttonAction();  // Execute the button action
                }
            }
        }
    }
} // namespace mainProgram