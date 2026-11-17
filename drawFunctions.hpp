#pragma once

#include "vector2.hpp"

#include "color.hpp"

#include <SDL3/SDL.h>

namespace DRAW {
	void drawLine(SDL_Renderer* renderer, const VECTOR::VECTOR2f start, const VECTOR::VECTOR2f end, const COLOR::color color = COLOR::WHITE, const float thickness = 1);
}