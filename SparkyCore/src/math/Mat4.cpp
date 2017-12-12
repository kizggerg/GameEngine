#include "Mat4.h"

namespace Sparky
{
	namespace Math
	{
		Mat4::Mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				m_Elements[i] = 0.0f;
			}
		}

		Mat4::Mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				if (i == 0 || i == 5 || i == 10 || i == 15)
				{
					m_Elements[i] = diagonal;
				}
				else
				{
					m_Elements[i] = 0.0f;
				}
			}
		}

		Mat4 Mat4::Identity()
		{
			return Mat4(1.0f);
		}

		Mat4& Mat4::Multiply(const Mat4& other)
		{
			float newElements[4 * 4];

			/// Calculates the resulting matrix.
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float sum = 0.0f;

					for (int k = 0; k < 4; k++)
					{
						sum += m_Elements[4 * i + k] * other.m_Elements[4 * k + j];
					}

					newElements[4 * i + j] = sum;
				}
			}

			/// Modifies this to be identical to the copy.
			for (int l = 0; l < 4 * 4; l++)
			{
				m_Elements[l] = newElements[l];
			}

			return *this;
		}

		Mat4 Mat4::Orthographic(float left, float right,
			float bottom, float top, float near, float far)
		{
			Mat4 result(1.0f);

			result.m_Elements[0] = 2.0f / (right - left);
			result.m_Elements[5] = 2.0f / (top - bottom);
			result.m_Elements[10] = -2.0f / (far - near);

			result.m_Elements[12] = -(right + left) / (right - left);
			result.m_Elements[13] = -(top + bottom) / (top - bottom);
			result.m_Elements[14] = -(far + near) / (far - near);

			return result;
		}

		Mat4 Mat4::Perspective(float fov, float aspectRatio,
			float near, float far)
		{
			Mat4 result(0.0f);

			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspectRatio;

			result.m_Elements[0] = a;
			result.m_Elements[5] = q;
			result.m_Elements[10] = - (far + near) / (far - near);
			result.m_Elements[11] = -1;
			result.m_Elements[14] = - (2*far*near) / (far - near);

			return result;
		}

		Mat4 Mat4::Translation(const Vec3& translation)
		{
			Mat4 result(1.0f);

			result.m_Elements[12] = translation.x;
			result.m_Elements[13] = translation.y;
			result.m_Elements[14] = translation.z;

			return result;
		}

		Mat4 Mat4::Rotation(float angle, const Vec3& axis)
		{
			Mat4 result(1.0f);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.m_Elements[0] = x * omc + c;
			result.m_Elements[1] = y * x * omc + z * s;
			result.m_Elements[2] = x * z * omc - y * s;

			result.m_Elements[4] = x * y * omc - z * s;
			result.m_Elements[5] = y * omc + c;
			result.m_Elements[6] = y * z * omc + x * s;

			result.m_Elements[8] = x * z * omc + y * s;
			result.m_Elements[9] = y * z * omc - x * s;
			result.m_Elements[10] = z * omc + c;

			return result;
		}

		Mat4 Mat4::Scale(const Vec3& scale)
		{
			Mat4 result(1.0f);

			result.m_Elements[0] = scale.x;
			result.m_Elements[5] = scale.y;
			result.m_Elements[10] = scale.z;

			return result;
		}


		Mat4 operator*(Mat4 left, const Mat4& right)
		{
			return left.Multiply(right);
		}

		Mat4& Mat4::operator*=(const Mat4& other)
		{
			return Multiply(other);
		}
	}
}
