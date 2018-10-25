//#include <glew/glew.h>

#define GLFW_INCLUDE_GLU

#include "LowLevelRenderer.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio>

# pragma comment (lib, "glu32.lib")

void drawCube()
{
	GLfloat vertices[] =
	{
		-1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
		1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
		-1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
		-1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
		-1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
		-1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
	};

	GLfloat colors[] =
	{
		0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
		1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
		0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
		0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
		0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
		0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
	};

	static float alpha = 0;
	//attempt to rotate cube
	glRotatef(alpha, 0, 1, 0);

	/* We have a color array and a vertex array */
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	/* Send data : 24 vertices */
	glDrawArrays(GL_QUADS, 0, 24);

	/* Cleanup states */
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	alpha += 1;
}


static void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void LowLevelRenderer::loop() {
	

	while (!glfwWindowShouldClose(m_Window))
	{
		// Scale to window size
		GLint windowWidth, windowHeight;
		glfwGetWindowSize(m_Window, &windowWidth, &windowHeight);
		glViewport(0, 0, windowWidth, windowHeight);

		// Draw stuff
		glClearColor(0.0, 0.8, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION_MATRIX);
		glLoadIdentity();
		gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

		glMatrixMode(GL_MODELVIEW_MATRIX);
		glTranslatef(0, 0, -5);

		drawCube();

		// Update Screen
		glfwSwapBuffers(m_Window);

		// Check for any input, or window movement
		glfwPollEvents();
	}

	glfwDestroyWindow(m_Window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

}

LowLevelRenderer::~LowLevelRenderer() {
	//SAFE_DELETE(m_VertexShader);
	//SAFE_DELETE(m_FragmentShader);
}

void LowLevelRenderer::init() {
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(1024, 620, "TEST", NULL, NULL);

	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	// Get info of GPU and supported OpenGL version
	//printf("Renderer: %s\n", glGetString(GL_RENDERER));
	//printf("OpenGL version supported %s\n", glGetString(GL_VERSION));

	glEnable(GL_DEPTH_TEST); // Depth Testing
	//glDepthFunc(GL_LEQUAL);
	//glDisable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	m_Window = window;
	return;
}
