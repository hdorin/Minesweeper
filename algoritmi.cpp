#include<iostream>
#include<stdlib.h>
#include<time.h>

//#include"algoritmi.h"
#include"globale.h"


using namespace std;
//FOLOSESTE CA PARAMETRU: "NoB"
void InitBombe(){
    int x,y;
    srand(time(NULL));
    for(x=0;x<NoL;x++)
        for(y=0;y<NoC;y++)
            mat1[x][y]=0;
    do{
        x=rand()%NoL;
        y=rand()%NoC;
        if(mat1[x][y]==0){
            mat1[x][y]=1;
            NoB--;
        }

    }while(NoB>0);
}
void Discover(int x,int y){

}

