#include "bgl/io/io.h"

using namespace bgl;

void main(int argc, const char** argv)
{
	// (1) Initialize BGL with all it subsystems
	Initialize(argc, argv);
	
	// (2) Loads a texture
	auto texture = io::LoadTexture("texture.jpg");
	
	// (3) Loads a shader program and configures it
	auto program = io::LoadProgram("vertex.vs", "pixel.ps");
	
	// TODO: Configure uniforms
}