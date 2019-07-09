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

		void draw_raw(Surface& screen, const color& col)
		{
			// TODO rewrite sgc::render::draw_triag function (or delte it)

			draw_line(screen, proj<2>(vertices[0]), proj<2>(vertices[1]), col);
			draw_line(screen, proj<2>(vertices[0]), proj<2>(vertices[2]), col);
			draw_line(screen, proj<2>(vertices[1]), proj<2>(vertices[2]), col);
		}


		void draw_fill(Surface& screen, const color& col)
		{
			// TODO
		}

		vec3i vertices[3];
	};


}}}
