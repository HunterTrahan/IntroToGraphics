#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>


using glm::vec3;
using glm::vec4;
using glm::mat4;

class App
{
	public:
		App();
		~App();

		bool start();
		bool end();
		bool update();
		bool fixedUpdate();
		bool draw();
};