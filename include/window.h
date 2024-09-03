#pragma once


#include "main.h"

#ifndef WINDOW_H
#define WINDOW_H

namespace mainProgram {

	class Window {
	private:

	public:

		void createWindow(const char* windowText, int windowWidth, int windowHeight);

		void createRenderer(SDL_Window *window);

		void initializeProgram();

		void renderWindow();

	};

}

#endif // WINDOW_H
