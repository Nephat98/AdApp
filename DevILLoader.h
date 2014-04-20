#ifndef IMAGE_H
#define IMAGE_H

// Language dependencies
#include <mutex>

// External dependencies
#include "IL/IL.h"

// Internal dependencies
#inlude "ImageLoader.h"

namespace bgl {
namespace io {
namespace detail {

/*
 *
 */
class DevILLoader : public ImageLoader
{
	private:
		/*
		 *
		 */
		static std::mutex mutex;
		
		/*
		 * Initializes DevIL
		 */
		void initialize(void) const
		{
			static bool initialized = false;

			if(not initialized)
			{
				ilInit();
				ilOriginFunc(IL_LOWER_LEFT);
				initialized = true;
			}
		}
		
	public:
		DevILLoader(const std::string& filename)
			: ImageLoader(filename)
		{
			initialize();
		}
		
		virtual std::shared_ptr<Image> load(void)
		{
			mutex.lock();
			
			// Creating image
			ILuint handle = ilGenImage();
			ilBindImage(handle);

			// Loading image
			if(IL_FALSE == ilLoadImage(getFilename().c_str()))
				throw std::exception(/* TODO */);
			
			auto width  = ilGetInteger(IL_IMAGE_WIDTH);
			auto height = ilGetInteger(IL_IMAGE_HEIGHT);
			auto pixels = static_cast<GLfloat*>(ilGetData());
			
			// Converting image
			ilConvertImage(IL_RGBA, IL_FLOAT);
		
			mutex.unlock();

			// 
			auto image = std::make_shared<Image>(width, height, pixels);
			ilDeleteImage(handle);
			return image;
		}
};

}};
#endif