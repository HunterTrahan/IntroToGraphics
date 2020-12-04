
#include "Earth.h"

Earth::Earth(glm::vec3 position, glm::quat rotation, glm::vec3 scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

bool Earth::start()
{
	m_mesh.initializeQuad();

	return true;
}

bool Earth::draw()
{
	//Draw "Earth" mesh
	m_mesh.draw();

	return false;
}