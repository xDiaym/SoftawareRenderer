#pragma once
#include "../math/vec.hpp"
#include "../surface/Surface.h"



using namespace sgc;
using namespace math;
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

	void line(Surface& screen, const vec2i& beg, const vec2i& end, const color& col)
	{
		int x0 = beg[0];
		int y0 = beg[1];
		int x1 = end[0];
		int y1 = end[1];

		int delta_x = std::abs(x1 - x0);
		int delta_y = std::abs(y1 - y0);

		int db_y = 2 * delta_y;
		int db_x = 2 * delta_x;
		short dir = (y1 > y0 ? 1 : -1);

		int d_error = 0;

		size_t y = y0;

		for (size_t x = x0; x <= x1; x++)
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

}}
