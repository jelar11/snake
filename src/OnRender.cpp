#include <vector>
#include <stdarg.h>
#include "functions.h"

std::string str_format(const std::string fmt, ...) {
    int size = ((int)fmt.size()) * 2 + 50;   // Use a rubric appropriate for your code
    std::string str;
    va_list ap;
    while (1) {     // Maximum two passes on a POSIX system...
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size) {  // Everything worked
            str.resize(n);
            return str;
        }
        if (n > -1)  // Needed size returned
            size = n + 1;   // For null char
        else
            size *= 2;      // Guess at a larger size (OS specific)
    }
    return str;
}

void DrawText(int x, int y, std::string str, bool centerH=false, FontSizes fontSize=e_FS_14, Colors color=e_C_White) {

    SDL_Color txtColor = Color( color );
	TTF_Font *font;
	switch( fontSize ){
		case e_FS_14:	font = debugFont;	break;
		case e_FS_16:	font = menuFont;	break;
		default:	break;
	}
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

	lines.push_back( str_format("State: %s", GameState_str[state]) );
	lines.push_back( str_format("Pos (x,y): %d, %d", snake.x, snake.y) );
	lines.push_back( str_format("Velocity: %d", snake.velocity) );

	SDL_Surface* txtSurf = TTF_RenderText_Solid( debugFont, "Txt", Color(e_C_Orange) );
	int h = txtSurf->h;
	int w = 0;
	int x = 20;
	int y = 100;
	int count = (int)lines.size();
	for( int i=0; i<count; i++ ){
		DrawText(x, y, lines[i].c_str(), false);
		txtSurf = TTF_RenderText_Solid( debugFont, lines[i].c_str(), Color(e_C_Orange) );
		w = ((txtSurf->w >= w ) ? txtSurf->w : w);
		y += h;
	}

	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xA5, 0x00, 0xFF );
	SDL_Rect rect_r = { 18, 98, 18 + w , (h*count)+2};
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
	
	DrawText((SCREEN_WIDTH/2), 2, "snake v.0.1", true, e_FS_16);
	
	DrawText((SCREEN_WIDTH -90), 2, str_format("Lives: %d", snake.lives), false, e_FS_16 );

}


void DrawLeve() {
	// Draws the outer border
	DrawBox(BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT, 4, e_C_Orange);

	// Draw random coints
	int x, y;
	char str[10];
	for( int i=0; i<=n-1; i++ ){
		SetColor( e_C_Yellow );
		x = cordinates[i][iX] + BOARD_X;
		y = cordinates[i][iY] + BOARD_Y;
		SDL_Rect first = { x, y, 5, 5 };
		SDL_RenderFillRect( gRenderer, &first );

//		sprintf(str, "%d", i);
//		DrawText(x, y, str);
	}

}

void DrawWorm() {
	SDL_Rect fillRect = { snake.x -5, snake.y -5, 10, 10 };
	SetColor( e_C_Red );
    SDL_RenderFillRect( gRenderer, &fillRect );
	
	SetColor( e_C_Blue );
	SDL_RenderDrawPoint(gRenderer, snake.x, snake.y);
}

void OnRender() {
	// Clear screen
	SetColor( e_C_Back );
    SDL_RenderClear( gRenderer );
	
	// draw top area
	DrawTopArea();
	
	DrawLeve();
	
	// draw the wrom
	DrawWorm();

	// draw Debug text
	if( showDebug ){
		DrawDebugText();	
	}
    // Update screen
    SDL_RenderPresent( gRenderer );

}