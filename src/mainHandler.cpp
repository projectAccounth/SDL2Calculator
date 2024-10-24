#include "../include/main.h"
#include "../include/mainHandling.h"
#include "../include/frameEvents.h"
#include "../include/button.h"
#include "../include/buttonMgr.h"
#include "../include/textBox.h"

namespace mainProgram {

	void Main::onQuit(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font) {

		SDL_DestroyRenderer(renderer);

		TTF_CloseFont(font);

        SDL_DestroyWindowSurface(window);

		SDL_DestroyWindow(window);
        TTF_Quit();
		SDL_Quit();
	}


    bool Main::processEvent(SDL_Event &event) {
		bool isRunning = true;
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
		return isRunning;
	}
}