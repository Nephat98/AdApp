#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "TextureManager.h"
#include "ImageLoaderFactory.h"

namespace bgl {
namespace io {

/*
 *
 */
class TextureManager
{
	private:
		static TextureManager* instance = nullptr;
		
		/*
		 *
		 */
		std::map<std::string, std::shared_ptr<Texture>> textures;
	
	protected:
		/*
		 *
		 */
		bool isLoaded(const std::string& filename)
		{
			return textures.find(filename) !=  textures.end();
		}
		
		/*
		 *
		 */
		void createTexture(const std::string& filename)
		{
			//
			auto imageLoader = (detail::ImageLoaderFactory::getInstance()).getLoader(filename);
			auto image = imageLoader->load();
			auto texture = std::make_shared<Texture>(image);
			
			// 
			textures.insert(std::make_pair(filename, texture);
			return texture;
		}
		
	public:
		/*
		 *
		 */
		std::shared_ptr<Texture> getTexture(const std::string& filename)
		{
			if(not isLoaded(filename))
				createTexture(filename);
			return textures[filename];
		}
		
		/*
		 *
		 */
		static TextureManager& getInstance(void)
		{
			if(instance == nullptr)
				instance = new TextureManager;
			return *instance;
		}
};

/* 
 * (1) Gets the instance of the Image Loader Factory
 * (2) Creates Image Loader with Image Loader Factory
 * (3) Loads image with Image Loader
 */
inline std::shared_ptr<Texture> LoadTexture(const std::string& filename)
{
	return (TextureManager::getInstance()).getTexture(filename);
}

}}
#endif