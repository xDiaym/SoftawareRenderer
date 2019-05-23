#pragma once
#include "../algebra/vec.hpp"
#include "../../surface/Surface.h"
#include "../../rentool/render.hpp"



using namespace sgc;
using namespace math::algebra;
using namespace surface;
using namespace render;


namespace sgc
{
namespace math
{
namespace geometry
{

	struct triangle
	{
		triangle(vec3i v0, vec3i v1, vec3i v2)
		{
			vertices[0] = v0;
			vertices[1] = v1;
			vertices[2] = v2;
		}

		void raw_draw(Surface& screen, const color& col)
		{
			// TODO rewrite sgc::render::draw_triag function (or delte it)

			draw_line(screen, cat<2>(vertices[0]), cat<2>(vertices[1]), col);
			draw_line(screen, cat<2>(vertices[0]), cat<2>(vertices[2]), col);
			draw_line(screen, cat<2>(vertices[1]), cat<2>(vertices[2]), col);
		}

		vec3f normal(void)
		{
			vec3f ret;
			vec3i v0 = vertices[0] - vertices[1];
			vec3i v1 = vertices[1] - vertices[2];

			ret = change_type<float>(v0 ^ v1);
			ret.normalize();

			return ret;

		}

		vec3i vertices[3];
	};


}}}
