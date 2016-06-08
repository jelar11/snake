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
	if( ((snake.x +10) >= (BOARD_X + BOARD_WIDTH)) ||
		((snake.x -10) <= (BOARD_X ) ) ||
		((snake.y +10) >= (BOARD_Y + BOARD_HEIGHT) ) ||
		((snake.y -10) <= (BOARD_Y) )
	   ){
		Dead();
	}

	int x = cordinates[ snake.nextCoint ][iX] + BOARD_X;
	int y = cordinates[ snake.nextCoint ][iY] + BOARD_Y;

	if( ((snake.x +5) >= x && (snake.x -5) <= (x +5)) &&
		((snake.y +5) >= y && (snake.y -5) <= (y +5))
	) {
		snake.nextCoint++;
		if( snake.nextCoint >= 10 ){
			gameState = e_GS_NextLevel;
		}
		snake.score += 10;
	}
}

void OnLoop() {
	
	switch( gameState ){
		case e_GS_Menu:
			
			break;
		case e_GS_Ready:
			snake.dir = e_DI_Right;
			GenerateLevel();
			snake.nextCoint = 0;
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