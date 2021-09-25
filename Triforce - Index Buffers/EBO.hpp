// OpenGL-Projects
// Triforce - Index Buffers
// EBO.hpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#pragma once

#include "Define.hpp"

class EBO
{
	public:

	GLuint id;

	EBO(GLuint* indices, GLsizeiptr size);

	void bind();

	void unbind();

	void destroy();
};