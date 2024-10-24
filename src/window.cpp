#include "../include/window.h"
#include "../include/textBox.h"

namespace mainProgram {


    SDL_Rect Entity1;

    SDL_Window* Window::createWindow(const char* windowText, int windowWidth, int windowHeight) {
        return SDL_CreateWindow(windowText, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    }

    SDL_Renderer* Window::createRenderer(SDL_Window *window) {
        return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    std::vector<SDL_Event>& GetFrameEvents() {
        static std::vector<SDL_Event> frame_events;
	    return frame_events;
    }

}