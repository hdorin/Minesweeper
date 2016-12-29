#include<iostream>
#include<windows.h>
#include<graphics.h>

#include"globale.h"
#include"interfata.h"

using namespace std;



void InitConsole(){
    SetConsoleTitle("Minesweeper");

    HANDLE  hConsole;
    _COORD coord;
    coord.X = 500;
    coord.Y = 100;
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = 100 - 1;
    Rect.Right = 50 - 1;
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
//outtextxy(4, aux+2, "5");
void CreateTable(){
    int i,j;

    initwindow(NoC*40+1,NoL*40+1,"Minesweeper");

    setfillstyle(SOLID_FILL, WHITE);

    floodfill(1,1,GREEN);

    for(i=0;i<NoC;i++)
        for(j=0;j<NoL;j++)
            DrawBlock_Fill(i,j,true);

    /*outtextxy(4, aux+2, "5");
    bar(0,0,aux,aux);
    bar(aux,aux,2*aux,2*aux);
    bar(0,2*aux,aux,3*aux);*/




}
void DrawBlock_Fill(int l,int c,bool IsUntouched){
    int i;

    if(IsUntouched==true){
        setcolor(LIGHTGRAY);
        rectangle(l*40,c*40,(l+1)*40,(c+1)*40);
        setcolor(WHITE);
        setbkcolor(WHITE);


        setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);

        //for(i=1;i<2;i++)
        //rectangle(l*40+i,c*40+i,(l+1)*40-i,(c+1)*40-i);
    }else{
        setfillstyle(SOLID_FILL, WHITE);
        bar(l*40+1,c*40+1,(l+1)*40-1,(c+1)*40-1);
    }
}
void DrawBlock_Number(int l,int c,int Number){
    int i;
    DrawBlock_Fill(l,c,false);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    setbkcolor(WHITE);
    //setfillstyle(SOLID_FILL, WHITE);
    //bar(l*40,c*40,(l+1)*40,(c+1)*40);
    switch(Number){
        case 1: setcolor(LIGHTBLUE); outtextxy(l*40+8, c*40, "1"); break;
        case 2: setcolor(GREEN); outtextxy(l*40+8, c*40, "2"); break;
        case 3: setcolor(LIGHTRED); outtextxy(l*40+8, c*40, "3"); break;
        case 4: setcolor(BLUE); outtextxy(l*40+8, c*40, "4"); break;
        case 5: setcolor(RED); outtextxy(l*40+8, c*40, "5"); break;
        case 6: setcolor(CYAN); outtextxy(l*40+8, c*40, "6"); break;
        case 7: setcolor(BLACK); outtextxy(l*40+8, c*40, "7"); break;
        case 8: setcolor(LIGHTGRAY); outtextxy(l*40+8, c*40, "8"); break;

    //outtextxy(l+4, c+2, Conv)
    }
        setcolor(LIGHTGRAY);

        rectangle(l*40,c*40,(l+1)*40,(c+1)*40);


}
void DrawBlock_Marked(int l,int c){
    if(mat2[c+1][l+1]==9){
        if(mat3[c+1][l+1]==0){
            setcolor(RED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            circle(l*40+20,c*40+20,10);
            floodfill(l*40+21,c*40+21,RED);
            mat3[c+1][l+1]=1;
        }else{
            DrawBlock_Fill(l,c,true);
            mat3[c+1][l+1]=0;
        }
    }
}
void afisare(){
    int i,j;
    for(i=1;i<=NoL;i++){
        for(j=1;j<=NoC;j++)
            cout<<mat1[i][j]<<" ";
        cout<<"     ";
        for(j=1;j<=NoC;j++)
            cout<<mat2[i][j]<<" ";
        cout<<endl;
    }

}
