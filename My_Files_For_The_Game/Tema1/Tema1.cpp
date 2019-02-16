// "Copyright [2018] Gavan Adrian-George, 334CA"
#include "Tema1.h"
#include <time.h>
#include <vector>
#include <iostream>
#include <Core/Engine.h>

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	glm::vec3 center = glm::vec3(0, 0, 0);

	info_brick aux;
	info_bonus aux2;

	// Coordonate pereti
	xc_wallL = XC_WALLL;
	yc_wallL = YC_WALLL;
	xc_wallR = XC_WALLR;
	yc_wallR = YC_WALLR;
	xc_wallU = XC_WALLU;
	yc_wallU = YC_WALLU;

	// Coordonate board
	xc_board = 0;
	yc_board = YC_BOARD;

	// Coordonate bila
	xc_ball = 0;
	yc_ball = YC_BALL;

	// Forma dreptunghi pentru afisajul de la finalul jocului
	Mesh* finish_rectangle = Object2D_Tema1::CreateRectangle("FinishRectangle", corner, FIN_LENGTH, FIN_WIDTH, glm::vec3(FIN_COLOR), true);
	AddMeshToList(finish_rectangle);

	// Peretii
	Mesh* wall_left = Object2D_Tema1::CreateRectangle("WallLeft", corner, WALL_WIDTH, WALL_LR_LENGTH, glm::vec3(WALL_COLOR), true);
	AddMeshToList(wall_left);

	Mesh* wall_right = Object2D_Tema1::CreateRectangle("WallRight", corner, WALL_WIDTH, WALL_LR_LENGTH, glm::vec3(WALL_COLOR), true);
	AddMeshToList(wall_right);

	Mesh* wall_up = Object2D_Tema1::CreateRectangle("WallUp", corner, WALL_UP_LENGTH, WALL_WIDTH, glm::vec3(WALL_COLOR), true);
	AddMeshToList(wall_up);

	// Placa
	Mesh* board = Object2D_Tema1::CreateRectangle("Board", corner, BOARD_LENGTH, BOARD_WIDTH, glm::vec3(BOARD_COLOR), true);
	AddMeshToList(board);

	// Bila
	Mesh* ball = Object2D_Tema1::CreateCircle("Ball", center, glm::vec3(BALL_COLOR));
	AddMeshToList(ball);

	// Caramizi (in functie de nivel)
	Mesh* brick1 = Object2D_Tema1::CreateRectangle("Brick1", corner, BRICK_LENGTH, BRICK_WIDTH, glm::vec3(BRICK1_COLOR), true);
	AddMeshToList(brick1);

	Mesh* brick2 = Object2D_Tema1::CreateRectangle("Brick2", corner, BRICK_LENGTH, BRICK_WIDTH, glm::vec3(BRICK2_COLOR), true);
	AddMeshToList(brick2);

	Mesh* brick3 = Object2D_Tema1::CreateRectangle("Brick3", corner, BRICK_LENGTH, BRICK_WIDTH, glm::vec3(BRICK3_COLOR), true);
	AddMeshToList(brick3);
	
	// Viata
	Mesh* life = Object2D_Tema1::CreateCircle("Life", center, glm::vec3(LIFE_COLOR));
	AddMeshToList(life);

	// Patratele pentru bonus
	Mesh* bonus_wall = Object2D_Tema1::CreateSquare("BWall", corner, SQUARE_LENGTH, glm::vec3(BWALL_COLOR), true);
	AddMeshToList(bonus_wall);

	Mesh* bonus_blong = Object2D_Tema1::CreateSquare("BLong", corner, SQUARE_LENGTH, glm::vec3(BLONG_COLOR), true);
	AddMeshToList(bonus_blong);

	Mesh* bonus_bsmall = Object2D_Tema1::CreateSquare("BSmall", corner, SQUARE_LENGTH, glm::vec3(BSMALL_COLOR), true);
	AddMeshToList(bonus_bsmall);

	Mesh* bonus_life = Object2D_Tema1::CreateSquare("BLife", corner, SQUARE_LENGTH, glm::vec3(BLIFE_COLOR), true);
	AddMeshToList(bonus_life);

	Mesh* bonus_takelife = Object2D_Tema1::CreateSquare("BTLife", corner, SQUARE_LENGTH, glm::vec3(BTLIFE_COLOR), true);
	AddMeshToList(bonus_takelife);

	Mesh* bonus_indestructible = Object2D_Tema1::CreateSquare("BIndestructible", corner, SQUARE_LENGTH, glm::vec3(BINDES_COLOR), true);
	AddMeshToList(bonus_indestructible);

	Mesh* bonus_speedup = Object2D_Tema1::CreateSquare("BSpeedup", corner, SQUARE_LENGTH, glm::vec3(BSPEEDUP_COLOR), true);
	AddMeshToList(bonus_speedup);

	// Formele pentru efectele bonus-urilor
	Mesh* bonus_wall_effect = Object2D_Tema1::CreateRectangle("BWall_Effect", corner, BWALL_LENGTH, BWALL_WIDTH, glm::vec3(WALLEF_COLOR), true);
	AddMeshToList(bonus_wall_effect);

	Mesh* small_board = Object2D_Tema1::CreateRectangle("SmallBoard", corner, SBOARD_LENGTH, BOARD_WIDTH, glm::vec3(BOARD_COLOR), true);
	AddMeshToList(small_board);

	Mesh* long_board = Object2D_Tema1::CreateRectangle("LongBoard", corner, LBOARD_LENGTH, BOARD_WIDTH, glm::vec3(BOARD_COLOR), true);
	AddMeshToList(long_board);

	Mesh* indestructible_ball = Object2D_Tema1::CreateCircle("Indestructible_Ball", center, glm::vec3(INDBALL_COLOR));
	AddMeshToList(indestructible_ball);

	// Se adauga cate 2 bonus-uri din fiecare tip in vectorul bonus-urilor
	aux2.bonus = "BWall";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BLong";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BSmall";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BLife";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BTLife";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BIndestructible";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	aux2.bonus = "BSpeedup";
	bonuses.push_back(aux2);
	bonuses.push_back(aux2);

	// Se adauga cele 3 vieti in vectorul vietilor
	for (int i = 0; i < 3; i++) {
		lifes.push_back(life);
		lifes_initial.push_back(life);
	}

	// Se includ caramizile in vectorul cu informatii despre caramizi
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			aux.brick = "Brick" + std::to_string(level);
			aux.x_brick = 70 * j + 80;
			aux.y_brick = i * 70 + 200;
			aux.destroyed = false;
			aux.disapear = false;
			aux.scale_x = 1;
			aux.scale_y = 1;
			aux.ind_bonus = -1;
			aux.lifes = 1;
			bricks.push_back(aux);
		}
	}

	for (int i = 1; i <= 6; i++) {
		for (int j = 7; j <= 12; j++) {
			aux.brick = "Brick" + std::to_string(level);
			aux.x_brick = 70 * j + 260;
			aux.y_brick = i * 70 + 200;
			aux.destroyed = false;
			aux.disapear = false;
			aux.scale_x = 1;
			aux.scale_y = 1;
			aux.ind_bonus = -1;
			aux.lifes = 1;
			bricks.push_back(aux);
		}
	}

	// Se seteaza bricks_counter ca fiind numarul total al caramizilor
	bricks_counter = bricks.size();

	// Se asociaza fiecare bonus unei caramizi (random)
	for (int i = 0; i < bonuses.size(); i++) {
		bonuses[i].ind_brick = -1;
		while (bonuses[i].ind_brick == -1) {
			bonuses[i].ind_brick = rand() % bricks.size();
			// Daca caramida are deja asociat un bonus trebuie gasita alta caramida
			if (bricks[bonuses[i].ind_brick].ind_bonus != -1) {
				bonuses[i].ind_brick = -1;
			}
			else {
				bricks[bonuses[i].ind_brick].ind_bonus = i;
			}
		}
		bonuses[i].xc_bonus = bricks[bonuses[i].ind_brick].x_brick + 25;
		bonuses[i].yc_bonus = bricks[bonuses[i].ind_brick].y_brick + 15;
		bonuses[i].angular = 0;
		bonuses[i].disapear = false;
		bonuses[i].translate_x = bonuses[i].xc_bonus;
		bonuses[i].translate_y = bonuses[i].yc_bonus;
	}

}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
	// Daca jocul nu afiseaza win sau lose (jocul "merge")
	if (start) {
		
		/* Verificarile pentru timpul bonusurilor sunt inafara if-ului care verifica daca bila a fost
		   lansata pentru ca bonusurile sa aiba efect si daca se pierde o viata si bila este pusa inapoi
		   pe placa */

		// Se verfica timpul pentru bonusul "perete jos" si daca bonusul este activ
		if ((time_wall <= 30) && (wall_effect)) {
			// Daca jocul nu este in pauza
			if (!pause) {
				time_wall += deltaTimeSeconds;
			}
			// Se afiseaza peretele de jos
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D_Tema1::Translate(650, 10) * Transform2D_Tema1::Translate(-650, -10);
			RenderMesh2D(meshes["BWall_Effect"], shaders["VertexColor"], modelMatrix);
		}
		// Se reseteaza timpul si flag-ul
		else {
			time_wall = 0;
			wall_effect = false;
		}

		// Daca jocul nu este in pauza
		if (!pause) {
			// Se verfica timpul pentru bonusul "placa mare" si daca bonusul este activ
			if ((time_blong <= 30) && (blong_effect)) {
				time_blong += deltaTimeSeconds;
				half_size_board = 150;
			}
			// Se verfica timpul pentru bonusul "placa mica" si daca bonusul este activ
			else if ((time_bsmall <= 30) && (bsmall_effect)) {
				time_bsmall += deltaTimeSeconds;
				half_size_board = 50;
			}
			// Se reseteaza flag-urile si se revine la dimensiunea normala
			else {
				blong_effect = false;
				bsmall_effect = false;
				half_size_board = 100;
			}

			// Se verfica timpul pentru bonusul "bila indestructibila" si daca bonusul este activ
			if ((time_indestructible <= 15) && (indestructible_effect)) {
				time_indestructible += deltaTimeSeconds;
			}
			// Se reseteaza flag-ul si timpul
			else {
				time_indestructible = 0;
				indestructible_effect = false;
			}

			// Se verfica timpul pentru bonusul "speedup bila" si daca bonusul este activ
			if ((time_speedup <= 30) && (speedup_effect)) {
				time_speedup += deltaTimeSeconds;
				ball_speed = deltaTimeSeconds * 600;
			}
			// Se reseteaza flag-ul si timpul si se revine la viteza normala a bilei
			else {
				time_speedup = 0;
				speedup_effect = false;
				ball_speed = deltaTimeSeconds * 300;
			}
		}

		// Daca mingea a fost detasata de pe placa
		if (ball_detached) {
			// Se verifica ciocnirea cu peretele de sus
			if (yc_ball + 10 >= yc_wallU - 12.5) {
				up_down = -1;
			}
			// Se verifica ciocnirea cu peretele din dreapta
			if ((xc_ball + 10 >= xc_wallR - 12.5)) {
				left_right = -1;
			}
			// Se verifica ciocnirea cu peretele din stanga
			if ((xc_ball - 10 <= xc_wallL + 12.5)) {
				left_right = 1;
			}

			// Se verifica daca bila se ciocneste de caramizi
			for (int i = 0; i < bricks.size(); i++) {
				if (!bricks[i].destroyed) {
					if ((xc_ball >= bricks[i].x_brick - 10) && (xc_ball <= bricks[i].x_brick + 60) 
						&& (yc_ball >= bricks[i].y_brick - 10) && (yc_ball <= bricks[i].y_brick + 40)) {
						// Daca pozitia anterioara a bilei nu era tot intersectata cu caramida, scade duritatea 
						// caramizii (sa nu cumva sa se scada mai mult duritatea la o ciocnire)
						if (!((xc_ball_old >= bricks[i].x_brick - 10) && (xc_ball_old <= bricks[i].x_brick + 60) 
							&& (yc_ball_old >= bricks[i].y_brick - 10) && (yc_ball_old <= bricks[i].y_brick + 40))) {
							bricks[i].lifes--;
						}
						// Daca bila nu este indestructibila se schimba directia bilei in functie de ciocnire
						if (!indestructible_effect) {
							// Ciocnire latura inferioara caramida
							if ((bricks[i].y_brick - 10 <= yc_ball) && (bricks[i].y_brick - 10 >= yc_ball_old)) {
								up_down = -1;
							}
							// Ciocnire latura superioara caramida
							else if ((bricks[i].y_brick + 40 >= yc_ball) && (bricks[i].y_brick + 40 <= yc_ball_old)) {
								up_down = 1;
							}
							// Ciocnire latura stanga caramida
							else if ((bricks[i].x_brick - 10 <= xc_ball) && (bricks[i].x_brick - 10 >= xc_ball_old)) {
								left_right = -1;
							}
							// Ciocnire latura dreapta caramida
							else if ((bricks[i].x_brick + 60 >= xc_ball) && (bricks[i].x_brick + 60 <= xc_ball_old)) {
								left_right = 1;
							}
						}
						// Daca bila e indestructibila se distruge caramida indiferent de duritate
						else if (indestructible_effect) {
							bricks[i].lifes = 0;
						}
						if (bricks[i].lifes <= 0) {
							bricks[i].destroyed = true;
							bricks[i].disapear = true;
						}
						// Se actualizeaza tipul caramizii in functie de duritatea ei
						else {
							bricks[i].brick = "Brick" + std::to_string(bricks[i].lifes);
						}


					}
				}
			}

			// Cazul cand bila loveste placa
			if ((yc_ball - 10 <= yc_board + 5) && (xc_ball + 10 >= xc_board - half_size_board) && (xc_ball - 10 <= xc_board + half_size_board)) {
				up_down = 1;
				// Cazul cand loveste placa in marginea stanga dar nu cu centrul bilei
				if (xc_ball < xc_board - half_size_board) {
					val_arccos = -sqrt(3.5) / 2;
				}
				// Cazul cand loveste placa in marginea dreapta dar nu cu centrul bilei
				else if (xc_ball > xc_board + half_size_board) {
					val_arccos = +sqrt(3.5) / 2;
				}
				// Cazul cand loveste placa cu centrul bilei
				else {
					val_arccos = (xc_ball - xc_board) / half_size_board;
				}
				// Pentru ca bila sa nu se duca orizontal cu axa OX, punem o limita asupra unghiului de reflexie
				// Limita este +- sqrt(3.5) / 2
				if (val_arccos < -sqrt(3.5) / 2) {
					val_arccos = -sqrt(3.5) / 2;
				}
				if (val_arccos > sqrt(3.5) / 2) {
					val_arccos = sqrt(3.5) / 2;
				}

				// Se calculeaza directia in care va pleca bila si se seteaza left_right
				if (cos(acos(val_arccos)) < 0) {
					left_right = -1;
				}
				else {
					left_right = 1;
				}

			}
			// Cazul cand nu loveste placa dar zidul de jos este activat
			else if ((yc_ball - 10) <= 20 && wall_effect) {
				up_down = 1;
			}

			// Cazul cand bila cade pe langa placa si se pierde o viata, 
			// cazul cand s-au distrus toate caramizile din nivelul curent si 
			// cazul cand bonusul de "minus viata" ia ultima viata a jucatorului
			if ((yc_ball - 10 <= 0) || (bricks_counter == 0) || (lifes.size() == 0)) {
				// Se reseteaza flag-urile si valorile
				up_down = 1;
				left_right = 1;
				ball_detached = false;
				val_arccos = 0;
				xc_ball = xc_board;
				if ((lifes.size() > 0) && (yc_ball - 10 <= 0)) {
					lifes.pop_back();
				}
				yc_ball = YC_BALL;

				// Daca se pierd toate vietile sau se castiga nivelul
				if ((lifes.size() == 0) || (bricks_counter == 0)) {
					// Daca se catiga nivelul, se incrementeaza numarul nivelului
					// si start se face true pentru a continua jocul
					if (bricks_counter == 0) {
						level++;
						start = true;
					}

					// Daca se catiga nivelul ultimul nivel al jocului,
					// se seteaza win ca fiind true (jucatorul a castigat)
					// si se reseteaza nivelul la 1
					if (bricks_counter == 0 && level > maxlevel) {
						level = 1;
						start = false;
						win = true;
					}

					// Daca s-au pierdut toate vietile, 
					// jocul se reia de la capat si win = false pentru ca jucatorul a pierdut
					if (lifes.size() == 0) {
						level = 1;
						start = false;
						win = false;
					}
					// Se reseteaza flag-ul ca sa nu fie pauza
					pause = false;

					// Se reseteaza flag-urile si timpurile bonusurilor
					time_wall = 0;
					wall_effect = false;

					time_bsmall = 0;
					bsmall_effect = false;

					time_blong = 0;
					blong_effect = false;

					time_indestructible = 0;
					indestructible_effect = false;

					time_speedup = 0;
					speedup_effect = false;

					// Se reseteaza numarul vietilor
					lifes = lifes_initial;

					// Caramizile trebuie reafisate, fiecare caramida avand valoarea corespunzatoare nivelului curent
					for (int i = 0; i < bricks.size(); i++) {
						bricks[i].destroyed = false;
						bricks[i].disapear = false;
						bricks[i].scale_x = 1;
						bricks[i].scale_y = 1;
						bricks[i].ind_bonus = -1;
						bricks[i].lifes = level;
						bricks[i].brick = "Brick" + std::to_string(level);
					}
					bricks_counter = bricks.size();

					// Se reseteaza bonusurile si se reataseaza unor caramizi (random)
					for (int i = 0; i < bonuses.size(); i++) {
						bonuses[i].ind_brick = -1;
						while (bonuses[i].ind_brick == -1) {
							bonuses[i].ind_brick = rand() % bricks.size();
							if (bricks[bonuses[i].ind_brick].ind_bonus != -1) {
								bonuses[i].ind_brick = -1;
							}
							else {
								bricks[bonuses[i].ind_brick].ind_bonus = i;
							}
						}

						bonuses[i].xc_bonus = bricks[bonuses[i].ind_brick].x_brick + 25;
						bonuses[i].yc_bonus = bricks[bonuses[i].ind_brick].y_brick + 15;
						bonuses[i].angular = 0;
						bonuses[i].disapear = false;
						bonuses[i].translate_x = bonuses[i].xc_bonus;
						bonuses[i].translate_y = bonuses[i].yc_bonus;
					}
				}
			}


			if (ball_detached) {
				// Daca a lovit placa si directia este setata ca fiind in jos, o schimb pentru ca bila sa se duca in sus
				if ((yc_ball - 10 <= yc_board + 5) && (up_down == -1) && (xc_ball + 10 >= xc_board - half_size_board) 
					&& (xc_ball - 10 <= xc_board + half_size_board)) {
					up_down = 1;
				}
				// Se retine pozitia anterioara a bilei
				xc_ball_old = xc_ball;
				yc_ball_old = yc_ball;
				// Daca nu este pauza, se calculeaza noile coordonate ale bilei
				// Se iau valorile in modul ale lui cos si sin, pentru ca semnul (directia) a fost calculata si setata anterior
				if (!pause) {
					xc_ball += left_right * abs(cos(acos(val_arccos))) * ball_speed;
					yc_ball += up_down * sin(acos(val_arccos)) * ball_speed;
				}
			}

		}

		// Se afiseaza bila
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D_Tema1::Translate(xc_ball, yc_ball) * Transform2D_Tema1::Scale(9, 9);
		if (!indestructible_effect) {
			RenderMesh2D(meshes["Ball"], shaders["VertexColor"], modelMatrix);
		}
		else {
			RenderMesh2D(meshes["Indestructible_Ball"], shaders["VertexColor"], modelMatrix);
		}

		// Se afiseaza vietile
		for (int i = 0; i < lifes.size(); i++) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D_Tema1::Translate(i * 30 + 40, 707) * Transform2D_Tema1::Scale(9, 9);
			RenderMesh2D(lifes[i], shaders["VertexColor"], modelMatrix);
		}

		// Se afiseaza peretii
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D_Tema1::Translate(xc_wallU, yc_wallU) * Transform2D_Tema1::Translate(-620, -12.5);
		RenderMesh2D(meshes["WallUp"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D_Tema1::Translate(xc_wallL, yc_wallL) * Transform2D_Tema1::Translate(-12.5, -350);
		RenderMesh2D(meshes["WallLeft"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D_Tema1::Translate(xc_wallR, yc_wallR) * Transform2D_Tema1::Translate(-12.5, -350);
		RenderMesh2D(meshes["WallRight"], shaders["VertexColor"], modelMatrix);

		// Se afiseaza placa
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D_Tema1::Translate(xc_board, yc_board) * Transform2D_Tema1::Translate(-half_size_board, -5);
		if (half_size_board == 100) {
			RenderMesh2D(meshes["Board"], shaders["VertexColor"], modelMatrix);
		}
		else if (half_size_board == 150) {
			RenderMesh2D(meshes["LongBoard"], shaders["VertexColor"], modelMatrix);
		}
		else if (half_size_board == 50) {
			RenderMesh2D(meshes["SmallBoard"], shaders["VertexColor"], modelMatrix);
		}

		// Se afiseaza patratele pentru bonusuri si se calculeaza bonusurile active
		for (int i = 0; i < bonuses.size(); i++) {
			if (bricks[bonuses[i].ind_brick].destroyed && (!bonuses[i].disapear)) {
				// Daca jocul nu este in pauza si patratul bonusului inca cade, se calculeaza noul unghi de rotire si noua pozitie y
				if (!pause) {
					bonuses[i].angular += 2 * deltaTimeSeconds;
					bonuses[i].translate_y -= 80 * deltaTimeSeconds;
				}
				// Se afiseaza patratul bonusului
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D_Tema1::Translate(bonuses[i].translate_x, bonuses[i].translate_y)
								* Transform2D_Tema1::Rotate(bonuses[i].angular) * Transform2D_Tema1::Translate(-10, -10);
				RenderMesh2D(meshes[bonuses[i].bonus], shaders["VertexColor"], modelMatrix);
				// Daca patratul iese din joc acesta nu se mai afiseaza
				if (bonuses[i].translate_y - 10 <= 0) {
					bonuses[i].disapear = true;
				}
				// Cazul cand jucatorul prinde un bonus cu placa
				else if ((bonuses[i].translate_y - 10 <= yc_board + 5) && (bonuses[i].translate_x + 10 >= xc_board - half_size_board) 
						&& (bonuses[i].translate_x - 10 <= xc_board + half_size_board)) {
					bonuses[i].disapear = true;
					// Cazul cand bonusul este de tip "perete jos"
					if (bonuses[i].bonus == "BWall") {
						time_wall = 0;
						wall_effect = true;
					}
					// Cazul cand bonusul este de tipul "placa lunga"
					else if (bonuses[i].bonus == "BLong") {
						time_blong = 0;
						time_bsmall = 0;
						bsmall_effect = false;
						blong_effect = true;
					}
					// Cazul cand bonusul este de tipul "placa scurta"
					else if (bonuses[i].bonus == "BSmall") {
						time_blong = 0;
						time_bsmall = 0;
						bsmall_effect = true;
						blong_effect = false;
					}
					// Cazul cand bonusul este de tipul "plus viata"
					else if (bonuses[i].bonus == "BLife") {
						lifes.push_back(meshes["Life"]);
					}
					// Cazul cand bonusul este de tipul "minus viata"
					else if (bonuses[i].bonus == "BTLife" && lifes.size() > 0) {
						lifes.pop_back();
					}
					// Cazul cand bonusul este de tipul "bila indestructibila"
					else if (bonuses[i].bonus == "BIndestructible") {
						time_indestructible = 0;
						indestructible_effect = true;
					}
					// Cazul cand bonusul este de tipul "speedup bila"
					else if (bonuses[i].bonus == "BSpeedup") {
						time_speedup = 0;
						speedup_effect = true;
					}
				}
			}
		}

		// Afisare caramizi si calculare disparitie
		for (int i = 0; i < bricks.size(); i++) {
			// Cazul cand caramida nu a fost lovita
			if (!bricks[i].destroyed) {
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D_Tema1::Translate(bricks[i].x_brick, bricks[i].y_brick);
				RenderMesh2D(meshes[bricks[i].brick], shaders["VertexColor"], modelMatrix);
			}
			// Cazul cand caramida a fost lovita
			else if (bricks[i].destroyed  && bricks[i].disapear) { 
				// Cazul cand caramida a fost lovita si s-a terminat efectul de disparitie
				if ((bricks[i].scale_x <= 0) && (bricks[i].scale_y <= 0)) {
					bricks[i].disapear = false;
					bricks_counter--;
				}
				// Cazul cand inca este vizibil efectul de disparitie
				else {
					// Daca jocul nu este in pauza se calculeaza noile valori pentru scalare si se afiseaza caramida
					if (!pause) {
						bricks[i].scale_x -= 2 * deltaTimeSeconds;
						bricks[i].scale_y -= 2 * deltaTimeSeconds;
					}
					modelMatrix = glm::mat3(1);
					modelMatrix *= Transform2D_Tema1::Translate(bricks[i].x_brick, bricks[i].y_brick) * Transform2D_Tema1::Translate(25, 15)
									* Transform2D_Tema1::Scale(bricks[i].scale_x, bricks[i].scale_y) * Transform2D_Tema1::Translate(-25, -15);
					RenderMesh2D(meshes[bricks[i].brick], shaders["VertexColor"], modelMatrix);
				}
			}
		}
	// Cazul cand se afiseaza win sau lose si se apasa exit (e)
	} else if (finish) {
		exit(1);
	}
	// Cazul cand trebuie sa se afiseze win
	else if (win) {		
		show_win();
	}
	// Cazul cand trebuie sa se afiseze lose
	else {
		show_lose();
	}

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	// Cazul cand se afiseaza win sau lose
	// Daca se apsa S se ia jocul de la capat
	// Daca se apasa E se inchide jocul
	if (!start) {
		if (window->KeyHold(GLFW_KEY_S)) {
			start = true;
			win = false;
		} else if (window->KeyHold(GLFW_KEY_E)) {
			finish = true;
		}
	}

	// Cand jocul merge, daca se apasa P se pune pauza.
	// Daca se apasa O se opreste pauza si jocul incepe sa mearga.
	if (start) {
		if (window->KeyHold(GLFW_KEY_P)) {
			pause = true;
		}
		else if (window->KeyHold(GLFW_KEY_O)) {
			pause = false;
		}
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
}

void Tema1::OnKeyRelease(int key, int mods)
{
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	/* mouseX se scaleaza cu (1280 / window->GetResolution().x) pentru a merge si pe fereastra marita */
	// Daca nu este pauza
	if (!pause) {
		// Cazul cand placa loveste in peretele din stanga
		if ((mouseX * 1280 / window->GetResolution().x) <= 25 + half_size_board) {
			xc_board = 25 + half_size_board;
		}
		// Cazul cand placa loveste in peretele din dreapta
		else if ((mouseX * 1280 / window->GetResolution().x) >= 1256 - half_size_board) {
			xc_board = 1256 - half_size_board;
		}
		else {
			xc_board = (mouseX * 1280 / window->GetResolution().x);
		}

		// Daca bila este inca pe placa
		if (!ball_detached) {
			// Cazul cand placa loveste peretele din stanga
			if ((mouseX * 1280 / window->GetResolution().x) <= 25 + half_size_board) {
				xc_ball = 25 + half_size_board;
			}
			// Cazul cand placa loveste peretele din dreapta
			else if ((mouseX * 1280 / window->GetResolution().x) >= 1256 - half_size_board) {
				xc_ball = 1256 - half_size_board;
			}
			else {
				xc_ball = (mouseX * 1280 / window->GetResolution().x);
			}
		}
	}
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	/* mouseX se scaleaza cu (1280 / window->GetResolution().x) pentru a merge si pe fereastra marita */
	// Daca nu este pauza
	if (!pause) {
		// Daca bila nu a fost inca lansata
		if (!ball_detached) {
			ball_detached = true;
			// Cazul cand placa loveste peretele din stanga
			if ((mouseX * 1280 / window->GetResolution().x) <= 25 + half_size_board) {
				xc_ball = 25 + half_size_board;
			}
			// Cazul cand placa loveste peretele din dreapta
			else if ((mouseX * 1280 / window->GetResolution().x) >= 1256 - half_size_board) {
				xc_ball = 1256 - half_size_board;
			}
			else {
				xc_ball = (mouseX * 1280 / window->GetResolution().x);
			}
		}
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}

// Functie pentru afisare victorie
void Tema1::show_win() {
	// W
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(590, 480) * Transform2D_Tema1::Rotate(RADIANS(120)) * Transform2D_Tema1::Scale(3.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(590, 460) * Transform2D_Tema1::Rotate(RADIANS(60)) * Transform2D_Tema1::Scale(3.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(690, 480) * Transform2D_Tema1::Rotate(RADIANS(120)) * Transform2D_Tema1::Scale(3.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(690, 460) * Transform2D_Tema1::Rotate(RADIANS(60)) * Transform2D_Tema1::Scale(3.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(655, 460) * Transform2D_Tema1::Scale(0.56, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(555, 460) * Transform2D_Tema1::Scale(0.56, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	show_start_exit();
}

// Functie pentru afisare infrangere
void Tema1::show_lose() {
	// L
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(600, 460) * Transform2D_Tema1::Rotate(RADIANS(90)) * Transform2D_Tema1::Scale(3.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(600, 460) * Transform2D_Tema1::Scale(1.5, 2);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	show_start_exit();
}

// Functie pentru afisare optiuni: exit sau start
void Tema1::show_start_exit() {
	// E
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(465, 160) * Transform2D_Tema1::Rotate(RADIANS(90)) * Transform2D_Tema1::Scale(1.5, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(465, 160) * Transform2D_Tema1::Scale(0.6, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(465, 195) * Transform2D_Tema1::Scale(0.6, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(465, 230) * Transform2D_Tema1::Scale(0.6, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);


	// S
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(804, 160) * Transform2D_Tema1::Rotate(RADIANS(90)) * Transform2D_Tema1::Scale(0.92, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(750, 195) * Transform2D_Tema1::Rotate(RADIANS(90)) * Transform2D_Tema1::Scale(0.92, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(730, 160);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(750, 195) * Transform2D_Tema1::Scale(0.6, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D_Tema1::Translate(750, 230) * Transform2D_Tema1::Scale(0.91, 1);
	RenderMesh2D(meshes["FinishRectangle"], shaders["VertexColor"], modelMatrix);
}
