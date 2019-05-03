#ifndef Draw_H
#define Draw_H
#include <string>
#include "Loadimage.h"
#include "Board.h"
#include <SDL_ttf.h>
#include<sstream>
using namespace std;
LTexture gScore;
LTexture gHighScore;

bool Draw(Board board )
{
	bool success = true;
	gFont = TTF_OpenFont( "COMICATE.ttf", 30);
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		SDL_Color textColor = { 255, 0, 0 };
        string s;
        ostringstream oscar;
        oscar << board.SCORES;
        s = oscar.str();
        if( !gScore.loadFromRenderedText( s, textColor ) )
		{
			printf( "Failed to render score texture!\n" );
			success = false;
		}

		string s1;
		ostringstream oscar1;
		oscar1 << board.HIGHSCORES;
		s1 = oscar1.str();
		if( !gHighScore.loadFromRenderedText( s1, textColor ) )
		{
			printf( "Failed to render highscore texture!\n" );
			success = false;
		}
	}
	return success;
}
#endif // Draw_H
