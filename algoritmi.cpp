#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<thread>
#include<graphics.h>

#include"globale.h"
#include"interfata.h"

using namespace std;

short DirL[10] = {0,-1,-1, 0, 1, 1, 1, 0,-1};
short DirC[10] = {0, 0, 1, 1, 1, 0,-1,-1,-1};

void DifficultySelected(){
    srand(time(NULL));
    switch(Difficulty){
        case 1:
            NoL=10;
            NoC=12;
            NoBo=15;
            NoPU=rand()%3+1;
            NoT=rand()%2;
            break;
        case 2:
            NoL=14;
            NoC=16;
            NoBo=30;
            NoPU=rand()%5+1;
            NoT=rand()%3+1;
            break;
        case 3:
            NoL=14;
            NoC=24;
            NoBo=50;
            NoPU=rand()%7+1;
            NoT=rand()%5+1;
            break;
        case 4:
            NoL=20;
            NoC=30;
            NoBo=80;
            NoPU=rand()%9+1;
            NoT=rand()%9+1;
            break;
    }
}
void InitBombe(int l,int c){
    int x,y;
    srand(time(NULL));
    for(x=1;x<=NoL;x++)
        for(y=1;y<=NoC;y++)
            mat1[x][y]=0;
    do{
        //srand(time(NULL));
        x=rand()%NoL+1;
        y=rand()%NoC+1;
        if(mat1[x][y]==0&&(l!=x||c!=y)){
            mat1[x][y]=1;
            NoBo--;
        }

    }while(NoBo>0);
}
void InitPoweUps(int l,int c){
    int x,y;
    //srand(time(NULL));
    while(NoPU>0){
        x=rand()%NoL+1;
        y=rand()%NoC+1;
        if(mat1[x][y]==0&&(l!=x||c!=y)){
            mat1[x][y]=2;
            NoPU--;
        }
    }
}
void InitTraps(int l,int c){
    int x,y;
    //srand(time(NULL));
    while(NoT>0){
        x=rand()%NoL+1;
        y=rand()%NoC+1;
        if(mat1[x][y]==0&&(l!=x||c!=y)){
            mat1[x][y]=3;
            NoT--;
        }
    }
}
void InitTabela(){
    int i,j;
    for(i=0;i<=NoL+1;i++)
        for(j=0;j<=NoC+1;j++)
            mat1[i][j]=mat2[i][j]=mat3[i][j]=0;

    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            mat2[i][j]=9;
    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            mat3[i][j]=0;
}
void Discover_Fill(int x,int y){
    int i,nr=0;
    if(mat2[x][y]==9&&mat1[x][y]==0&&mat3[x][y]==0){
        for(i=1;i<=8;i++)
            if(mat1[x+DirL[i]][y+DirC[i]]==1)
                nr++;
        mat2[x][y]=nr;
        if(nr==0){
            for(i=1;i<=8;i++)
                Discover_Fill(x+DirL[i],y+DirC[i]);
        }
    }
}
void Discover(int x,int y){
    int mat[100][100];
    int i,j;
    bool Execute;
    if(IsFirstMove==true){
        InitBombe(x,y);
        InitTraps(x,y);
        InitPoweUps(x,y);
        IsFirstMove=false;
    }
    switch(mat1[x][y]){
        case 1: GameOver=true; return ;
        case 2:    break;
        case 3: CoverBlocks(y-1,x-1); mat1[x][y]=0; return;//mat1[x][y]=0;
    }
    Execute=(mat1[x][y]==2);
    if(mat1[x][y]==2)
        mat1[x][y]=0;

    CanChangeClr=CanClear=false;
    thread t1 (RevealTemporarely,y-1,x-1,Execute);

    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            mat[i][j]=mat2[i][j];
    Discover_Fill(x,y);

    while(CanChangeClr==false&&Execute==true)
        Sleep(1);

    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            if(mat[i][j]!=mat2[i][j]){
                if(mat[i][j]==0)
                    DrawBlock_Fill(j-1,j-1,false);
                else
                    DrawBlock_Number(j-1,i-1,mat2[i][j]);
            }
    CanClear=true;
    //if(t1.joinable()==true)
        t1.join();
}
void DiscoverExtended(int l,int c,int val){
    int i,j,nr=0,mat[100][100];
    bool EndAfter=false;
    for(i=1;i<=8;i++)
        if(mat3[l+DirL[i]][c+DirC[i]]==1)
            nr++;
    if(nr==val&&val>0){
        for(i=1;i<=NoL;i++)
            for(j=1;j<=NoC;j++)
                mat[i][j]=mat2[i][j];
        for(i=1;i<=8;i++)
            if(mat3[l+DirL[i]][c+DirC[i]]==0&&mat2[l+DirL[i]][c+DirC[i]]==9){
                if(mat1[l+DirL[i]][c+DirC[i]]==1){
                    GameOver=true;
                    return ;
                }
                    if(mat1[l+DirL[i]][c+DirC[i]]==3)
                        EndAfter=true;
                    Discover(l+DirL[i],c+DirC[i]);

                    if(EndAfter==true){
                        EndAfter=false;
                        return ;
                    }
            }
        for(i=1;i<=NoL;i++)
            for(j=1;j<=NoC;j++)
                if(mat[i][j]!=mat2[i][j]){
                    if(mat[i][j]==0)
                        DrawBlock_Fill(j-1,j-1,false);
                    else
                        DrawBlock_Number(j-1,i-1,mat2[i][j]);
                }
    }
}
bool TestSfarsitJoc(){
    int i,j;
    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            if(mat1[i][j]==0&&mat2[i][j]==9)
                return false;
    GameOver=true;
    return true;
}
