#include "globals.h"

void PauseGame() {
	
	static GameState old_state = state;
	if( state == e_GS_Pause ){
		state = old_state;
	}else{
		old_state = state;
		state = e_GS_Pause;
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
				case SDLK_UP:		snake.dir = e_DI_Up;	break;
				case SDLK_LEFT:		snake.dir = e_DI_Left;	break;
				case SDLK_DOWN:		snake.dir = e_DI_Down;	break;
				case SDLK_RIGHT:	snake.dir = e_DI_Right;	break;

				// Other input
				case SDLK_d:	showDebug = !showDebug;			break;

				case SDLK_j:	snake.x = SCREEN_WIDTH /2;
								snake.y = SCREEN_HEIGHT /2;		break;
								
				case SDLK_p:	PauseGame();					break;
				case SDLK_s:	skipState= true;				break;
					
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