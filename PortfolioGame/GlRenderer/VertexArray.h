#ifndef VERTEX_ARRAY_CLASS_H
#define VERTEX_ARRAY_CLASS_H

#include <glad/glad.h>

#include "VertexBuffer.h"

class VertexArray
{
public:
	VertexArray();

	void LinkVertexBuffer(VertexBuffer vbo, GLuint layout);

	void Bind();
	void UnBind();
	void Delete();

	GLuint ID;

private:
	void Generate();
};

#endif // !VERTEX_ARRAY_CLASS_H
