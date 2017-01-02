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
void DisplayTable(){
    int i,j;


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
void DisplayMenu_Title(){
    int addx2=146,addy2=60;
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(1,1,GREEN);
    setcolor(GREEN);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 4);
    outtextxy(100,28,"The Adventures of the");

    setcolor(RED);
    settextstyle(EUROPEAN_FONT,   HORIZ_DIR, 5);
    outtextxy(addx2,addy2,"M");

    setcolor(BLUE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    outtextxy(addx2+55,addy2+3,"inesweeper");


    //setcolor(RED);
    //settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    //outtextxy(267,10,"er");
}

void DisplayMenu_Options(){
    dmost dmo;
    setbkcolor(dmo.colr);
    //void setlinestyle(int linestyle, unsigned upattern, int thickness);
    //setlinestyle(SOLID_LINE,SOLID_LINE,3);

    //EASY
    setfillstyle(SOLID_FILL,dmo.colr);
    bar(dmo.sx,dmo.sy,dmo.sx+dmo.addx,dmo.sy+dmo.addy);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 4);
    outtextxy(dmo.sx+10,dmo.sy+5,"Easy 10x12");



    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 3);
    outtextxy(dmo.sx+10,dmo.sy+35,"Bombs: 15");
    outtextxy(dmo.sx+10,dmo.sy+55,"Traps: 0-1");
    outtextxy(dmo.sx+10,dmo.sy+75,"Reveals: 1-3");

    //MEDIUM
    bar(dmo.sx,dmo.sy+dmo.addy+dmo.addby,dmo.sx+dmo.addx,dmo.sy+dmo.addy+dmo.addy+dmo.addby);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 4);
    outtextxy(dmo.sx+10,dmo.sy+5+dmo.addy+dmo.addby,"Medium 15x15");



    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 3);
    outtextxy(dmo.sx+10,dmo.sy+35+dmo.addy+dmo.addby,"Bombs: 30");
    outtextxy(dmo.sx+10,dmo.sy+55+dmo.addy+dmo.addby,"Traps: 1-3");
    outtextxy(dmo.sx+10,dmo.sy+75+dmo.addy+dmo.addby,"Reveals: 1-5");

    //HARD
    bar(dmo.sx+dmo.addx+dmo.addbx,dmo.sy,dmo.sx+dmo.addx+dmo.addx+dmo.addbx,dmo.sy+dmo.addy);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 4);
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+5,"Hard 15x20");



    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 3);
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+35,"Bombs: 50");
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+55,"Traps: 1-9");
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+75,"Reveals: 1-9");




    //EXPERT
    bar(dmo.sx+dmo.addx+dmo.addbx,dmo.sy+dmo.addy+dmo.addby,dmo.sx+dmo.addx+dmo.addx+dmo.addbx,dmo.sy+dmo.addy+dmo.addy+dmo.addby);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 4);
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+5+dmo.addy+dmo.addby,"Expert 20x30");



    setcolor(WHITE);
    settextstyle(BOLD_FONT,   HORIZ_DIR, 3);
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+35+dmo.addy+dmo.addby,"Bombs: 99");
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+55+dmo.addy+dmo.addby,"Traps: 1-9");
    outtextxy(dmo.sx+10+dmo.addx+dmo.addbx,dmo.sy+75+dmo.addy+dmo.addby,"Reveals: 1-9");




}

