#include <iostream>
#include <random>
#include <ctime>
#include "math/math.hpp"
#include "surface/Surface.h"
#include "rentool/render.hpp"



#ifdef _DEBUG
using namespace sgc;

using namespace math;
using namespace surface;
using namespace render;
#endif // _DEBUG




int main(int argc, char **arhv)
{
	Surface s(255, 255);

	line(s, vec2i(0), vec2i(64), color(255));

	triangle(s, vec2i(0), vec2i(64), vec2i{ 0, 64 }, color{ 0, 255, 255 });

	s.drop_image("images/ppm/triangle.ppm");

	return 0;
}
