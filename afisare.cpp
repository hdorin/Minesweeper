#include<iostream>

#include"globale.h"

using namespace std;

void afisare(){
    int i,j;
    for(i=0;i<NoL;i++){
        for(j=0;j<NoC;j++)
            cout<<mat1[i][j]<<" ";
        cout<<endl;
    }

}
