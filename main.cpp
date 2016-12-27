#include<iostream>


#include"globale.h"
#include"definire-globale.h"
#include"algoritmi.h"
#include"interfata.h"

using namespace std;



int main(){



//DIMENSIUNILE FERESTREI (CONSOLA)
CmdWidth=80;
CmdHeight=35;
InitConsole();

NoC=10;
NoL=20;
NoBo=40;


InitBombe();//Init bombe dupa ce jucatorul face prima miscare
InitTabela();
afisare();
int l,c;
cout<<endl<<"l c=";
cin>>l>>c;
Discover(l,c);
cout<<endl;
afisare();


return 0;}
