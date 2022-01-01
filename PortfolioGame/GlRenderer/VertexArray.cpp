#include "VertexArray.h"

VertexArray::VertexArray()
{
	Generate();
}

void VertexArray::LinkAttribute(VertexBuffer vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	vbo.Bind();

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	vbo.UnBind();
}

void VertexArray::Bind()
{
	glBindVertexArray(ID);
}

void VertexArray::UnBind()
{
	glBindVertexArray(0);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::Generate()
{
	glGenVertexArrays(1, &ID);
}
