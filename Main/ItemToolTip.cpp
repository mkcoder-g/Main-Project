#include "stdafx.h"
#include "ItemToolTip.h"
#include "CustomTooltip.h"
#include "PeriodicItem.h"
#include "Offset.h"
#include "Util.h"

char TipTextList[40][100];
int TipTextColor[40];
int TipTextBold[40];
DWORD lpItem = 0;
WORD ItemIndex = -1;

void InitItemToolTip() // OK
{
	MemorySet(0x0049A3B8,0x90,0x23); // Fix Ancient 1

	MemorySet(0x0049A42C,0x90,0x23); // Fix Ancient 2

	SetCompleteHook(0xE8,0x0065D46C,&RenderItem3D);

	SetCompleteHook(0xE8,0x00602C03,&RenderItemInfo);

	SetCompleteHook(0xE8,0x00602D14,&RenderItemInfo);

	SetCompleteHook(0xE8,0x005B7BF0,&RenderTipTextList);
}

void RenderItem3D(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp) // OK
{
	if(AskYesOrNo == 1 && ErrorMessage == 152)
	{
		Type = ItemIndex;
		SetWord(0x07641800,ItemIndex);
	}

	((void(*)(float,float,float,float,int,int,int,int,bool))0x005E8790)(sx,sy,Width,Height,Type,Level,Option1,ExtOption,PickUp);
}

void RenderItemInfo(int sx,int sy,DWORD ip,bool sell) // OK
{
	if(*(WORD*)ip == -1)
	{
		return;
	}

	if(!(AskYesOrNo == 1 && ErrorMessage == 152))
	{
		ItemIndex = *(WORD*)ip;
	}

	lpItem = ip;

	((void(*)(int,int,DWORD,bool))0x005B2070)(sx,sy,ip,sell);
}

void RenderTipTextList(int x,int y,int count,int tab,int sort,int point) // OK
{
	if(*(WORD*)lpItem == -1)
	{
		return;
	}

	RenderPeriodicTipText();

	memcpy(TipTextList,TextList(0),sizeof(TipTextList));
	memcpy(TipTextColor,TextListColor,sizeof(TipTextColor));
	memcpy(TipTextBold,TextBold,sizeof(TipTextBold));

	int m_ItemIndex = *(WORD*)lpItem;

	int m_ItemLevel = (*(DWORD*)(lpItem + 2) >> 3) & 15;

	for(int n = 0; n < MAX_CUSTOM_TOOLTIP; n++)
	{
		CUSTOM_TOOLTIP_INFO ToolTip = gCustomTooltip.m_CustomTooltipInfo[n];

		if(ToolTip.Index != -1 && ToolTip.ItemIndex == m_ItemIndex)
		{
			if(ToolTip.ItemLevel == -1 || ToolTip.ItemLevel == m_ItemLevel)
			{
				AddTipText(ToolTip.Text,ToolTip.FontColor,ToolTip.FontBold,ToolTip.Position);
			}
		}
	}

	memcpy(TextList(0),TipTextList,sizeof(TipTextList));
	memcpy(TextListColor,TipTextColor,sizeof(TipTextColor));
	memcpy(TextBold,TipTextBold,sizeof(TipTextBold));

	((void(*)(int,int,int,int,int,int))0x005ACE20)(x,y,TextNum,tab,sort,point);
}

void AddTipText(char* text,int color,int bold) // OK
{
	if(TextNum >= 40)
	{
		return;
	}
	
	wsprintf(TextList(TextNum),text);
	TextListColor[TextNum] = color;
	TextBold[TextNum] = bold;
	
	TextNum += 1;
}

void AddTipText(char* text,int color,int bold,int slot) // OK
{
	if(TextNum >= 40)
	{
		return;
	}

	if(slot >= 0 && slot <= TextNum) 
	{
		for(int n = TextNum-1; n >= slot; n--) 
		{
			strncpy_s(TipTextList[n+1],TipTextList[n],100);
			TipTextColor[n+1] = TipTextColor[n];
			TipTextBold[n+1] = TipTextBold[n];
		}

		strncpy_s(TipTextList[slot],text,100);
		TipTextColor[slot] = color;
		TipTextBold[slot] = bold;
	}
	else
	{
		strncpy_s(TipTextList[TextNum],text,100);
		TipTextColor[TextNum] = color;
		TipTextBold[TextNum] = bold;
	}

	TextNum += 1;
}