#include "stdafx.h"
#include "OptionsMenu.h"
#include "CustomMessage.h"
#include "Camera.h"
#include "HealthBar.h"
#include "Font.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

COptionsMenu gOptionsMenu;

float CalculateCenterPosX(float size)
{
	const float screenCenterX = 320.0f;
	return (screenCenterX - (size / 2.0f));
}

float CalculateCenterPosY(float size)
{
	const float screenCenterY = 216.0f;
	return (screenCenterY - (size / 2.0f));
}

void RenderText(HFONT font,int x,int y,char* text,bool centered = false)
{
	SIZE sz;

	GetTextExtentPoint(pGetFontDC(pTextThis()), text, strlen(text), &sz);

	int px = (x - (640 * sz.cx / *(DWORD*)MAIN_RESOLUTION_X >> 1));

	int py = (y - (480 * sz.cy / *(DWORD*)MAIN_RESOLUTION_Y >> 1));

	EnableAlphaTest(true);

	pSetTextFont(pTextThis(),font);
	pSetBGTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(),255,255,255,255);
	pDrawText(pTextThis(),((centered)?px:x),py,text,0,0,0,0);
	pSetTextFont(pTextThis(),pFontNormal);
}

void PushButton()
{
	MouseLButtonPush = 0;

	MouseUpdateTime = 0;
	MouseUpdateTimeMax = 6;

	pPlayBuffer(25,0,0);
}

COptionsMenu::COptionsMenu()
	: DeleteFloor(0),
	  DeleteMapObjects(0),
	  DeleteObjects(0),
	  DeleteShadows(0),
	  DeleteEffects(0),
	  DeleteSkills(0),
	  DeleteAttackBar(0),
	  DeletePvp(0),
	  MainWidth(340.0f),
	  MainHeight(270.0f),
	  MainPosX(CalculateCenterPosX(MainWidth)),
	  MainPosY(CalculateCenterPosY(MainHeight)),
	  SectionWidth(100),
	  SectionPosY(MainPosY + 30.0f),
	  AntilagPosX(160.0f),
	  GeneralPosX(265.0f),
	  ResolutionPosX(375.0f),
	  FontPosX(455.0f)
{
	for (int i = 0; i < MAX_FONTS; i++)
	{
		Resolutions[i] = 0;
		Fonts[i] = (i * 2) + 9;
	}

	const char* resolutionsText[MAX_RESOLUTIONS] = {
		"640x480","800x600","1024x768","1280x1024",
		"1360x768","1440x900","1600x900","1680x1050","1920x1080"
	};

	for (int n = 0; n < MAX_RESOLUTIONS; n++)
	{
		sprintf_s(ResolutionsText[n], "%s", resolutionsText[n]);
	}
}

COptionsMenu::~COptionsMenu()
{

}

void COptionsMenu::Init()
{
	if(gProtect.m_MainInfo.AdvancedOptionMenuSwitch == 0)
	{
		return;
	}

	SetCompleteHook(0xE9,0x006587A6,&DrawOptionsMenuUI);

	SetCompleteHook(0xE9,0x0064EB67,&HandleOptionsMenuControl);
}

__declspec(naked) void COptionsMenu::DrawOptionsMenuUI()
{
	static DWORD originalCodeAddress = 0x0065BEC1;

	_asm
	{
		PushAd
	}

	gOptionsMenu.DrawOptionsMenuMain();
	gOptionsMenu.DrawOptionsMenuRender();
	gOptionsMenu.DrawOptionsMenuGeneral();
	gOptionsMenu.DrawOptionsMenuResolution();
	gOptionsMenu.DrawOptionsMenuFont();
	gOptionsMenu.DrawOptionsMenuClose();

	_asm
	{
		PopAd
		Jmp[originalCodeAddress]
	}
}

