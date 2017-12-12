#pragma once

#include <iostream>

namespace Sparky
{
	namespace Math
	{
		struct Vec2
		{
		// Members:
			/// The X and Y components of the 2D vector.
			float x, y;
			
		// Methods:
			/// Constructs a 2D zero vector
			Vec2();

			/// Constructs a 2D vector with the given
			/// x and y components.
			Vec2(const float &x, const float &y);

			/// Adds the X and Y components of the 
			/// other vector and returns the result
			Vec2& Add(const Vec2& other);
			
			/// Subtracts the X and Y components of the 
			/// other vector and returns the result
			Vec2& Subtract(const Vec2& other);

			/// Multiplies the X and Y components of the 
			/// other vector and returns the result
			Vec2& Multiply(const Vec2& other);

			/// Divides the X and Y components of the 
			/// other vector and returns the result
			Vec2& Divide(const Vec2& other);

		// Operators:
			/// Adds two vectors.
			friend Vec2& operator+(Vec2 left, const Vec2 &right);

			/// Subtracts two vectors.
			friend Vec2& operator-(Vec2 left, const Vec2 &right);

			/// Multiplies two vectors.
			friend Vec2& operator*(Vec2 left, const Vec2 &right);

			/// Divides two vectors.
			friend Vec2& operator/(Vec2 left, const Vec2 &right);

			/// Returns true if this and the other have the same
			/// X and Y components.
			bool operator==(const Vec2 &other);

			/// Returns false if this and the other have the same
			/// X and Y components.
			bool operator!=(const Vec2 &other);

			/// Adds the other vector to this.
			Vec2& operator+=(const Vec2 &other);

			/// Subtracts the other vector to this.
			Vec2& operator-=(const Vec2 &other);

			/// Multiplies the other vector to this.
			Vec2& operator*=(const Vec2 &other);

			/// Divides this by the other vector.
			Vec2& operator/=(const Vec2 &other);

			/// Outputs the vector as a string.
			friend std::ostream& operator<<(std::ostream&, const Vec2& vector);
		};


	}
}