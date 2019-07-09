#pragma once
#include <cassert>
#include <iostream>


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


		vec<width, T> col(const size_t index)
		{
			assert(index < height);
			vec<height, T> ret();
			for (size_t i = 0; i < height; i++)
			{
				ret[i] = data[i][index];
			}
			return ret;
		}

		const vec<width, T> col(const size_t index)
		const {
			assert(index < height);
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


		static mat<width, height, T> diag(mat<width, height, T> &matrix, T value=1)
		{
			assert(width == height);

			for (size_t i = 0; i < width; i++)
				matrix[i][i] = value;

			return matrix;
		}



		vec<width, T> data[height];
	};
	// TODO write matrix struct


	template<size_t c1, size_t r1, size_t c2, typename T, typename U>
	mat<c1, c2, T> operator* (const mat<c1, r1, T>& left, const mat<r1, c2, U>& right)
	{
		mat<c1, c2, T> ret;
		for (size_t i = 0; i < c1; i++)
		{
			for (size_t j = 0; j < c2; j++)
			{
				for (size_t k = 0; k < r1; k++)
				{
					std::cout << left[i] * right.col(k) << std::endl;
					ret[i][j] = left[i] * right.col(k);
				}
			}
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
