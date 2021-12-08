#ifndef ELEMENT_BUFFER_CLASS_H
#define ELEMENT_BUFFER_CLASS_H

#include <glad/glad.h>

class ElementBuffer
{
public:
	ElementBuffer(GLuint* indices, GLsizeiptr size);

	void Bind();
	void UnBind();
	void Delete();

	GLuint ID;

private:
	void Generate(GLuint* indices, GLsizeiptr size);
};

#endif // !ELEMENT_BUFFER_CLASS_H
