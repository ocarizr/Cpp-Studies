#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

Shader::Shader(std::vector<std::pair<ShaderType, std::string>> shaderSources)
{
	for (auto&& source : shaderSources)
	{
		GetShaderSource(source.first, source.second);
	}

	Compile();
}

Shader::~Shader()
{
	Delete();
}

void Shader::Activate()
{
	if (m_compiled)
	{
		glUseProgram(ID);
	}
}

void Shader::Compile()
{
	std::vector<GLuint> shaders;
	for (auto&& sourcepair : m_shadersSource)
	{
		GLuint shader = glCreateShader(TranslateShaderType(sourcepair.first));
		const char* source = sourcepair.second.c_str();
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);
		CompileErrors(shader, ShaderTypeToStr(sourcepair.first));
		shaders.push_back(shader);
	}

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program

	for (auto&& shader : shaders)
	{
		glAttachShader(ID, shader);
	}

	// Wrap-up/Link all the shaders together into the shader program
	glLinkProgram(ID);
	CompileErrors(ID, "PROGRAM");

	// Delete the now useless Vertex and Fragment Shader Objects
	for (auto&& shader : shaders)
	{
		glDeleteShader(shader);
	}

	m_shadersSource.clear();
	m_compiled = true;
}

void Shader::Delete()
{
	glDeleteProgram(ID);
	ID = 0u;
	m_compiled = false;
}

void Shader::GetShaderSource(ShaderType type, std::string filename)
{
	std::string filePath = "..\\resources\\shaders\\" + filename;
	std::ifstream in(filePath, std::ios::binary);
	if (in)
	{
		std::string content;
		in.seekg(0, std::ios::end);
		content.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&content[0], content.size());
		in.close();
		m_shadersSource.emplace_back(type, std::move(content));
		return;
	}
	throw(errno);
}

constexpr GLuint Shader::TranslateShaderType(ShaderType type) const
{
	switch (type)
	{
	case ShaderType::Fragment:
		return GL_FRAGMENT_SHADER;
	case ShaderType::Vertex:
		return GL_VERTEX_SHADER;
	case ShaderType::Compute:
		return GL_COMPUTE_SHADER;
	case ShaderType::Geometry:
		return GL_GEOMETRY_SHADER;
	}
}

constexpr const char* Shader::ShaderTypeToStr(ShaderType type) const
{
	switch (type)
	{
	case ShaderType::Fragment:
		return "FRAGMENT";
	case ShaderType::Vertex:
		return "VERTEX";
	case ShaderType::Compute:
		return "COMPUTE";
	case ShaderType::Geometry:
		return "GEOMETRY";
	}
}

void Shader::CompileErrors(uint32_t shader, std::string type)
{
	GLint hasCompiled = 0;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for: " << type << "\n" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "SHADER_LINKING_ERROR for: " << type << "\n" << std::endl;
		}
	}
}
