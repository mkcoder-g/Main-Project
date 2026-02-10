#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"

void InitMap()  // OK
{
	SetByte(0x00639A36,0xEB); // Fix Check .map files

	SetByte(0x00639A3C,0xEB); // Fix Check .map files

	SetByte(0x00639C29,0xEB); // Fix Check .att files

	SetByte(0x00639C2F,0xEB); // Fix Check .att files

	SetByte(0x00639CCC,0xEB); // Fix Check .obj files

	SetByte(0x00639CD2,0xEB); // Fix Check .obj files

	SetByte(0x00639A35,0x69); // Increase terrain

	SetByte(0x00639C28,0x69); // Increase terrain

	SetByte(0x00639CCB,0x69); // Increase terrain

	SetByte(0x004611FC,0x63); // Show title on Silent

	SetCompleteHook(0xE8,0x005F97B1,&LoadMapName);

	SetCompleteHook(0xE8,0x00675D9F,&LoadMapName);

	SetCompleteHook(0xE8,0x00679035,&LoadMapName);

	SetCompleteHook(0xE8,0x0046125E,&LoadMapTitle);
}

char* LoadMapName(int index) //OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->MapName;
	}

	return ((char*(*)(int))0x005F8F60)(index);
}

bool LoadMapTitle(char* a,GLuint b,GLuint c,GLuint d,bool e,bool f) // OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(*(DWORD*)MAIN_CURRENT_MAP);

	if(lpInfo != 0)
	{
		a = lpInfo->TitlePath;
	}

	return pLoadImageTGA(a,b,c,d,e,f);
}