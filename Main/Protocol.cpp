#include "stdafx.h"
#include "Protocol.h"
#include "Attack.h"
#include "CCRC32.H"
#include "ChaosBox.h"
#include "Common.h"
#include "GoldenArcher.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Notice.h"
#include "Offset.h"
#include "PacketManager.h"
#include "PeriodicItem.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "ServerList.h"
#include "Shop.h"
#include "Util.h"
#include "WindowTime.h"

BOOL ProtocolCoreEx(BYTE head, BYTE* lpMsg, int size, int key) // OK
{
	switch (head)
	{
	case 0xD7:
		GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
		break;
	case 0xDE:
		GCCharacterCreationEnableRecv((PMSG_CHARACTER_CREATION_ENABLE_RECV*)lpMsg);
		break;
	case 0x16:
		GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
		break;
	case 0x17:
		GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
		break;
	case 0x22:
		GCItemGetRecv((PMSG_ITEM_GET_RECV*)lpMsg);
		break;
	case 0x24:
		GCItemMoveRecv((PMSG_ITEM_MOVE_RECV*)lpMsg);
		break;
	case 0x26:
		GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
		break;
	case 0x27:
		GCManaRecv((PMSG_MANA_RECV*)lpMsg);
		break;
	case 0x2C:
		GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
		break;
	case 0x2D:
		GCPeriodicEffectRecv((PMSG_PERIODIC_EFFECT_RECV*)lpMsg);
		break;
	case 0x31:
		ShopPcPoint = 0;
		break;
	case 0x37:
		GCTradeResponseRecv((PMSG_TRADE_RESPONSE_RECV*)lpMsg);
		break;
	case 0x88:
		GCChaosMixRateRecv((PMSG_CHAOS_MIX_RATE_RECV*)lpMsg);
		break;
	case 0x94:
		GoldenArcherCountRecv((PMSG_GOLDEN_ARCHER_COUNT_RECV*)lpMsg);
		break;
	case 0x9C:
		GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
		break;
	case 0xA3:
		GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
		break;
	case 0xB1:
		switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
		{
		case 0x00:
			GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
			break;
		case 0x01:
			GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
			break;
		}
		break;
	case 0xD0:
		switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
		{
			case 0x04:
				GCPcPointPointRecv((PMSG_PC_POINT_POINT_RECV*)lpMsg);
				break;
		}
		break;
	case 0xD5:
		switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
		{
			case 0x00:
				GCPeriodicItemInit();
				return 1;
			case 0x01:
				GCPeriodicItemRecv((PMSG_PERIODIC_ITEM_RECV*)lpMsg);
				return 1;
			case 0x02:
				GCPeriodicItemDeleteRecv((PMSG_PERIODIC_ITEM_DELETE_RECV*)lpMsg);
				return 1;
		}
		break;
	case 0xF1:
		switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
		{
		case 0x00:
			GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
			break;
		case 0x01:
			GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
			break;
		case 0x02:
			GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
			break;
		}
		break;
	case 0xF3:
		switch(((lpMsg[0]== 0xC1)?lpMsg[3]:lpMsg[4]))
		{
			case 0x00:
				GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
				break;
			case 0x03:
				GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
				break;
			case 0x04:
				GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
				break;
			case 0x05:
				GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
				break;
			case 0x06:
				GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
				break;
			case 0x07:
				GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
				break;
			case 0xE0:
				GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
				return 1;
			case 0xE1:
				GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
				return 1;
			case 0xE2:
				GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
				return 1;
			case 0xE4:
				GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
				return 1;
			case 0xE6:
				GCPcPointPriceListRecv((PMSG_PC_POINT_PRICE_LIST_RECV*)lpMsg);
				return 1;
			case 0xE7:
				GCShopPriceListRecv((PMSG_SHOP_PRICE_LIST_RECV*)lpMsg);
				return 1;
			case 0xE8:
				GCWindowNameRecv((PMSG_WINDOW_NAME_RECV*)lpMsg);
				return 1;
			case 0xEA:
				CCServerNameRecv((PMSG_SERVER_NAME_RECV*)lpMsg);
				return 1;
			case 0xEB:
				GCCustomAttackStatusRecv((PMSG_CUSTOM_ATTACK_STATUS_RECV*)lpMsg);
				return 1;
			case 0xEC:
				GCItemStackListRecv((PMSG_ITEM_LIST_INFO_RECV*)lpMsg);
				return 1;
			case 0xED:
				GCItemValueListRecv((PMSG_ITEM_LIST_INFO_RECV*)lpMsg);
				return 1;
			case 0xEF:
				GCEventTimeListRecv((PMSG_EVENT_TIME_LIST_RECV*)lpMsg);
				return 1;
		}
		break;
	}

	return ProtocolCore(head, lpMsg, size, key);
}

void GCWindowNameRecv(PMSG_WINDOW_NAME_RECV* lpMsg) // OK
{
	strcpy_s(WindowName,lpMsg->title);
}

