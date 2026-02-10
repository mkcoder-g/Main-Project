#pragma once

#include "Protocol.h"

#define MAX_MONEY 2000000000

struct PMSG_ITEM_LIST_INFO_RECV
{
	PSWMSG_HEAD header; // C2:F3:[EC:ED]
	BYTE count;
};

struct ITEM_STACK_INFO
{
	WORD Index;
	BYTE Level;
	BYTE MaxStack;
};

struct ITEM_VALUE_INFO
{
	WORD Index;
	BYTE Level;
	BYTE Grade;
	DWORD Value;
};

struct SHOP_INFO
{
	DWORD money;
};

struct ITEM_INFO
{
	char Name[30];
	BYTE TwoHand;
	WORD Level;
	BYTE Slot;
	BYTE Skill;
	BYTE Width;
	BYTE Height;
	BYTE DamageMin;
	BYTE DamageMax;
	BYTE DefenseSuccessRate;
	BYTE Defense;
	BYTE MagicDefense;
	BYTE AttackSpeed;
	BYTE WalkSpeed;
	BYTE Durability;
	BYTE MagicDurability;
	BYTE MagicDamageRate;
	WORD RequireStrength;
	WORD RequireDexterity;
	WORD RequireEnergy;
	WORD RequireVitality;
	WORD RequireLeadership;
	WORD RequireLevel;
	BYTE Value;
	DWORD BuyMoney;
	BYTE SetAttr;
	BYTE RequireClass[5];
	BYTE Resistance[7];
};

typedef struct
{
	WORD index; //0
	BYTE unk01; //2
	BYTE unk02; //3
	DWORD options; //4
	BYTE unk03; //8
	BYTE unk04; //9
	BYTE m_TwoHand; //10
	BYTE unk05; //11
	WORD DmgMin; //12
	WORD DmgMax; //14
	BYTE m_SuccessfulBlocking; //16
	BYTE unk06; //17
	WORD m_Defense; //18
	WORD m_MagicDefense; //20
	BYTE m_btMagicPwr; //22
	BYTE m_btAtkSpeed; //23
	WORD m_btWalkSpeed; //24
	BYTE Durability; //26
	BYTE OptExc; //27
	BYTE OptAnc; //28
	BYTE gap1D; //29
	WORD ReqStr; //30
	WORD ReqAgi; //32
	WORD ReqEne; //34
	WORD ReqVit; //36
	WORD ReqCmd; //38
	WORD LvlReq;//40
	BYTE OptCount; //42
	BYTE OptionsRef[8]; //43
	BYTE OptionsEspecial[8]; //52
	BYTE unk16; //61
	BYTE unk17; //62
	BYTE unk18; //63
	BYTE unk19; //64
	BYTE unk20; //65
	BYTE unk21; //66
	BYTE unk22; //67
	BYTE unk23; //68
	BYTE unk24; //69
	BYTE unk25; //70
	BYTE unk26; //71
	BYTE unk27; //72
	BYTE unk28; //73
	BYTE unk29; //74
	BYTE unk30; //75
	BYTE unk31; //76
	//Size -> 72 //New 76
}
ITEM_STRUCT;

#define GetItemInfo(x) (ITEM_INFO*)(*(DWORD*)(0x07513324) + x * sizeof(ITEM_INFO))

void InitShop();
void RenderStackNumber();
WORD GetItemDurability(DWORD a,ITEM_INFO* lpItemInfo,int level);
DWORD GetItemRepairMoney(int money,int dur,int maxdur,WORD index,char* TextOut);
DWORD GetItemValue(DWORD a,int type);
void ShowBuyPrice(char* TextOut,char* text,char* param);
void ColorBuyPrice();
void GCShopPriceListRecv(PMSG_SHOP_PRICE_LIST_RECV* lpMsg);
void GCPcPointPriceListRecv(PMSG_PC_POINT_PRICE_LIST_RECV* lpMsg);
int ItemMaxStack(int index,int level);
bool ItemValue(int index,int level,int grade,int dur,int* value);
void GCItemStackListRecv(PMSG_ITEM_LIST_INFO_RECV* lpMsg);
void GCItemValueListRecv(PMSG_ITEM_LIST_INFO_RECV* lpMsg);

extern DWORD ShopPcPoint;