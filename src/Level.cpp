#include "functions.h"
#include "globals.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

const int n = 10;
int cordinates[n][2];

bool WithinBoard(int x, int y)
{
	bool res = false;
	if( (x >= 0 && x <= BOARD_WIDTH) &&
		(y >= 0 && y <= BOARD_HEIGHT))
	{
		res = true;
	}
	return res;
}

void GenerateLevel() {
	int i = 0;

	srand (time(NULL));
	do{
		int x = rand() % BOARD_WIDTH;
		int y = rand() % BOARD_HEIGHT;

		if( WithinBoard(x, y) )
		{
			cordinates[i][iX] = x;
			cordinates[i][iY] = y;
			i++;
		}
	}while( i < 10);

}
