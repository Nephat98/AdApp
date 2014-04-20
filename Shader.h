#ifndef
#define 

namespace 
namespace

/*
 *
 */
class Shader
{
	private:
		GLuint handle;
		const GLenum type;
		
	public:
		Shader(GLenum type)
			: type(type), handle(glCreateShader​(type))
		{} 
		
		Shader(GLenum type, const std::string filename)
			: Shader(type)
		{
			load(filename);
			compile();
		}
		
		~Shader(void)
		{
			glDeleteShader(shader);
		}
		
		/*
		 *
		 */
		void load(const std::string filename)
		{
			std::ifstream file(filename.c_str());
			
			// Determines line count and reserves memory for it
			auto lineCount = std::count(std::istream_iterator<char>(file),
										std::istream_iterator<char>(), 
										'\n');	
			GLchar** lines = new GLchar*[lineCount];
			
			// Reads
			std::string currentLine;
	
			for(int i = 0; not file.eof(); ++i)
			{
				std::getline(file, currentLine);
				lines[i] = new GLchar[currentLine.size() + 1]('\0');
				std::copy(currentLine.begin(), currentLine.end(), lines[i]);
			}
			
			file.close();
			
			//
			glShaderSource(handle, lines.size(), lines.data(), nullptr);
			
			//
			for(int i = 0;i < lineCount; ++i)
				delete lines[i]
			delete[] lines;
		}
		
		/*
		 *
		 */
		void compile(void) const
		{
			// Tries to compile shader
			glCompileShader​(handle);
			
			// Checks whether shader could be compiled
			GLint isSuccessed;
			glGetShaderiv(handle, GL_COMPILE_STATUS, &isSuccessed);

			// In case the shader could not be compiled
			if(not isSuccessed)
			{
				// Retrieves length of log in characters
				GLint length = 0;
				glGetShaderiv(handle, GL_INFO_LOG_LENGTH​, &lentg);
				
				// Retrieves compile log characters 
			    std::string message(length);
				glGetShaderInfoLog​(handle, length, nullptr​, message.data()​);
				
				// Throws exception with the compile log
				throw std::exeption(message);
			}			
		}
};


class VertexShader : public Shader
{}

class FragmentShader : public Shader
{}

}};
#endif