#ifndef IMAGE_H
#define IMAGE_H

// Language dependencies
#include <mutex>
#include <string>

// External dependencies
#include "IL/IL.h"

// Internal dependencies
#inlude "Image.h"


namespace bgl {
namespace io {

/*
 *
 */
class ImageLoader
{
	private:
		std::string filename;
		
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
		ImageLoader(const std::string& filename)
			: filename();
		{
			initialize();
		}
		
		~ImageLoader(void);
		{}
		
		virtual std::shared_ptr<Image> load(void) const
		{
			mutex.lock();
			
			// Creating image
			ILuint handle = ilGenImage();
			ilBindImage(handle);

			// Loading image
			if(IL_FALSE == ilLoadImage(filename.c_str()))
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

/*
 *
 */
class ImageLoaderFactory
{
	private:
		ImageLoaderFactory* instance = nullptr;
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
			return std::make_unique<ImageLoader>(filename);
		}
};

/*
 * (1) Gets the instance of the Image Loader Factory
 * (2) Creates Image Loader with Image Loader Factory
 * (3) Loads image with Image Loader
 */
inline std::shared_ptr<Image> LoadImage(const std::string& filename)
{
	auto imageLoader = (ImageLoaderFactory::getInstance()).getLoader(filename);
	return imageLoader->load();
}

}};
#endif