#pragma once
#include "../math/algebra/vec.hpp"
#include "../surface/Surface.h"



using namespace sgc;
using namespace math;
using namespace algebra;
using namespace surface;



namespace sgc
{
namespace render
{

	void draw_rect(Surface& screen, const vec2i& pos, const vec2i& size, const color& col)
	{
		// TODO make class-member func
		for (int y = pos[0]; y < pos[0] + size[0]; y++)
		{
			for (int x = pos[1]; x < pos[1] + size[1]; x++)
			{
				screen.change_pixel_color(x, y, col);
			}
		}
	}

	void draw_line(Surface& screen, const vec2i& beg, const vec2i& end, const color& col)
	{
		// TODO add assertion

		bool steep = false;		/* delta_x is greater than delta_y, or vice versa
								   simply speaking, the line is "horizontal" or "vertical" */


		int x0 = beg[0];		// Begin and end line position
		int y0 = beg[1];
		int x1 = end[0];
		int y1 = end[1];

		if (std::abs(x1 - x0) < std::abs(y1 - y0))
		{
			steep = true;
			std::swap(x0, y0);
			std::swap(x1, y1);
		}

		if (x0 > x1)
		{
			std::swap(x0, x1);
			std::swap(y0, y1);
		}

		int delta_x = x1 - x0;	// x-lenght (?)
		int delta_y = y1 - y0;	// y-lenght (?)

		int db_y = 2 * std::abs(delta_y);				
		int db_x = 2 * delta_x;
		short dir = (y1 > y0 ? 1 : -1);

		int d_error = 0;

		int y = y0;
		/*
			We know delta_x and delta_y before the loop,
			so why check them in a loop?
		*/
		if (steep)
		{
			for (int x = x0; x <= x1; x++)
			{
				screen.change_pixel_color(x, y, col);
				d_error += db_y;
				if (d_error >= delta_x)
				{
					y += dir;
					d_error -= db_x;
				}
			}
		}
		else
		{
			for (int x = x0; x <= x1; x++)
			{
				screen.change_pixel_color(y, x, col);
				d_error += db_y;
				if (d_error >= delta_x)
				{
					y += dir;
					d_error -= db_x;
				}
			}
		}
	}

	void draw_line(Surface& screen, int x0, int y0, int x1, int y1, const color& col)
	{
		// TODO add assertion

		bool steep = false;		/* delta_x is greater than delta_y, or vice versa
								   simply speaking, the line is "horizontal" or "vertical" */


		if (std::abs(x1 - x0) < std::abs(y1 - y0))
		{
			steep = true;
			std::swap(x0, y0);
			std::swap(x1, y1);
		}

		if (x0 > x1)
		{
			std::swap(x0, x1);
			std::swap(y0, y1);
		}

		int delta_x = x1 - x0;	// x-lenght (?)
		int delta_y = y1 - y0;	// y-lenght (?)

		int db_y = 2 * std::abs(delta_y);
		int db_x = 2 * delta_x;
		short dir = (y1 > y0 ? 1 : -1);

		int d_error = 0;

		int y = y0;
		/*
			We know delta_x and delta_y before the loop,
			so why check them in a loop?
		*/
		if (steep)
		{
			for (int x = x0; x <= x1; x++)
			{
				screen.change_pixel_color(x, y, col);
				d_error += db_y;
				if (d_error >= delta_x)
				{
					y += dir;
					d_error -= db_x;
				}
			}
		}
		else
		{
			for (int x = x0; x <= x1; x++)
			{
				screen.change_pixel_color(y, x, col);
				d_error += db_y;
				if (d_error >= delta_x)
				{
					y += dir;
					d_error -= db_x;
				}
			}
		}
	}

	void draw_triangle(Surface& screen, const vec2i& v1, const vec2i& v2, const vec2i& v3, const color& col)
	{
		draw_line(screen, v1, v2, col);
		draw_line(screen, v2, v3, col);
		draw_line(screen, v3, v1, col);
	}

	/*
		for (size_t i = 0; i < md.face_size(); i++)
	{
		std::vector<int> face = md.face(i);

		for (size_t j = 0; j < 3; j++)
		{
			vec3f l0 = md.vert(face[j]);
			vec3f l1 = md.vert(face[(j + 1) % 3]);		 // if j == 3

			int x0 = (s.width  - 1) * (l0[0] + 1) / 2;
			int y0 = (s.height - 1) * (l0[1] + 1) / 2;
			int x1 = (s.width  - 1) * (l1[0] + 1) / 2;
			int y1 = (s.height - 1) * (l1[1] + 1) / 2;

			//std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << " " << std::endl;

			line(s, vec2i{ y0, x0 }, vec2i{ y1, x1 }, color{ 0, 255, 255 });		// I dont know wat it means 0_0
		}
	}
	*/

	void fill_triag(Surface& screen, vec2i l0, vec2i l1, vec2i l2, const color& col)
	{
		if (l0[1] > l1[1]) std::swap(l0, l1);
		if (l0[1] > l2[1]) std::swap(l0, l2);
		if (l1[1] > l2[1]) std::swap(l1, l2);

		float delta_hyp = (l2[0] - l0[0]) / (float)(l2[1] - l0[1]);
		float delta_cat = (l1[0] - l0[0]) / (float)(l1[1] - l0[1]);

		float x0 = (float)l0[0];
		float x1 = (float)l0[0];

		for (int i = l0[1]; i < l1[1]; i++)
		{
			draw_line(screen, (int)x0, i, (int)x1, i, col);
			x0 += delta_hyp;
			x1 += delta_cat;
		}
	}
}}
