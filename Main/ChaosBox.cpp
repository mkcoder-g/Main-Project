#include "stdafx.h"
#include "ChaosBox.h"
#include "Offset.h"
#include "Protocol.h"
#include "Util.h"

DWORD MixRate = 0;
DWORD MixMoney = 0;
DWORD MixTax = 0;
DWORD LastMixCode = 0;

void InitChaosBox() // OK
{
	SetCompleteHook(0xE8,0x004F256F,&PrintPlayerChaosRate);

	SetCompleteHook(0xE8,0x0060AA40,&PrintPlayerChaosRate);

	SetCompleteHook(0xE8,0x0060AB1C,&PrintPlayerChaosRate);
	
	SetCompleteHook(0xE8,0x004F260C,&PrintPlayerChaosMoney);

	SetCompleteHook(0xE8,0x0060ABC7,&PrintPlayerChaosMoney);
	
	SetCompleteHook(0xE8,0x0060ABF3,&PrintPlayerChaosMoney);

	SetCompleteHook(0xE8,0x0045BD70,&PrintPlayerRefineryRate);

	SetCompleteHook(0xE8,0x0045BE6F,&PrintPlayerRefineryRate);
}

void ChaosBoxMixSend() // OK
{
	DWORD MixType = (CheckWindow(WINDOWS_REFINERY)) ? CHAOS_MIX_JEWEL_OF_HARMONY_ITEM_PURITY : ((pPetMixIndex == 1) ? CHAOS_MIX_PET1 : ((pPetMixIndex == 2) ? CHAOS_MIX_PET2 : pChaosMixIndex));
	
	if(MixType != LastMixCode)
	{
		LastMixCode = MixType;

		PMSG_CHAOS_MIX_RATE_SEND pMsg;

		pMsg.header.set(0x88,sizeof(pMsg));

		pMsg.type = LastMixCode;

		DataSend((BYTE*)&pMsg,pMsg.header.size);
	}
}

bool ChaosBoxMixCheck() // OK
{
	if(CheckWindow(WINDOWS_REFINERY))
	{
		return 1;
	}

	if(pPetMixIndex != 0 || pChaosMixIndex > 57)
	{
		return 1;
	}

	switch(pChaosMixIndex)
	{
		case CHAOS_MIX_CHAOS_ITEM:
		case CHAOS_MIX_DEVIL_SQUARE:
		case CHAOS_MIX_PLUS_ITEM_LEVEL1:
		case CHAOS_MIX_PLUS_ITEM_LEVEL2:
		case CHAOS_MIX_DINORANT:
		case CHAOS_MIX_FRUIT:
		case CHAOS_MIX_WING1:
		case CHAOS_MIX_BLOOD_CASTLE:
		case CHAOS_MIX_WING2:
		case CHAOS_MIX_PLUS_ITEM_LEVEL3:
		case CHAOS_MIX_PLUS_ITEM_LEVEL4:
		case CHAOS_MIX_WING3:
		case CHAOS_MIX_PIECE_OF_HORN:
		case CHAOS_MIX_BROKEN_HORN:
		case CHAOS_MIX_HORN_OF_FENRIR:
		case CHAOS_MIX_HORN_OF_FENRIR_UPGRADE:
		case CHAOS_MIX_SHIELD_POTION1:
		case CHAOS_MIX_SHIELD_POTION2:
		case CHAOS_MIX_SHIELD_POTION3:
		case CHAOS_MIX_ITEM_380:
		case CHAOS_MIX_ILLUSION_TEMPLE:
		case CHAOS_MIX_FEATHER_OF_CONDOR:
		case CHAOS_MIX_WING4:
			return 1;
	}

	return 0;
}

void ChaosBoxConvertMoney(int money,char* target) // OK
{
	if(money >= 1000000000)
	{
		wsprintf(target,"%d,%03d,%03d,%03d",money/1000000000,money%1000000000/1000000,money%1000000/1000,money%1000);
	}
	else if(money >= 1000000)
	{
		wsprintf(target,"%d,%03d,%03d",money%1000000000/1000000,money%1000000/1000,money%1000);
	}
	else if(money > 1000)
	{
		wsprintf(target,"%d,%03d",money%1000000/1000,money%1000);
	}
	else
	{
		wsprintf(target,"%d",money%1000);
	}
}

void PrintPlayerChaosRate(char* a, char* b,char* c,int d) // OK
{
	if(ChaosBoxMixCheck() != 0)
	{
		ChaosBoxMixSend();

		d = MixRate;
	}

	wsprintf(a,b,c,d);
}

void PrintPlayerChaosMoney(char* a, char* b, char* c, char* d) // OK
{
	if(ChaosBoxMixCheck() != 0)
	{
		ChaosBoxConvertMoney(MixMoney,c);

		ChaosBoxConvertMoney((MixMoney+MixTax),d);
	}

	wsprintf(a,b,c,d);
}

void PrintPlayerRefineryRate(char* a, char* b,char* c,char* d,int e) // OK
{
	if(ChaosBoxMixCheck() != 0)
	{
		ChaosBoxMixSend();

		e = MixRate;
	}

	wsprintf(a,b,c,d,e);
}

void GCChaosMixRateRecv(PMSG_CHAOS_MIX_RATE_RECV* lpMsg) // OK
{
	MixRate = lpMsg->rate;

	MixMoney = lpMsg->money;

	MixTax = lpMsg->tax;
}