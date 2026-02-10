#include "stdafx.h"
#include "PrintPlayer.h"
#include "Offset.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"

DWORD ViewIndex = 0;
DWORD ViewLevel = 0;
DWORD ViewReset = 0;
DWORD ViewPoint = 0;
DWORD ViewCurHP = 0;
DWORD ViewMaxHP = 0;
DWORD ViewCurMP = 0;
DWORD ViewMaxMP = 0;
DWORD ViewCurBP = 0;
DWORD ViewMaxBP = 0;
DWORD ViewCurSD = 0;
DWORD ViewMaxSD = 0;
DWORD ViewDamageHP = 0;
DWORD ViewDamageSD = 0;
DWORD ViewExperience = 0;
DWORD ViewNextExperience = 0;
DWORD ViewStrength = 0;
DWORD ViewDexterity = 0;
DWORD ViewVitality = 0;
DWORD ViewEnergy = 0;
DWORD ViewLeadership = 0;
DWORD ViewAddStrength = 0;
DWORD ViewAddDexterity = 0;
DWORD ViewAddVitality = 0;
DWORD ViewAddEnergy = 0;
DWORD ViewAddLeadership = 0;
DWORD ViewPhysiSpeed = 0;
DWORD ViewMagicSpeed = 0;
DWORD ViewCurPoint = 0;
DWORD ViewMaxPoint = 0;
DWORD ViewFruitAddPoint = 0;
DWORD ViewMaxFruitAddPoint = 0;
DWORD ViewFruitSubPoint = 0;
DWORD ViewMaxFruitSubPoint = 0;

void InitPrintPlayer() // OK
{
	SetCompleteHook(0xE8,0x0059FA5E,&PrintDrawCircleHPMP);

	SetCompleteHook(0xE8,0x0059FB67,&PrintDrawCircleHPMP);

	SetCompleteHook(0xE8,0x0059ECF0,&PrintDrawCircleSDBP);

	SetCompleteHook(0xE8,0x0059F060,&PrintDrawCircleSDBP);

	SetCompleteHook(0xE8,0x005A22EA,&PrintBarExperience1);

	SetCompleteHook(0xE8,0x005A232D,&PrintBarExperience2);

	SetCompleteHook(0xE8,0x0049F337,&PrintPlayerViewHP1);

	SetCompleteHook(0xE8,0x0059FAF6,&PrintPlayerViewHP1);

	SetCompleteHook(0xE8,0x005F8566,&PrintPlayerViewHP1);

	SetCompleteHook(0xE8,0x005A096C,&PrintPlayerViewHP2);

	SetCompleteHook(0xE8,0x0059FBFF,&PrintPlayerViewMP1);

	SetCompleteHook(0xE8,0x005F86B6,&PrintPlayerViewMP1);

	SetCompleteHook(0xE8,0x005A0993,&PrintPlayerViewMP2);

	SetCompleteHook(0xE8,0x0059ED97,&PrintPlayerViewBP1);

	SetCompleteHook(0xE8,0x0059ED0A,&PrintPlayerViewBP2);

	SetCompleteHook(0xE8,0x0059F103,&PrintPlayerViewSD1);

	SetCompleteHook(0xE8,0x0059F07A,&PrintPlayerViewSD2);

	SetCompleteHook(0xE8,0x005F686E,&PrintPlayerViewExperience);
	
	SetCompleteHook(0xE8,0x005A23F4,&PrintPlayerViewExperience);

	SetCompleteHook(0xE8,0x005F8B94,&PrintPlayerViewLevelUp);

	SetCompleteHook(0xE8,0x005F6CEB,&PrintPlayerViewStrength);

	SetCompleteHook(0xE8,0x005F7E4B,&PrintPlayerViewDexterity);

	SetCompleteHook(0xE8,0x005F84EB,&PrintPlayerViewVitality);

	SetCompleteHook(0xE8,0x005F863E,&PrintPlayerViewEnergy);

	SetCompleteHook(0xE8,0x005F8F1F,&PrintPlayerViewLeadership);

	SetCompleteHook(0xE8,0x005F832C,&PrintPlayerViewAttackSpeed);

	SetCompleteHook(0xE8,0x004F4A06,&PrintPlayerViewPcPoints);

	SetCompleteHook(0xE8,0x005FB486,&PrintPlayerViewPcPoints);

	SetCompleteHook(0xE8,0x006F3EF6,&RenderNumber);

	SetCompleteHook(0xE8,0x004FF521,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067CCC7,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067D08C,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067D19A,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067D1F1,&PrintDamageOnScreenSD);
	
	SetCompleteHook(0xE8,0x0067DDA8,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067DE03,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067DE9A,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067DEF5,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067DF10,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x0067DF6A,&PrintDamageOnScreenSD);
	
	SetCompleteHook(0xE8,0x006821C9,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x00682B1E,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x00682B54,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x006835F0,&PrintDamageOnScreenHP);
	
	SetCompleteHook(0xE8,0x00683626,&PrintDamageOnScreenHP);

	SetCompleteHook(0xE8,0x00675DB5,&PrintPlayerMapName);

	SetCompleteHook(0xE8,0x0067904B,&PrintPlayerMapName);

	SetCompleteHook(0xE9,0x0053B91A,&CalculateAttackSpeed);
}

