#include "../include/button.h"
#include "../include/main.h"

namespace mainProgram
{
    static void buttonProcessEvent(button_t *btn, const SDL_Event *ev)
    {
        // react on mouse click within button rectangle by setting 'pressed'
        if (ev->type == SDL_MOUSEBUTTONDOWN)
        {
            if (ev->button.button == SDL_BUTTON_LEFT &&
                ev->button.x >= btn->buttonBox.x &&
                ev->button.x <= (btn->buttonBox.x + btn->buttonBox.w) &&
                ev->button.y >= btn->buttonBox.y &&
                ev->button.y <= (btn->buttonBox.y + btn->buttonBox.h))
            {
                btn->pressed = true;
            }
        }
    }

    static bool renderButton(SDL_Renderer *r, button_t *btn)
    {
        // draw button
        SDL_SetRenderDrawColor(r, btn->colour.r, btn->colour.g, btn->colour.b, btn->colour.a);
        SDL_RenderFillRect(r, &btn->buttonBox);

        // if button press detected - reset it so it wouldn't trigger twice
        if (btn->pressed)
        {
            btn->pressed = false;
            return true;
        }
        return false;
    }
} // namespace mainProgram