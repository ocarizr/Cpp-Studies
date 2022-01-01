#ifndef VERTEX_ARRAY_CLASS_H
#define VERTEX_ARRAY_CLASS_H

#include <glad/glad.h>

#include "VertexBuffer.h"

class VertexArray
{
public:
	VertexArray();

	void LinkAttribute(VertexBuffer vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void Bind();
	void UnBind();
	void Delete();

	GLuint ID;

private:
	void Generate();
};

#endif // !VERTEX_ARRAY_CLASS_H