void DrawBlock_Fill(int l,int c,bool IsUntouched){

    if(IsUntouched==true){
        setcolor(LIGHTGRAY);
        rectangle(l*40,c*40,(l+1)*40,(c+1)*40);
        //setcolor(WHITE);
        setbkcolor(WHITE);

        if(GameOver==false)
            setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
        else
            setfillstyle(SOLID_FILL,RED);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);

        //for(i=1;i<2;i++)
        //rectangle(l*40+i,c*40+i,(l+1)*40-i,(c+1)*40-i);
    }else{
        setfillstyle(SOLID_FILL, WHITE);
        bar(l*40+1,c*40+1,(l+1)*40-1,(c+1)*40-1);
    }
}
void DrawBlock_Number(int l,int c,int Number){
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
void DrawBlock_Marked(int l,int c,int MarkedType){
    if(mat2[c+1][l+1]==9){
        if(MarkedType==0){
            setcolor(RED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            circle(l*40+20,c*40+20,10);
            floodfill(l*40+21,c*40+21,RED);
            mat3[c+1][l+1]=1;
        }else
            if(MarkedType==1){
                setcolor(CYAN);
                setfillstyle(SOLID_FILL, LIGHTCYAN);
                circle(l*40+20,c*40+20,10);
                floodfill(l*40+21,c*40+21,CYAN);
                mat3[c+1][l+1]=2;
            }else
                if(MarkedType==2){
                    DrawBlock_Fill(l,c,true);
                    mat3[c+1][l+1]=0;
                }
    }
}
void DrawBlock_Reveal_Mines(int l,int c,bool Undo){
    if(Undo==true){
        //setcolor(LIGHTGRAY);
        //rectangle(l*40,c*40,(l+1)*40,(c+1)*40);
        setbkcolor(WHITE);
        if(GameOver==false)
            setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);

    }else{
        setfillstyle(INTERLEAVE_FILL, LIGHTRED);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);
    }
}
//DESCOPERA TEMPORAR BLOCK-ul CARE DESCOPERA MOMENTAN
void DrawBlock_Reaveal_RevealBlock(int l,int c,bool Undo){
    if(Undo==true){
        //setcolor(LIGHTGRAY);
        //rectangle(l*40,c*40,(l+1)*40,(c+1)*40);
        setbkcolor(WHITE);
        if(GameOver==false)
            setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);

    }else{

        setfillstyle(INTERLEAVE_FILL, LIGHTBLUE);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);
    }
}
//DESCOPERA TEMPORAR BLOCK-ul CARE ACOPERA LA LOC
void DrawBlock_Reaveal_CoverBlock(int l,int c,bool Undo){
    if(Undo==true){
        //setcolor(LIGHTGRAY);
        //rectangle(l*40,c*40,(l+1)*40,(c+1)*40);
        setbkcolor(WHITE);
        if(GameOver==false)
            setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);

    }else{

        setfillstyle(INTERLEAVE_FILL, GREEN);
        bar(l*40+2,c*40+2,(l+1)*40-2,(c+1)*40-2);
    }
}
void EvidentiereBlockuriLaFinal(){
    int i,j;
    for(i=1;i<=NoL;i++)
        for(j=1;j<=NoC;j++)
            if(mat2[i][j]==9){
                if(mat1[i][j]==1)
                    DrawBlock_Fill(j-1,i-1,true);
                if(mat1[i][j]==2){
                    setfillstyle(SOLID_FILL, BLUE);
                    bar((j-1)*40+2,(i-1)*40+2,((j-1)+1)*40-2,((i-1)+1)*40-2);
                }
                if(mat1[i][j]==3){
                    setfillstyle(SOLID_FILL, GREEN);
                    bar((j-1)*40+2,(i-1)*40+2,((j-1)+1)*40-2,((i-1)+1)*40-2);
                }
            }

}
void CoverBlocks(int x,int y){
    int i,j;
        for(i=x-3;i<=x+3;i++)
            for(j=y-3;j<=y+3;j++){
                DrawBlock_Fill(i,j,true);
                mat2[j+1][i+1]=9;
                mat3[j+1][i+1]=0;
            }
}
void RevealTemporarely(int x,int y,bool Execute){
    int i,j;
    if(Execute==false)
        return ;
    //DrawBlock_Fill(x,y,false);
    for(i=x-3;i<=x+3;i++)
        for(j=y-3;j<=y+3;j++)
            if(mat1[j+1][i+1]==1)
                DrawBlock_Reveal_Mines(i,j,false);
            else
                if(mat1[j+1][i+1]==2)
                    DrawBlock_Reaveal_RevealBlock(i,j,false);
                else
                    if(mat1[j+1][i+1]==3)
                        DrawBlock_Reaveal_CoverBlock(i,j,false);
        delay(500);
        for(i=x-3;i<=x+3;i++)
            for(j=y-3;j<=y+3;j++)
                if(mat1[j+1][i+1]==1){
                    DrawBlock_Reveal_Mines(i,j,true);
                    if(mat3[j+1][i+1]>0)
                        DrawBlock_Marked(i,j,mat3[j+1][i+1]-1);
                }else
                    if(mat1[j+1][i+1]==2){
                        DrawBlock_Reaveal_RevealBlock(i,j,true);
                        if(mat3[j+1][i+1]>0)
                            DrawBlock_Marked(i,j,mat3[j+1][i+1]-1);
                    }else
                        if(mat1[j+1][i+1]==3){
                            DrawBlock_Reaveal_CoverBlock(i,j,true);
                            if(mat3[j+1][i+1]>0)
                                DrawBlock_Marked(i,j,mat3[j+1][i+1]-1);
                        }

}
void afisare(){
    /*int i,j;
    for(i=1;i<=NoL;i++){
        for(j=1;j<=NoC;j++)
            cout<<mat1[i][j]<<" ";
        cout<<"    ";
        for(j=1;j<=NoC;j++)
            cout<<mat2[i][j]<<" ";
        cout<<"    ";
        for(j=1;j<=NoC;j++)
            cout<<mat3[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/

}
