
class Uniform
{
	private:
		Program program;
		GLint location;
		
		/*
		 *
		 */
		void determineLocation(void)
		{
			location = glGetUniformLocation​(program.getHandle(), name.c_str()​);
		}
	
	public:
		Uniform(Program program, const std::string name)
			: program(program), name(name)
		{
			determineLocation();
		}
		
		void setValue()
		
};

class Sampler : public Uniform
{
	private:
		using Sampler::setValue
		using Sampler::getValue
		
	public:
		Sampler(Program program, const std::string name)
			: Uniform(program, name)
		{}
		
		void setTexture(const Texture texture)
		{
			setUniform(texture.getTextureUnit());
		}
};










				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				/*
				 *
				 */
				void setValue(GLfloat value)
				{
					glUniform1f(location, value);
				}
				
				void setValue(GLdouble value)
				{
					glUniform1d(location, value);
				}
				
				void setValue(GLint value)
				{
					glUniform1i(location, value);
				}
				
				void setValue(GLuint value)
				{
					glUniform1ui(location, value);
				}
				
				
				
				
				getName()
				{
					return name;
				}
				
	
				
				
				
				
				
		
		};
		
		
	private:
		std::unordered_map<std::string, Uniform> uniforms;
		
		void validate(void);
		void compile(void);
		void link();
		
	public:
		
		Uniform getUniform(const std::string name)
		{
			return uniforms[name];
		}
};



 