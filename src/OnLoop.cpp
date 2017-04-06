

void MoveWorm() {

	switch( snake.dir ){
		case e_DI_Up:		snake.y -= snake.velocity;	break;
		case e_DI_Down:		snake.y += snake.velocity;	break;
		case e_DI_Left:		snake.x -= snake.velocity;	break;
		case e_DI_Right:	snake.x += snake.velocity;	break;
		case e_DI_Stop:		break;
	}

	static int prevX = snake.x;
	static int prevY = snake.y;

	int diffX = abs( (prevX) -snake.x);
	int diffY = abs( (prevY) -snake.y);
	if( diffX >= 10 || diffY >= 10 ){
		prevX = snake.x;
		prevY = snake.y;
		for( int i=snake.tailLen; i>0; i-- ){
			snake.tailD[i] = snake.tailD[i -1];
		}
		snake.tailD[0] = snake.dir;
//		snake.tailLen++;
		snake.invalid = true;
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
	
	switch( state ){
		case e_GS_Menu:
			if( skipState ){
				skipState = false;
				state = e_GS_Ready;
			}
			
			break;
		case e_GS_Ready:
			snake.dir = e_DI_Right;
			if( skipState ){
				skipState = false;
				state = e_GS_Game;
			}
			
			break;
		case e_GS_Game:
			MoveWorm();
			CheckForCollition();
			if( skipState ){
				skipState = false;
				state = e_GS_NextLevel;
			}
			
			break;
		case e_GS_NextLevel:
			if( skipState ){
				skipState = false;
				state = e_GS_Menu;
			}
			
			break;
			
		case e_GS_Pause:
			break;

		case e_GS_LastEnum:
			state = e_GS_Menu;
			break;
	}
}