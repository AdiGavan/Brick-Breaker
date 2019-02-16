// "Copyright [2018] Gavan Adrian-George, 334CA"
#include "Object2D_Tema1.h"

#include <Core/Engine.h>

// Functie pentru creare patrat
Mesh* Object2D_Tema1::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

// Functie pentru crearea unui cerc
Mesh* Object2D_Tema1::CreateCircle(std::string name, glm::vec3 center, glm::vec3 color)
{
	std::vector<VertexFormat> vertices;
	// Se adauga centrul in vectorul varfurilor.
	vertices.push_back(VertexFormat(center, color));

	// Se adauga 360 de puncte (valorile punctelor de pe cercul trigonometric pentru fiecare din cele 360 de grade)
	for (int i = 0; i < 360; ++i) {
		vertices.push_back(VertexFormat(center + glm::vec3(sin(RADIANS(i)), cos(RADIANS(i)), 0), color));
	}

	Mesh* circle = new Mesh(name);
	
	// Se formeaza triunghiurile
	std::vector<unsigned short> indices;
	
	for (int i = 0; i < 360; ++i) {
		indices.push_back(0);
		indices.push_back(i);
		indices.push_back(i + 1);
	}

	indices.push_back(0);
	indices.push_back(359);
	indices.push_back(1);
	
	circle->InitFromData(vertices, indices);
	return circle;
}

// Functie pentru creare dreptunghi (acelasi principiu ca la "CreateSquare", doar ca avem 2 dimensiuni pentru laturi)
Mesh* Object2D_Tema1::CreateRectangle(std::string name, glm::vec3 leftBottomCorner, float length, float height, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, height, 0), color),
		VertexFormat(corner + glm::vec3(0, height, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}
