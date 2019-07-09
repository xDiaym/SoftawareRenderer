#define _USE_MATH_DEFINES

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
	vec3f testv1(0.1f);
	vec3f testv2(2.f);

	//std::cout << testv1 * testv2 << std::endl << std::endl;

	mat4f test1(0.f);
	mat4f test2(0.f);
	mat4f test3(0.f);
	
	mat4f out(0.f);

	test1 = mat4f::translate(test1, testv1);
	test2 = mat4f::scale	(test2, testv2);
	test2 = mat4f::scale	(test2, testv2);

	out = test2 * test1;


	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << out << std::endl;
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
