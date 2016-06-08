#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Constans
const int BRICK_SIZE     = 10;
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int BOARD_WIDTH = SCREEN_WIDTH - 2;
const int BOARD_HEIGHT = SCREEN_HEIGHT - 22;
const int BOARD_X = 1;
const int BOARD_Y = 21;
const int DELAY = 10;


#define iX 0
#define iY 1

// Global variables
SDL_Window		*gWindow;
SDL_Renderer	*gRenderer;
TTF_Font		*debugFont;
TTF_Font		*menuFont;

int gameState;
int menuState;
bool running;
bool showDebug;
std::string highScore[6];

enum FontSizes {
	e_FS_14 = 0,
	e_FS_16,

	e_FS_LastEnum
};

enum Direction {
	e_DI_Up,
	e_DI_Down,
	e_DI_Left,
	e_DI_Right,
	e_DI_Stop
};

static const char * Direction_str[] = { "Up", "Down", "Left", "Right", "Stop"};

struct Snake {
	int x, y;
	int lives;
	int score;
	int velocity;
	Direction dir;
	int nextCoint;
};

static Snake snake;

enum GameState {
	e_GS_Menu = 0,
	e_GS_Ready,
	e_GS_Game,
	e_GS_NextLevel,
	e_GS_GameOver,
	e_GS_Pause,
	e_GS_HighScore,

	e_GS_LastEnum

};
static const char * GameState_str[] ={"menu", "ready", "game", "nextLevel", "gameover", "pause", "highscore"};

enum MenuStates {
	e_MS_StartGame = 0,
	e_MS_HighScore,
	e_MS_Exit,

	e_MS_LastEnum
};
static const char * MenuStates_str[]={"Start game", "High score", "Exit"};

#endif
