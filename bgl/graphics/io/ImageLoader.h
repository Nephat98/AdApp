#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

// C++ Standard Library dependencies
#include <string>
#include <memory>

// Internal dependencies
#include "Image.h"

namespace bgl {
namespace io {
namespace detail {

/*
 *
 */
class ImageLoader
{
	private:
		std::string filename;

	protected:
		const std::string& getFilename(void) const
		{
			return filename;
		}
		
	public:
		ImageLoader(const std::string& filename)
			: filename(filename)
		{}
		
		virtual std::shared_ptr<Imge> load(void) = 0;
		 
};

}}}
#endif