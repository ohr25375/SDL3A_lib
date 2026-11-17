#pragma once

#include <cstdint>

namespace FRAMERATE {
	class FRATE {
	public:
		bool doDelay();

		double FPS = 60;
	private:
		uint64_t computeTime = 0;
	};
}