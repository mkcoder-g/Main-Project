#include "stdafx.h"
#include "Interface.h"
#include "Offset.h"
#include "Util.h"
#include "Texture.h"
#include "PrintPlayer.h"
#include "CustomMap.h"
#include "CustomDailyRewardMain.h" // <-- ESTA LINHA É A QUE REMOVE O SEU ERRO!

cInterface gInterface;

void cInterface::Init()
{
	SetCompleteHook(0xE8, 0x0063E959, &this->LoadImages);
}

void cInterface::DrawSelectServer(HDC Hdc)
{
	((void(__cdecl*)(HDC Hdc)) 0x0065F860)(Hdc);
}

void cInterface::DrawSelectCharacter(HDC Hdc)
{
	((void(__cdecl*)(HDC Hdc)) 0x0065EE70)(Hdc);
}

void cInterface::ChangeWindowText()
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(*(DWORD*)MAIN_CURRENT_MAP);

	static char textreset[256];
	sprintf_s(textreset, sizeof(textreset), "Resets: %d || Map: %s", ViewReset, lpInfo->MapName);
	SetWindowText(*(HWND*)0x07AFEE84, textreset);
}

void cInterface::Work()
{
	((void(__cdecl*)()) 0x004D7566)();

	gInterface.ChangeWindowText();

	// =====================================
	// ESCUTADOR DE CLIQUES DO BÓNUS DIÁRIO
	// =====================================
	CheckDailyRewardClick();
	// =====================================
}

void cInterface::LoadImages()
{
	((void(*)()) 0x0063A540)();

	TextureCurrent = 6000;

	gInterface.LoadImagesType(1, "Custom\\Interface\\newui_option_check.tga", 151);
}

void cInterface::LoadImagesType(int Type, char* Folder, int ImageID)
{
	switch (Type)
	{
	case 0:
	{
		((void(cdecl*)(char* Folder, int ModelID, int a3, int a4, int a5, int a6)) 0x006F9D4F)(Folder, ImageID, 0x2600, 0x2900, 0, 1);
	}
	break;
	case 1:
	{
		((void(cdecl*)(char* Folder, int ModelID, int a3, int a4, int a5, int a6)) 0x006FA244)(Folder, ImageID, 0x2600, 0x2900, 0, 1);
	}
	break;
	}
}