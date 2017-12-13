#pragma once

#include "MathFunctions.h"
#include "Vec3.h"
#include "Vec4.h"

namespace Sparky
{
	namespace Math
	{
		struct Mat4
		{
		// Members:
		union
		{
			/// The elements of the 4 x 4 matrix.
			float m_Elements[4 * 4];
			/// The elements interpreted as column vectors.
			Vec4 columns[4];
		};

		// Methods:
			/// Constructs a 4 x 4 matrix where every
			/// element is 0.
			Mat4();

			/// Constructs a 4 x 4 matrix where every
			/// diagonal element is the diagonal, and
			/// every other element is 0.
			Mat4(float diagonal);

			/// Returns the 4 x 4 identity matrix.
			static Mat4 Identity();

			/// Multiplies two 4 x 4 matrices using
			/// matrix multiplication.
			Mat4& Multiply(const Mat4& other);

			/// Construct a matrix where objects near and far
			/// are drawn at the same size.
			static Mat4 Orthographic(float left, float right,
				float bottom, float top, float near, float far);

			/// Constructs a matrix where objects near and far
			/// are drawn at a size with respect to the aspect ratio.
			static Mat4 Perspective(float fov, float aspectRatio, 
				float near, float far);

			/// Translates the matrix by the given translation.
			static Mat4 Translation(const Vec3& translation);

			/// Rotates the matrix by the angle on the given axis.
			static Mat4 Rotation(float angle, const Vec3& axis);

			/// Scales the matrix by the given scale factor.
			static Mat4 Scale(const Vec3& scale);

		// Operators:
			/// Multiplies left by right using matrix multiplication.
			friend Mat4 operator*(Mat4 left, const Mat4& right);

			/// Multiplies this matrix with the other using matrix
			/// multiplication.
			Mat4& operator*=(const Mat4& other);
		};
	}
}


