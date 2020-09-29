#include "App.h"
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "App.h"
#include <cstdio>

bool App::start()
{
	return false;
}

bool App::end()
{
	return false;
}

bool App::update()
{
	return false;
}

bool App::fixedUpdate()
{
	return false;
}

bool App::draw()
{
	//Set the clear color
	glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

	//Enables the depth buffer
	glEnable(GL_DEPTH_TEST);
}
