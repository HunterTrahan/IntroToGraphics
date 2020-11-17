#include "Buddha.h"

Buddha::Buddha(glm::vec3 position, glm::quat rotation, glm::vec3 scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

bool Buddha::start()
{
	//Load Buddha texture
	if (!m_texture.load("Jade.jpg")) 
	{
		printf("Failed to load Jade.jpg.\n");
		return false;
	}

	return true;
}

bool Buddha::draw()
{
	//Bind texture
	m_texture.bind(0);

	return false;
}
