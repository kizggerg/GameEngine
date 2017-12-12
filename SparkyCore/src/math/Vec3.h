#pragma once

#include <iostream>

namespace Sparky
{
	namespace Math
	{
		struct Vec3
		{
		// Members:
			/// The X, Y, Z components of the 3D vector.
			float x, y, z;
			
		// Methods:
			/// Constructs a 3D zero vector
			Vec3();

			/// Constructs a 3D vector with the given
			/// x, y, and z components.
			Vec3(const float &x, const float &y, const float &z);

			/// Adds the X, Y, and Z components of the 
			/// other vector and returns the result
			Vec3& Add(const Vec3& other);

			/// Subtracts the X, Y, and Z components of the 
			/// other vector and returns the result
			Vec3& Subtract(const Vec3& other);

			/// Multiplies the X, Y, and Z components of the 
			/// other vector and returns the result
			Vec3& Multiply(const Vec3& other);

			/// Divides the X, Y, and Z components of the 
			/// other vector and returns the result
			Vec3& Divide(const Vec3& other);

		// Operators:
			/// Adds two vectors.
			friend Vec3& operator+(Vec3 left, const Vec3 &right);

			/// Subtracts two vectors.
			friend Vec3& operator-(Vec3 left, const Vec3 &right);

			/// Multiplies two vectors.
			friend Vec3& operator*(Vec3 left, const Vec3 &right);

			/// Divides two vectors.
			friend Vec3& operator/(Vec3 left, const Vec3 &right);

			/// Returns true if this and the other have the same
			/// X, Y, and Z components.
			bool operator==(const Vec3 &other);

			/// Returns false if this and the other have the same
			/// X, Y, Z, and W components.
			bool operator!=(const Vec3 &other);

			/// Adds the other vector to this.
			Vec3& operator+=(const Vec3 &other);

			/// Subtracts the other vector to this.
			Vec3& operator-=(const Vec3 &other);

			/// Multiplies the other vector to this.
			Vec3& operator*=(const Vec3 &other);

			/// Divides this by the other vector.
			Vec3& operator/=(const Vec3 &other);

			/// Outputs the vector as a string.
			friend std::ostream& operator<<(std::ostream&, const Vec3& vector);
		};


	}
}