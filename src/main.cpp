#include "globals.h"

#include "OnInit.cpp"
#include "OnEvent.cpp"
#include "OnLoop.cpp"
#include "OnRender.cpp"

#include "LTimer/LTimer.h"
#include <sstream>

const int SCREEN_FPS = 40;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

using namespace std;

int main( int argc, char* args[] )
{
	//The frames per second timer
	LTimer fpsTimer;
	LTimer capTimer;
	std::stringstream timeText;

	printf("snake v.0.1\n");
	if( Init() ){

		int countedFrames = 0;
		fpsTimer.start(); 
		running = true;
		while( running ){
			capTimer.start();
			 
			OnEvent();
 			OnLoop();
 			OnRender();

				//Calculate and correct fps
				avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
				if( avgFPS > 2000000 )
				{
					avgFPS = 0;
				}

			++countedFrames;
			int frameTicks = capTimer.getTicks();
			if( frameTicks < SCREEN_TICKS_PER_FRAME ) {
				SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
			}
		}
	
	
		CleanUp();
	}else{
		printf("Faild to init the game\n");
	}

	return 0;
}