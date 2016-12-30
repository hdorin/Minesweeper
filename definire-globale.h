#ifndef DEFINIRE-GLOBALE_H_INCLUDED
#define DEFINIRE-GLOBALE_H_INCLUDED

bool IsFirstMove;//PT A PREVENI SITUATIILE DE GASIT BOMBA DIN PRIMA
bool GameOver;
bool Victory;
//SE INCLUDE DOAR IN main.cpp

short mat1[100][100];//ce se foloseste pentru joc
int NoL,NoC;//NoL - number of  lines   NoC - nunber of columns
int NoBo;//NoBo - number of bombe
int NoPU,NoT;//NoPU - number of power-ups   NoT - number of traps

short mat2[100][100];//ce vede jucatorul

int mat3[100][100];//CASUTE MARCATE CU STEGULETE

//DIMENSIUNILE FERESTREI (CONSOLA)
int CmdWidth;
int CmdHeight;


bool RButtonIsPressed;
bool LButtonIsPressed;

#endif // DEFINIRE-GLOBALE_H_INCLUDED
