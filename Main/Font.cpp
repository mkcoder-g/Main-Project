#include "stdafx.h"
#include "Font.h"
#include "Offset.h"
#include "Util.h"

int FontSize;

DWORD FontCharSet;

char FontName[100];

int ReadFontFile(char* path) // OK
{	
	FontSize = GetPrivateProfileInt("FontInfo","FontSize",13,path);
	
	FontCharSet = GetPrivateProfileInt("FontInfo","FontCharSet",1,path);
	
	GetPrivateProfileString("FontInfo","FontName","Tahoma",FontName,sizeof(FontName),path);

	return GetPrivateProfileInt("FontInfo","ChangeFontSwitch",0,path);
}

void InitFont() // OK
{
	if(ReadFontFile(".\\Config.ini") != 0)
	{
		SetCompleteHook(0xE8,0x0064964D,&FontNormal);

		SetCompleteHook(0xE8,0x006496B4,&FontBool);
		
		SetCompleteHook(0xE8,0x0064971C,&FontBig);
		
		SetCompleteHook(0xE8,0x00649786,&FontFixed);

		SetByte(0x00649652,0x90);
		
		SetByte(0x006496B9,0x90);
		
		SetByte(0x00649721,0x90);
		
		SetByte(0x0064978B,0x90);
	}
}

void ReloadFont() // OK
{
	DWORD offsetFunc = ((DWORD(*)())0x00463272)();
	
	offsetFunc = offsetFunc + 0x45C8;

	*(HFONT*)(offsetFunc + 0x183) = FontNormal();

	pFontNormal = FontNormal();

	pFontBold = FontBool();

	pFontBig = FontBig();

	pFontFixed = FontFixed();

	*(DWORD*)MAIN_FONT_SIZE = FontSize;

	((void(*)())0x0063B6C2)();
}

HFONT FontNormal() // OK
{
	return CreateFont(FontSize,0,0,0,FW_NORMAL,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontBool() // OK
{
	return CreateFont(FontSize,0,0,0,FW_BOLD,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontBig() // OK
{
	return CreateFont(FontSize*2,0,0,0,FW_BOLD,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontFixed() // OK
{
	return CreateFont(FontSize,0,0,0,FW_NORMAL,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}