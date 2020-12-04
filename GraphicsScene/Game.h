#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <Gizmos.h>
#include <Texture.h>
#include "OBJMesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Light.h"
#include "Earth.h"

class Camera;

class Game
{
	public:
		Game();
		Game(int width, int height, const char* title);
		~Game();

		///
		/// Runs the game
		///
		int run();

		///
		/// starts the game
		///
		bool start();

		///
		/// updates the game
		///
		bool update(double deltaTime);

		///
		/// draws objects to the screen
		///
		bool draw();

		///
		/// closes the game
		///
		bool end();

		///
		/// get the window
		///
		GLFWwindow* getWindow() { return m_window; }

		///
		/// get the width
		///
		int getWidth() { return m_width; }

		///
		/// get the height
		///
		int getHeight() { return m_height; }

		///
		/// get the title
		///
		const char* getTitle() { return m_title; }

	protected:
		///
		/// pointer to the window
		///
		GLFWwindow* m_window;

		///
		/// pointer to the camera
		///
		Camera* m_camera;

		///
		/// refrence to the shader
		///
		aie::ShaderProgram	m_shader;

		///
		/// refrence to the light
		///
		Light m_light;

		///
		/// refrence to the obj mesh
		///
		aie::OBJMesh		m_objMesh;

		///
		/// refrence to the obj texture
		///
		aie::Texture		m_objTexture;

		///
		/// refrence to the mesh transform
		///
		glm::mat4			m_meshTransform;

		///
		/// pointer to the earth
		///
		Earth* m_earth;

		///
		/// refrence to the mesh
		///
		Mesh				m_mesh;

		///
		/// refrence to the texture
		///
		aie::Texture		m_texture;

	private:
		///
		/// int for the width and height
		///
		int m_width, m_height;

		///
		/// charcater pointer for the title
		///
		const char* m_title;
};