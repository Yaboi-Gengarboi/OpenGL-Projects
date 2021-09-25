// OpenGL-Projects
// Triforce - Index Buffers
// VBO.cpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#include "VBO.hpp"

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::destroy()
{
	glDeleteBuffers(1, &id);
}