__declspec(naked) void COptionsMenu::HandleOptionsMenuControl()
{
	static DWORD originalCodeAddress = 0x0064EED5;

	_asm
	{
		PushAd
	}

	if (gOptionsMenu.IsDeleteFloorEnabled() ||
		gOptionsMenu.IsDeleteMapObjectsEnabled() ||
		gOptionsMenu.IsDeleteObjectsEnabled() ||
		gOptionsMenu.IsDeleteShadowsEnabled() ||
		gOptionsMenu.IsDeleteEffectsEnabled() ||
		gOptionsMenu.IsDeleteSkillsEnabled() ||
		gOptionsMenu.IsMonsterHealthBarEnabled() ||
		gOptionsMenu.IsAutoAttackBarEnabled() ||
		gOptionsMenu.IsPvpAutoEnabled() ||
		gOptionsMenu.IsAutomaticAttackEnabled() ||
		gOptionsMenu.IsSoundWhisperEnabled() ||
		gOptionsMenu.IsVolumeEnabled() ||
		gOptionsMenu.IsSlideHelpEnabled() ||
		gOptionsMenu.IsGlowEnabled() ||
		gOptionsMenu.IsResolutionsEnabled() ||
		gOptionsMenu.IsFontSizeEnabled() ||
		gOptionsMenu.IsCloseEnabled())
	{
		originalCodeAddress = 0x0064EED0;
	}

	_asm
	{
		PopAd
		Jmp[originalCodeAddress]
	}
}

void COptionsMenu::DrawOptionsMenuMain()
{
	EnableAlphaTest(1);
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	pDrawBarForm(this->MainPosX, this->MainPosY, this->MainWidth, this->MainHeight);

	glColor3f(1.0, 1.0, 1.0);
	DisableAlphaBlend();

	EnableAlphaTest(true);

	pSetTextFont(pTextThis(),pFontBold);
	pSetBGTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(),255,0,0,255);
	pDrawText(pTextThis(),320, (int)this->MainPosY + 5, gCustomMessage.GetMessage(6), 0, 0, 8, 0);
	DisableAlphaBlend();
}

void COptionsMenu::DrawOptionsMenuRender()
{
	RenderText(pFontBold,(int)this->AntilagPosX, (int)this->SectionPosY,gCustomMessage.GetMessage(7));

	DrawFloorDeletionOption();
	DrawMapObjectDeletionOption();
	DrawObjectsDeletionOption();
	DrawShadowDeletionOption();
	DrawEffectDeletionOption();
	DrawSkillDeletionOption();
	DrawMonsterHealthBarOption();
	DrawAutoAttackBarOption();
	DrawPvPAutoOption();
}

void COptionsMenu::DrawOptionsMenuGeneral()
{
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(8));

	RenderText(pFontBold,(int)this->GeneralPosX, (int)this->SectionPosY,Text);

	this->DrawAutomaticAttackOption();
	this->DrawSoundWhisperOption();
	this->DrawVolumeOption();
	this->DrawSlideHelpOption();
	this->DrawGlowOption();
}

void COptionsMenu::DrawOptionsMenuResolution()
{
	char resolutionTitle[64] = { 0 };
	sprintf_s(resolutionTitle, gCustomMessage.GetMessage(9));

	RenderText(pFontBold,(int)this->ResolutionPosX, (int)this->SectionPosY, resolutionTitle);

	int optionPosX = (int)this->ResolutionPosX;
	int optionPosY = (int)this->SectionPosY + 20;
	int optionWidth = 67;
	int optionHeight = 19;
	this->Resolutions[*(DWORD*)MAIN_RESOLUTION] = 1;

	for (int i = 0; i < MAX_RESOLUTIONS; i++)
	{
		EnableAlphaTest(true);

		glColor3f(0.2f, 0.2f, 0.2f);
		pDrawBarForm((float)optionPosX, (float)optionPosY, (float)optionWidth, (float)optionHeight);

		if (this->Resolutions[i])
			glColor3f(0.8f, 0.6f, 0.3f);
		else if (pMouseOnZone(optionPosX, optionPosY, optionWidth, optionHeight, 1))
		{
			glColor3f(0.5f, 0.5f, 0.5f);
		}
		else
			glColor3f(0.05f, 0.05f, 0.05f);

		pDrawBarForm((float)optionPosX + 0.75f, (float)optionPosY + 0.75f, (float)optionWidth - 1.5f, (float)optionHeight - 1.5f);

		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_TEXTURE_2D);

		EnableAlphaTest(false);

		RenderText(pFontNormal,optionPosX+(optionWidth/2),optionPosY+(optionHeight/2),this->ResolutionsText[i],true);

		optionPosY += 20;
	}
}

