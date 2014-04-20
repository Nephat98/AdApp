























class Program
{
	private:
		std::shared_ptr<VertexShader> vertexShader;
		std::shared_ptr<FragmentShader> fragmentShader;
	
	protected:
		GLuint handle;
		
		void compile(void)
		{
			vertexShader.compile();
			fragmentShader.compile();
		}
		
		void link(void)
		{
			glLinkProgram(handle);
		}
		
	public:
		Program(void)
			: handle(glCreateProgram​())
		{}
		
		void setVertexShader(void)
		void setFragmentShader(coid)
		
		
		


void glAttachShader​(GLuint program​, GLuint shader​);


	public:
		
		
	
		
}
















