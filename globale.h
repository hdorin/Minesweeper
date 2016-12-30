#ifndef GLOBALE_H_INCLUDED
#define GLOBALE_H_INCLUDED

extern bool IsFirstMove;//PT A PREVENI SITUATIILE DE GASIT BOMBA DIN PRIMA
extern bool GameOver;
extern bool Victory;

//SE INCLUDE IN FIECARE FISIER CPP
//PENTRU A PUTEA ACCESARE VARIABILELE (DEFINITE DE definire-globale.h)

extern short mat1[100][100];//ce se foloseste pentru joc
extern int NoL,NoC;//NoL - number of  lines   NoC - nunber of columns
extern int NoBo;//NoBo - number of bombe
extern int NoPU,NoT;//NoPU - number of power-ups   NoT - number of traps


extern short mat2[100][100];//ce vede jucatorul

extern int mat3[100][100];//CASUTE MARCATE CU STEGULETE

//DIMENSIUNILE FERESTREI (CONSOLA)
extern int CmdWidth;
extern int CmdHeight;

//

extern bool RButtonIsPressed;
extern bool LButtonIsPressed;

#endif // GLOBALE_H_INCLUDED
