#include "globals.h"

bool LoadMedia()
{
	if( (debugFont = TTF_OpenFont( "/usr/share/fonts/truetype/msttcorefonts/Courier_New_Bold.ttf", 14 )) == NULL ){
		return false;
	}

	if( (menuFont = TTF_OpenFont( "/usr/share/fonts/truetype/msttcorefonts/Courier_New_Bold.ttf", 16 )) == NULL ){
		return false;
	}

	return true;
}



bool Init()
{
	if( SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        return false;
    }
    
    if( TTF_Init() < 0 ){
        return false;
    }

    if( (gWindow = SDL_CreateWindow("snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_OPENGL) ) == NULL ){
        return false;
    }

    if( (gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL ){
        return false;
    }
    
    if( ! LoadMedia() ){
		return false;
	}

	gameState = e_GS_Menu;
	menuState = e_MS_StartGame;
	showDebug = false;

	snake.x = SCREEN_WIDTH /2;
	snake.y = SCREEN_HEIGHT /2;
	snake.lives = 3;
	snake.score = 0;
	snake.velocity = 2;
	snake.dir = e_DI_Stop;
    
    return true;
}


void CleanUp()
{
	 TTF_Quit();
	 IMG_Quit();
	 SDL_Quit();
}



