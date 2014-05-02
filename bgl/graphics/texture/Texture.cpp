#include "OpenGL.h"
#include "OpenIL.h"
#include "Texture.h"

#include <stack>

namespace bgl {
namespace renderer {

static std::stack<GLuint> availableTextureUnits;

Texture::Texture(void)
	: handle(0)
{
	initialize();
}

void Texture::initialize(void)
{
	static bool initialized = false;
	
	if(not initialized)
	{
		initializeOpenIL();
		initializeTextureUnits();
		initialized = true;
	}
}

void Texture::initializeOpenIL(void)
{
	ilInit();
	ilutInit();
}

void Texture::initializeTextureUnits(void)
{
	GLint count = 0;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &count);
	
	for(auto i = 0;i < count; ++i)
		availableTextureUnits.push(index);
}

void Texture::load(const std::string filename)
{
	handle = ilutLoadImage(filename.c_str());
}

GLuint Texture::getAvailableTextureUnit(void)
{
	if(availableTextureUnits.empty())
		 throw std::exception("No texture unit available");
	else index = availableTextureUnits.pop();
}

void Texture::bind(void)
{
	auto index = getAvailableTextureUnit();
	glActiveTexture(GL_TEXTURE_0 + index);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
}

}}