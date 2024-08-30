#include "../include/window.h"

namespace mainProgram {


    SDL_Rect Entity1;

    void Window::createWindow() {
        mainWindow = SDL_CreateWindow("Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT , 0);
    }

    void Window::createRenderer() {
        mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    }

    void Window::initializeProgram() {
        SDL_Init(SDL_INIT_EVERYTHING);
        
        createWindow();

        createRenderer();
    }

    void Window::renderWindow() {
        
        SDL_SetRenderDrawColor(mainRenderer, 128, 128, 128, 255);
        SDL_RenderClear(mainRenderer);

        SDL_RenderPresent(mainRenderer);

    }

    std::vector<SDL_Event>& GetFrameEvents() {
        static std::vector<SDL_Event> frame_events;
	    return frame_events;
    }

}