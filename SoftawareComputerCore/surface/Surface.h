#pragma once
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../math/vec.hpp"


using namespace sgc;
using namespace math;

namespace sgc
{
namespace surface
{
	class Surface
	{
	public:
		Surface(size_t _width, size_t _height, color col = color{ 0, 0, 0 });
		Surface();
		~Surface();

		void drop_image(std::string filename);
		void load_image(std::string filename);

		void change_pixel_color(size_t x, size_t y, color col);

		void fill(const color& c);
		void test_image(void);

		void samlipng(void);

		// TODO replace 
		size_t width, height;
	private:
		size_t color_deep = 255;
		std::vector<vec<3, uint8_t>> canvas;
	};
}}
