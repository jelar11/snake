#include <vector>
#include <stdarg.h>
#include "functions.h"


void DrawText(int x, int y, std::string str, bool centerH=false, FontSizes fontSize=e_FS_14, Colors color=e_C_White) {

    SDL_Color txtColor = Color( color );
	TTF_Font *font = fonts[ fontSize ];
    SDL_Surface* txtSurf = TTF_RenderText_Solid( font, str.c_str(), txtColor);

    SDL_Texture* mTexture = SDL_CreateTextureFromSurface( gRenderer, txtSurf );
    SDL_FreeSurface( txtSurf );
	
	
	if( centerH ){
		x =  x - (txtSurf->w/2);
	}
	SDL_Rect renderQuad = { x, y, txtSurf->w, txtSurf->h };
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad); 

	
	SDL_DestroyTexture(mTexture);
}

void DrawDebugText() {
	std::vector<std::string> lines;

	lines.push_back( str_format("State: %s", GameState_str[gameState]) );
	lines.push_back( str_format("Pos (x,y): %d, %d", snake.x, snake.y) );
	lines.push_back( str_format("Velocity: %d", snake.velocity) );
	lines.push_back( str_format("Direction: %s", Direction_str[snake.dir]) );

	SDL_Surface* txtSurf;
	int w = 0;
	int x = 20;
	int y = 100;
	int boxH = 0;
	int count = (int)lines.size();
	for( int i=0; i<count; i++ ){
		DrawText(x, y, lines[i].c_str(), false, e_FS_14);
		txtSurf = TTF_RenderText_Solid( fonts[ e_FS_14 ], lines[i].c_str(), Color(e_C_Orange) );
		w = ((txtSurf->w >= w ) ? txtSurf->w : w);
		y += txtSurf->h;
		boxH += txtSurf->h;
	}

	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xA5, 0x00, 0xFF );
	SDL_Rect rect_r = { 18, 98, 18 + w , boxH +2 };
	SDL_RenderDrawRect( gRenderer, &rect_r );
}

void DrawBox(int x1, int y1, int x2, int y2, int width, Colors c) {
	SDL_Rect r = {x1, y1, x2, y2};
	SetColor( c );
	SDL_RenderFillRect( gRenderer, &r );
	
	SDL_Rect r2 = {x1 +width, y1 +width, x2 -(2*width), y2 -(2*width)};
	SetColor( e_C_Back );
	SDL_RenderFillRect( gRenderer, &r2 );
}

void DrawTopArea() {
	DrawBox(1, 1, SCREEN_WIDTH-2, 19, 2, e_C_White);

	DrawText(4, 2, str_format("Score: %d", snake.score ), false, e_FS_16 );

	DrawText((SCREEN_WIDTH/2), 2, (e_GS_Pause == gameState  ? "- Pause -" : "snake v.0.1"), true, e_FS_16);

	DrawText((SCREEN_WIDTH -90), 2, str_format("Lives: %d", snake.lives), false, e_FS_16 );

}


void DrawLeve() {
	// Draws the outer border
	DrawBox(BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT, 4, e_C_Orange);

	// Draw random coints
	int x, y;
	int i = snake.nextCoint;
	SetColor( e_C_Yellow );
	x = cordinates[i][iX] + BOARD_X;
	y = cordinates[i][iY] + BOARD_Y;
	SDL_Rect first = { x, y, 5, 5 };
	SDL_RenderFillRect( gRenderer, &first );


}

void DrawWorm() {
	SDL_Rect fillRect = { snake.x -5, snake.y -5, 10, 10 };
	SetColor( e_C_Red );
	SDL_RenderFillRect( gRenderer, &fillRect );

	SetColor( e_C_Blue );
	SDL_RenderDrawPoint(gRenderer, snake.x, snake.y);
}

void DrawMenu() {
	int x = SCREEN_WIDTH/2;
	int y = 80;
	DrawText(x, y, "Menu", true, e_FS_16);
	y += 18;
	DrawText(x, y, "--------------", true, e_FS_16 );
	y += 18;
	Colors c = e_C_White;
	std::string str;
	for( int i=0; i<e_MS_LastEnum; i++ ){
		if( menuState == i ){
			c = e_C_Yellow;
			str = str_format("> %s <", MenuStates_str[i] );
		}else{
			c = e_C_White;
			str = MenuStates_str[i];
		}
		DrawText(x, y, str, true, e_FS_16, c);
		y += 18;
	}
}

void DrawHighScore() {
	int x = SCREEN_WIDTH/2;
	int y = 80;
	DrawText(x, y, "HighScore", true, e_FS_16, e_C_Blue );
	y += 18;
	DrawText(x, y, "-------------------", true, e_FS_16 );
	y += 18;
	x -= 90;
	std::string str;
	for( int i=0; i<6; i++ ){
		int pos = highScore[i].find(",");
		std::string name = highScore[i].substr(0, pos);
		int score = atoi( highScore[i].substr(pos +1, highScore[i].length() ).c_str() );
		if( name.empty() )
			str = str_format("%d. ---", i +1 );
		else
			str = str_format("%d. %s      %d", i +1, name.c_str(), score );
		DrawText(x, y, str, false, e_FS_16);
		y += 18;
	}
	y += 18;
	x = SCREEN_WIDTH/2;
	DrawText(x, y, "> Back <", true, e_FS_16, e_C_Yellow );
}

void DrawGameOVer() {
	int x = BOARD_X + (BOARD_WIDTH/2);
	int y = (SCREEN_HEIGHT /2) - 50;
	DrawText(x, y, "Game over", true, e_FS_18 );

	y = 242;
	x = SCREEN_WIDTH/2;
	DrawText(x, y, "> Menu <", true, e_FS_16, e_C_Yellow );
}

void OnRender() {
	// Clear screen
	SetColor( e_C_Back );
    SDL_RenderClear( gRenderer );
	
	// draw top area
	DrawTopArea();
	
	switch( gameState ){
		case e_GS_Menu:
			DrawMenu();
		break;
		case e_GS_HighScore:
			DrawHighScore();
		break;
		case e_GS_Pause:
		case e_GS_Game:
			DrawLeve();
			// draw the wrom
			DrawWorm();

		break;
		case e_GS_GameOver:
			if( snake.lives > 0 ){
				snake.x = SCREEN_WIDTH /2;
				snake.y = SCREEN_HEIGHT /2;

				gameState = e_GS_Game;
			}else
				DrawGameOVer();
		break;
		case e_GS_NextLevel:
		break;
		case e_GS_Ready:
		break;
		default:
		break;
	}

	// draw Debug text
	if( showDebug ){
		DrawDebugText();
	}
    // Update screen
    SDL_RenderPresent( gRenderer );

}
