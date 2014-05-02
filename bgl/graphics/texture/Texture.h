














namespace bgl {
namespace renderer {

/*
 *
 */
class Texture
{
	private:
		GLuint handle = 0;
		
	public:
		Texture(void)
		{
			setImage();
		}
		
		void setImage()
		
		GLuint getHandle(void) const
		{
			return handle;
		}
};

/*
 * (1) Loads the texture image file
 * (2) Creates new texture by passing an image to it
 */
inline std::shared_ptr<Texture> LoadTexture(const std::string& filename)
{
	auto image = LoadImage(filename);
	return std::make_shared<Texture>(*image);
}

}}
#endif