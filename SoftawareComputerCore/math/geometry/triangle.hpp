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


		void fill_draw(Surface& screen, const color& col)
		{
			// TODO make union in vector
			// vertices[i][1] mean coordinates y
			if (vertices[0][1] > vertices[1][1]) std::swap(vertices[0], vertices[1]);
			if (vertices[0][1] > vertices[1][1]) std::swap(vertices[0], vertices[2]);
			if (vertices[1][1] > vertices[2][1]) std::swap(vertices[1], vertices[2]);



			float delta_hyp = (vertices[2][0] - vertices[0][0]) /\
				(float)(vertices[2][1] - vertices[0][1]);
			float delta_cat = (vertices[1][0] - vertices[0][0]) /\
				(float)(vertices[1][1] - vertices[0][1]);

			float hyp_err = 0;
			float cat_err = 0;

			int hyp_x = vertices[0][1];
			int cat_x = vertices[0][1];

			for (uint8_t i = vertices[0][1]; i < vertices[1][1]; i++)
			{
				if (hyp_err > .5f)
				{
					hyp_x++;
					hyp_err--;
				}

				if (cat_err > .5f)
				{
					cat_x++;
					cat_err--;
				}

				// screen.change_pixel_color(hyp_x, i, col);
				// screen.change_pixel_color(cat_x, i, col);
			
				draw_line(screen, hyp_x, i, cat_x, i, col);

				hyp_err += delta_hyp;
				cat_err += delta_cat;
			}
		}


		vec3i normal(void)
		{
			return (vertices[2] - vertices[0]) ^ (vertices[1] - vertices[0]);
		}


		vec3i vertices[3];
	};


}}}
