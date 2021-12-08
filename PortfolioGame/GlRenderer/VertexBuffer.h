#ifndef VERTEX_BUFFER_CLASS_H
#define VERTEX_BUFFER_CLASS_H

#include <glad/glad.h>

class VertexBuffer
{
public:
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void UnBind();
	void Delete();

	GLuint ID;

private:
	void Generate(GLfloat* vertices, GLsizeiptr size);
};

#endif // !VERTEX_BUFFER_CLASS_H