void RenderNumber(float* a, int b, float* c, float d, float e) // OK
{
	if(b != -1 && ((bool(__cdecl*)(DWORD))0x004600A0)(*(DWORD*)MAIN_CURRENT_MAP) == true)
	{
		b = -2;
		e = 1.0f;
	}

	((void(*)(float*,int,float*,float,float))0x006432CA)(a,b,c,d,e);
}

void PrintDamageOnScreenHP(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e) // OK
{
	if(((int)b) > 0)
	{
		b = ViewDamageHP;
	}

	((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD))0x006F3D60)(a,b,c,d,e);
}

void PrintDamageOnScreenSD(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e) // OK
{
	if(((int)b) > 0)
	{
		b = ViewDamageSD;
	}

	((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD))0x006F3D60)(a,b,c,d,e);
}

void PrintPlayerMapName(char* a, char* b, char* c, char* d) // OK
{
	wsprintf(a,b,d,c);
}

void PrintDrawCircleHPMP(DWORD a,float b,float c,float d,float e,float f,float g,float h,float i,int j,int k,GLfloat l) // OK
{
	float HP = (float)(ViewMaxHP-ViewCurHP)/(float)ViewMaxHP;
	float MP = (float)(ViewMaxMP-ViewCurMP)/(float)ViewMaxMP;

	c =((a==0xEB)?MP:HP)*48.0f+432.0f;
    e=48.0f-((a==0xEB)?MP:HP)*48.0f;
    g =((a==0xEB)?MP:HP)*48.0f/64.0f;
    i =(1.0f-((a==0xEB)?MP:HP))*48.0f/64.0f;

	return pDrawImage(a,b,c,d,e,f,g,h,i,j,k,l);
}

void PrintDrawCircleSDBP(DWORD a,float b,float c,float d,float e,float f,float g,float h,float i,int j,int k,GLfloat l) // OK
{
	float SD = (float)(ViewMaxSD-ViewCurSD)/(float)ViewMaxSD;
	float BP = (float)(ViewMaxBP-ViewCurBP)/(float)ViewMaxBP;

	c =((a==0x101)?BP:SD)*36.0f+438.0f;
    e=36.0f-((a==0x101)?BP:SD)*36.0f;
	g =((a==0x101)?BP:SD)*36.0f/64.0f;
    i =(1.0f-((a==0x101)?BP:SD))*36.0f/64.0f;

	return pDrawImage(a,b,c,d,e,f,g,h,i,j,k,l);
}

void PrintBarExperience1(float a,float b,float c,float d) // OK
{
	float Experience = (float)ViewExperience-(float)gLevelExperience[ViewLevel-1];
	float NextExperience = (float)ViewNextExperience-(float)gLevelExperience[ViewLevel-1];
	
	Experience = ((ViewExperience < gLevelExperience[ViewLevel-1]) ? 0.0f : Experience);
	
	c = (Experience > 0.0f && NextExperience > 0.0f) ? ((Experience/NextExperience)*10.0f) : 0.0f;
	c -= (int)c;
	c *= 198.0f;

	pDrawBarForm(a,b,c,d);
}

