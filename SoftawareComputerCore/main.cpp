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
	mat4f test1(0.f);
	test1 = mat4f::diag(test1);

	std::cout << test1;
	system("pause");
	return 0;


	Surface screen(1024, 1024);
	triangle tr(vec3i{ 0, 0, 1 }, vec3i{ 64, 128, 1 }, vec3i{ 128, 0, 1 });

	tr.draw_raw(screen, color{ 0, 255, 255 });

	// s.flip_vertically();
	screen.drop_image("../images/ppm/fill_triangle.ppm");
	// system("PAUSE");

	return 0;
}
