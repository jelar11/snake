#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

enum Colors {
	e_C_Black	= 0x000000,
	e_C_Red		= 0xFF0000,
	e_C_Green	= 0x00FF00,
	e_C_Blue	= 0x0000FF,
	e_C_Gray	= 0x808080,
	e_C_Orange	= 0xFF9900,
	e_C_White	= 0xFFFFFF,
	e_C_Back	= 0x221F1E
};
// SetCoor("#AABBCC");
void SetColor(Colors c ) {
	
	int r = (c & 0xff0000) >> 16;
	int g = (c & 0x00ff00) >> 8;
	int b = (c & 0x0000ff);
	int a = 0xFF;
	
	SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
}

SDL_Color Color(Colors c) {
	unsigned char r = (c & 0xff0000) >> 16;
	unsigned char g = (c & 0x00ff00) >> 8;
	unsigned char b = (c & 0x0000ff);
	
	SDL_Color color = {r,g,b};
	return color;
}

#endif