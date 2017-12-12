#include "Vec3.h"

namespace Sparky
{
	namespace Math
	{
		Vec3::Vec3()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vec3::Vec3(const float &x, const float &y, const float &z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3& Vec3::Add(const Vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vec3& Vec3::Subtract(const Vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vec3& Vec3::Multiply(const Vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		Vec3& Vec3::Divide(const Vec3& other)
		{
			y /= other.y;
			x /= other.x;
			z /= other.z;

			return *this;
		}

		Vec3& operator+(Vec3 left, const Vec3 &right)
		{
			return left.Add(right);
		}

		Vec3& operator-(Vec3 left, const Vec3 &right)
		{
			return left.Subtract(right);
		}

		Vec3& operator*(Vec3 left, const Vec3 &right)
		{
			return left.Multiply(right);
		}

		Vec3& operator/(Vec3 left, const Vec3 &right)
		{
			return left.Divide(right);
		}

		bool Vec3::operator==(const Vec3 &other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool  Vec3::operator!=(const Vec3 &other)
		{
			return !(*this == other);
		}

		Vec3& Vec3::operator+=(const Vec3 &other)
		{
			return Add(other);
		}

		Vec3& Vec3::operator-=(const Vec3 &other)
		{
			return Subtract(other);
		}

		Vec3& Vec3::operator*=(const Vec3 &other)
		{
			return Multiply(other);
		}

		Vec3& Vec3::operator/=(const Vec3 &other)
		{
			return Divide(other);
		}

		std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
		{
			stream << "Vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}


	}
}