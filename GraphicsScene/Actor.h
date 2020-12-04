#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

class Actor
{
	public:
		Actor() {}
		Actor(glm::vec3 position, glm::quat rotation, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });
		~Actor() {}

		///
		/// Virtual bool for start that returns true
		///
		virtual bool start() { return true; }

		///
		/// Virtual bool for update that returns true
		///
		virtual bool update(double deltaTime) { return true; }

		///
		/// Virtual bool for draw that returns true
		///
		virtual bool draw() { return true; }

		///
		/// Virtual bool for end that returns true
		///
		virtual bool end() { return true; }

		///
		/// Gets the position
		///
		glm::vec3 getPosition() { return m_position; }

		///
		/// Set the position
		///
		void setPosition(glm::vec3 position) { m_position = position; }

		///
		/// Gets the rotation
		///
		glm::quat getRotation() { return m_rotation; }

		///
		/// Set the rotation
		///
		void setRotation(glm::quat rotation) { m_rotation = rotation; }
		
		///
		/// Gets the position
		///
		glm::vec3 getScale() { return m_scale; }

		///
		///Set the scale
		///
		void setScale(glm::vec3 scale) { m_scale = scale; }

		///
		/// Gets the position
		///
		glm::mat4 getTransform();

		///
		/// Get the parent
		///
		Actor* getParent() { return m_parent; }

		///
		/// set the parrent
		///
		void setParent(Actor* parent) { m_parent = parent; }

		///
		/// Get the Parent Position
		///
		glm::vec3 getParentPosition();

		///
		/// Get the parent rotation
		///
		glm::quat getParentRotation();

	protected:

		///
		/// vecctor 3 for position
		///
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };

		///
		/// Quaternion for rotation
		///
		glm::quat m_rotation{ 1.0f, 0.0f, 0.0f, 0.0f };

		///
		/// vector 3 for scale
		///
		glm::vec3 m_scale{ 1.0f, 1.0f, 1.0f };

	private:

		///
		/// sets m_parent to nullptr
		///
		Actor* m_parent = nullptr;
};