#pragma once
#include "Actor.h"

class Light
{
	public:
		///
		/// get the direction
		///
		glm::vec3 getDirection() { return m_direction; }

		///
		/// set the direction
		///
		void setDirection(glm::vec3 direction) { m_direction = direction; }

		///
		/// get the ambient
		///
		glm::vec3 getAmbient() { return m_ambient; }

		///
		/// set the ambient
		///
		void setAmbient(glm::vec3 ambient) { m_ambient = ambient; }

		///
		/// get the diffuse
		///
		glm::vec3 getDiffuse() { return m_diffuse; }

		///
		/// set the diffuse
		///
		void setDiffuse(glm::vec3 diffuse) { m_diffuse = diffuse; }

		///
		/// get the specular
		///
		glm::vec3 getSpecular() { return m_specular; }
		
		///
		/// set the specular
		///
		void setSpecular(glm::vec3 specular) { m_specular = specular; }

	private:
		///
		/// vector 3 fpr direction
		///
		glm::vec3 m_direction;

		///
		/// vector 3 for ambient
		///
		glm::vec3 m_ambient;

		///
		/// vector 3 for diffuse
		///
		glm::vec3 m_diffuse;

		///
		/// vector 3 for specular
		///
		glm::vec3 m_specular;
};