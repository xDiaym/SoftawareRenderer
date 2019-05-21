#pragma once

#include <initializer_list>
#include <cassert>
#include <cmath>
#include <iostream>



namespace sgc
{
namespace math 
{

	template<size_t size, typename T>
	struct vec
	{
		vec(T fill = 0)
		{
			for (T& element : data)
			{
				element = fill;
			}
		}
		vec(std::initializer_list<T> list)
		{
			// TODO delete assertion
			assert(list.size() == size);

			size_t i = 0;
			for (const T& element : list)
			{
				data[i++] = element;
			}
		}

		T& operator[](size_t index)
		{
			assert(index < size);
			return data[index];
		}

		const T& operator[](const size_t index)
		const {
			assert(index < size);
			return data[index];
		}

		float get_len(void)
		{
			return static_cast<float>(std::sqrt((*this) * (*this)));
		}

		vec<size, T> normalize()
		{
			return (*this) / get_len();
		}

		T data[size];
	};


	/*-----------------------------------------*/
	template<size_t size, typename T>
	std::ostream& operator<<(std::ostream& stream, const sgc::math::vec<size, T>& vector)
	{
		stream << "Vector: ";
		for (size_t s = 0; s < size; s++)
			stream << vector[s] << ", ";
		return stream;
	}

	/*-----------------------------------------*/

	template<size_t size, typename T, typename U>
	vec<size, T> operator+(vec<size, T> vector, const U& number)
	{
		for (size_t s = 0; s < size; s++)
		{
			vector[s] += number;
		}
		return vector;
	}


	template<size_t size, typename T, typename U>
	vec<size, T> operator-(vec<size, T> vector, const U& number)
	{
		for (size_t s = 0; s < size; s++)
		{
			vector[s] -= number;
		}
		return vector;
	}

	/*---------------------------------------*/

	template<size_t size, typename T, typename U>
	vec<size, T> operator+(vec<size, T> left, const vec<size, U>& right)
	{
		for (size_t s = size; s--; left[s] += right[s]);
		return left;
	}
	
	template<size_t size, typename T, typename U>
	vec<size, T> operator-(vec<size, T> left, const vec<size, U>& right)
	{
		for (size_t s = size; s--; left[s] -= right[s]);
		return left;
	}
	/*---------------------------------------*/


	/*---------------------------------------*/
	template<size_t size, typename T, typename U>
	vec<size, T> operator*(vec<size, T> left, const U& number)
	{
		for (size_t s = size; s--; left[s] *= number);
		return left;
	}

	template<size_t size, typename T, typename U>
	vec<size, T> operator/(vec<size, T> left, const U& number)
	{
		for (size_t s = size; s--; left[s] /= number);
		return left;
	}

	/*-----------------------------------------*/

	template<size_t size, typename T, typename U>
	vec<size, T> operator^(vec<size, T> left, const vec<size, U>& right)
	{
		for (size_t s = size; s--; left[s] *= right[s]);
		return left;
	}

	template<size_t size, typename T, typename U>
	vec<size, T> operator/(vec<size, T> left, const vec<size, U>& right)
	{
		for (size_t s = size; s--; left[s] /= right[s]);
		return left;
	}

	/*---------------------------------------*/

	template<size_t size, typename T, typename U>
	T operator*(vec<size, T> left, const vec<size, U>& right)
	{
		T cast = 0;
		for (size_t s = size; s--; cast += left[s] * right[s]);
		return cast;
	}


	typedef vec<3, uint8_t> color;

	typedef vec<2, int>   vec2i;
	typedef vec<2, float> vec2f;

	typedef vec<3, int>   vec3i;
	typedef vec<2, float> vec3f;
	
	typedef vec<4, int>   vec4i;
	typedef vec<2, float> vec4f;

}}