void COptionsMenu::DrawOptionsMenuFont()
{
	char titleText[64] = { 0 };
	sprintf_s(titleText, gCustomMessage.GetMessage(10));

	RenderText(pFontBold,(int)this->FontPosX, (int)this->SectionPosY, titleText);

	int optionPosX = (int)this->FontPosX;
	int optionPosY = (int)this->SectionPosY + 20;
	int optionWidth = 20;
	int optionHeight = 19;

	for (int i = 0; i < MAX_FONTS; i++)
	{
		EnableAlphaTest(true);

		glColor3f(0.2f, 0.2f, 0.2f);
		pDrawBarForm((float)optionPosX, (float)optionPosY, (float)optionWidth, (float)optionHeight);

		if (this->Fonts[i] == FontSize)
			glColor3f(0.8f, 0.6f, 0.3f);
		else if (pMouseOnZone(optionPosX, optionPosY, optionWidth, optionHeight, 1))
		{
			glColor3f(0.5f, 0.5f, 0.5f);
		}
		else
			glColor3f(0.05f, 0.05f, 0.05f);

		pDrawBarForm((float)optionPosX + 0.75f, (float)optionPosY + 0.75f, (float)optionWidth - 1.5f, (float)optionHeight - 1.5f);

		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_TEXTURE_2D);

		EnableAlphaTest(false);

		char optionText[5] = { 0 };

		sprintf_s(optionText, "%d", this->Fonts[i]);

		RenderText(pFontNormal,optionPosX+(optionWidth/2),optionPosY+(optionHeight/2),optionText,true);

		optionPosY += 20;
	}
}

void COptionsMenu::DrawFloorDeletionOption()
{
	int PosY = (int)this->SectionPosY + 20;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(11));

	if (!this->DeleteFloor)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawMapObjectDeletionOption()
{
	int PosY = (int)this->SectionPosY + 40;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(12));

	if (!this->DeleteMapObjects)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawObjectsDeletionOption()
{
	int PosY = (int)this->SectionPosY + 60;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(13));

	if (!this->DeleteObjects)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawShadowDeletionOption()
{
	int PosY = (int)this->SectionPosY + 80;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(14));

	if (!this->DeleteShadows)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawEffectDeletionOption()
{
	int PosY = (int)this->SectionPosY + 100;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(15));

	if (!this->DeleteEffects)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawSkillDeletionOption()
{
	int PosY = (int)this->SectionPosY + 120;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(16));

	if (!this->DeleteSkills)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawMonsterHealthBarOption()
{
	int PosY = (int)this->SectionPosY + 140;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(17));

	if (!MonsterHPBarMode)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawAutoAttackBarOption()
{
	int PosY = (int)this->SectionPosY + 160;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(18));

	if (!this->DeleteAttackBar)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->AntilagPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawPvPAutoOption()
{
	int PosY = (int)this->SectionPosY + 180;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(51));

	if (!this->DeletePvp)
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->AntilagPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal, ((int)this->AntilagPosX + Width + 5), PosY + 5, Text);
}

void COptionsMenu::DrawAutomaticAttackOption()
{
	int PosY = (int)this->SectionPosY + 20;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(19));

	if (*(BYTE*)0x0076EFB0)
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->GeneralPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawSoundWhisperOption()
{
	int PosY = (int)this->SectionPosY + 40;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(20));

	if (*(BYTE*)0x075AE948)
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->GeneralPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawVolumeOption()
{
	int PosY = (int)this->SectionPosY + 80;
	float Height = 10.0f;
	int MAX_VALUE = 9;
	char Text[64] = { 0 };
	sprintf_s(Text, "%s: %d", gCustomMessage.GetMessage(21), *(DWORD*)0x07B02760);

	RenderText(pFontNormal,(int)this->GeneralPosX, PosY + ((int)Height / 2) - 15, Text);

	EnableAlphaTest(1);

	glColor3f(0.2f, 0.2f, 0.2f);
	pDrawBarForm(this->GeneralPosX, (float)PosY, (float)this->SectionWidth, Height);

	glColor3f(0.0f, 0.0f, 0.0f);
	pDrawBarForm(this->GeneralPosX + 1.0f, (float)PosY + 1, (float)this->SectionWidth - 2.0f, Height - 2.0f);

	glColor3f(1.0f, 1.0f, 1.0f);

	float X = this->GeneralPosX + 1.0f;

	for (int i = 0; i < MAX_VALUE; i++)
	{
		if (i >= *(int*)0x07B02760)
			glColor3f(0.0f, 0.0f, 0.0f);
		else
			glColor3f(0.8f, 0.6f, 0.3f);

		pDrawBarForm(X, (float)PosY + 1.0f, (((float)this->SectionWidth - 2.0f) / MAX_VALUE), Height - 2.0f);

		X += (((float)this->SectionWidth - 2.0f) / MAX_VALUE);
	}

	pTextureBlind();
}

