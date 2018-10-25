#include "Shader.h"

void Shader::compile() {
	m_Shader = glCreateShader(m_Type);
	glShaderSource(m_Shader, 1, &m_Text, NULL);
	glCompileShader(m_Shader);
}
