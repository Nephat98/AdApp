#ifndef IO_H
#define IO_H

#include "TextureManager.h"
#include "ImageLoaderFactory.h"


namespace bgl {
namespace io {

/* 
 * (1) Gets the instance of the Image Loader Factory
 * (2) Creates Image Loader with Image Loader Factory
 * (3) Loads image with Image Loader
 */
inline std::shared_ptr<Image> LoadImage(const std::string& filename)
{
	auto imageLoader = (detail::ImageLoaderFactory::getInstance()).getLoader(filename);
	return imageLoader->load();
}

/*
 *
 */
inline std::shared_ptr<Texture> LoadTexture(const std::string& filename)
{
	return (detail::TextureManager::getInstance).getTexture(filename);
}

}}
#endif