void COptionsMenu::DrawSlideHelpOption()
{
	int PosY = (int)this->SectionPosY + 110;
	int Width = 10;
	int Height = 10;
	char Text[64] = { 0 };
	sprintf_s(Text, gCustomMessage.GetMessage(22));

	if (*(BYTE*)0x0076B94C)
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.5f, 1.0f, 0.5f, 1, 1, 0.0);
	else
		pDrawImage(2086, this->GeneralPosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 1.0f, 0.5f, 1, 1, 0.0);

	RenderText(pFontNormal,((int)this->GeneralPosX + Width + 5), PosY + 5,Text);
}

void COptionsMenu::DrawGlowOption()
{
	int PosY = (int)this->SectionPosY + 150;
	float Height = 10.0f;
	int MAX_VALUE = 4;
	char Text[64] = { 0 };
	sprintf_s(Text, "%s: %d", gCustomMessage.GetMessage(23), (2 * *(BYTE*)0x00770388) + 5);

	RenderText(pFontNormal,(int)this->GeneralPosX, PosY + ((int)Height / 2) - 15, Text);

	EnableAlphaTest(1);

	glColor3f(0.2f, 0.2f, 0.2f);
	pDrawBarForm(this->GeneralPosX, (float)PosY, (float)this->SectionWidth, Height);

	glColor3f(0.0f, 0.0f, 0.0f);
	pDrawBarForm(this->GeneralPosX + 1.0f, (float)PosY + 1.0f, (float)this->SectionWidth - 2.0f, Height - 2.0f);

	float X = this->GeneralPosX + 1.0f;

	for (int i = 0; i < MAX_VALUE; i++)
	{
		if (i >= *(BYTE*)0x00770388)
			glColor3f(0.0f, 0.0f, 0.0f);
		else
			glColor3f(0.8f, 0.6f, 0.3f);

		pDrawBarForm(X, (float)PosY + 1.0f, (((float)this->SectionWidth - 2.0f) / MAX_VALUE), Height - 2.0f);

		X += (((float)this->SectionWidth - 2.0f) / MAX_VALUE);
	}

	pTextureBlind();
}

void COptionsMenu::DrawOptionsMenuClose()
{
	int PosX = (int)CalculateCenterPosX(34.0f);
	int PosY = (int)this->MainPosY + (int)this->MainHeight - 30;
	int Width = 34;
	int Height = 19;

	if (pMouseOnZone((int)PosX, (int)PosY, (int)Width, (int)Height, 1))
	{
		if (!MouseLButtonPush)
		{
			pDrawImage(2075, (float)PosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.235f, 0.843f, 0.24f, 1, 1, 0.0);
		}
		else
		{
			pDrawImage(2075, (float)PosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.47f, 0.843f, 0.24f, 1, 1, 0.0);
		}
	}
	else
	{
		pDrawImage(2075, (float)PosX, (float)PosY, (float)Width, (float)Height, 0.0f, 0.0f, 0.843f, 0.24f, 1, 1, 0.0);
	}
}

bool COptionsMenu::IsDeleteFloorEnabled()
{
	int PosY = (int)this->SectionPosY + 20;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if((this->DeleteFloor ^= 1))
		{
			BYTE replace[10] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
			MemoryCpy(0x006617D2, replace, sizeof(replace));
		}
		else
		{
			BYTE replace[10] = { 0x6A, 0x00, 0xE8, 0x55, 0x7B, 0xFA, 0xFF, 0x83, 0xC4, 0x04 };
			MemoryCpy(0x006617D2, replace, sizeof(replace));
		}

		return true;
	}

	return false;
}

bool COptionsMenu::IsDeleteMapObjectsEnabled()
{
	int PosY = (int)this->SectionPosY + 40;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if((this->DeleteMapObjects ^= 1))
			SetByte(0x00614DBA, 0xC3);
		else
			SetByte(0x00614DBA, 0x55);

		return true;
	}

	return false;
}

bool COptionsMenu::IsDeleteObjectsEnabled()
{
	int PosY = (int)this->SectionPosY + 60;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if ((this->DeleteObjects ^= 1))
			SetByte(0x0052143D, 0xC3);
		else
			SetByte(0x0052143D, 0x55);

		return true;
	}

	return false;
}

