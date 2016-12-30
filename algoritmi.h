#ifndef ALGORITMI_H_INCLUDED
#define ALGORITMI_H_INCLUDED

void InitBombe(int l,int c); //FOLOSESTE CA PARAMETRU: "NoBo"
void InitTabela(); //TABELA PE CARE O VEDE JUCATORUL
void Discover(int x,int y); //
void DiscoverExtended(int l,int c,int val);
bool TestSfarsitJoc();
void InitTraps(int l,int c);
void InitPoweUps(int l,int c);


#endif // ALGORITMI_H_INCLUDED
