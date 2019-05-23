#include <iostream>
#include <random>
#include <ctime>
#include "math/math.hpp"
#include "surface/Surface.h"
#include "rentool/render.hpp"
#include "model/Model.hpp"
#include "math/geometry/triangle.hpp"



#ifdef _DEBUG
using namespace sgc;

using namespace math;
using namespace algebra;
using namespace geometry;

using namespace surface;
using namespace render;
using namespace loader;
#endif // _DEBUG




int main(int argc, char **argv)
{
	Surface s(1024, 1024);

	draw_line(s, 0, 10, 128, 512, color{ 0, 255, 255 });


	triangle tr(vec3i{ 0, 0, 1 }, vec3i{ 64, 128, 1 }, vec3i{ 128, 0, 1 });

	tr.raw_draw(s, color{ 0, 255, 255 });

	// s.flip_vertically();
	s.drop_image("../images/ppm/fill_triangle.ppm");
	// system("PAUSE");

	return 0;
}
