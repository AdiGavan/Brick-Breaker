// "Copyright [2018] Gavan Adrian-George, 334CA"
#include <iostream>

// Coordonate pereti
#define XC_WALLL 12.5
#define YC_WALLL 370
#define XC_WALLR 1268.5
#define YC_WALLR 370
#define XC_WALLU 640
#define YC_WALLU 707.5

// yc board
# define YC_BOARD 25

// xc bila
# define YC_BALL 60

#define WALL_WIDTH 25
#define SQUARE_LENGTH 20
#define BRICK_LENGTH 50
#define BRICK_WIDTH 30
#define WALL_LR_LENGTH 700
#define WALL_UP_LENGTH 1240
#define BOARD_LENGTH 200
#define BOARD_WIDTH 10
#define LBOARD_LENGTH 300
#define SBOARD_LENGTH 100
#define FIN_LENGTH 60
#define FIN_WIDTH 20
#define BWALL_LENGTH 1300
#define BWALL_WIDTH 20

#define BALL_COLOR 0, 1, 0
#define WALL_COLOR 1, 0.5, 0
#define BOARD_COLOR 1, 0.5, 0
#define BRICK1_COLOR 1, 1, 0
#define BRICK2_COLOR 0.576471, 0.858824, 0.439216
#define BRICK3_COLOR 0.8, 0.498039, 0.196078
#define LIFE_COLOR 0, 1, 0
#define FIN_COLOR 1, 0, 0
#define BWALL_COLOR 0.5, 0.5, 0.5
#define BLONG_COLOR 0, 1, 1
#define BSMALL_COLOR 0, 0, 1
#define BLIFE_COLOR 0, 1, 0
#define BTLIFE_COLOR 0.184314, 0.309804, 0.184314
#define BINDES_COLOR 1, 0.43, 0.74
#define BSPEEDUP_COLOR 1, 1, 1
#define WALLEF_COLOR 0.5, 0.5, 0.5
#define INDBALL_COLOR 1, 0.43, 0.74

// Structura in care se vor retine informatiile pentru fiecare caramida
struct info_brick {
	std::string brick;	// Tipul caramizii
	float x_brick;		// X-ul coltului stanga jos al caramizii
	float y_brick;		// Y-ul coltului stanga jos al caramizii
	float scale_x;		// Factor scalare lungime pentru disparitia caramizii
	float scale_y;		// Factor scalare latime pentru disparitia caramizii
	bool destroyed;		// Flag pentru a stii daca caramida a fost lovita 
	bool disapear;		// Flag pentru a stii cand caramida a disparut de pe suprafata
	int ind_bonus;		// Indicele bonusului asociat caramizii
	int lifes;			// Numarul de vieti al caramizii (duritatea caramizii)
};

// Structura in care se vor retine informatiile pentru fiecare bonus
struct info_bonus {
	std::string bonus;	// Tipul bonusului
	float xc_bonus;		// X-ul centrului patratului unui bonus
	float yc_bonus;		// Y-ul centrului patratului unui bonus 
	int ind_brick;		// Indicele caramizii careia ii este asociat bonusul
	float angular;		// Unghiul pentru rotirea patratului unui bonus
	bool disapear;		// Flag pentru a stii daca patratul pentru un bonus a disparut
	float translate_x;	// Coordonata X pentru translatia patratului (efectul de cadere)
	float translate_y;	// Coordonata Y pentru translatia patratului (efectul de cadere)
};