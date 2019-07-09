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
	Surface screen(1024, 1024);
	// triangle tr(vec3i{ 0, 0, 1 }, vec3i{ 64, 128, 1 }, vec3i{ 128, 0, 1 });

	mat4f trans(0.f);
	vec4i pos{ 512, 512, 0, 1 };
	trans = mat4f::translate(trans, vec3f(20.f));
	screen.change_pixel_color(proj<2>(pos), color{ 0, 255, 255 });

	pos = trans * pos;
	//tr.draw_raw(screen, color{ 0, 255, 255 });
	screen.change_pixel_color(proj<2>(pos), color{ 0, 255, 255 });

	screen.flip_vertically();
	screen.drop_image("../res/img/ppm/matrix_test1.ppm");
	// system("PAUSE");

	return 0;
}
