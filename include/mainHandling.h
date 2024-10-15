#pragma once

#ifndef HANDLER_H
#define HANDLER_H
#include "main.h"
#include "buttonMgr.h"

namespace mainProgram {
	class Main {
	private:

	public:
		void onQuit(SDL_Renderer *renderer, SDL_Window *window);

		void processEvent(SDL_Renderer *renderer, SDL_Window *window,
							SDL_Event &event, bool isRunning,
							buttonManager numericButtons,
							buttonManager operationButtons,
							buttonManager functionButtons);
	};
}

#endif /* HANDLER_H */