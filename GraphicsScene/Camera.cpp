#include "Camera.h"
#include "Game.h"

glm::mat4 Camera::getViewMatrix()
{
	//Convert degrees to radians
	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);

	//Calulate the forward vector
	glm::vec3 forward(cos(pitchRadians) * cos(yawRadians),
					  sin(pitchRadians), cos(pitchRadians) * sin(yawRadians));				  
	
	//Return the view matrix
	return glm::lookAt(m_position, m_position + forward, glm::vec3(0, 1, 0));
}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(glm::pi<float>() * 0.25f,
							width / height, 
						    0.1f, 1000.0f);
}

bool Camera::update(double deltatime)
{
	int keyForawrd = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_A;
	int keyRight = GLFW_KEY_D;
	int keyUp = GLFW_KEY_SPACE;
	int keyDown = GLFW_KEY_LEFT_CONTROL;
	
	//Convert degrees to radians
	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);

	//Calulate the forward vector
	glm::vec3 forward(cos(pitchRadians) * cos(yawRadians),
		sin(pitchRadians), cos(pitchRadians) * sin(yawRadians));

	//Calulate the right vector
	glm::vec3 right(-sin(yawRadians), 0, cos(yawRadians));

	//calculate the up vector
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	//Check input
	if (glfwGetKey(m_instance->getWindow(), keyForawrd))
	{
		//Move forward
		m_position += forward * (float)deltatime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyBack))
	{
		//Move backwards
		m_position -= forward * (float)deltatime;
	}

	if (glfwGetKey(m_instance->getWindow(), keyLeft))
	{
		//Move left
		m_position -= right * (float)deltatime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyRight))
	{
		//Move right
		m_position += right * (float)deltatime;
	}

	if (glfwGetKey(m_instance->getWindow(), keyUp))
	{
		//Move up
		m_position += up * (float)deltatime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyDown))
	{
		//Move forward
		m_position -= up * (float)deltatime;
	}

	double currentMouseX = 0.0;
	double currentMouseY = 0.0;
	double previousMouseX = 0.0;
	double previousMouseY = 0.0;

	//Get current mouse coordinates
	glfwGetCursorPos(m_instance->getWindow(), &currentMouseX, &currentMouseY);

	//Turn the camera based on the change in mouse position (delta mouse)
	m_yaw += m_turnSpeed * (currentMouseX - previousMouseX);
	m_pitch -= m_turnSpeed * (currentMouseY - previousMouseY);

	//Store previous mouse coordinates
	previousMouseX = currentMouseX;
	previousMouseY = currentMouseY;



	return true;
}
