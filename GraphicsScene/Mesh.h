#pragma once
#include <glm/glm.hpp>
#include <Texture.h>

class Mesh
{
	public:
		///
		/// struct holding the position, color, normal, and textCoord
		///
		struct Vertex {
			glm::vec4 position;
			glm::vec4 normal;
			glm::vec4 color;
			glm::vec2 texCoord;
		};

	public:
		Mesh() : m_triCount(0), m_vao(0), m_vbo(0), m_ibo(0) {}
		~Mesh();

		///
		/// initialize the vertexCount, vertices, indexCount, indices
		///
		void initialize(
			unsigned int vertexCount,
			const Vertex* vertices,
			unsigned int indexCount = 0,
			unsigned int* indices = nullptr);

		///
		/// initializes a quad
		///
		void initializeQuad();

		///
		/// initializes a cube
		///
		void initializeCube();

		///
		/// draws the mesh
		///
		virtual void draw();

	protected:
		///
		/// int for triCount
		///
		unsigned int m_triCount;

		///
		/// int for vao, vbo, and ibo
		///
		unsigned int m_vao, m_vbo, m_ibo;
};