#pragma once
#include <string>
#include "Types.h"

class Shader {
	const char* m_Text;
	GLenum m_Type;
	GLuint m_Shader;
public:

	Shader(const char* shaderText, GLenum shaderType) : m_Text(shaderText) {}

	void compile();
	inline GLuint get() const {
		return m_Shader;
	}
};