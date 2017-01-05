#ifndef INTERFATA_H_INCLUDED
#define INTERFATA_H_INCLUDED

void afisare();
void DisplayMenu_Title();
void DisplayMenu_Options();
void DisplayTable();
void DrawBlock_Fill(int l,int c,bool IsUntouched);
void DrawBlock_Number(int l,int c,int Number);
void DrawBlock_Marked(int l,int c,int MarkedType);
void EvidentiereBlockuriLaFinal();
void CoverBlocks(int x,int y);
void RevealTemporarely(int x,int y,bool Execute);
void CreateGraphicsWindow();
void DestroyGraphicsWindow();
void DisplayVictoryMessage();

//void DrawBlock_Reveal_Mines(int l,int c,bool Undo);
//void DrawBlock_Reaveal_RevealBlock(int l,int c,bool Undo);
//void DrawBlock_Reaveal_CoverBlock(int l,int c,bool Undo);


#endif // INTERFATA_H_INCLUDED
