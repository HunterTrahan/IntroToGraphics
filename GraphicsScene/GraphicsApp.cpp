#include "GraphicsApp.h"
#include <cstdio>

GraphicsApp::GraphicsApp()
{
	m_width = 1280;
	m_height = 720;
	m_title = "Computer Graphics";

}

GraphicsApp::GraphicsApp(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

GraphicsApp::~GraphicsApp()
{
}

int GraphicsApp::run()
{
	bool updating = true;
	bool drawing = true;

	if (!start())
	{
		return -1;
	}

	while (updating && drawing)
	{
		updating = update();
		drawing = draw();
	}

	if (!end())
	{
		return -2;
	}

	return 0;
}

bool GraphicsApp::start()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Initialize GLFW
	if (!glfwInit())
	{
		return -1;
	}

	//Create window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	//Ensure that the window was created
	if (m_window == nullptr)
	{
		glfwTerminate();

		return -2;
	}

	//Set the window as the target
	glfwMakeContextCurrent(m_window);

	//Load OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();

		return -3;
	}

	//Print the OpenGL version number
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", major, minor);

	//Initialize Gizmos
	aie::Gizmos::create(10000, 10000, 10000, 10000);

	//Set up camera
	m_view = glm::lookAt(vec3(10, 10, 10), vec3(0, 0, 0), vec3(0, 1, 0));
	m_projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.0f);

	//Set the clear color
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	//Enables the depth buffer
	glEnable(GL_DEPTH_TEST);
}

bool GraphicsApp::update()
{
	glfwPollEvents();

	//Keep the window open until it is closed
	if (glfwWindowShouldClose(m_window) || glfwGetKey(m_window, GLFW_KEY_ESCAPE))
	{
		return false;
	}

	return true;
}

bool GraphicsApp::draw()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Clear the Gizmos
	aie::Gizmos::clear();

	aie::Gizmos::addTransform(mat4(1));

	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i < 21; ++i)
	{
		aie::Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : black);

		aie::Gizmos::addLine(vec3(10, 0, -10 + 1),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}

	aie::Gizmos::draw(m_projection * m_view);

	glfwSwapBuffers(m_window);

	return true;
}

bool GraphicsApp::end()
{
	//Destroy Gizmos
	aie::Gizmos::destroy();

	//Close the window
	glfwDestroyWindow(m_window);

	//Terminate GLFW
	glfwTerminate();

	return true;
}