bool COptionsMenu::IsDeleteShadowsEnabled()
{
	int PosY = (int)this->SectionPosY + 80;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if ((this->DeleteShadows ^= 1))
			SetByte(0x005066FE, 0xC3);
		else
			SetByte(0x005066FE, 0x55);

		return true;
	}

	return false;
}

bool COptionsMenu::IsDeleteEffectsEnabled()
{
	int PosY = (int)this->SectionPosY + 100;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if ((this->DeleteEffects ^= 1))
		{
			SetByte(0x006DA9C1, 0xC3); // pCreateParticle
			SetByte(0x006EE878, 0xC3); // pCreateSprite
		}
		else
		{
			SetByte(0x006DA9C1, 0x55);
			SetByte(0x006EE878, 0x55);
		}

		return true;
	}

	return false;
}

bool COptionsMenu::IsDeleteSkillsEnabled()
{
	int PosY = (int)this->SectionPosY + 120;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		if ((this->DeleteSkills ^= 1))
		{
			SetByte(0x00634724, 0xC3);
			SetByte(0x006C4750, 0xC3);
			SetByte(0x006A7FF6, 0);
		}
		else
		{
			SetByte(0x00634724, 0x55);
			SetByte(0x006C4750, 0x55);
			SetByte(0x006A7FF6, 1);
		}

		return true;
	}

	return false;
}

bool COptionsMenu::IsMonsterHealthBarEnabled()
{
	int PosY = (int)this->SectionPosY + 140;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		MonsterHPBarMode ^= 1;

		return true;
	}

	return false;
}

bool COptionsMenu::IsAutoAttackBarEnabled()
{
	int PosY = (int)this->SectionPosY + 160;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		this->DeleteAttackBar ^= 1;

		return true;
	}

	return false;
}

bool COptionsMenu::IsPvpAutoEnabled()
{
	int PosY = (int)this->SectionPosY + 180;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->AntilagPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		this->DeletePvp ^= 1;

		if (this->DeletePvp)
		{
			SetByte(0x005426C5 + 2, 0); 
			SetByte(0x0054239A + 2, 0); 
			SetByte(0x00542854 + 2, 0); 
		}
		else
		{
			SetByte(0x005426C5 + 2, 0x80);
			SetByte(0x0054239A + 2, 0x80);
			SetByte(0x00542854 + 2, 0x80);
		}
		return true;
	}

	return false;
}

bool COptionsMenu::IsAutomaticAttackEnabled()
{
	int PosY = (int)this->SectionPosY + 20;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->GeneralPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		*(BYTE*)0x0076EFB0 ^= 1;

		return true;
	}

	return false;
}

bool COptionsMenu::IsSoundWhisperEnabled()
{
	int PosY = (int)this->SectionPosY + 40;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->GeneralPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		*(BYTE*)0x075AE948 ^= 1;

		return true;
	}

	return false;
}

bool COptionsMenu::IsVolumeEnabled()
{
	int PosY = (int)this->SectionPosY + 80;
	float Height = 10.0f;
	int MAX_VALUE = 9;
	int newVolumeLevel = 0;
	int cursorInicial = (int)this->GeneralPosX + 1;

	while (pCursorX < cursorInicial || pCursorX > cursorInicial + (int)(((float)this->SectionWidth - 2.0f) / MAX_VALUE) || pCursorY < (int)PosY + 1 || pCursorY >(int)PosY + ((int)Height - 1) || !MouseLButtonPush)
	{
		cursorInicial += (int)(((float)this->SectionWidth - 2.0f) / MAX_VALUE);
		newVolumeLevel++;

		if (cursorInicial >= (int)(this->GeneralPosX + (float)this->SectionWidth))
			return false;
	}

	*(DWORD*)0x07B02760 = newVolumeLevel;

	static const float _1_div_log_2 = 1 / log(2.0f);

	float volumeSound = 0.30102999566398119802f * log(10.0f / newVolumeLevel) * _1_div_log_2;

	volumeSound *= -2000.0f;

	((int(__cdecl*)(int a1)) 0x006A523F)((int)volumeSound);

	return true;
}

