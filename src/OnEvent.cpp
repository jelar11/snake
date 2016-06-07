#include "globals.h"

void PauseGame() {
	if( e_GS_Game == gameState ){
		gameState = e_GS_Pause;
	}else if( e_GS_Pause == gameState ){
		gameState = e_GS_Game;
	}
}

void OnEvent() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {

		if( event.type == SDL_QUIT ){
			running = false;
		}


		if( event.type == SDL_KEYDOWN ){
			switch( event.key.keysym.sym ){
				// Exit/quit
				case SDLK_ESCAPE:
				case SDLK_e:
				case SDLK_q:	running = false;	break;
				
				// Snake movement
				case SDLK_UP:		snake.dir = (snake.dir != e_DI_Down ? e_DI_Up : snake.dir);		break;
				case SDLK_LEFT:		snake.dir = (snake.dir != e_DI_Right ? e_DI_Left : snake.dir);	break;
				case SDLK_DOWN:		snake.dir = (snake.dir != e_DI_Up ? e_DI_Down : snake.dir);		break;
				case SDLK_RIGHT:	snake.dir = (snake.dir != e_DI_Left ? e_DI_Right : snake.dir);	break;

				// Other input
				case SDLK_d:	showDebug = !showDebug;			break;

				case SDLK_j:	snake.x = SCREEN_WIDTH /2;
								snake.y = SCREEN_HEIGHT /2;		break;

				case SDLK_SPACE:
				case SDLK_p:	PauseGame();					break;
				case SDLK_s:	gameState++;					break;
					
				case SDLK_PLUS:		snake.velocity++;			break;
				case SDLK_MINUS:	snake.velocity--;			break;

				default:
//					printf("Key pressed: %d\n", event.key.keysym.sym );
				break;
			}

		}
		if( event.type == SDL_KEYUP ){
//	        printf("Key released: %d\n", event.key.keysym.sym );
		}


	}
}
