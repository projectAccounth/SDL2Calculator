#pragma once

#ifndef MAIN_HDR
#define MAIN_HDR

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
#include <thread>
#include <vector>
#include <functional>

#include "color3.h"

using namespace std::chrono;
using namespace std::this_thread;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800

namespace mainProgram {
		
	extern SDL_Window* mainWindow;
	extern SDL_Renderer* mainRenderer;

}

namespace mainProgram {
	class Main {
	private:

	public:
		void onQuit();

		bool processEvent();
	};
}

#endif /* MAINHDR_H */
