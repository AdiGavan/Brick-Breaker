#pragma once
// "Copyright [2018] Gavan Adrian-George, 334CA"
#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include "Transform2D_Tema1.h"
#include "utils.h"
#include "Object2D_Tema1.h"

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	void show_win();
	void show_lose();
	void show_start_exit();


protected:
	glm::mat3 modelMatrix;

	// Coordonate pereti
	float xc_wallL = 0;
	float yc_wallL = 0;
	float xc_wallR = 0;
	float yc_wallR = 0;
	float xc_wallU = 0;
	float yc_wallU = 0;

	// Coordonate board
	float xc_board = 0;
	float yc_board = 0;

	// Jumatate din dimensiunea placii
	float half_size_board = 100;

	// Coordonate bila
	float xc_ball = 0;
	float yc_ball = 0;

	// Viteza bilei
	float ball_speed = 0;

	// Flag pentru desprindere bila (pentru a sti daca s-a apasat butonul mouse-ului)
	bool ball_detached = false;

	// Variabile pentru directia bilei
	float up_down = 1;		// 1 in sus, -1 in jos
	float left_right = 1;	// 1 in dreapta, -1 in stanga

	// Valoarea pentru functia arccos
	float val_arccos = 0;

	// Valorile pozitiei anterioare a bilei (pentru verificare impact caramizi)
	float xc_ball_old = 0;
	float yc_ball_old = 0;


	// Vectorul pentru caramizi
	std::vector<info_brick> bricks;
	// Vectorul pentru bonusuri
	std::vector<info_bonus> bonuses;
	// Vectorul pentru vieti
	std::vector<Mesh*> lifes;
	// Vectorul pentru vieti initiale (pentru reset joc)
	std::vector<Mesh*> lifes_initial;

	// Contor pentru bilele nedistruse
	int bricks_counter = 0;
	
	// Timp petrecut cu bonusul "zid jos" si flag pentru a sti daca bonusul este activ
	float time_wall = 0;
	bool wall_effect = false;

	// Timp petrecut cu bonusul "bila invincibila" si flag pentru a sti daca bonusul este activ
	float time_indestructible = 0;
	bool indestructible_effect = false;

	// Timp petrecut cu bonusul "placa mica" si flag pentru a sti daca bonusul este activ
	float time_bsmall = 0;
	bool bsmall_effect = false;

	// Timp petrecut cu bonusul "placa mare" si flag pentru a sti daca bonusul este activ
	float time_blong = 0;
	bool blong_effect = false;

	// Timp petrecut cu bonusul "viteza bila" si flag pentru a sti daca bonusul este activ
	float time_speedup = 0;
	bool speedup_effect = false;
	
	// Indice nivel curent
	int level = 1;
	// Indice nivel maxim
	int maxlevel = 3;

	// Flag pentru start joc (daca este false, va aprea rezultatul: castigator sau invins)
	bool start = true;
	// Flag pentru inchidere joc
	bool finish = false;
	// Flag pentru a sti daca jucatorul a castigat sau a pierdut
	bool win = false;
	// Flag pentru a sti daca este pusa pauza sau nu
	bool pause = false;
};
