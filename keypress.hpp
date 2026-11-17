#pragma once

#include <map>

namespace KEYPRESS {
	class KEYPRESS {
	public:
		bool down = false;
		bool up = false;
		bool isHold = false;
		bool state = false;
		void update(void);

	private:
		bool lastState = false;
	};

	class KEYS {
	public:
		void update(void);
		KEYPRESS operator[](uint32_t n) const;
		KEYPRESS& operator[](uint32_t n);

		bool any() const;

	private:
		std::map<uint32_t, KEYPRESS> keys{};
	};

	class MOUSE {
		public:
		int x, y;
		double xdir, ydir;
		double mouseSensitivity = 1.0;
		KEYPRESS left;
		KEYPRESS right;
		KEYPRESS middle;
		void update(void);

		private:
		int xd, yd;
	};
}  // namespace KEYPRESS