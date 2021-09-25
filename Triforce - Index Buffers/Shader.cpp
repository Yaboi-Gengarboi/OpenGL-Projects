// OpenGL-Projects
// Triforce - Index Buffers
// Shader.cpp
// File created on 2021-09-24 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#include "Shader.hpp"

string get_file_contents(cstring filename)
{
	ifstream fin(filename, ios::binary);
	string contents;

	if (fin)
	{
		fin.seekg(0, ios::end);
		contents.resize(fin.tellg());
		fin.seekg(0, ios::beg);
		fin.read(&contents[0], contents.size());
		fin.close();
		return contents;
	}

	throw(errno);
	return contents;
}

Shader::Shader(cstring vertexFile, cstring fragmentFile)
{
	string vertexCode(get_file_contents(vertexFile));
	string fragmentCode(get_file_contents(fragmentFile));

	cstring vertexSource = vertexCode.c_str();
	cstring fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentShader);

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::activate()
{
	glUseProgram(id);
}

void Shader::destroy()
{
	glDeleteProgram(id);
}