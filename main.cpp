#include<iostream>
#include<conio.h>
#include <windows.h>
#include<graphics.h>

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
    ///REFOLOSIT
    //ShowWindow( GetConsoleWindow(), SW_HIDE );


    NoC=12;
    NoL=12;
    NoBo=20;
    IsFirstMove=true;
    ///REFOLOSIT
    //CmdWidth=10;
    //CmdHeight=10;

    //Init bombe dupa ce jucatorul face prima miscare
    InitTabela();
    afisare();

    InitConsole();

    delay(500);
    CreateTable();
    InitMouseControl();

    getch();
return 0;



/*

//DIMENSIUNILE FERESTREI (CONSOLA)






InitBombe();//Init bombe dupa ce jucatorul face prima miscare
InitTabela();
afisare();
int l,c;
cout<<endl<<"l c=";
cin>>l>>c;
Discover(l,c);
cout<<endl;
afisare();
*/

return 0;}
