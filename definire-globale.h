#ifndef DEFINIRE_GLOBALE_H_INCLUDED
#define DEFINIRE_GLOBALE_H_INCLUDED
//SE INCLUDE DOAR IN main.cpp

bool IsFirstMove;//PT A PREVENI SITUATIILE DE GASIT BOMBA DIN PRIMA
bool GameOver;
bool Victory;

short mat1[100][100];//ce se foloseste pentru joc
int NoL,NoC;//NoL - number of  lines   NoC - nunber of columns
int NoBo;//NoBo - number of bombe
int NoPU,NoT;//NoPU - number of power-ups   NoT - number of traps

bool WaitOneMore;//BUG: Cand fac combo si pierd, imediat se duce la meniu
bool Menu;//1 - Meniu principal  0-jocul e in desfasurare
short Difficulty;// 1-4

short mat2[100][100];//ce vede jucatorul
int mat3[100][100];//CASUTE MARCATE CU STEGULETE


bool RButtonIsPressed;
bool LButtonIsPressed;


#endif // DEFINIRE-GLOBALE_H_INCLUDED
