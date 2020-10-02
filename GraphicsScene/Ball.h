#pragma once
#include "Actor.h"
#include <glm/glm.hpp>

class Ball : public Actor	
{
	public:
		Ball();
		Ball(glm::vec4 color, float radius);
		~Ball() {}

		bool draw() override;

	protected:
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		glm::vec4 m_color;
		float m_radius;
};

