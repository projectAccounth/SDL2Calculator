#pragma once

#ifndef BUTTON_MGR_H
#define BUTTON_MGR_H
#include "main.h"
#include "button.h"

namespace mainProgram {
    class buttonManager {
    public:
        std::vector<textButton> buttons;

        // adding buttons to the existing button list
        void addButton(textButton button);

        void loadAllText(SDL_Renderer *renderer);

        // rendering all buttons added in the list
        void renderAll(SDL_Renderer *renderer);

        // event handling for buttons
        void handleEvents(SDL_Event &e);
    };
}


#endif /* BUTTON_MGR_H */