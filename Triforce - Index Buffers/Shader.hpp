// OpenGL-Projects
// Triforce - Index Buffers
// Shader.hpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#pragma once

#include "Define.hpp"

string get_file_contents(cstring filename);

class Shader
{
	public:

	GLuint id;

	Shader(cstring vertexFile, cstring fragmentFile);

	void activate();

	void destroy();
};