void PrintBarExperience2(float a,float b,DWORD c,float d,float e) // OK
{
	float Experience = (float)ViewExperience-(float)gLevelExperience[ViewLevel-1];
	float NextExperience = (float)ViewNextExperience-(float)gLevelExperience[ViewLevel-1];

	Experience = ((ViewExperience < gLevelExperience[ViewLevel-1])?0.0f:Experience);
	
	c = (Experience > 0.0f && NextExperience > 0.0f)?(int)((Experience/NextExperience)*10.0f):0;
	c = ((c<0)?0:((c>9)?9:c));

	pDrawBigText(a,b,c,d,e);
}

void PrintPlayerViewHP1(char* a, char* b) // OK
{
	wsprintf(a,b,ViewCurHP,ViewMaxHP);
}

void PrintPlayerViewHP2(float a,float b,DWORD c,float d,float e) // OK
{
	pDrawBigText(a+6,b,ViewCurHP,d,e);
}

void PrintPlayerViewMP1(char* a, char* b) // OK
{
	wsprintf(a,b,ViewCurMP,ViewMaxMP);
}

void PrintPlayerViewMP2(float a,float b,DWORD c,float d,float e) // OK
{
	pDrawBigText(a-20,b,ViewCurMP,d,e);
}

void PrintPlayerViewBP1(char* a, char* b) // OK
{
	wsprintf(a,b,ViewCurBP,ViewMaxBP);
}

void PrintPlayerViewBP2(float a,float b,DWORD c,float d,float e) // OK
{
	pDrawBigText(a,b,ViewCurBP,d,e);
}

void PrintPlayerViewSD1(char* a, char* b) // OK
{
	wsprintf(a,b,ViewCurSD,ViewMaxSD);
}

void PrintPlayerViewSD2(float a,float b,DWORD c,float d,float e) // OK
{
	pDrawBigText(a,b,ViewCurSD,d,e);
}

void PrintPlayerViewExperience(char* a, char* b) // OK
{
	wsprintf(a,b,ViewExperience,ViewNextExperience);
}

void PrintPlayerViewLevelUp(char* a, char* b) // OK
{
	wsprintf(a,b,ViewPoint);
}

void PrintPlayerViewStrength(char* a, char* b) // OK
{
	wsprintf(a,b,ViewStrength+ViewAddStrength);
}

void PrintPlayerViewDexterity(char* a, char* b) // OK
{
	wsprintf(a,b,ViewDexterity+ViewAddDexterity);
}

void PrintPlayerViewVitality(char* a, char* b) // OK
{
	wsprintf(a,b,ViewVitality+ViewAddVitality);
}

void PrintPlayerViewEnergy(char* a, char* b) // OK
{
	wsprintf(a,b,ViewEnergy+ViewAddEnergy);
}

void PrintPlayerViewLeadership(char* a, char* b) // OK
{
	wsprintf(a,b,ViewLeadership+ViewAddLeadership);
}

void PrintPlayerViewAttackSpeed(char* a, char* b) // OK
{
	CHARACTER_ATTRIBUTE* CharacterAttribute = (CHARACTER_ATTRIBUTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT));

	if((CharacterAttribute->Class & 7) == 0)
	{
		wsprintf(a,b,ViewMagicSpeed);
	}
	else
	{
		wsprintf(a,b,ViewPhysiSpeed);
	}
}

void PrintPlayerViewPcPoints(char* a, char* b) // OK
{
	wsprintf(a,b,ViewCurPoint,ViewMaxPoint);
}

