#ifndef GLOBALE_H_INCLUDED
#define GLOBALE_H_INCLUDED

//SE INCLUDE IN FIECARE FISIER CPP
//PENTRU A PUTEA ACCESARE VARIABILELE (DEFINITE DE definire-globale.h)

extern bool mat1[100][100];//ce se foloseste pentru joc
extern int NoL,NoC;//NoL - number of  lines   NoC - nunber of columns
extern int NoBo;//NoBo - number of bombe

extern short mat2[100][100];//ce vede jucatorul

//DIMENSIUNILE FERESTREI (CONSOLA)
extern int CmdWidth;
extern int CmdHeight;

#endif // GLOBALE_H_INCLUDED