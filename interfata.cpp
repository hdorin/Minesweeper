#include<iostream>
#include<windows.h>

#include"globale.h"

using namespace std;



void InitConsole(){
    SetConsoleTitle("Minesweeper");

    HANDLE  hConsole;

    _COORD coord;
    coord.X = CmdWidth;
    coord.Y = CmdHeight;
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = CmdHeight - 1;
    Rect.Right = CmdWidth - 1;
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void afisare(){
    int i,j;
    for(i=0;i<=NoL+1;i++){
        for(j=0;j<=NoC+1;j++)
            cout<<mat1[i][j]<<" ";
        cout<<"     ";
        for(j=0;j<=NoC+1;j++)
            cout<<mat2[i][j]<<" ";
        cout<<endl;
    }

}
