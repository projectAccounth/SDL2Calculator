#pragma once

#ifndef MAIN_HDR
#define MAIN_HDR

#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
#include <thread>
#include <vector>

#include "color3.h"

using namespace std::chrono;
using namespace std::this_thread;

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 500

namespace mainProgram {
		
	extern SDL_Window* mainWindow;
	extern SDL_Renderer* mainRenderer;

}

namespace mainProgram {
	class Main {
	private:

	public:

		bool processEvent();

		void onQuit();
	};
}

#endif /* MAINHDR_H */
