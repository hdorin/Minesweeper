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
        if(ismouseclick(WM_RBUTTONDOWN)){
                getmouseclick(WM_RBUTTONDOWN, x, y);
                RButtonIsPressed=true;

                cout << "The right mouse was clicked at: ";
                cout << "x=" << y/40;
                cout << " y=" << x/40 << endl;

            //DrawBlock_Fill(x/40,y/40,false);
            DrawBlock_Marked(x/40,y/40);

        }
                if(ismouseclick(WM_RBUTTONUP)){
                    getmouseclick(WM_RBUTTONUP, x, y);
                    RButtonIsPressed=false;
                    if(LButtonIsPressed==true)
                        if(mat2[y/40+1][x/40+1]>0&&mat2[y/40+1][x/40+1]<9){
                            cout<<"\nDETECTED\n";
                            DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);
                        }
                    Victory=TestSfarsitJoc();
                    if(GameOver==true)
                        return ;
                    cout << "The right mouse was released at: ";
                    cout << "x=" << x/40;
                    cout << " y=" << y/40 << endl;
                }
    }

}
void LButton(){
    int x, y;
    int auxx=1;
    LButtonIsPressed=false;
    while(true){
        if(ismouseclick(WM_LBUTTONDOWN)){
                getmouseclick(WM_LBUTTONDOWN, x, y);
                LButtonIsPressed=true;

                cout << "The left mouse was clicked at: ";
                cout << "x=" << x/40;
                cout << " y=" << y/40 << endl;

                //CAND VREAU SA APAS CASUTE
                if(mat3[y/40+1][x/40+1]==0)
                    Discover(y/40+1,x/40+1);
                Victory=TestSfarsitJoc();
                if(GameOver==true)
                    return ;

                afisare();


        }
                if(ismouseclick(WM_LBUTTONUP)){
                        getmouseclick(WM_LBUTTONUP, x,y);
                        LButtonIsPressed=false;
                        if(RButtonIsPressed==true)
                            if(mat2[y/40+1][x/40+1]>0&&mat2[y/40+1][x/40+1]<9){
                                cout<<"\nDETECTED\n";
                                DiscoverExtended(y/40+1,x/40+1,mat2[y/40+1][x/40+1]);

                                Victory=TestSfarsitJoc();
                                if(GameOver==true)
                                    return ;
                            }


                        cout << "The left mouse was released at: ";
                        cout << "x=" << x/40;
                        cout << " y=" << y/40 << endl;
                    }
    }

}
void InitMouseControl(){

    thread (RButton).detach();
    thread (LButton).detach();
}

