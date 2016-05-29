
void OnLoop() {
	
	switch( state ){
		case e_GS_Menu:
			if( skipState ){
				skipState = false;
				state = e_GS_Ready;
			}
			
			break;
		case e_GS_Ready:
			if( skipState ){
				skipState = false;
				state = e_GS_Game;
			}
			
			break;
		case e_GS_Game:
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