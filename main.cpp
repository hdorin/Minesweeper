#include<iostream>
#include<conio.h>
//#include<graphics.h> // CONFLICT CU windows.h
#include<stdlib.h>
#include<time.h>


#include"globale.h"
#include"definire-globale.h"
#include"algoritmi.h"
#include"interfata.h"
#include"miscare.h"

using namespace std;

#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif
#include<windows.h>


int main(){
    ShowWindow( GetConsoleWindow(), SW_HIDE );
    while(true){
        //Menu=true;
        NoC=15;
        NoL=11;
        IsFirstMove=true;
        GameOver=false;
        WaitOneMore=false;
        LButtonIsPressed=RButtonIsPressed=false;

        CreateGraphicsWindow();

        DisplayMenu_Title();
        DisplayMenu_Options();
        InitMenuControl();

        Menu=false;
        DestroyGraphicsWindow();

        DifficultySelected();
        //NoBo=1;///STERGE

        CreateGraphicsWindow();
        InitTabela();

        Sleep(200);
        DisplayTable();
        InitMouseControl();

        while(GameOver==false)
            Sleep(5);
        if(Victory==false)
            EvidentiereBlockuriLaFinal();
        else
            DisplayVictoryMessage();
        while(LButtonIsPressed==false||RButtonIsPressed==false)
            Sleep(5);
        Menu=true;
        Sleep(10);
        DestroyGraphicsWindow();
    }
return 0;}
