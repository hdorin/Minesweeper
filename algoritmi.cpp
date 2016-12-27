#include<iostream>
#include<stdlib.h>
#include<time.h>

//#include"algoritmi.h"
#include"globale.h"

using namespace std;

short DirL[10] = {0,-1,-1, 0, 1, 1, 1, 0,-1};
short DirC[10] = {0, 0, 1, 1, 1, 0,-1,-1,-1};

void InitBombe(){
    int x,y;
    srand(time(NULL));
    for(x=1;x<=NoL;x++)
        for(y=1;y<=NoC;y++)
            mat1[x][y]=0;
    do{
        x=rand()%NoL+1;
        y=rand()%NoC+1;
        if(mat1[x][y]==0){
            mat1[x][y]=1;
            NoBo--;
        }

    }while(NoBo>0);
}
void InitTabela(){
    int i,j;
    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            mat2[i][j]=9;
}
void Discover(int x,int y){
    int i,j,nr=0;
    if(mat2[x][y]==9&&mat1[x][y]==0){
        for(i=1;i<=8;i++)
            if(mat1[x+DirL[i]][y+DirC[i]]==1)
                nr++;
        mat2[x][y]=nr;
        if(nr==0){
            for(i=1;i<=8;i++)
                Discover(x+DirL[i],y+DirC[i]);
        }
    }
}