bool COptionsMenu::IsSlideHelpEnabled()
{
	int PosY = (int)this->SectionPosY + 110;
	int Width = 10;
	int Height = 10;

	if (pMouseOnZone((int)this->GeneralPosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		*(BYTE*)0x0076B94C ^= 1;

		return true;
	}

	return false;
}

bool COptionsMenu::IsGlowEnabled()
{
	int PosY = (int)this->SectionPosY + 150;
	float Height = 10.0f;
	int MAX_VALUE = 4;
	int glowLevel = 0;
	int cursorInicial = (int)this->GeneralPosX + 1;

	while (pCursorX < cursorInicial || pCursorX > cursorInicial + (int)(((float)this->SectionWidth - 2.0f) / MAX_VALUE) || pCursorY < (int)PosY + 1 || pCursorY >(int)PosY + ((int)Height - 1) || !MouseLButtonPush)
	{
		cursorInicial += (int)(((float)this->SectionWidth - 2.0f) / MAX_VALUE);
		glowLevel++;

		if (cursorInicial >= (int)(this->GeneralPosX + (float)this->SectionWidth))
			return false;
	}

	*(BYTE*)0x00770388 = glowLevel;

	return true;
}

bool COptionsMenu::IsResolutionsEnabled()
{
	int PosX = (int)this->ResolutionPosX;
	int PosY = (int)this->SectionPosY + 20;
	int Width = 67;
	int Height = 19;

	for (int i = 0; i < MAX_RESOLUTIONS; i++)
	{
		if (pMouseOnZone(PosX, PosY, Width, Height, 1) && MouseLButtonPush)
		{
			if (this->Resolutions[i] == 1)
			{
				return true;
			}

			PushButton();

			this->Resolutions[*(DWORD*)MAIN_RESOLUTION] = 0;

			this->Resolutions[i] = 1;

			HKEY key;

			if (RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, KEY_ALL_ACCESS, &key) == ERROR_SUCCESS)
			{
				if (RegSetValueEx(key, "Resolution", 0, REG_DWORD, (const BYTE*)&i, sizeof(i)) == ERROR_SUCCESS)
				{
					((int(*)())0x00647E80)(); //OpenInitFile

					RECT rect;
					rect.left = 0;
					rect.top = 0;
					rect.right = *(DWORD*)MAIN_RESOLUTION_X;
					rect.bottom = *(DWORD*)MAIN_RESOLUTION_Y;
					LONG PosX = ((GetSystemMetrics(SM_CXSCREEN)) / 2) - (*(DWORD*)MAIN_RESOLUTION_X / 2);
					LONG PosY = ((GetSystemMetrics(SM_CYSCREEN)) / 2) - (*(DWORD*)MAIN_RESOLUTION_Y / 2);

					if (!*(BOOL*)0x0077E3D8)
					{
						LONG STYLE = WS_POPUP;
						LONG EXSTYLE = WS_EX_APPWINDOW /*| WS_EX_TOPMOST*/;
						SetWindowLongPtr(*(HWND*)(MAIN_WINDOW), GWL_STYLE, STYLE); // Set the Window Style
						SetWindowLongPtr(*(HWND*)(MAIN_WINDOW), GWL_EXSTYLE, EXSTYLE); // Set the Window Extra Style
						AdjustWindowRect(&rect, STYLE, FALSE); // Adjust the rectangle inside
					}
					else
					{
						LONG STYLE = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_BORDER | WS_CLIPCHILDREN;
						SetWindowLongPtr(*(HWND*)(MAIN_WINDOW), GWL_STYLE, STYLE); // Set the Window Style
						AdjustWindowRect(&rect, STYLE, FALSE); // Adjust the rectangle inside
					}

					SetWindowPos(*(HWND*)(MAIN_WINDOW), NULL, PosX, PosY, rect.right - rect.left, rect.bottom - rect.top,
						SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);

					MoveWindow(*(HWND*)(MAIN_WINDOW), PosX, PosY, rect.right - rect.left, rect.bottom - rect.top, TRUE); // Change the size

					if (!*(BOOL*)0x0077E3D8)
					{
						this->ApplyFullScreenSettings();
					}

					gCamera.SetCurrentValue(); // Fix the 3d camera position

					ReloadFont();

					// Update the CUIMng saved width and height
					DWORD V1 = ((DWORD(*)()) 0x00463272)(); //CUIMng::Instance()
					*(DWORD*)(V1 + 40) = *(DWORD*)MAIN_RESOLUTION_X;
					*(DWORD*)(V1 + 44) = *(DWORD*)MAIN_RESOLUTION_Y;

					// Update the CInput saved width and height
					DWORD V2 = ((DWORD(*)()) 0x0040760B)(); //CInput::Instance()
					*(DWORD*)(V2 + 40) = *(DWORD*)MAIN_RESOLUTION_X;
					*(DWORD*)(V2 + 44) = *(DWORD*)MAIN_RESOLUTION_Y;

					// Update the CGameCensorship saved width and height
					DWORD V3 = ((DWORD(*)()) 0x004A92BD)(); //CGameCensorship::GetInstance()
					((void(__thiscall*)(DWORD This)) 0x004A930A)(V3); //CGameCensorship::Create()

					SetByte(0x004215CB, 0x20); // Skip Window Resize Check

					// Chat and Whisper Input
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE34) + 4), 180, 14);
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE34) + 240), 50, 14);
					// User and Password Input
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE38) + 4), 100, 14);
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE38) + 240), 100, 14);
					// 
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE3C) + 4), 100, 14);
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)(((*(DWORD*)0x07AFEE3C) + 240), 100, 14);
					//
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)((*(DWORD*)0x07AFEE40), 200, 20);
					//
					((void(__thiscall*)(DWORD This, int iWidth, int iHeight)) 0x004215B7)((*(DWORD*)0x07AFEE44), 200, 20);

					SetByte(0x004215CB, 0x05); // Restore Window Resize Check
				}
				else
				{
					this->Resolutions[*(DWORD*)MAIN_RESOLUTION] = 1;

					this->Resolutions[i] = 0;
				}

				RegCloseKey(key);
			}

			return true;
		}

		PosY += 20;
	}

	return false;
}

