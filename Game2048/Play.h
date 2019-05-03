#include "Board.h"
#include "Loadimage.h"
#include "Functions.h"
//#include "HighScores.h"
void Play()
{
    Board board;
    board.Khoitao();
    board.HighScores();
    SDL_Event e;
    bool quit = false;
    while(!quit){
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            board.handleEvent(e);
        }
        board.HighScores();
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        gBackground.render(0, 0);
        Updateload();
        Draw(board);
        gScore.render(350,50);
        gHighScore.render(50,50);
        board.update();
        if(board.Endgame()== 1){
            gGameover.render(60,240);
            End();
        }
        if( e.type == SDL_KEYDOWN )
        {
            switch (e.key.keysym.sym){
                case SDLK_RETURN:
                board.again();
                board.update();
                board.Khoitao();
                board.SCORES = 0;
                New();
                break;
            }
        }
        SDL_RenderPresent( gRenderer );
    }
}

