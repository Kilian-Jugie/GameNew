#include "Callbacks.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
namespace {

	static void error_callback(int error, const char* description) {
		fprintf(stderr, "Error: %s\n", description);
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}