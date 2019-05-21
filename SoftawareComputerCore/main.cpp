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


	triangle(s, vec2i(95), vec2i{ 95, 159 }, vec2i{ 159, 95 }, color{ 0, 255, 255 });
	triangle(s, vec2i(159), vec2i{ 95, 159 }, vec2i{ 159, 95 }, color{ 255, 255, 255 });

	s.drop_image("images/ppm/triangles.ppm");

	return 0;
}
