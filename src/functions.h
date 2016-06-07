#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

enum Colors {
	e_C_Black		= 0x000000,
	e_C_Red			= 0xFF0000,
	e_C_Green		= 0x00FF00,
	e_C_Blue		= 0x0000FF,
	e_C_LiteBlue	= 0x4D4DFF,
	e_C_Gray		= 0x808080,
	e_C_Yellow		= 0xE6E600,
	e_C_Orange		= 0xFFA500,
	e_C_White		= 0xFFFFFF,
	e_C_Back		= 0x221F1E
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

void LoadHighScore() {
	ifstream f;
	f.open("highscore.dat", ifstream::in);
	if( f.is_open() )
		{
		f.seekg(ios::beg);
		std::string line;
		int i=0;
		while( getline(f, line) ){
			highScore[i++] = line;
		}
		f.close();
	}else{
		printf("Highscore file not found.\n");
	}
	
}

void SaveHighSCore() {
	
	ofstream f;
	f.open("highscore.dat", ofstream::out );
	if( f.is_open() ){
		for( int i=0; i<6; i++ ){
			if( ! highScore[i].empty() ){
				f << highScore[i] << "\n";
			}
		}
		f.close();
	}
}

#endif
