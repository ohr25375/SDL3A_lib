#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#define DEG2RAD (M_PI / 180)
#include <concepts>

namespace VECTOR {
	template <typename T>
		requires std::integral<T> || std::floating_point<T>
	struct VECTOR2 {
		T x{};
		T y{};

		template<typename T2, typename T3>
			requires (std::integral<T2> || std::floating_point<T2>) && (std::integral<T3> || std::floating_point<T3>)
		VECTOR2(const T2 x, const T3 y) : x((T)x), y((T)y) {}

		template<typename T2>
			requires std::integral<T2> || std::floating_point<T2>
		VECTOR2(const T2 xy) : x((T)xy), y((T)xy) {}

		template<typename T2>
			requires std::integral<T2> || std::floating_point<T2>
		VECTOR2(const VECTOR2<T2> xy) : x((T)xy.x), y((T)xy.y) {}

		VECTOR2() {
			x = 0;
			y = 0;
		}

		VECTOR2& operator+=(const VECTOR2& rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		VECTOR2 operator+(const VECTOR2& rhs) const {
			auto temp = *this;
			temp += rhs;
			return temp;
		}

		VECTOR2& operator-=(const VECTOR2& rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		VECTOR2 operator-(const VECTOR2& rhs) const {
			VECTOR2 temp = *this;
			temp -= rhs;
			return temp;
		}

		VECTOR2 operator-() const {
			VECTOR2 temp = *this;
			temp.x = -temp.x;
			temp.y = -temp.y;
			return temp;
		}

		VECTOR2& operator*=(const double& rhs) {
			this->x *= rhs;
			this->y *= rhs;
			return *this;
		}

		VECTOR2 operator*(const double& rhs) const {
			VECTOR2 temp = *this;
			temp *= rhs;
			return temp;
		}

		VECTOR2& operator/=(const double& rhs) {
			this->x /= rhs;
			this->y /= rhs;
			return *this;
		}

		VECTOR2 operator/(const double& rhs) const {
			VECTOR2 temp = *this;
			temp /= rhs;
			return temp;
		}

		double dot(const VECTOR2& rhs) const {
			return x * rhs.x + y * rhs.y;
		}

		double magnitude() const {
			return sqrt(this->dot(*this));
		}

		VECTOR2 normalize() const {
			return (*this / this->magnitude());
		}

		VECTOR2 rotate(const double& angle) const {
			VECTOR2 tmp = *this;
			tmp.x = x * cos(-angle) - y * sin(-angle);
			tmp.y = x * sin(-angle) + y * cos(-angle);
			return tmp;
		}

		VECTOR2 scale(const VECTOR2& rhs) const {
			VECTOR2 tmp = *this;
			tmp.x *= rhs.x;
			tmp.y *= rhs.y;
			return tmp;
		}
	};

	#define VECTOR2f VECTOR2<float>
	#define VECTOR2i VECTOR2<int>
}