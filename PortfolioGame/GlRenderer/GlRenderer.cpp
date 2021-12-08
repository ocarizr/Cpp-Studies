// GlRenderer.cpp : Defines the functions for the static library.
//

#include "framework.h"
#include "Extern.h"

#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ElementBuffer.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

	// Triangle vertices coordinates
GLfloat vertices[] =
{
	-0.5f,		-0.5f * float(sqrt(3)) / 3,		0.f, // Lower left corner
	0.5f,		-0.5f * float(sqrt(3)) / 3,		0.f, // Lower right corner
	0.f,		0.5f * float(sqrt(3)) * 2 / 3,	0.f, // Upper corner
	-0.5f / 2,	0.5f * float(sqrt(3)) / 6,		0.f, // Inner left
	0.5f / 2,	0.5f * float(sqrt(3)) / 6,		0.f, // Inner right
	0.f,		-0.5f * float(sqrt(3)) / 3,		0.f // Inner down
};

GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

// TODO: This is an example of a library function
void fnGlRenderer()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using (4.6)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	// Tell GLFW we are using the CORE profile
	// Only modern OpenGL functions are available
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "", nullptr, nullptr);
	// Error check if the window fails to create
	if (window == nullptr)
	{
		std::cout << "Failed to create the window" << std::endl;
		glfwTerminate();
		return;
	}

	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();
	// Set the viewport of OpenGL in the window
	// Now it goes from x = 0, y = 0 to x = 800 to y = 800
	glViewport(0, 0, 800, 800);

	Shader shader;
	shader.GetShaderSource(Shader::ShaderType::Fragment, "fragment.frag");
	shader.GetShaderSource(Shader::ShaderType::Vertex, "vertex.vert");
	shader.Compile();

	VertexArray vao;
	vao.Bind();

	VertexBuffer vbo(vertices, sizeof(vertices));
	ElementBuffer ebo(indices, sizeof(indices));
	vao.LinkVertexBuffer(vbo, 0);

	vao.UnBind();
	vbo.UnBind();
	ebo.UnBind();

	// Bind both the VBO and VAO to 0, so that we don't accidentaly modify them
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Set a background color (light grey)
	glClearColor(0.8f, 0.8f, 0.85f, 1.f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the front buffer with the back buffer
	glfwSwapBuffers(window);

	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.8f, 0.8f, 0.85f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Activate();
		vao.Bind();

		// Draw the triangle using the indices and the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the front buffer with the back buffer
		glfwSwapBuffers(window);

		// Take care of all GLFW events like window resizing, etc.
		glfwPollEvents();
	}

	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	shader.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW
	// Must terminate after an Init call
	glfwTerminate();
}
