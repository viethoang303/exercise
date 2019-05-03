#ifndef Board_H
#define Board_H
#include "Loadimage.h"
#include <fstream>
#include <iostream>
using namespace std;
const int ROW[] = {0,8,144,280,416};
const int COLUMN[] = {0,140,276, 412,548};
LTexture gBackground;
LTexture gTile;
LTexture g2;
LTexture g4;
LTexture g8;
LTexture g16;
LTexture g32;
LTexture g64;
LTexture g128;
LTexture g256;
LTexture g512;
LTexture g1024;
LTexture g2048;
LTexture g4096;
LTexture g8192;
LTexture g16384;
LTexture g32768;
LTexture g65536;
LTexture gGameover;
class Board
{
    public:
        int SCORES=0;
        int HIGHSCORES=0;
        Board();
        int Taoso();
        void Khoitao();
        void Themso();
        void Quaphai();
        void Congphai();
        void Phai();
        void Quatrai();
        void Congtrai();
        void Trai();
        void Xuongduoi();
        void Congduoi();
        void Duoi();
        void Lentren();
        void Congtren();
        void Tren();
        void handleEvent(SDL_Event& e);
        void update();
        int Endgame();
        void again();
        void HighScores();
    private:
        int Matran[4][4];
        int DEM=0;

};

Board::Board()
{
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            Matran[i][j]=0;
        }
    }
}
int Board::Taoso(){
    srand(time(0));
    int a = rand()%100+1;
    if(a<=95) return 2;
    else return 4;
}
void Board::Khoitao(){
    srand(time(0));
    int x,y,x1,y1;
    x = rand()%4;
    y = rand()%4;
    do{
        x1 = rand()%4;
        y1 = rand()%4;
    } while(x1==x && y1==y);
    Matran[x][y]=2;
    Matran[x1][y1]=2;
}
void Board::Themso(){
    srand(time(0));
    int i, j;
    do{
        i = rand()%4;
        j = rand()%4;
    } while (Matran[i][j]!=0);
    Matran[i][j]=Taoso();
}

void Board::Quaphai(){
    for(int j=0; j<4; j++){
        for (int i=3; i>=0; i--){
            if(Matran[i][j]==0){
                for(int h=i-1; h>=0; h--){
                    if(Matran[h][j]!=0){
                        Matran[i][j]=Matran[h][j];
                        Matran[h][j]=0;
                        i--;
                        DEM++;
                    }
                }
            }
        }
    }
}
void Board::Congphai(){
    for (int j=0; j<4; j++){
        for (int i=3; i>0; i--){
            if (Matran[i][j]==Matran[i-1][j] && Matran[i][j]!=0){
                Matran[i][j]+=Matran[i-1][j];
                Matran[i-1][j]=0;
                SCORES+=Matran[i][j];
                Quaphai();
                DEM++;
            }
        }
    }
}
void Board::Phai(){
    Quaphai();
    Congphai();
    if(DEM!=0){
        Themso();
        DEM=0;
    }
}

