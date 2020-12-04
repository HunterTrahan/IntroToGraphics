#pragma once
#include "Game.h"
#include "Actor.h"

class Camera : public Actor
{
	public:
		Camera(Game* instance) { m_instance = instance; }
		~Camera() {}

		///
		/// matrix 4 to get the view matrix
		///
		glm::mat4 getViewMatrix();

		///
		/// matrix 4 to get the projection matrix
		///
		glm::mat4 getProjectionMatrix(float width, float height);

		///
		/// get the yaw
		///
		float getYaw();

		///
		/// set the yaw
		///
		void setYaw(float degrees);

		///
		/// get the Pitch
		///
		float getPitch();

		///
		/// set the pitch
		///
		void setPitch(float degrees);

		///
		/// update the camera
		///
		bool update(double deltaTime) override;

	private:
		///
		/// pointer to the game instance
		///
		Game* m_instance;

		///
		/// deafult yaw value
		///
		float m_yaw = 0.0f; //theta

		///
		/// deafult pitch value
		///
		float m_pitch = 0.0f; //phi

		///
		/// deafult move speed value
		///
		float m_moveSpeed = 10.0f;

		///
		/// deafult turn speed value
		///
		float m_turnSpeed = 0.04f;

		///
		/// double current mouse x
		///
		double m_currentMouseX = 0.0;

		///
		/// double current mouse y
		///
		double m_currentMouseY = 0.0;

		///
		/// double previous mouse x
		///
		double m_previousMouseX = 0.0;

		///
		/// double previous mouse y
		///
		double m_previousMouseY = 0.0;
};