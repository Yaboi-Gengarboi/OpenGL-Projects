// OpenGL-Projects
// Triforce - Index Buffers
// VAO.hpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#pragma once

#include "VBO.hpp"

class VAO
{
	public:

	GLuint id;

	VAO();

	void linkVBO(VBO vbo, GLuint layout);

	void bind();

	void unbind();

	void destroy();
};