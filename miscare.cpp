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
        delay(1);
        if(ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN, x, y);

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
                    cout<<"\nDETECTED\n";
                    DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);

                    Victory=TestSfarsitJoc();

                }
        }
        if(GameOver==true)
            return ;
    }
}
void LButton(){
    int x, y;
    int auxx=1;
    LButtonIsPressed=false;
    while(true){
            delay(1);
            //cout<<"aaaaaaaa";
        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
            LButtonIsPressed=true;

        }

        if(ismouseclick(WM_LBUTTONUP)){
            getmouseclick(WM_LBUTTONUP, x,y);
            LButtonIsPressed=false;

            //MISCAREA CU CLICK DREAPTA + STANGA
                if(RButtonIsPressed==true){
                    if(mat2[y/40+1][x/40+1]>0&&mat2[y/40+1][x/40+1]<9){
                        cout<<"\nDETECTED-123\n";
                        DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);

                        Victory=TestSfarsitJoc();
                    }
                }else{
                    cout<<"\nNU TREBUIE-123\n";
                    //CAND VREAU SA APAS CASUTE
                    if(mat3[y/40+1][x/40+1]==0){
                    Discover(y/40+1,x/40+1);
                    Victory=TestSfarsitJoc();
                }
                afisare();
                }
        }
        if(GameOver==true)
            return ;

    }
}
void Mwheel(){
    int x,y;
    while(true){
        delay(1);
        if(ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN, x, y);


            //CoverBlocks(x/40,y/40);
            RevealTemporarely(x/40,y/40,true);



        }
    }
}
void InitMouseControl(){

    thread (RButton).detach();
    thread (LButton).detach();
    //thread (Mwheel).detach();
}

