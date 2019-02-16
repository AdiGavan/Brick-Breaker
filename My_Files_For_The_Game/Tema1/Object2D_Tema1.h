#pragma once
// "Copyright [2018] Gavan Adrian-George, 334CA"
#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D_Tema1
{
	// Functie pentru creare patrat
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	// Functie pentru creare cerc
	Mesh* CreateCircle(std::string name, glm::vec3 center, glm::vec3 color);
	//Functie pentru creare dreptunghi
	Mesh* CreateRectangle(std::string name, glm::vec3 leftBottomCorner, float length, float height, glm::vec3 color, bool fill = false);
}

