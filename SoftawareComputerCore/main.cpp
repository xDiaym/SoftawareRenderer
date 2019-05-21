#include <iostream>
#include <random>
#include <ctime>
#include "math/math.hpp"
#include "surface/Surface.h"
#include "rentool/render.hpp"
#include "model/Model.hpp"



#ifdef _DEBUG
using namespace sgc;

using namespace math;
using namespace surface;
using namespace render;
using namespace loader;
#endif // _DEBUG




int main(int argc, char **argv)
{

	Surface s(1024, 1024);
	Model md("sources/models/african_head.obj");



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

	s.flip_vertically();
	s.drop_image("images/ppm/african_head.ppm");
	system("PAUSE");

	return 0;
}
