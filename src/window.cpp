#include "../include/window.h"
#include "../include/textBox.h"

namespace mainProgram {


    SDL_Rect Entity1;

    SDL_Window* Window::createWindow(const char* windowText, int windowWidth, int windowHeight) {
        return SDL_CreateWindow(windowText, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    }

    SDL_Renderer* Window::createRenderer(SDL_Window *window) {
        return SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    }

    void Window::renderWindow(buttonManager gr1, buttonManager gr2, buttonManager gr3, SDL_Renderer *renderer, textBox box1, textBox box2) {
        // main color of the screen   
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

        SDL_RenderClear(renderer);
        // whatever that needs to be rendered go between RenderClear and RenderPresent

        box1.render(renderer);
        box2.render(renderer);

        gr1.renderAll(renderer);
        gr2.renderAll(renderer);
        gr3.renderAll(renderer);

        SDL_RenderPresent(renderer);

    }

    std::vector<SDL_Event>& GetFrameEvents() {
        static std::vector<SDL_Event> frame_events;
	    return frame_events;
    }

}