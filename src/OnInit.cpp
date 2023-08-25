#include "highScore.h"

bool LoadMedia()
{
	for( int i=0; i<e_FS_LastEnum; i++ ){
		if( (fonts[ i ] = TTF_OpenFont( "Fonts/Courier_New_Bold.ttf", FontSizes_nums[i])) == NULL ){
			std::cout << "Init font error.\n";
			return false;
		}
	}

	LoadHighScore();

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

	SDL_ShowCursor(SDL_DISABLE);
    
    if( ! LoadMedia() ){
		return false;
	}

	gameState = e_GS_Menu;
	menuState = e_MS_StartGame;
	showDebug = false;

	snake = new Snake();
    
    return true;
}


void CleanUp()
{
	SaveHighScore();

	for( int i=0; i<e_FS_LastEnum; i++ ){
		TTF_CloseFont( fonts[i] );
	}

	 TTF_Quit();
	 IMG_Quit();
	 SDL_Quit();
}



