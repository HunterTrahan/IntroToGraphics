#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int x;

int main()
{
	//Initialize GLFW
	if (!glfwInit())
	{
		return -1;
	}

	//Create window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	//Ensure that the window was created
	if (window == nullptr)
	{
		glfwTerminate();

		return -2;
	}

	//Set the window as the target
	glfwMakeContextCurrent(window);

	//Load OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();

		return -3;
	}

	//Print the OpenGL version number
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", major, minor);

	//Keep the window open until it is closed
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		//Game goes here

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Close the window
	glfwDestroyWindow(window);

	//Terminate GLFW
	glfwTerminate();

	return 0;
}