bool COptionsMenu::IsFontSizeEnabled()
{
	int PosX = (int)this->FontPosX;
	int PosY = (int)this->SectionPosY + 20;
	int Width = 20;
	int Height = 19;

	for (int i = 0; i < MAX_FONTS; i++)
	{
		if (pMouseOnZone(PosX, PosY, Width, Height, 1) && MouseLButtonPush)
		{
			if (this->Fonts[i] == FontSize)
			{
				return true;
			}

			PushButton();

			FontSize = this->Fonts[i];

			ReloadFont();

			return true;
		}

		PosY += 20;
	}

	return false;
}

bool COptionsMenu::IsCloseEnabled()
{
	int PosX = (int)CalculateCenterPosX(34.0f);
	int PosY = (int)this->MainPosY + (int)this->MainHeight - 30;
	int Width = 34;
	int Height = 19;

	if (pMouseOnZone(PosX, PosY, Width, Height, 1) && MouseLButtonPush)
	{
		PushButton();

		ErrorMessage = *(DWORD*)0x07B0275C;

		*(DWORD*)0x07B0275C = 0;

		return true;
	}

	return false;
}

void COptionsMenu::ApplyFullScreenSettings()
{
	DEVMODE DevMode;

	DEVMODE* pDevmodes;

	int nModes = 0;

	while (EnumDisplaySettings(NULL, nModes, &DevMode))
	{
		nModes++;
	}

	pDevmodes = new DEVMODE[nModes + 1]; //. Create mod list

	nModes = 0;

	while (EnumDisplaySettings(NULL, nModes, &pDevmodes[nModes]))
	{
		nModes++;
	}

	DWORD dwBitsPerPel = 16;

	for (int n1 = 0; n1 < nModes; n1++)
	{
		if (pDevmodes[n1].dmBitsPerPel == 16 && *(int*)0x07AFEC9C == 0)
		{
			dwBitsPerPel = 16;
			break;
		}

		if (pDevmodes[n1].dmBitsPerPel == 24 && *(int*)0x07AFEC9C == 1)
		{
			dwBitsPerPel = 24;
			break;
		}

		if (pDevmodes[n1].dmBitsPerPel == 32 && *(int*)0x07AFEC9C == 1)
		{
			dwBitsPerPel = 32;
			break;
		}
	}

	for (int n2 = 0; n2 < nModes; n2++)
	{
		if (pDevmodes[n2].dmPelsWidth == *(int*)MAIN_RESOLUTION_X && pDevmodes[n2].dmPelsHeight == *(int*)MAIN_RESOLUTION_Y && pDevmodes[n2].dmBitsPerPel == dwBitsPerPel)
		{
			ChangeDisplaySettings(&pDevmodes[n2], 0);
			break;
		}
	}

	delete[] pDevmodes; //. remove mod list
}