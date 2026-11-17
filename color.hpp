#pragma once

#include <cstdint>

namespace COLOR {
	struct color {
		uint8_t r,g,b,a;
		color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xff);
		color(uint32_t rgb = 0xffffff, uint8_t a = 0xff);
	};

	const color WHITE(0xffffff);
	const color GRAY(0xa0a0a0);
	const color BLACK(0x000000);
}