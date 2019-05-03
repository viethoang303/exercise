#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <ctime>
#include "Loadimage.h"
#include "Board.h"
#include "Draw.h"
#include "Play.h"
using namespace std;

int main( int argc, char* args[] )
{
    init();
    loadMedia();
    Play();
    close();
	return 0;
}
