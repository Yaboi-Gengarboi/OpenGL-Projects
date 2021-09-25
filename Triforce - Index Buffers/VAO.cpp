// OpenGL-Projects
// Triforce - Index Buffers
// VAO.cpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#include "VAO.hpp"

VAO::VAO()
{
	glGenVertexArrays(1, &id);
}

void VAO::linkVBO(VBO vbo, GLuint layout)
{
	vbo.bind();

	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(layout);

	vbo.unbind();
}

void VAO::bind()
{
	glBindVertexArray(id);
}

void VAO::unbind()
{
	glBindVertexArray(0);
}

void VAO::destroy()
{
	glDeleteVertexArrays(1, &id);
}