#include "Model.hpp"



namespace sgc
{
namespace loader
{

	Model::Model(std::string filename)
	{
		std::ifstream obj_file(filename, std::ifstream::in);

		std::string line;
		while (!obj_file.eof())
		{
			std::getline(obj_file, line);
			std::istringstream iss(line);
			char trash;

			if (!line.compare(0, 2, "v "))
			{
				iss >> trash;
				vec3f vert;
				for (size_t i = 0; i < 3; i++)
					iss >> vert[i];
				_verts.push_back(vert);
			}
			else if (line.compare(0, 2, "f "))
			{
				char slashtrash;
				int i;
				std::vector<int> fac;		// o_O Does not contain offensive language
				while (iss >> i >> slashtrash >> trash >> slashtrash >> trash)
				{
					--i;
					fac.push_back(i);
				}
				_faces.push_back(fac);
			}
		}

	}

	Model::~Model()
	{

	}

	size_t Model::vert_size(void)
	{
		return _verts.size();
	}

	size_t Model::face_size(void)
	{
		return _faces.size();
	}

	std::vector<int> Model::face(size_t i)
	{
		return _faces[i];
	}

	vec3f Model::vert(size_t i)
	{
		return _verts[i];
	}

}}
