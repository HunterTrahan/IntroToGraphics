#include "Ball.h"
#include <Gizmos.h>

Ball::Ball()
{
	m_color = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
	m_radius = 1.0f;
}

Ball::Ball(glm::vec4 color, float radius)
{
	m_color = color;
	m_radius = radius;
}

bool Ball::draw()
{
	//Build a transform matrix
	glm::mat4 transform = glm::translate(m_position) * glm::toMat4(m_rotation);

	//Draw the transform
	aie::Gizmos::addTransform(transform, m_radius * 2.0f);

	//Draw the ball
	//aie::Gizmos::addSphere(m_position, m_radius, 16, 16, m_color);
	aie::Gizmos::addSphere(glm::vec3(0.0f), m_radius, 6.0f * m_radius, 6.0f * m_radius, m_color, &transform);

	return true;
}
