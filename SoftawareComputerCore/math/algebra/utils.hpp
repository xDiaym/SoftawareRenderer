#pragma once

namespace sgc
{
namespace math
{
namespace algebra 
{
	

	template<size_t size, typename T, typename U>
	static vec<size, T> projection(vec<size, T>& u, vec<size, U>& v)
	{
		vec<size, T> puv(0);

		T delta = static_cast<T>((v * u) / std::pow(v.get_len(), 2));
		puv = v * delta;
		return puv;
	}

	inline float radians(float angle)
	{
		return angle * M_PI / 180;
	}

	inline float degrees(float angle)
	{
		return angle * 180 / M_PI;
	}

}}}
