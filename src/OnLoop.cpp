
void MoveWorm() {

	switch( snake.dir ){
		case e_DI_Up:		snake.y -= snake.velocity;	break;
		case e_DI_Down:		snake.y += snake.velocity;	break;
		case e_DI_Left:		snake.x -= snake.velocity;	break;
		case e_DI_Right:	snake.x += snake.velocity;	break;
		case e_DI_Stop:		break;
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
			snake.dir = e_DI_Left;
			if( skipState ){
				skipState = false;
				state = e_GS_Game;
			}
			
			break;
		case e_GS_Game:
			MoveWorm();
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