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

		void renderWindow(buttonManager gr1, buttonManager gr2, buttonManager gr3, SDL_Renderer *renderer, textBox box1, textBox box2);

	};

}

#endif // WINDOW_H
