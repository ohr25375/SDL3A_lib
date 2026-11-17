#include "drawFunctions.hpp"

#include <iostream>

namespace DRAW {
	void drawLine(SDL_Renderer* renderer, const VECTOR::VECTOR2f start, const VECTOR::VECTOR2f end, const COLOR::color color, const float thickness) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderLine(renderer, start.x, start.y, end.x, end.y);
	}
}