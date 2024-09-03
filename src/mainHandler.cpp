#include "../include/main.h"
#include "../include/frameEvents.h"

namespace mainProgram {

    SDL_Renderer* mainRenderer = NULL;
    SDL_Window* mainWindow = NULL;


    bool Main::processEvent() {
		SDL_Event event;
		bool isRunning = true;
		while (SDL_PollEvent(&event)) {
			GetFrameEvents().push_back(event);
			switch (event.type) {
				case SDL_WINDOWEVENT_CLOSE: {
					isRunning = false;
					break;
				}
				case SDL_QUIT: {
					isRunning = false;
					break;
				}
			}	
		}

		return isRunning;
	}

	void Main::onQuit() {

		SDL_DestroyRenderer(mainProgram::mainRenderer);

        SDL_DestroyWindowSurface(mainProgram::mainWindow);

		SDL_DestroyWindow(mainProgram::mainWindow);

		SDL_Quit();
        TTF_Quit();

	}
}

SDL_Color Color3ToSDLColor(Color3 color) {
	SDL_Color returnValue;
	returnValue.r = color.r;
	returnValue.g = color.g;
	returnValue.b = color.b;
	returnValue.a = color.a;
	return returnValue;
}