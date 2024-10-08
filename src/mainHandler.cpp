#include "../include/main.h"
#include "../include/frameEvents.h"

namespace mainProgram {

    SDL_Renderer* mainRenderer = NULL;
    SDL_Window* mainWindow = NULL;

	void Main::onQuit() {

		SDL_DestroyRenderer(mainProgram::mainRenderer);

        SDL_DestroyWindowSurface(mainProgram::mainWindow);

		SDL_DestroyWindow(mainProgram::mainWindow);
        TTF_Quit();
		SDL_Quit();
	}


    bool Main::processEvent() {
		SDL_Event event;
		bool isRunning = true;
		while (SDL_PollEvent(&event)) {
			GetFrameEvents().push_back(event);
			switch (event.type) {
				case SDL_WINDOWEVENT_CLOSE: {
					isRunning = false;
					onQuit();
					break;
				}
				case SDL_QUIT: {
					isRunning = false;
					onQuit();
					break;
				}
			}	
		}

		return isRunning;
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