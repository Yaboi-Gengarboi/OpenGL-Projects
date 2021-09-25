// OpenGL-Projects
// Triforce - Index Buffers
// VBO.hpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#pragma once

#include "Define.hpp"

class VBO
{
	public:

	GLuint id;

	VBO(GLfloat* vertices, GLsizeiptr size);

	void bind();

	void unbind();

	void destroy();
};