void CalculateAttackSpeed(DWORD This)
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) != 5)
	{
		return;
	}

	CHARACTER_ATTRIBUTE* CharacterAttribute = (CHARACTER_ATTRIBUTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT));

	CharacterAttribute->Level = GET_MAX_WORD_VALUE(ViewLevel);
	CharacterAttribute->LevelUpPoint = GET_MAX_WORD_VALUE(ViewPoint);

	CharacterAttribute->Experience = ((ViewExperience>ViewNextExperience)?ViewNextExperience:ViewExperience);
	CharacterAttribute->NextExperince = ViewNextExperience;

	CharacterAttribute->Strength = GET_MAX_WORD_VALUE(ViewStrength);
	CharacterAttribute->Dexterity = GET_MAX_WORD_VALUE(ViewDexterity);
	CharacterAttribute->Vitality = GET_MAX_WORD_VALUE(ViewVitality);
	CharacterAttribute->Energy = GET_MAX_WORD_VALUE(ViewEnergy);
	CharacterAttribute->Leadership = GET_MAX_WORD_VALUE(ViewLeadership);

	CharacterAttribute->AddStrength = GET_MAX_WORD_VALUE(ViewAddStrength);
	CharacterAttribute->AddDexterity = GET_MAX_WORD_VALUE(ViewAddDexterity);
	CharacterAttribute->AddVitality = GET_MAX_WORD_VALUE(ViewAddVitality);
	CharacterAttribute->AddEnergy = GET_MAX_WORD_VALUE(ViewAddEnergy);
	CharacterAttribute->AddLeadership = GET_MAX_WORD_VALUE(ViewAddLeadership);

	CharacterAttribute->Life = GET_MAX_WORD_VALUE(ViewCurHP);
	CharacterAttribute->LifeMax = GET_MAX_WORD_VALUE(ViewMaxHP);

	CharacterAttribute->Mana = GET_MAX_WORD_VALUE(ViewCurMP);
	CharacterAttribute->ManaMax = GET_MAX_WORD_VALUE(ViewMaxMP);

	CharacterAttribute->SkillMana = GET_MAX_WORD_VALUE(ViewCurBP);
	CharacterAttribute->SkillManaMax = GET_MAX_WORD_VALUE(ViewMaxBP);

	CharacterAttribute->Shield = GET_MAX_WORD_VALUE(ViewCurSD);
	CharacterAttribute->ShieldMax = GET_MAX_WORD_VALUE(ViewMaxSD);

	CharacterAttribute->AddPoint = GET_MAX_WORD_VALUE(ViewFruitAddPoint);
	CharacterAttribute->MaxAddPoint = GET_MAX_WORD_VALUE(ViewMaxFruitAddPoint);

	CharacterAttribute->MinusPoint = GET_MAX_WORD_VALUE(ViewFruitSubPoint);
	CharacterAttribute->MaxMinusPoint = GET_MAX_WORD_VALUE(ViewMaxFruitSubPoint);

	SKILL_ATTACK_SPEED_INFO* lpInfo = gSkillAttackSpeed.GetInfo(((BYTE(__thiscall*)(DWORD,DWORD))0x004D8E90)(MAIN_HASH_CLASS,(*(DWORD*)MAIN_VIEWPORT_STRUCT+966)));

	BYTE AnimationValue = gProtect.m_MainInfo.AttackAnimationValue[(CharacterAttribute->Class & 7)];
	DWORD PhysiSpeed = ViewPhysiSpeed;
	DWORD MagicSpeed = ViewMagicSpeed;

	if(lpInfo != 0)
	{
		if(lpInfo->AnimationValue != -1)
		{
			AnimationValue = lpInfo->AnimationValue;
		}

		if(lpInfo->MaxPhysiSpeed != -1 && ViewPhysiSpeed >= (DWORD)lpInfo->MaxPhysiSpeed)
		{
			PhysiSpeed = lpInfo->MaxPhysiSpeed;
		}

		if(lpInfo->MaxMagicSpeed != -1 && ViewMagicSpeed >= (DWORD)lpInfo->MaxMagicSpeed)
		{
			MagicSpeed = lpInfo->MaxMagicSpeed;
		}
	}

	SetByte(0x00510E56,AnimationValue);

	CharacterAttribute->AttackSpeed = GET_MAX_WORD_VALUE(PhysiSpeed);
	CharacterAttribute->MagicSpeed = GET_MAX_WORD_VALUE(MagicSpeed);
}