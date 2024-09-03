#pragma once

#ifndef COLOR3_H
#define COLOR3_H

#include "main.h"

typedef struct Color3
{
    uint8_t r, g, b, a;
} Color3;

SDL_Color Color3ToSDLColor(Color3 color);

#endif /* COLOR3_H */