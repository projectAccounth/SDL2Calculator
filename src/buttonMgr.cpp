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
        for(auto &button : buttons) {
            button.handleEvents(e);
        }
    }

    void buttonManager::toggleAllActive(bool value) {
        for (auto &button : buttons) {
            button.toggleActive(value);
        }
    }
}