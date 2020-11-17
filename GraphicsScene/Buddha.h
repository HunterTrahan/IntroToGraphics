#pragma once
#include <Texture.h>
#include "Actor.h"
#include "Mesh.h"

class Buddha : public Actor
{
	public:
		Buddha(glm::vec3 position, glm::quat rotation, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });

		bool start() override;
		bool draw() override;

	private:
		aie::Texture m_texture;
};

