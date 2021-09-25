// OpenGL-Projects
// Triforce - Index Buffers
// main.cpp
// File created on 2021-09-22 by Justyn Durnford
// File last modified on 2021-09-24 by Justyn Durnford

#include "EBO.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"

// Vertex coordinates.
GLfloat vertices[] =
{
	// Lower-left corner.
	-0.5f, -0.5f * sqrt_3 / 3, 0.0f,
	// Lower-right corner.
	0.5f,  -0.5f * sqrt_3 / 3, 0.0f,
	// Upper corner.
	0.0f,  0.5f * sqrt_3 * 2 / 3, 0.0f,
	// Left midpoint.
	-0.5f / 2, 0.5f * sqrt_3 / 6, 0.0f,
	// Right midpoint.
	0.5f / 2, 0.5f * sqrt_3 / 6, 0.0f,
	// Bottom midpoint.
	0.0f, -0.5f * sqrt_3 / 3, 0.0f
};

GLuint indices[] =
{
	0, 3, 5,
	3, 2, 4,
	5, 4, 1
};

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Parameters: Width, Height, Name, Fullscreen?, ???
	GLFWwindow* window = glfwCreateWindow(800, 800, "Triforce", nullptr, nullptr);

	if (window == nullptr)
	{
		cout << "ERROR: Failed to create GLFW window." << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0, 0, 800, 800);

	Shader shader_program("default.vert", "default.frag");

	VAO vao1;
	vao1.bind();

	VBO vbo1(vertices, sizeof(vertices));
	EBO ebo1(indices, sizeof(indices));

	vao1.linkVBO(vbo1, 0);
	vao1.unbind();
	vbo1.unbind();
	ebo1.unbind();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader_program.activate();
		vao1.bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	vao1.destroy();
	vbo1.destroy();
	ebo1.destroy();
	shader_program.destroy();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}