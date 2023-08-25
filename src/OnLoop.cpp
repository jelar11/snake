#include "Level.cpp"

bool MovedOneCell()
{
	static int lastCellX = 0;
	static int lastCellY = 0;

	if( lastCellX == 0 && lastCellY == 0)
	{
		lastCellX = snake->x;
		lastCellY = snake->y;
	}

	if( std::abs(snake->x - lastCellX) >= 12 || std::abs(snake->y - lastCellY) >= 12 )
	{
		lastCellX = snake->x;
		lastCellY = snake->y;
		return true;
	}

	return false;
}

void MoveWorm() {

	switch( snake->dir ){
		case e_DI_Up:		snake->y -= snake->velocity;	break;
		case e_DI_Down:		snake->y += snake->velocity;	break;
		case e_DI_Left:		snake->x -= snake->velocity;	break;
		case e_DI_Right:	snake->x += snake->velocity;	break;
		case e_DI_Stop:		break;
	}

	if( MovedOneCell() )
	{
		snake->tail.push_back(Point(snake->x, snake->y));
		if( (int)snake->tail.size() > snake->tail_size )
			snake->tail.pop_front();
	}

}

void Dead() {
	if( snake->dir != e_DI_Stop ){
		snake->lives--;
		snake->dir = e_DI_Stop;
		gameState = e_GS_GameOver;
	}
}

void NewGame() {
	snake->x = SCREEN_WIDTH /2;
	snake->y = SCREEN_HEIGHT /2;
	snake->lives = 3;
	snake->score = 0;
	snake->velocity = 2;
	snake->dir = e_DI_Right;
	snake->nextCoint = 0;
}

void CheckForCollition() {
	// Check outer wall
	if( ((snake->x +10) >= (BOARD_X + BOARD_WIDTH) +1) ||
		((snake->x -10) <= (BOARD_X +1) ) ||
		((snake->y +10) >= (BOARD_Y + BOARD_HEIGHT +1) ) ||
		((snake->y -10) <= (BOARD_Y-1) )
		){
		Dead();
	}

	const int x = cordinates[ snake->nextCoint ][iX] + BOARD_X;
	const int y = cordinates[ snake->nextCoint ][iY] + BOARD_Y;

	if( ((snake->x +5) >= x && (snake->x -5) <= (x +5)) &&
		((snake->y +5) >= y && (snake->y -5) <= (y +5))
	) {
		snake->nextCoint++;
		if( snake->nextCoint >= 10 ){
			gameState = e_GS_NextLevel;
		}
		snake->score += 10;
		snake->tail_size++;
		if( (snake->score % 4) == 0 )
		{
			snake->velocity++;
		}
	}
}

void OnLoop() {
	
	switch( gameState ){
		case e_GS_Menu:
			
			break;
		case e_GS_Ready:
			NewGame();

			GenerateLevel();
			gameState = e_GS_Game;
			
			break;
		case e_GS_Game:
			MoveWorm();
			CheckForCollition();
			break;
		case e_GS_GameOver:
			snake->highScoreIndex = CheckForHighScore(snake->score);
			if( snake->highScoreIndex >= 0 ){
				gameState = e_GS_NewHighScore;
			}
			break;
		case e_GS_NewHighScore:
		break;
		case e_GS_NextLevel:
			
			break;
			
		case e_GS_Pause:
			break;

		case e_GS_LastEnum:
			gameState = e_GS_Menu;
			break;
	}
	SDL_ShowCursor( (showDebug ? SDL_ENABLE : SDL_DISABLE) );
}
