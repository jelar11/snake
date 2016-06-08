#include "globals.h"

bool LoadMedia()
{
	for( int i=0; i<e_FS_LastEnum; i++ ){
		if( (fonts[ i ] = TTF_OpenFont( "/usr/share/fonts/truetype/msttcorefonts/Courier_New_Bold.ttf", FontSizes_nums[i])) == NULL ){
			return false;
		}
	}
	
	debugFont = fonts[ e_FS_14 ];
	menuFont = fonts[ e_FS_16 ];

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
	snake.nextCoint = 0;
    
    return true;
}


void CleanUp()
{
	for( int i=0; i<e_FS_LastEnum; i++ ){
		TTF_CloseFont( fonts[i] );
	}
	
	 TTF_Quit();
	 IMG_Quit();
	 SDL_Quit();
}



