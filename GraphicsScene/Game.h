#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera;

class Game
{
	public:
		Game();
		Game(int width, int height, const char* title);
		~Game();

		int run();

		bool start();
		bool update(double deltatime);
		bool draw();
		bool end();

		GLFWwindow* getWindow() { return m_window; }
		int getWidth() { return m_width; }
		int getHeight() { return m_height; }
		const char* getTitle() { return m_title; }

	protected:
		GLFWwindow* m_window;
		Camera* m_camera;
		//glm::mat4 m_view;
		//glm::mat4 m_projection;

	private:
		int m_width;
		int m_height;
		const char* m_title;
		
};