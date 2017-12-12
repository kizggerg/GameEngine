#pragma once

#include <iostream>

namespace Sparky
{
	namespace Math
	{
		struct Vec4
		{
		// Members:
			/// The X, Y, Z, W components of the 4D vector.
			float x, y, z, w;
			
		// Methods:
			/// Constructs a 4D zero vector
			Vec4();

			/// Constructs a 4D vector with the given
			/// x, y, z, and w components.
			Vec4(const float &x, const float &y, const float &z, const float &w);

			/// Adds the X, Y, Z, and W components of the 
			/// other vector and returns the result
			Vec4& Add(const Vec4& other);

			/// Subtracts the X, Y, Z, and W components of the 
			/// other vector and returns the result
			Vec4& Subtract(const Vec4& other);

			/// Multiplies the X, Y, Z, and W components of the 
			/// other vector and returns the result
			Vec4& Multiply(const Vec4& other);

			/// Divides the X, Y, Z, and W components of the 
			/// other vector and returns the result
			Vec4& Divide(const Vec4& other);

		// Operators:
			/// Adds two vectors.
			friend Vec4 operator+(Vec4 left, const Vec4 &right);

			/// Subtracts two vectors.
			friend Vec4 operator-(Vec4 left, const Vec4 &right);

			/// Multiplies two vectors.
			friend Vec4 operator*(Vec4 left, const Vec4 &right);

			/// Divides two vectors.
			friend Vec4 operator/(Vec4 left, const Vec4 &right);

			/// Returns true if this and the other have the same
			/// X, Y, Z, and W components.
			bool operator==(const Vec4 &other);

			/// Returns false if this and the other have the same
			/// X, Y, Z, and W components.
			bool operator!=(const Vec4 &other);

			/// Adds the other vector to this.
			Vec4& operator+=(const Vec4 &other);

			/// Subtracts the other vector to this.
			Vec4& operator-=(const Vec4 &other);

			/// Multiplies the other vector to this.
			Vec4& operator*=(const Vec4 &other);

			/// Divides this by the other vector.
			Vec4& operator/=(const Vec4 &other);

			/// Outputs the vector as a string.
			friend std::ostream& operator<<(std::ostream&, const Vec4& vector);
		};


	}
}