#include "keypress.hpp"

namespace KEYPRESS {
	void KEYPRESS::update(void) {
		if (state != lastState) {
			down = state;
			up = !state;
			isHold = false;
			lastState = state;
			return;
		}
		lastState = state;
		if (state) {
			if (isHold) return;
			if (!down) return;

			down = false;
			isHold = true;
			return;
		} else {
			if (!up) return;

			up = false;
		}
	}

	void KEYS::update(void) {
		for (auto& [_, k] : keys) {
			k.update();
		}
	}
	KEYPRESS KEYS::operator[](uint32_t n) const {
		return keys.at(n);
	}
	KEYPRESS& KEYS::operator[](uint32_t n) {
		return keys[n];
	}
	bool KEYS::any() const {
		bool isPressed = false;
		for (auto& [_, k] : keys) {
			if (k.down) {
				isPressed = true;
				break;
			}
		}
		return isPressed;
	}
}
