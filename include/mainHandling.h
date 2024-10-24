#pragma once

#ifndef HANDLER_H
#define HANDLER_H
#include "main.h"
#include "buttonMgr.h"

namespace mainProgram {
	class Main {
	private:

	public:
		void onQuit(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font);

		bool processEvent(SDL_Event &event);
	};
}

#endif /* HANDLER_H */