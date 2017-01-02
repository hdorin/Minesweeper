#include<iostream>
#include<conio.h>
#include <windows.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>

#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif





#include"globale.h"
#include"definire-globale.h"
#include"algoritmi.h"
#include"interfata.h"
#include"miscare.h"

using namespace std;

int main(){

    while(true){
        //Menu=true;
        NoC=15;
        NoL=11;
        IsFirstMove=true;
        GameOver=false;
        WaitOneMore=false;
        LButtonIsPressed=RButtonIsPressed=false;

        initwindow(NoC*40+1,NoL*40+1,"Minesweeper");
        //InitTabela();

        DisplayMenu_Title();
        DisplayMenu_Options();
        InitMenuControl();

        Menu=false;
        closegraph();

        DifficultySelected();

        initwindow(NoC*40+1,NoL*40+1,"Minesweeper");
        InitTabela();
        afisare();
        InitConsole();

        delay(500);
        DisplayTable();
        InitMouseControl();

        while(GameOver==false)
            Sleep(5);
        if(Victory==false){
            cout<<"AI PIERDUT!";
            EvidentiereBlockuriLaFinal();
        }else
            cout<<"AI CASTIGAT!";
        while(LButtonIsPressed==false||RButtonIsPressed==false)
            Sleep(5);
        Menu=true;
        delay(10);
        closegraph();
        //delay(1000);

    }


return 0;}
