#include "color.hpp"

namespace COLOR {
	color::color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

	color::color(uint32_t rgb, uint8_t a) : a(a) {
		r = (rgb & 0xff0000) >> 16;
		g = (rgb & 0x00ff00) >> 8;
		b = (rgb & 0x0000ff) >> 0;
	}

}
