#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>

#include <vector>
#include <string>
#include <utility>

class Shader
{
public:
	enum class ShaderType : uint8_t
	{
		Fragment,
		Vertex,
		Geometry,
		Compute
	};

	Shader() = default;
	Shader(std::vector<std::pair<ShaderType, std::string>> shaderSources);
	~Shader();

	void Activate();
	void Compile();
	void Delete();

	void GetShaderSource(ShaderType type, std::string filename);
	
	[[nodiscard]] const bool IsCompiled() const { return m_compiled; }

	GLuint ID = 0u;

private:
	constexpr GLuint TranslateShaderType(ShaderType type) const;
	constexpr const char* ShaderTypeToStr(ShaderType type) const;

	void CompileErrors(uint32_t shader, std::string type);

	std::vector<std::pair<ShaderType, std::string>> m_shadersSource;
	bool m_compiled = false;
};

#endif // !SHADER_CLASS_H
