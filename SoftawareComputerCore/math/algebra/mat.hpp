#pragma once
#include <cmath>
#include <cassert>
#include <iostream>
#include "utils.hpp"


namespace sgc
{
namespace math
{
namespace algebra
{

	template<size_t width, size_t height, typename T>
	struct mat
	{
		mat(T fi=0)
		{
			fill(fi);
		}


		vec<width, T>& operator[] (const size_t index)
		{
			assert(index < height);
			return data[index];
		}

		const vec<width, T>& operator[] (const size_t index)
		const {
			assert(index < height);
			return data[index];
		}


		vec<height, T> col(const size_t index)
		{
			assert(index < width);
			vec<height, T> ret(0);
			for (size_t i = 0; i < height; i++)
			{
				ret[i] = data[i][index];
			}
			return ret;
		}

		const vec<height, T> col(const size_t index) const
		{
			assert(index < width);
			vec<height, T> ret(0);
			for (size_t i = 0; i < height; i++)
			{
				ret[i] = data[i][index];
			}
			return ret;
		}

		void fill(T value)
		{
			for (size_t i = 0; i < height; i++)
			{
				data[i] = vec<width, T>(value);
			}
		}


		// -----------------------------------------------------------------------
		// TODO make this crap not-member


		static mat<width, height, T> diag(mat<width, height, T> &matrix, T value=1)
		{
			assert(width == height);

			for (size_t i = 0; i < width; i++)
				matrix[i][i] = value;

			return matrix;
		}

		static mat<4, 4, T> translate(mat<4, 4, T> &matrix, vec<3, T> &vector)
		{
			matrix = mat<4, 4, T>::diag(matrix);

			for (size_t i = 0; i < 3; ++i)
				matrix[i][3] = vector[i];

			return matrix;
		}


		static mat<4, 4, T> scale(mat<4, 4, T> &matrix, vec<3, T> &vector)
		{
			for (size_t i = 0; i < 3; ++i)
				matrix[i][i] = vector[i];

			matrix[3][3] = 1;

			return matrix;
		}


		static mat<4, 4, T> rotate(mat<4, 4, T> &matrix, float angle, vec<3, T> &vector)
		{
			matrix[0][0] = (vector[0] * vector[0])	* (1 - std::cos(radians(angle))) + 				std::cos(radians(angle));
			matrix[0][1] =  vector[0] * vector[1]	* (1 - std::cos(radians(angle))) - vector[2] *	std::sin(radians(angle));
			matrix[0][2] =  vector[0] * vector[2]	* (1 - std::cos(radians(angle))) + vector[1] *	std::sin(radians(angle));
			//matrix[0][3] = 0;

			matrix[1][0] =  vector[0] * vector[1]	* (1 - std::cos(radians(angle))) + vector[2] *	std::sin(radians(angle));
			matrix[1][1] = (vector[1] * vector[1])	* (1 - std::cos(radians(angle))) + 				std::cos(radians(angle));
			matrix[1][2] =  vector[1] * vector[2]	* (1 - std::cos(radians(angle))) - vector[0] *	std::sin(radians(angle));
			//matrix[1][3] = 0;

			matrix[2][0] =  vector[2] * vector[0]	* (1 - std::cos(radians(angle))) - vector[1] *	std::sin(radians(angle));
			matrix[2][1] =  vector[2] * vector[1]	* (1 - std::cos(radians(angle))) + vector[0] *	std::sin(radians(angle));
			matrix[2][2] = (vector[2] * vector[2])	* (1 - std::cos(radians(angle))) + 				std::cos(radians(angle));
			//matrix[2][3] = 0;

			matrix.col(3)	= vec<3, T>(0);
			matrix[3]		= vec<4, T>{ 0, 0, 0, 1 };


			return matrix;
		}


		vec<width, T> data[height];
	};
	// TODO write matrix struct


	template<size_t c1, size_t r1, size_t c2, typename T, typename U>
	mat<c1, c2, T> operator* (const mat<c1, r1, T>& left, const mat<r1, c2, U>& right)
	{
		mat<c1, c2, T> ret(0.f);
		for (size_t i = 0; i < r1; ++i)
		{
			for (size_t j = 0; j < r1; ++j)
			{
				ret[i][j] = left[i] * right.col(j);
			}
		}
		return ret;
	}


	template<size_t w1, size_t h1, size_t s1, typename T, typename U>
	vec<s1, T> operator* (const mat<w1, h1, U> &matrix, const vec<s1, T> &vector)
	{
		assert(s1 == h1);

		vec<s1, T> ret(0);
		for (size_t i = 0; i < s1; ++i)
		{
			ret[i] = (matrix[i] * vector);
		}

		return ret;
	}


	template<size_t width, size_t height, typename T>
	std::ostream& operator<<(std::ostream& stream, const mat<width, height, T>& matrix)
	{
		for (size_t i = 0; i < height; i++)
		{
			stream << matrix[i] << std::endl;
		}
		return stream;
	}



	typedef mat<4, 4, float>	mat4f;
	typedef mat<4, 4, int>		mat4i;
	
	typedef mat<3, 3, float>	mat3f;
	typedef mat<3, 3, int>		mat3i;

	typedef mat<2, 2, float>	mat2f;
	typedef mat<2, 2, int>		mat2i;
}}}