void CCServerNameRecv(PMSG_SERVER_NAME_RECV* lpMsg) // OK
{
	memset(ServerName,0,sizeof(ServerName));

	for(int n=0;n < lpMsg->count;n++)
	{
		PMSG_SERVER_NAME* lpInfo = (PMSG_SERVER_NAME*)(((BYTE*)lpMsg)+sizeof(PMSG_SERVER_NAME_RECV)+(sizeof(PMSG_SERVER_NAME)*n));

		memcpy(ServerName[lpInfo->index],lpInfo->Name,sizeof(ServerName[lpInfo->index]));
	}
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]) & 0x7FFF;

	if (ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCCharacterCreationEnableRecv(PMSG_CHARACTER_CREATION_ENABLE_RECV* lpMsg) // OK
{
	SetExperienceTable(lpMsg->CharacterMaxLevel,lpMsg->ExperienceMultiplierConstA,lpMsg->ExperienceMultiplierConstB,lpMsg->CharacterDeleteMaxLevel);
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]) & 0x7FFF;

	if (ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCItemGetRecv(PMSG_ITEM_GET_RECV* lpMsg)
{
	if (lpMsg->result != 0xFF && lpMsg->result != 0xFE)
	{
		*(DWORD*)0x075AD588 = lpMsg->ViewIndex;
	}
}

void GCItemMoveRecv(PMSG_ITEM_MOVE_RECV* lpMsg) // OK
{
	LastMixCode = -1;
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if (lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if (lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP == 0) ? ViewCurHP : lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if (lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if (lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if (lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCPeriodicEffectRecv(PMSG_PERIODIC_EFFECT_RECV* lpMsg) // OK
{
	if(lpMsg->group == 2)
	{
		if(lpMsg->state)
		{
			if((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x20) == 0x20)
				*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x20;

			if((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x40) == 0x40)
				*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x40;

			if((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x80) == 0x80)
				*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x80;

			KillTimer(*(HWND*)(MAIN_WINDOW),1007);

			*(DWORD*)0x07AFEE7C = 0;
		}
		else
		{
			if(lpMsg->value == 6)
			{
				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x20) != 0x20)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) |= 0x20;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x40) == 0x40)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x40;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x80) == 0x80)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x80;
			}
			else if(lpMsg->value == 7)
			{
				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x20) == 0x20)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x20;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x40) != 0x40)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) |= 0x40;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x80) == 0x80)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x80;
			}
			else if(lpMsg->value == 8)
			{
				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x20) == 0x20)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x20;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x40) == 0x40)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) -= 0x40;

				if ((*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) & 0x80) != 0x80)
					*(DWORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+172) |= 0x80;
			}

			*(DWORD*)0x07AFEE7C = lpMsg->time;

			KillTimer(*(HWND*)(MAIN_WINDOW),1007);

			SetTimer(*(HWND*)(MAIN_WINDOW),1007,1000,0);
		}
	}
}

void GCTradeResponseRecv(PMSG_TRADE_RESPONSE_RECV* lpMsg) // OK
{
	if (lpMsg->response == 1 && ErrorMessage == 110)
	{
		ErrorMessage = 0;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]) & 0x7FFF;

	if (ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ServerCode = lpMsg->NextServerCode;

	ReconnectOnMapServerMove(lpMsg->IpAddress, lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCPcPointPointRecv(PMSG_PC_POINT_POINT_RECV* lpMsg) // OK
{
	ViewCurPoint = lpMsg->ViewCurPoint;
	ViewMaxPoint = lpMsg->ViewMaxPoint;
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	ServerCode = lpMsg->ServerCode;

	ViewIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);

	PMSG_HARDWAREID_INFO_SEND pMsg;

	pMsg.header.set(0xF3, 0x09, sizeof(pMsg));

	memcpy(pMsg.HardwareId, GetHardwareId(), sizeof(pMsg.HardwareId));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewLevel = lpMsg->Level;
	ViewPoint = lpMsg->ViewPoint;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if (lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ViewLevel = lpMsg->Level;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
	ViewExperience = lpMsg->Experience;
	ViewNextExperience = lpMsg->NextExperience;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewFruitAddPoint = lpMsg->FruitAddPoint;
	ViewMaxFruitAddPoint = lpMsg->MaxFruitAddPoint;
	ViewFruitSubPoint = lpMsg->FruitSubPoint;
	ViewMaxFruitSubPoint = lpMsg->MaxFruitSubPoint;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for (int n = 0; n<lpMsg->count; n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV) + (sizeof(PMSG_NEW_HEALTH_RECV)*n));

		InsertNewHealthBar(lpInfo->index, lpInfo->type, lpInfo->rate);
	}
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0)
	{
		((int(__cdecl*)(char*))0x0065CF60)(lpMsg->message);
	}
	else if(lpMsg->type == 1)
	{
		((void*(*)(char*,char*,int))0x0053EC70)("",lpMsg->message,lpMsg->color);
	}
	else if(lpMsg->type == 2)
	{
		NoticeAdd(lpMsg->color,lpMsg->message);
	}
}

void DataSend(BYTE* lpMsg, DWORD size) // OK
{
	BYTE EncBuff[2048];

	if (gPacketManager.AddData(lpMsg, size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send, EncBuff, size);

		if (EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if (EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				((void(__thiscall*)(void*, int))0x00404870)((void*)MAIN_HASH_CLASS, MAIN_PACKET_SERIAL);

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				((void(__thiscall*)(void*, int))0x004049E0)((void*)MAIN_HASH_CLASS, MAIN_PACKET_SERIAL);

				size = gPacketManager.Encrypt(&send[2], &EncBuff[1], (size - 1)) + 2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3], &EncBuff[2], (size - 2)) + 3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*, BYTE*, DWORD))0x00404610)((void*)0x07B02978, send, size);
	}
}