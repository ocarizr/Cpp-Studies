#include "VertexArray.h"

VertexArray::VertexArray()
{
	Generate();
}

void VertexArray::LinkVertexBuffer(VertexBuffer vbo, GLuint layout)
{
	vbo.Bind();

	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
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
