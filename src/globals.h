#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Constans
// 	const int BRICK_SIZE     = 15;
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int DELAY = 10;


SDL_Window    *gWindow;
SDL_Renderer  *gRenderer;
TTF_Font      *debugFont;


bool running;
bool skipState;
bool showDebug;

struct Snake {
	int x, y;
	int lives;
	int score;
	int velocity;
} snake;


enum GameState {
	e_GS_Menu = 0,
	e_GS_Ready,
	e_GS_Game,
	e_GS_NextLevel,
	e_GS_Pause,
	
	e_GS_LastEnum

} state;

static const char * GameState_str[] ={"menu", "ready", "game", "nextLevel", "pause"};

#endif