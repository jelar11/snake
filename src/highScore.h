
#ifndef _HIGHSCORE_H_
#define _HIGHSCORE_H_

struct HighScoreItem {
	char name[16];
	int score;
};

extern HighScoreItem highScore[6];

void LoadHighScore();
void SaveHighScore();
int CheckForHighScore(int newScore );

#endif