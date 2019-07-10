#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../math/algebra/vec.hpp"



using namespace sgc;
using namespace math;
using namespace algebra;



namespace sgc
{
namespace loader
{

	class Model
	{
	public:
		Model(std::string filename);
		~Model();
	
		size_t vert_size(void);
		size_t face_size(void);

		std::vector<int> face(size_t i);
		vec3f vert(size_t i);

		void clear()

	private:
		std::vector<std::vector<int>> _faces;
		std::vector<vec3f> _verts;
	};


}}
