#pragma once
// "Copyright [2018] Gavan Adrian-George, 334CA"
#include <include/glm.h>

namespace Transform2D_Tema1
{
	// Matrice translatie
	inline glm::mat3 Translate(float translateX, float translateY)
	{
		return glm::transpose(
			glm::mat3(1, 0, translateX,
				0, 1, translateY,
				0, 0, 1)
		);
	}

	// Matrice scalare
	inline glm::mat3 Scale(float scaleX, float scaleY)
	{
		return glm::transpose(
			glm::mat3(scaleX, 0, 0,
				0, scaleY, 0,
				0, 0, 1)
		);
	}

	// Matrice rotatie
	inline glm::mat3 Rotate(float radians)
	{
		return glm::transpose(
			glm::mat3(cos(radians), -sin(radians), 0,
				sin(radians), cos(radians), 0,
				0, 0, 1)
		);
	}
}
