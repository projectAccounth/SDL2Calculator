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
#include <string>
#include <cstring>

using namespace std::chrono;
using namespace std::this_thread;

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 500

namespace mainProgram {
    enum CURRENT_FUNCTION {
        NONE,
        SQRT,
        SIN, ASIN,
        COS, ACOS,
        TAN, ATAN,
        RAND,
    };
    enum CURRENT_OPERATION {
        NOOP,
        ADD, SUB,
        MUL, DIV
    };
}

#endif /* MAINHDR_H */
