#include "Level.cpp"

void MoveWorm() {

	switch( snake.dir ){
		case e_DI_Up:		snake.y -= snake.velocity;	break;
		case e_DI_Down:		snake.y += snake.velocity;	break;
		case e_DI_Left:		snake.x -= snake.velocity;	break;
		case e_DI_Right:	snake.x += snake.velocity;	break;
		case e_DI_Stop:		break;
	}
}

void Dead() {
	if( snake.dir != e_DI_Stop ){
		snake.lives--;
		snake.dir = e_DI_Stop;
	}
}
void CheckForCollition() {
	// Check outer wall
	if( (snake.x >= (BOARD_WIDTH)) ||
		(snake.x <= 6 ) ||
		(snake.y >= SCREEN_HEIGHT -6) ||
		(snake.y <= 30)
	   ){
		Dead();
	}
}

void OnLoop() {
	
	switch( gameState ){
		case e_GS_Menu:
			
			break;
		case e_GS_Ready:
			snake.dir = e_DI_Right;
			GenerateLevel();
			gameState = e_GS_Game;
			
			break;
		case e_GS_Game:
			MoveWorm();
			CheckForCollition();
			
			break;
		case e_GS_NextLevel:
			
			break;
			
		case e_GS_Pause:
			break;

		case e_GS_LastEnum:
			gameState = e_GS_Menu;
			break;
	}

}