void Board::Quatrai(){
    for(int j=3; j>=0; j--){
        for (int i=0; i<4; i++){
            if(Matran[i][j]==0){
                for(int h=i+1; h<4; h++){
                    if(Matran[h][j]!=0){
                        Matran[i][j]=Matran[h][j];
                        Matran[h][j]=0;
                        i++;
                        DEM++;
                    }
                }
            }
        }
    }
}
void Board::Congtrai(){
    for (int j=3; j>=0; j--){
        for (int i=0; i<3; i++){
            if(Matran[i][j]==Matran[i+1][j] && Matran[i][j]!=0){
                Matran[i][j]+=Matran[i+1][j];
                Matran[i+1][j]=0;
                SCORES+=Matran[i][j];
                Quatrai();
                DEM++;
            }
        }
    }
}
void Board::Trai(){
    Quatrai();
    Congtrai();
    if(DEM!=0){
        Themso();
        DEM=0;
    }
}
void Board::Xuongduoi(){
    for(int i=0; i<4; i++){
        for(int j=3; j>=0; j--){
            if(Matran[i][j]==0){
                for (int h=j-1; h>=0; h--){
                    if(Matran[i][h]!=0){
                        Matran[i][j]=Matran[i][h];
                        Matran[i][h]=0;
                        j--;
                        DEM++;
                    }
                }
            }
        }
    }
}
void Board::Congduoi(){
    for (int i=3; i>=0; i--){
        for (int j=0; j<3; j++){
            if(Matran[i][j]==Matran[i][j+1] && Matran[i][j]!=0){
                Matran[i][j]+=Matran[i][j+1];
                Matran[i][j+1]=0;
                SCORES += Matran[i][j];
                Xuongduoi();
                DEM++;
            }
        }
    }
}
void Board::Duoi(){
    Xuongduoi();
    Congduoi();
    if(DEM!=0){
        Themso();
        DEM=0;
    }
}
void Board::Lentren(){
    for(int i=3; i>=0; i--){
        for(int j=0; j<4; j++){
            if(Matran[i][j]==0){
                for(int h=j+1; h<4; h++){
                    if(Matran[i][h]!=0){
                        Matran[i][j]=Matran[i][h];
                        Matran[i][h]=0;
                        j++;
                        DEM++;
                    }
                }
            }
        }
    }
}
void Board::Congtren(){
    for (int i=3; i>=0; i--){
        for (int j=0; j<3; j++){
            if(Matran[i][j]==Matran[i][j+1] && Matran[i][j]!=0){
                Matran[i][j]+=Matran[i][j+1];
                Matran[i][j+1]=0;
                SCORES+=Matran[i][j];
                Lentren();
                DEM++;
            }
        }
    }
}
void Board::Tren(){
    Lentren();
    Congtren();
    if(DEM!=0){
        Themso();
        DEM=0;
    }
}



void Board::handleEvent(SDL_Event& e)
{
    if(e.type==SDL_KEYDOWN){
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: Tren(); break;
            case SDLK_DOWN: Duoi(); break;
            case SDLK_LEFT: Trai(); break;
            case SDLK_RIGHT: Phai(); break;
        }
    }
}

 void Board::update()
 {
     for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if(Matran[i][j]==0){
                gTile.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==2){
                g2.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==4){
                g4.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==8){
                g8.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==16){
                g16.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==32){
                g32.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==64){
                g64.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==128){
                g128.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==256){
                g256.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==512){
                g512.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==1024){
                g1024.render(ROW[i+1],COLUMN[j+1]);
            } else
            if(Matran[i][j]==2048){
                g2048.render(ROW[i+1],COLUMN[j+1]);
            }
        }
     }
 }

int Board::Endgame()
 {
    int a = 0, b = 0, c = 0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if(Matran[i][j]==0){
                a=1;
            }
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(Matran[i][j]==Matran[i][j+1] || Matran[i][j]==Matran[i+1][j]){
                b=1;
            }
        }
    }
    for (int i=0; i<3; i++){
        if(Matran[3][i]==Matran[3][i+1] || Matran[i][3]==Matran[i+1][3]){
            c=1;
        }
    }
    if(a==0 && b==0 && c==0) return 1;
    else return 0;
 }
 void Board::again()
 {
     for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            Matran[i][j]=0;
        }
    }
 }
 void Board::HighScores()
 {
    int data;
    int a = 0;
    ifstream file;
    file.open("SCORES.txt");
    file >> data;
    HIGHSCORES = data;
    if(SCORES>HIGHSCORES){
        HIGHSCORES = SCORES;
        a=1;
    }
    file.close();
    if(a==1){
        ofstream outfile;
        outfile.open("SCORES.txt");
        data=SCORES;
        outfile << data;
        outfile.close();
    }
}
#endif // Board_H

