#include "../include/window.h"
#include "../include/textBox.h"

namespace mainProgram {


    SDL_Rect Entity1;

    void Window::createWindow(const char* windowText, int windowWidth, int windowHeight) {
        mainWindow = SDL_CreateWindow(windowText, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    }

    void Window::createRenderer(SDL_Window *window) {
        mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    }

    void Window::initializeProgram() {
        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();
        createWindow("Program", WINDOW_WIDTH, WINDOW_HEIGHT);

        createRenderer(mainWindow);
    }

    void Window::renderWindow() {
        
        SDL_SetRenderDrawColor(mainRenderer, 128, 128, 128, 255);
        SDL_RenderClear(mainRenderer);
        renderTextBox(displayBox);
        renderTextBox(prevInputBox);
        SDL_RenderPresent(mainRenderer);

    }

    std::vector<SDL_Event>& GetFrameEvents() {
        static std::vector<SDL_Event> frame_events;
	    return frame_events;
    }

}