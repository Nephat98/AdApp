#ifndef IMAGE_LOADER_FACTORY_H
#define IMAGE_LOADER_FACTORY_H

// C++ Standard Library dependencies
#include <mutex>
#include <memory>

// Internal dependencies
#include "DevILLoader.h"

namespace bgl {
namespace io {
namespace detail {

/*
 *
 */
class ImageLoaderFactory
{
	private:
		constexpr static ImageLoaderFactory* instance = nullptr;
		std::mutex mutex;

		//
		ImageLoaderFactory(void) = delete;
		ImageLoaderFactory(const ImageLoaderFactory&) = delete
	public:

		/*
		 *
		 */
		static ImageLoader& getInstance(void)
		{
			std::lock_guard<std::mutex> lock(mutex);

			if(instance == nullptr)
				instance = new ImageLoaderFactory;
			return *instance;
		}

		/*
		 *
		 */
		std::unique_ptr<ImageLoader> getLoader(const std::string& filename) const
		{
			return std::make_unique<DevILLoader>(filename);
		}
};

}}}
#endif