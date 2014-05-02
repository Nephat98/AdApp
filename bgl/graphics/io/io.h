#ifndef IO_H
#define IO_H

#include "TextureManager.h"
#include "ImageLoaderFactory.h"


namespace bgl {
namespace io {

/* 
 * (1) Gets the instance of the Image Loader Factory
 * (2) Creates an Image Loader with the Image Loader Factory
 * (3) Loads image with created Image Loader
 */
inline std::shared_ptr<Image> LoadImage(const std::string& filename)
{
	auto imageLoaderFactory = ImageLoaderFactory::getInstance();
	auto imageLoader = imageLoaderFactory.getLoader(filename);
	auto image = imageLoader->load();
	return image;
}

/*
 * (1) Gets instance of the Texture Manager
 * (2) The Texture Manager loads the image and creates a texture from it 
 */
inline std::shared_ptr<Texture> LoadTexture(const std::string& filename)
{
	auto textureManager = TextureManager::getInstance();
	auto texture = textureManager.getTexture(filename);
	return texture;
}

}}
#endif