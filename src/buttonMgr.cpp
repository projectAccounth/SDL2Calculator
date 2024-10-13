#include "../include/buttonMgr.h"

namespace mainProgram {
    void buttonManager::addButton(textButton button) {
        // push back 1 object to the vector
        buttons.push_back(button);
    }

    void buttonManager::renderAll(SDL_Renderer *renderer) {
        // like the foreach (List) in C#
        for (auto &button : buttons) {
            if (button.isVisible())
                button.render(renderer);
        }
    }

    void buttonManager::loadAllText(SDL_Renderer *renderer) {
        for (auto &button : buttons) {
            button.loadText(renderer);
        }
    }

    void buttonManager::handleEvents(SDL_Event &e) {
        // checking whether you're moving the mouse or pressing the mouse
        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            // getting mouse state (x, y, ....)
            SDL_GetMouseState(&mouseX, &mouseY);
            // using the foreach-alike function with the : operator
            for (auto &button : buttons) {
                button.checkHover(mouseX, mouseY);

                // checking whether it's a click or not
                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    std::cout << "Clicked" << "\n";
                }
            }
        }
    }
}