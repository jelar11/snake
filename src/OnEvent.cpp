#include "globals.h"

void PauseGame() {
	if( e_GS_Game == gameState ){
		gameState = e_GS_Pause;
	}else if( e_GS_Pause == gameState ){
		gameState = e_GS_Game;
	}
}

void MenuAction() {
	switch( menuState ){
		case e_MS_StartGame:
			gameState = e_GS_Ready;
			break;
		case e_MS_HighScore:
			gameState = e_GS_HighScore;
			break;
		case e_MS_Exit:
			running = false;
		break;
	}
}

void OnEvent() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {

		if( event.type == SDL_QUIT ){
			running = false;
		}

        const unsigned char* keys = SDL_GetKeyboardState(NULL);

		if( event.type == SDL_KEYDOWN ){
			switch( event.key.keysym.sym ){
				// Exit/quit
				case SDLK_ESCAPE:
				case SDLK_e:
				case SDLK_q:	running = false;	break;
				
				// Snake movement
				case SDLK_UP:
					if( e_GS_Menu != gameState ){
						snake->dir = (snake->dir != e_DI_Down ? e_DI_Up : snake->dir);
					}else{
						menuState--;
						if( menuState < 0)	menuState = e_MS_Exit;
					}

				break;
				case SDLK_LEFT:		snake->dir = (snake->dir != e_DI_Right ? e_DI_Left : snake->dir);	break;
				case SDLK_DOWN:
					if( e_GS_Menu != gameState ){
						snake->dir = (snake->dir != e_DI_Up ? e_DI_Down : snake->dir);
					}else{
						menuState++;
						if( menuState >= e_MS_LastEnum )	menuState = e_MS_StartGame;
					}
				break;
				case SDLK_RIGHT:	snake->dir = (snake->dir != e_DI_Left ? e_DI_Right : snake->dir);	break;

				// Other input
				case SDLK_RETURN:
					if( e_GS_Menu == gameState ){
						MenuAction();
					}else if( e_GS_HighScore == gameState || e_GS_NewHighScore == gameState || e_GS_GameOver == gameState ){
						gameState = e_GS_Menu;
					}
				break;
				case SDLK_d:	showDebug = !showDebug;			break;

				case SDLK_j:	snake->x = SCREEN_WIDTH /2;
								snake->y = SCREEN_HEIGHT /2;	break;

				case SDLK_n:	((keys[SDL_SCANCODE_RSHIFT] || keys[SDL_SCANCODE_RSHIFT]) ? snake->nextCoint-- : snake->nextCoint++);	break;

				case SDLK_SPACE:
				case SDLK_p:	PauseGame();					break;
				case SDLK_s:	((keys[SDL_SCANCODE_RSHIFT] || keys[SDL_SCANCODE_RSHIFT]) ? gameState-- : gameState++);					break;

					
				case SDLK_PLUS:		snake->velocity++;			break;
				case SDLK_MINUS:	snake->velocity--;			break;

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
