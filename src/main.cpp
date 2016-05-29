#include "globals.h"

#include "OnInit.cpp"
#include "OnEvent.cpp"
#include "OnLoop.cpp"
#include "OnRender.cpp"

using namespace std;

int main( int argc, char* args[] )
{
	printf("snake v.0.1\n");
	if( Init() ){

		running = true;
		while( running ){
			OnEvent();
 			OnLoop();
 			OnRender();

			SDL_Delay(DELAY);
		}
	
	
		CleanUp();
	}else{
		printf("Faild to init the game\n");
	}

	return 0;
}