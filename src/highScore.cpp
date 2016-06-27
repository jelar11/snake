
#include "highScore.h"

#include <stdlib.h>     /* atoi */
#include <fstream>
#include <iostream>


#include <string.h>

//#include "globals.h"

using namespace std;

void LoadHighScore() {

	ifstream f;
	f.open("highscore.dat", ifstream::in);
	if( f.is_open() )
		{
		f.seekg(ios::beg);
		std::string line;
		int i=0;
		while( getline(f, line) ){
			int pos =line.find(",");
			strcpy( highScore[i].name, line.substr(0, pos).c_str() );
			highScore[i++].score = atoi( line.substr(pos +1, line.length() ).c_str() );
		}
		f.close();
	}else{
		printf("Highscore file not found.\n");
	}
	
}

void SaveHighScore() {

	ofstream f;
	f.open("highscore.dat", ofstream::out );
	if( f.is_open() ){
		for( int i=0; i<6; i++ ){
			if( highScore[i].score > 0 ){
				f << highScore[i].name << "," << highScore[i].score << "\n";
			}else{
				f << "\n";
			}
		}
		f.close();
	}
}


int CheckForHighScore(int newScore ) {
	static bool runOnce = false;
	if( runOnce )
		return -1;

	runOnce = true;
	int index = -1;
	for( int i=6; i>=0; i-- ){
		if( newScore >= highScore[i].score ){
			index = i;
		}
	}

	return index;
}