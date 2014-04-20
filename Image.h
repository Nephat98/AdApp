#ifndef IMAGE_H
#define IMAGE_H

// C++ Standard Library dependencies
#include <vector>

namespace bgl {

/*
 *
 */
class Image
{
	public:
		typedef float Color;
		typedef std::vector<Color>::size_type Size;

	private:
		Size width;
		Size height;
		std::vector<Color> pixels;

	public:

		template<typename InputIterator>
		Image(Size width, Size height, InputIterator first, InputIterator last)
			: width(width), height(height), pixels(first, last)
		{}

		Size getWidth(void) const
		{
			return width;
		}

		Size getHeight(void) const
		{
			return height;
		}

		const Color* getData(void) const
		{
			return pixels.data();
		}
};

};
#endif