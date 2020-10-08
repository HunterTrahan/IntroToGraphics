#include "Game.h"
#include "Camera.h"
#include <cstdio>

Game::Game()
{
	m_width = 1280;
	m_height = 720;
	m_title = "Computer Graphics";

}

Game::Game(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

Game::~Game()
{
}

int Game::run()
{
	bool updating = true;
	bool drawing = true;

	double deltaTime = 0.0f;
	double timeOfPreviousUpdate = 0.0f;

	if (!start())
	{
		return -1;
	}

	while (updating && drawing)
	{
		//Get the current time
		double timeOfCurrentUpadte = glfwGetTime();

		//Find the change in time
		deltaTime = timeOfCurrentUpadte - timeOfPreviousUpdate;

		//STore the current time for the next loop
		timeOfPreviousUpdate = timeOfCurrentUpadte;

		updating = update(deltaTime);
		drawing = draw();
	}

	if (!end())
	{
		return -2;
	}

	return 0;
}

bool Game::start()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Initialize GLFW
	if (!glfwInit())
	{
		return false;
	}

	//Create window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	//Ensure that the window was created
	if (m_window == nullptr)
	{
		glfwTerminate();

		return false;
	}

	//Set the window as the target
	glfwMakeContextCurrent(m_window);

	//Load OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();

		return false;
	}

	//Print the OpenGL version number
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", major, minor);

	//Initialize Gizmos
	aie::Gizmos::create(10000, 10000, 10000, 10000);

	//Set up camera
	m_camera = new Camera(this);
	m_camera->setPosition({ 10, 10, 10 });
	m_camera->setYaw(-135.0);
	m_camera->setPitch(-35.0f);

	//Set the clear color
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	//Enables the depth buffer
	glEnable(GL_DEPTH_TEST);

	//Create a placeholder for a starting position and rotation
	m_startActor = new Actor({ 10.0f, 5.0f, 10.0f }, glm::vec3(0.0f, -1.0f, 1.0f));
	//Create a placeholder for an ending position and rotation
	m_endActor = new Actor({ -10.0f, 0.0f, -10.0f }, glm::vec3(0.0f, 1.0f, -1.0f));

	//Create a bone
	m_bone = new Bone({
		{ 10.0f, 5.0f, 10.0f }, glm::vec3(0.0f, -1.0f, 1.0f) },
		{ { -10.0f, 0.0f, -10.0f }, glm::vec3(0.0f, 1.0f, -1.0f) }
	);

	m_bone2 = new Bone({
		{ 1.0f, 5.0f, 1.0f }, glm::vec3(0.0f, -1.0f, 1.0f) },
		{ { -1.0f, 0.0f, -1.0f }, glm::vec3(0.0f, 1.0f, -1.0f) }
	);

	//Create a skeleton
	m_skeleton = new Skeleton();
	//Add the bone to the skeleton
	m_skeleton->addBone(m_bone);
	m_skeleton->addBone(m_bone2);

	return true;
}

bool Game::update(double deltaTime)
{
	glfwPollEvents();

	//Keep the window open until it is closed
	if (glfwWindowShouldClose(m_window) || glfwGetKey(m_window, GLFW_KEY_ESCAPE))
	{
		return false;
	}

	m_camera->update(deltaTime);

	m_skeleton->update(deltaTime);

	return true;
}

bool Game::draw()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Clear the Gizmos
	aie::Gizmos::clear();

	aie::Gizmos::addTransform(mat4(1), 2.0f);

	vec4 white(1, 1, 1, 1);
	vec4 grey(0.5f, 0.5f, 0.5f, 1);

	for (int i = 0; i < 21; ++i)
	{
		aie::Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : grey);

		aie::Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : grey);
	}

	m_skeleton->draw();

	aie::Gizmos::draw(m_camera->getProjectionMatrix(m_width, m_height) * m_camera->getViewMatrix());

	glfwSwapBuffers(m_window);

	return true;
}

bool Game::end()
{
	delete m_startActor;
	delete m_endActor;
	delete m_bone;
	delete m_skeleton;

	//Destroy Gizmos
	aie::Gizmos::destroy();

	//Close the window
	glfwDestroyWindow(m_window);

	//Terminate GLFW
	glfwTerminate();

	return true;
}
