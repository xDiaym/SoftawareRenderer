#include <iostream>
#include <random>
#include <ctime>
#include "math/math.hpp"
#include "surface/Surface.h"
#include "rentool/render.hpp"
#include "model/Model.hpp"
//#include "math/geometry/triangle.hpp"



#ifdef _DEBUG
using namespace sgc;

using namespace math;
using namespace algebra;
//using namespace geometry;

using namespace surface;
using namespace render;
using namespace loader;
#endif // _DEBUG




int main(int argc, char **argv)
{
	Surface s(1024, 1024);
	Model md("../sources/models/african_head.obj");

	draw_triangle (s, vec2i(16),  vec2i(64),  vec2i{ 16, 64 },   color{ 255, 255, 255 });
	fill_triag    (s, vec2i(127), vec2i(255), vec2i{ 127, 255 }, color{ 0, 255, 255 });



	// s.flip_vertically();
	s.drop_image("../images/ppm/fill_triangle.ppm");
	// system("PAUSE");

	return 0;
}
