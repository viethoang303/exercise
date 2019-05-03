#ifndef Functions_h
#define Functions_h
#include "Loadimage.h"

const int SCREEN_WIDTH = 556;
const int SCREEN_HEIGHT = 680;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Game 2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	if(!gBackground.loadFromFile("background 2.png"))
    {
        printf( "Failed to load bk texture!\n" );
		success = false;
    }

    if( !gTile.loadFromFile( "Tile Background.png" ) )
	{
		printf( "Failed to load Tile texture!\n" );
		success = false;
	}
    if( !g2.loadFromFile( "2 Tile.png" ) )
	{
		printf( "Failed to load 2 texture!\n" );
		success = false;
	}
	 if( !g4.loadFromFile( "4 Tile.png" ) )
	{
		printf( "Failed to load 4 texture!\n" );
		success = false;
	}
	 if( !g8.loadFromFile( "8 Tile.png" ) )
	{
		printf( "Failed to load 8 texture!\n" );
		success = false;
	}
	 if( !g16.loadFromFile( "16 Tile.png" ) )
	{
		printf( "Failed to load 16 texture!\n" );
		success = false;
	}
	 if( !g32.loadFromFile( "32 Tile.png" ) )
	{
		printf( "Failed to load 32 texture!\n" );
		success = false;
	}
	if( !g64.loadFromFile( "64 Tile.png" ) )
	{
		printf( "Failed to load 64 texture!\n" );
		success = false;
	}
	if( !g128.loadFromFile( "128 Tile.png" ) )
	{
		printf( "Failed to load 128 texture!\n" );
		success = false;
	}
	if( !g256.loadFromFile( "256 Tile.png" ) )
	{
		printf( "Failed to load 256 texture!\n" );
		success = false;
	}
	if( !g512.loadFromFile( "512 Tile.png" ) )
	{
		printf( "Failed to load 512 texture!\n" );
		success = false;
	}
	if( !g1024.loadFromFile( "1024 Tile.png" ) )
	{
		printf( "Failed to load 2 texture!\n" );
		success = false;
	}
	if( !g2048.loadFromFile( "2048 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !g4096.loadFromFile( "4096 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !g8192.loadFromFile( "8192 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !g16384.loadFromFile( "16384 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !g32768.loadFromFile( "32768 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !g65536.loadFromFile( "65536 Tile.png" ) )
	{
		printf( "Failed to load 2048 texture!\n" );
		success = false;
	}
	if( !gGameover.loadFromFile( "game over.png" ) )
	{
		printf( "Failed to load gameover texture!\n" );
		success = false;
	}
    return success;
}

void close()
{
	g2.free();
	g4.free();
	g8.free();
	g16.free();
	g32.free();
	g64.free();
	g128.free();
	g256.free();
	g512.free();
	g1024.free();
	g2048.free();
	gBackground.free();
	gGameover.free();
	gTile.free();
	gScore.free();

	TTF_CloseFont( gFont );
	gFont = NULL;

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
void Updateload()
{
    gTile.render(8, 548);
    gTile.render(8, 412);
    gTile.render(8, 276);
    gTile.render(8, 140);
    gTile.render(144, 548);
    gTile.render(144, 412);
    gTile.render(144, 276);
    gTile.render(144, 140);
    gTile.render(280, 548);
    gTile.render(280, 412);
    gTile.render(280, 276);
    gTile.render(280, 140);
    gTile.render(416, 548);
    gTile.render(416, 412);
    gTile.render(416, 276);
    gTile.render(416, 140);
}
void End()
{
    g2.setAlpha(85);
    g4.setAlpha(85);
    g8.setAlpha(85);
    g16.setAlpha(85);
    g32.setAlpha(85);
    g64.setAlpha(85);
    g128.setAlpha(85);
    g256.setAlpha(85);
    g512.setAlpha(85);
    g1024.setAlpha(85);
    g2048.setAlpha(85);
    g4096.setAlpha(85);
    g8192.setAlpha(85);
    g16384.setAlpha(85);
    g32768.setAlpha(85);
    g65536.setAlpha(85);
}
void New()
{
    g2.setAlpha(1000);
    g4.setAlpha(1000);
    g8.setAlpha(1000);
    g16.setAlpha(1000);
    g32.setAlpha(1000);
    g64.setAlpha(1000);
    g128.setAlpha(1000);
    g256.setAlpha(1000);
    g512.setAlpha(1000);
    g1024.setAlpha(1000);
    g2048.setAlpha(1000);
    g4096.setAlpha(1000);
    g8192.setAlpha(1000);
    g16384.setAlpha(1000);
    g32768.setAlpha(1000);
    g65536.setAlpha(1000);
}

#endif // Functons_h


