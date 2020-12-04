#pragma once
#include <Texture.h>
#include "Actor.h"
#include "Mesh.h"

class Earth : public Actor
{
	public:
		Earth(glm::vec3 position, glm::quat rotation, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });

		///
		/// start override
		///
		bool start() override;

		///
		/// draw override
		///
		bool draw() override;

	private:
		///
		/// refrence to Mesh
		///
		Mesh m_mesh;
};