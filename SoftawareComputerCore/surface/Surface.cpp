#include "Surface.h"



namespace sgc
{
namespace surface
{
	Surface::Surface(size_t _width, size_t _height, color col)
		: width(_width), height(_height)
	{
		canvas.resize(width * height);
		fill(col);
	}

	Surface::Surface()
		: width(1), height(1)
	{
		canvas.resize(1);
	}

	Surface::~Surface()
	{
	}

	void Surface::drop_image(std::string filename)
	{
		std::ofstream image(filename, std::ofstream::binary);
		
		image << "P6\n" << width << " " << height << "\n" << color_deep << "\n";
		for (color col : canvas)
			image << col[0] << col[1] << col[2];

		image.close();
	}

	void Surface::load_image(std::string filename)
	{
		std::ifstream source(filename);
		std::string data;

		// Chek 'P6' file format
		std::getline(source, data, '\n');
		assert(data == "P6");

		// Get width and height
		std::getline(source, data, ' ');
		width = std::stoi(data);

		std::getline(source, data, '\n');
		height = std::stoi(data);

		canvas.resize(width * height);

		// Get color factor
		std::getline(source, data, '\n');
		color_deep = std::stoi(data);

		
		//std::string dt(std::istreambuf_iterator<char>(source.rdbuf()), std::istreambuf_iterator<char>());
		//std::cout << dt << std::endl;

		char buff[4];
		for (size_t i = 0; i < canvas.size(); i++)
		{
			source.get(buff, 4);
			canvas[i] = color{ static_cast<uint8_t>(buff[0]),
							   static_cast<uint8_t>(buff[1]),
							   static_cast<uint8_t>(buff[2]) };
		}
		source.close();
	}

	void Surface::flip_vertically(void)
	{
		size_t c = height - 1;
		for (size_t i = 0; i < height / 2; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				// std::cerr << j << " " << i << " " << c << std::endl;
				std::swap(canvas[j + i * width], canvas[j + c * width]);
			}
			c--;
		}
	}

	void Surface::change_pixel_color(const size_t x, const size_t y, const color col)
	{
		assert(x < width && y < height);
		canvas[x + y * width] = col;
	}

	void Surface::change_pixel_color(const vec2i & pos, color col)
	{
		assert(pos[0] < (int)width && pos[1] < (int)height);
		canvas[pos[0] + pos[1] * width] = col;
	}

	void Surface::fill(const color & c)
	{
		float delta_x = color_deep / (float)width;
		float delta_y = color_deep / (float)height;

		for (size_t h = 0; h < height; h++)
		{
			for (size_t w = 0; w < width; w++)
			{
				canvas[w + h * width] = c;
			}
		}
	}

	void Surface::test_image(void)
	{

		float delta_x = color_deep / (float)width;
		float delta_y = color_deep / (float)height;
	
		for (size_t h = 0; h < height; h++)
		{
			for (size_t w = 0; w < width; w++)
			{
				canvas[w + h * width] = color{ static_cast<uint8_t>(w*delta_x), static_cast<uint8_t>(h*delta_y), 127 };
			}
		}
	}

}}
