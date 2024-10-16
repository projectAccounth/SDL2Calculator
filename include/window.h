#pragma once


#include "main.h"
#include "buttonMgr.h"
#include "button.h"
#include "textBox.h"

#ifndef WINDOW_H
#define WINDOW_H

namespace mainProgram {

	class Window {
	private:

	public:

		SDL_Window* createWindow(const char* windowText, int windowWidth, int windowHeight);

		SDL_Renderer* createRenderer(SDL_Window *window);

	};

}

#endif // WINDOW_H
