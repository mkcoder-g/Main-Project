#pragma once

#define TextNum *(int*)(0x07672F38)
#define TextListColor (&*(int*)0x07641DD4)
#define TextBold (&*(int*)0x07670800)
#define TextList(x) (char*)(0x07640C48+(100*x))

void InitItemToolTip();
void RenderItem3D(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp);
void RenderItemInfo(int sx,int sy,DWORD ip,bool sell);
void RenderTipTextList(int x,int y,int count,int tab,int sort,int point);
void AddTipText(char* text,int color,int bold);
void AddTipText(char* text,int color,int bold,int slot);