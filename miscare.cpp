#include<iostream>
//#include<conio.h>
#include<thread>
#include<graphics.h>

#include"globale.h"
#include"interfata.h"
#include"miscare.h"
#include"algoritmi.h"

using namespace std;

void RButton(){
    int x, y;
    RButtonIsPressed=false;
    while(true){
        if(Menu==true)
            return ;
        delay(1);
        if(ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN, x, y);
            if(GameOver==false)
                RButtonIsPressed=true;

            //CAND VREAU SA MARCHEZ CASUTE
            if(LButtonIsPressed==false)
                    DrawBlock_Marked(x/40,y/40,mat3[y/40+1][x/40+1]);
        }
        if(ismouseclick(WM_RBUTTONUP)){
            getmouseclick(WM_RBUTTONUP, x, y);

            RButtonIsPressed=false;

            //MISCAREA CU CLICK DREAPTA + STANGA
            if(LButtonIsPressed==true)
                if(mat2[y/40+1][x/40+1]>0&&mat2[y/40+1][x/40+1]<9){
                    DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);

                    Victory=TestSfarsitJoc();

                    if(GameOver==true)
                        WaitOneMore=true;
                }
        }

    }
}
void LButton(){
    int x, y;
    LButtonIsPressed=false;
    while(true){
        if(Menu==true)
            return ;
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if(GameOver==false)
                LButtonIsPressed=true;

        }
        if(ismouseclick(WM_LBUTTONUP)){
            getmouseclick(WM_LBUTTONUP, x,y);
            LButtonIsPressed=false;
            if(WaitOneMore==true)
                WaitOneMore=false;
            else
                if(GameOver==true){
                    LButtonIsPressed=RButtonIsPressed=true;
                    return ;
                }

            //MISCAREA CU CLICK DREAPTA + STANGA
                if(RButtonIsPressed==true){
                    if(mat2[y/40+1][x/40+1]>0&&mat2[y/40+1][x/40+1]<9){
                        DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);

                        Victory=TestSfarsitJoc();
                    }
                }else//CAND VREAU SA APAS CASUTE
                    if(mat3[y/40+1][x/40+1]==0){
                        Discover(y/40+1,x/40+1);
                        Victory=TestSfarsitJoc();
                    }
        }

    }
}
void InitMouseControl(){
    thread (RButton).detach();
    thread (LButton).detach();
}

void MenuSelect(){
    int x,y;
    dmost dmo;
    while(Menu==true){
        delay(1);
        if(ismouseclick(WM_LBUTTONUP)){
            getmouseclick(WM_LBUTTONUP, x,y);
                    if(x>=dmo.sx&&y>=dmo.sy)
                        if(x<=dmo.sx+dmo.addx&&y<=dmo.sy+dmo.addy){
                            Difficulty=1;
                            Menu=false;
                        }
                    if(x>=dmo.sx&&y>=dmo.sy+dmo.addy+dmo.addby)
                        if(x<=dmo.sx+dmo.addx&&y<=dmo.sy+dmo.addy+dmo.addy+dmo.addby){
                            Difficulty=2;
                            Menu=false;
                        }
                    if(x>=dmo.sx+dmo.addx+dmo.addbx&&y>=dmo.sy)
                        if(x<=dmo.sx+dmo.addx+dmo.addx+dmo.addbx&&y<=dmo.sy+dmo.addy){
                            Difficulty=3;
                            Menu=false;
                        }
                    if(x>=dmo.sx+dmo.addx+dmo.addbx&&y>=dmo.sy+dmo.addy+dmo.addby)
                        if(x<=dmo.sx+dmo.addx+dmo.addx+dmo.addbx&&y<=dmo.sy+dmo.addy+dmo.addy+dmo.addby){
                            Difficulty=4;
                            Menu=false;
                        }
                }
        if(ismouseclick(WM_RBUTTONUP))
            getmouseclick(WM_RBUTTONUP, x,y);
    }
}
void InitMenuControl(){
    Menu=true;
    thread t1 (MenuSelect);
    t1.join();
}
