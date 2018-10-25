#pragma once
#include "Types.h"
//#include "Callbacks.h"

class LowLevelRenderer {
	GLFWwindow* m_Window;
	Shader* m_VertexShader, *m_FragmentShader;
	GLuint m_Program;
	GLint m_MVPLocation, m_VPOSLocation, m_VCOLLocation;
public:
	LowLevelRenderer() {}
	~LowLevelRenderer();

	void init();
	void loop();
};