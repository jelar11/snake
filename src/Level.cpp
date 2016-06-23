#include "functions.h"
#include "globals.h"
#include <stdlib.h>     /* srand, rand */

const int n = 10;
int cordinates[n][2];

void GenerateLevel() {


	for( int i=0; i<=n-1; i++ ){
		cordinates[i][iX] = rand() % BOARD_WIDTH;
		cordinates[i][iY] = rand() % BOARD_HEIGHT;

//		printf("Coor[%d]: (%d,%d) \n", i, cordinates[i][iX], cordinates[i][iY] );
	}

}
