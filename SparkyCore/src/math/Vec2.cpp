#include "Vec2.h"

namespace Sparky
{
	namespace Math
	{

		Vec2::Vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vec2::Vec2(const float &x, const float &y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2& Vec2::Add(const Vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		Vec2& Vec2::Subtract(const Vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vec2& Vec2::Multiply(const Vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		Vec2& Vec2::Divide(const Vec2& other)
		{
			y /= other.y;
			x /= other.x;

			return *this;
		}

		Vec2 operator+(Vec2 left, const Vec2 &right)
		{
			return left.Add(right);
		}

		Vec2 operator-(Vec2 left, const Vec2 &right)
		{
			return left.Subtract(right);
		}

		Vec2 operator*(Vec2 left, const Vec2 &right)
		{
			return left.Multiply(right);
		}

		Vec2 operator/(Vec2 left, const Vec2 &right)
		{
			return left.Divide(right);
		}

		bool Vec2::operator==(const Vec2 &other)
		{
			return x == other.x && y == other.y;
		}

		bool  Vec2::operator!=(const Vec2 &other)
		{
			return !(*this == other);
		}

		Vec2& Vec2::operator+=(const Vec2 &other)
		{
			return Add(other);
		}

		Vec2& Vec2::operator-=(const Vec2 &other)
		{
			return Subtract(other);
		}

		Vec2& Vec2::operator*=(const Vec2 &other)
		{
			return Multiply(other);
		}

		Vec2& Vec2::operator/=(const Vec2 &other)
		{
			return Divide(other);
		}

		std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
		{
			stream << "Vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}


	}
}