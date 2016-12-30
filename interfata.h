#ifndef INTERFATA_H_INCLUDED
#define INTERFATA_H_INCLUDED

void afisare();
void InitConsole();
void CreateTable();
void DrawBlock_Fill(int l,int c,bool IsUntouched);
void DrawBlock_Number(int l,int c,int Number);
void DrawBlock_Marked(int l,int c,bool IsMarked);
void EvidentiereBombe();
void CoverBlocks(int x,int y);
void RevealMinesTemporarely(int x,int y,bool Execute);
void DrawBlock_RevealMines(int l,int c,bool Undo);


#endif // INTERFATA_H_INCLUDED
