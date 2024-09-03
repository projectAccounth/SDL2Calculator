#pragma once

#include "main.h"

namespace mainProgram
{
    typedef struct
    {
        SDL_Rect buttonBox; // dimensions of button
        Color3 colour;
        bool pressed;
    } button_t;

    // This will be placed in the main event loop
    static void buttonProcessEvent(button_t *btn, const SDL_Event *ev);

    static bool renderButton(SDL_Renderer *r, button_t *btn);

} // namespace mainProgram