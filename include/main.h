#pragma once
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
#include <thread>
#include <vector>

using namespace std::chrono;
using namespace std::this_thread;

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 600

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
