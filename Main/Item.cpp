#include "stdafx.h"
#include "Item.h"
#include "CustomEffect.h"
#include "CustomItem.h"
#include "CustomItemBow.h"
#include "CustomJewel.h"
#include "CustomTooltip.h"
#include "CustomWing.h"
#include "Offset.h"
#include "PeriodicItem.h"
#include "Util.h"

void InitItem() // OK
{
	SetCompleteHook(0xFF,0x0052870B,&GetItemColor);

	SetCompleteHook(0xFF,0x0062346B,&GetItemColor);

	SetCompleteHook(0xE8,0x0051D40E,&GetItemEffect);

	SetCompleteHook(0xE8,0x00628CDC,&GetItemEffect);

	SetCompleteHook(0xE9,0x0049A47D,&IsFullSetItem);

	//SetCompleteHook(0xE9,0x0049A471,&RenderSetOption);
}

void InitItemBow() // OK
{
	SetCompleteHook(0xE9,0x0050A4EA,&ItemBowCheckIndex1);

	SetCompleteHook(0xE9,0x0050B0C2,&ItemBowCheckIndex2);

	SetCompleteHook(0xE9,0x0050B394,&ItemBowCheckIndex3);

	SetCompleteHook(0xE9,0x0067EB99,&ItemBowCheckIndex4);

	SetCompleteHook(0xE9,0x0050C7AD,&ItemBowCheckIndex5);

	SetCompleteHook(0xE9,0x0050C336,&ItemBowCheckIndex6);

	SetCompleteHook(0xE9,0x0050C09D,&ItemBowCheckIndex7);

	SetCompleteHook(0xE9,0x0067EC59,&ItemBowCheckIndex8);

	SetCompleteHook(0xE9,0x0050BEC6,&ItemBowCheckIndex9);

	SetCompleteHook(0xE9,0x0050BDC9,&ItemBowCheckIndex10);

	SetCompleteHook(0xE9,0x0050A554,&ItemCrossbowCheckIndex1);

	SetCompleteHook(0xE9,0x0050B12C,&ItemCrossbowCheckIndex2);

	SetCompleteHook(0xE9,0x0050B3FE,&ItemCrossbowCheckIndex3);

	SetCompleteHook(0xE9,0x0067EBB8,&ItemCrossbowCheckIndex4);

	SetCompleteHook(0xE9,0x0050C838,&ItemCrossbowCheckIndex5);

	SetCompleteHook(0xE9,0x0050C3A2,&ItemCrossbowCheckIndex6);

	SetCompleteHook(0xE9,0x0050C109,&ItemCrossbowCheckIndex7);

	SetCompleteHook(0xE9,0x0067EC78,&ItemCrossbowCheckIndex8);

	SetCompleteHook(0xE9,0x0050BF54,&ItemCrossbowCheckIndex9);

	SetCompleteHook(0xE9,0x0050BE35,&ItemCrossbowCheckIndex10);

	SetCompleteHook(0xE9,0x005E7478,&ItemBowInventory);

	SetCompleteHook(0xE9,0x0054C60A,&BowCheckIndex1);

	SetCompleteHook(0xE9,0x005414A1,&BowCheckIndex2);

	SetCompleteHook(0xE9,0x0053A255,&BowCheckIndex3);

	SetCompleteHook(0xE9,0x005B8913,&BowCheckIndex4);

	SetCompleteHook(0xE9,0x0054FDD6,&BowCheckIndex5);

	SetCompleteHook(0xE9,0x005912EA,&BowCheckIndex6);

	SetCompleteHook(0xE9,0x0054C1C8,&BowCheckIndex7);

	SetCompleteHook(0xE9,0x005410EF,&BowCheckIndex8);

	SetCompleteHook(0xE9,0x00525C31,&BowCheckModelIndex1);

	SetCompleteHook(0xE9,0x0050CCD2,&BowCheckModelIndex2);

	SetCompleteHook(0xE9,0x0056E758,&BowCheckModelIndex3);

	SetCompleteHook(0xE9,0x0056CCE3,&BowCheckModelIndex4);

	SetCompleteHook(0xE9,0x0050CD40,&CrossbowCheckModelIndex1);

	SetCompleteHook(0xE9,0x0061A70C,&CrossbowCheckModelIndex2);

	SetCompleteHook(0xE9,0x00525C98,&CrossbowCheckModelIndex3);

	SetCompleteHook(0xE9,0x0051CE93,&CrossbowCheckModelIndex4);

	SetCompleteHook(0xE9,0x006F155E,&ItemBowAddSkillEffect1);

	SetCompleteHook(0xE9,0x006F1856,&ItemBowAddSkillEffect2);
}

void InitBundle() // OK
{
	SetCompleteHook(0xE9,0x0048D698,&BundleCheckIndex1);

	SetCompleteHook(0xE9,0x005B360A,&BundleCheckIndex2);

	SetCompleteHook(0xE9,0x005E8D82,&BundleCheckIndex3);

	SetCompleteHook(0xE9,0x005E7FFD,&BundleCheckIndex4);

	SetCompleteHook(0xE9,0x005E7BC6,&BundleCheckIndex5);
}

void InitJewel() // OK
{
	SetCompleteHook(0xE9,0x005CC9C6,&JewelCheckApplyItem1);

	SetCompleteHook(0xE9,0x005DDE99,&JewelCheckApplyItem2);

	SetCompleteHook(0xE9,0x005DEBB4,&JewelCheckIndex1);

	SetCompleteHook(0xE9,0x0061B1E3,&JewelCheckIndex2);

	SetCompleteHook(0xE9,0x00684158,&JewelCheckIndex3);
}

void InitWing() // OK
{
	SetCompleteHook(0xE9,0x0052CD2A,&WingMakePreviewCharSet);

	SetCompleteHook(0xE9,0x00623A8E,&WingDisableLevelGlow);

	SetCompleteHook(0xE9,0x005B54B9,&WingSetIncDamage);

	SetCompleteHook(0xE9,0x005B5511,&WingSetDecDamage);

	SetCompleteHook(0xE9,0x00535CC9,&WingSetDefense);

	SetCompleteHook(0xE9,0x00535DC5,&WingSetExtraDefense);

	SetCompleteHook(0xE9,0x00536D43,&WingSetOption);

	SetCompleteHook(0xE9,0x005363D0,&WingSetNewOption);

	SetCompleteHook(0xE9,0x00526168,&WingSetModelType);

	SetCompleteHook(0xE9,0x005355BD,&WingCheckIndex1);

	SetCompleteHook(0xE9,0x00535FB7,&WingCheckIndex2);

	SetCompleteHook(0xE9,0x00536929,&WingCheckIndex3);

	SetCompleteHook(0xE9,0x00538A4F,&WingCheckIndex4);

	SetCompleteHook(0xE9,0x00538BA5,&WingCheckIndex5);

	SetCompleteHook(0xE9,0x00538CE6,&WingCheckIndex6);

	SetCompleteHook(0xE9,0x0058DA54,&WingCheckIndex7);

	SetCompleteHook(0xE9,0x005B05A8,&WingCheckIndex8);

	SetCompleteHook(0xE9,0x005B15AF,&WingCheckIndex9);

	SetCompleteHook(0xE9,0x005B2281,&WingCheckIndex10);

	SetCompleteHook(0xE9,0x005B32E2,&WingCheckIndex11);

	SetCompleteHook(0xE9,0x005B611D,&WingCheckIndex12);

	SetCompleteHook(0xE9,0x005B7EFB,&WingCheckIndex13);

	SetCompleteHook(0xE9,0x005B844A,&WingCheckIndex14);

	SetCompleteHook(0xE9,0x005BCD5B,&WingCheckIndex15);

	SetCompleteHook(0xE9,0x005C4083,&WingCheckIndex16);

	SetCompleteHook(0xE9,0x005C40CE,&WingCheckIndex17);

	SetCompleteHook(0xE9,0x005DDED5,&WingCheckIndex18);

	SetCompleteHook(0xE9,0x005DEB01,&WingCheckIndex19);

	SetCompleteHook(0xE9,0x00535FFE,&WingCheckIndex20);

	SetCompleteHook(0xE9,0x00536045,&WingCheckIndex21);

	SetCompleteHook(0xE9,0x00537B4B,&WingCheckIndex22);

	SetCompleteHook(0xE9,0x004EF14B,&WingCheckIndex23);

	SetCompleteHook(0xE9,0x004EE95F,&WingCheckIndex24);

	SetCompleteHook(0xE9,0x005BBA9E,&WingCheckModelIndex1);

	SetCompleteHook(0xE9,0x00627DCD,&WingCheckModelIndex2);

	SetCompleteHook(0xE9,0x00623B54,&WingCheckModelIndex3);
}

void GetItemColor(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e) // OK
{
	if(gCustomItem.GetCustomItemColor((a-ITEM_BASE_MODEL),(float*)d) == 0 && gCustomItemBow.GetCustomItemBowColor((a-ITEM_BASE_MODEL),(float*)d) == 0)
	{
		((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD))0x0061C0AF)(a,b,c,d,e);
	}
}

void GetItemEffect(DWORD a,int b,float* c,float d,int e,int f,int g,int h,int i) // OK
{
	for(int n=0;n < MAX_CUSTOM_EFFECT;n++)
	{
		if(gCustomEffect.m_CustomEffectInfo[n].Index != -1)
		{
			if(gCustomEffect.m_CustomEffectInfo[n].ItemIndex != (b-ITEM_BASE_MODEL))
			{
				continue;
			}

			DWORD o = 240 * b + *(DWORD*)0x05801AE8;

			float ItemColor[3];
			
			float Position[3] = {0.0f,0.0f,0.0f};

			float WorldPosition[3] = {0.0f,0.0f,0.0f};

			ItemColor[0] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorR/255.0f);
			
			ItemColor[1] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorG/255.0f);
			
			ItemColor[2] = (float)(gCustomEffect.m_CustomEffectInfo[n].ColorB/255.0f);

			pTransformPosition(o,0x0694982C+(48*gCustomEffect.m_CustomEffectInfo[n].EffectValue),Position,WorldPosition,true);

			switch(gCustomEffect.m_CustomEffectInfo[n].EffectType)
			{
				case 0:
					pCreateSprite(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,gCustomEffect.m_CustomEffectInfo[n].Scale,ItemColor,1,0,gCustomEffect.m_CustomEffectInfo[n].EffectLevel);
					break;
				case 1:
					pCreateParticle(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,a+28,ItemColor,gCustomEffect.m_CustomEffectInfo[n].EffectLevel,gCustomEffect.m_CustomEffectInfo[n].Scale,1);
					break;
				case 2:
					pCreateEffect(gCustomEffect.m_CustomEffectInfo[n].EffectIndex,WorldPosition,(float*)a+28,ItemColor,gCustomEffect.m_CustomEffectInfo[n].EffectLevel,a,0,0,0,0,0);
					break;
			}
		}
	}

	if((b >= GET_ITEM_MODEL(12,136) && b <= GET_ITEM_MODEL(12,143)) || gCustomJewel.CheckCustomJewelByItem((b-ITEM_BASE_MODEL)) != 0)
	{
		e = (8<<3);
	}

	pRenderPartObjectEffect(a,b,c,d,e,f,g,h,i);
}

__declspec(naked) void IsFullSetItem() // OK
{
	static DWORD IsFullSetItemAddress1 = 0x0049A487;

	_asm
	{
		Mov Byte Ptr Ss:[Ebp-0x04],1
		Mov DWord Ptr Ss:[Ebp-0x24],0
		Jmp[IsFullSetItemAddress1]
	}
}

__declspec(naked) void RenderSetOption() // OK
{
	static DWORD RenderSetOptionListInItemAddress1 = 0x0049A480;
	static DWORD* This;
	static BYTE* Item;
	static bool* isfulloption;
	static BYTE* byLimitOptionNum;

	_asm
	{ 
		Mov Eax,[Ebp-0x44]
		Mov This,Eax
		Mov Eax,[Ebp+0x08]
		Mov Item,Eax
		Lea Eax,[Ebp-0x04]
		Mov isfulloption,Eax
		Lea Eax,[Ebp-0x18]
		Mov byLimitOptionNum,Eax
	}

	(*isfulloption) = ((bool(*)(DWORD*,BYTE*))0x0049A0D2)(This,Item);
	
	if((*isfulloption))
	{
		(*byLimitOptionNum) = 13;
	}

	_asm
	{
		Jmp[RenderSetOptionListInItemAddress1]
	}
}

void __declspec(naked) ItemBowCheckIndex1()
{
	static DWORD ItemIndex;
	static DWORD ItemBowCheckIndexAddress1 = 0x0050A4F1;
	static DWORD ItemBowCheckIndexAddress2 = 0x0050A504;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex-ITEM_BASE_MODEL,TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp ItemBowCheckIndexAddress1;
		}
	}

	_asm
	{
		Popad
		Jmp ItemBowCheckIndexAddress2;
	}
}

void __declspec(naked) ItemBowCheckIndex2()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050B0C9;
	static DWORD DisableBowAnimation = 0x0050B0DC;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex3()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050B39B;
	static DWORD DisableBowAnimation = 0x0050B3AE;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex4()
{
	static WORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0067EBF2;
	static DWORD DisableBowAnimation = 0x0067EB9F;

	_asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex5()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050C7B5;
	static DWORD DisableBowAnimation = 0x0050C7E7;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex6()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050C33E;
	static DWORD DisableBowAnimation = 0x0050C351;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex7()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050C0A5;
	static DWORD DisableBowAnimation = 0x0050C0B8;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex8()
{
	static WORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0067ECB5;
	static DWORD DisableBowAnimation = 0x0067EC5F;

	_asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL, TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex9()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050BECE;
	static DWORD DisableBowAnimation = 0x0050BF03;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemBowCheckIndex10()
{
	static DWORD ItemIndex;
	static DWORD EnableBowAnimation = 0x0050BDD1;
	static DWORD DisableBowAnimation = 0x0050BDE4;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		_asm
		{
			Popad
			Jmp EnableBowAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableBowAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex1()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050A56E;
	static DWORD DisableCrossAnimation = 0x0050A57E;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex2()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050B146;
	static DWORD DisableCrossAnimation = 0x0050B156;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex3()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050B418;
	static DWORD DisableCrossAnimation = 0x0050B428;

	_asm
	{
		Mov ItemIndex, Edx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex4()
{
	static WORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0067EBC4;
	static DWORD DisableCrossAnimation = 0x0067EC21;

	_asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex5()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050C851;
	static DWORD DisableCrossAnimation = 0x0050C880;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex6()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050C3BB;
	static DWORD DisableCrossAnimation = 0x0050C3CB;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex7()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050C122;
	static DWORD DisableCrossAnimation = 0x0050C135;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex8()
{
	static WORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0067EC84;
	static DWORD DisableCrossAnimation = 0x0067ECE7;

	_asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex9()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050BF6D;
	static DWORD DisableCrossAnimation = 0x0050BF9D;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemCrossbowCheckIndex10()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossAnimation = 0x0050BE4E;
	static DWORD DisableCrossAnimation = 0x0050BE5F;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossAnimation;
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossAnimation;
	}
}

void __declspec(naked) ItemBowInventory()
{
	static DWORD ItemIndex;
	static DWORD FixInventoryPosition = 0x005E7480;
	static DWORD IgnoreInventoryPosition = 0x005E74A7;

	__asm
	{
		Mov ItemIndex, Esi;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp FixInventoryPosition;
		}
	}

	__asm
	{
		Popad
		Jmp IgnoreInventoryPosition;
	}
}

void __declspec(naked) BowCheckIndex1()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0054C616;
	static DWORD DisableBow = 0x0054C69C;

	__asm
	{
		Mov ItemIndex, Ebp;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex2()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x005414D0;
	static DWORD DisableBow = 0x005414A9;

	__asm
	{
		Mov ItemIndex, Esi;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex3()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0053A25C;
	static DWORD DisableBow = 0x0053A268;

	__asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex4()
{
	static WORD ItemIndex;
	static DWORD EnableBow = 0x005B8941;
	static DWORD DisableBow = 0x005B8919;

	__asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex5()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0054FDDE;
	static DWORD DisableBow = 0x0054FDE6;

	__asm
	{
		Mov ItemIndex, Edi;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex6()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0059130E;
	static DWORD DisableBow = 0x005912F1;

	__asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex7()
{
	static WORD ItemIndex;
	static DWORD EnableBow = 0x0054C1D2;
	static DWORD DisableBow = 0x0054C281;

	__asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckIndex8()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0054111E;
	static DWORD DisableBow = 0x005410F7;

	__asm
	{
		Mov ItemIndex, Esi;
		Pushad
	}

	if(ItemIndex == GET_ITEM(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckModelIndex1()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x00525C38;
	static DWORD DisableBow = 0x00525C47;

	__asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckModelIndex2()
{
	static DWORD ItemIndex;
	static DWORD EnableBow = 0x0050CCDA;
	static DWORD DisableBow = 0x0050CCEF;

	__asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckModelIndex3()
{
	static WORD ItemIndex;
	static DWORD EnableBow = 0x0056E76D;
	static DWORD DisableBow = 0x0056E75F;

	__asm
	{
		Mov ItemIndex, Cx;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) BowCheckModelIndex4()
{
	static WORD ItemIndex;
	static DWORD EnableBow = 0x0056CCFF;
	static DWORD DisableBow = 0x0056CCE9;

	__asm
	{
		Mov ItemIndex, Ax;
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 22) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_BOW))
	{
		__asm
		{
			Popad
			Jmp EnableBow;
		}
	}

	__asm
	{
		Popad
		Jmp DisableBow;
	}
}

void __declspec(naked) CrossbowCheckModelIndex1()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossbow = 0x0050CD59;
	static DWORD DisableCrossbow = 0x0050CD6E;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossbow
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossbow
	}
}

void __declspec(naked) CrossbowCheckModelIndex2()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossbow = 0x0061A722;
	static DWORD DisableCrossbow = 0x0061A73B;

	_asm
	{
		Mov ItemIndex, Eax
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossbow
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossbow
	}
}

void __declspec(naked) CrossbowCheckModelIndex3()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossbow = 0x00525CB1;
	static DWORD DisableCrossbow = 0x00525CBD;

	_asm
	{
		Mov ItemIndex, Ecx
		Pushad
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossbow
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossbow
	}
}

void __declspec(naked) CrossbowCheckModelIndex4()
{
	static DWORD ItemIndex;
	static DWORD EnableCrossbow = 0x0051CEA5;
	static DWORD DisableCrossbow = 0x0051CEFC;

	_asm
	{
		Pushad
		Mov Eax, Dword Ptr Ds : [Ebp + 0x1C]
		Mov ItemIndex,Eax
	}

	if(ItemIndex == GET_ITEM_MODEL(4, 18) || ItemIndex == GET_ITEM_MODEL(4, 19) || gCustomItemBow.CheckCustomItemBow(ItemIndex - ITEM_BASE_MODEL,TYPE_CROSS))
	{
		_asm
		{
			Popad
			Jmp EnableCrossbow
		}
	}

	_asm
	{
		Popad
		Jmp DisableCrossbow
	}
}

__declspec(naked) void ItemBowAddSkillEffect1()
{
	static DWORD ItemIndex;
	static DWORD ItemBowAddSkillEffectAddress1 = 0x006F1564;
	static DWORD ItemBowAddSkillEffectAddress2 = 0x006A7FB0;

	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp-0x04]
		Mov Dword Ptr Ss:[Ebp-0x10],Ecx
		Mov ItemIndex,Ecx
	}
	
	if(gCustomItemBow.CheckCustomItemBow(ItemIndex-ITEM_BASE_MODEL,TYPE_CROSS))
	{
		int Effect = gCustomItemBow.GetCustomItemBowEffect(ItemIndex-ITEM_BASE_MODEL);

		_asm
		{
			Push 0
			Push 0
			Mov Cl,Byte Ptr Ss:[Ebp+0x18]
			Push Ecx
			Mov Dl,Byte Ptr Ss:[Ebp+0x14]
			Push Edx
			Mov Eax,Dword Ptr Ss:[Ebp+0x0C]
			Mov Cx,Word Ptr Ds:[Eax+0x0BE]
			Push Ecx
			Mov Edx,Dword Ptr Ss:[Ebp+0x0C]
			Push Edx
			Mov Eax,Dword Ptr Ss:[Ebp-0x0C]
			Push Eax
			Mov Ecx,Dword Ptr Ss:[Ebp+0x0C]
			Add Ecx,0x128
			Push Ecx
			Mov Edx,Dword Ptr Ss:[Ebp+0x0C]
			Add Edx,0x1C
			Push Edx
			Mov Eax,Dword Ptr Ss:[Ebp+0x0C]
			Add Eax,0x10
			Push Eax
			Push Effect
			Call [ItemBowAddSkillEffectAddress2]
			Add Esp,0x2C
		}
	}
	
	_asm
	{
		Jmp[ItemBowAddSkillEffectAddress1]
	}
}

__declspec(naked) void ItemBowAddSkillEffect2()
{
	static DWORD ItemIndex;
	static DWORD ItemBowAddSkillEffectAddress1 = 0x006F185C;
	static DWORD ItemBowAddSkillEffectAddress2 = 0x006A7FB0;

	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp-0x08]
		Mov Dword Ptr Ss:[Ebp-0x14],Ecx
		Mov ItemIndex,Ecx
	}

	if(gCustomItemBow.CheckCustomItemBow(ItemIndex-ITEM_BASE_MODEL,TYPE_BOW))
	{
		int Effect = gCustomItemBow.GetCustomItemBowEffect(ItemIndex-ITEM_BASE_MODEL);

		_asm
		{
			Push 0
			Push 0
			Mov Dl,Byte Ptr Ss:[Ebp+0x18]
			Push Edx
			Mov Al,Byte Ptr Ss:[Ebp+0x14]
			Push Eax
			Mov Ecx,Dword Ptr Ss:[Ebp+0x0C]
			Mov Dx,Word Ptr Ds:[Ecx+0x0BE]
			Push Edx
			Mov Eax,Dword Ptr Ss:[Ebp+0x0C]
			Push Eax
			Mov Ecx,Dword Ptr Ss:[Ebp-0x0C]
			Push Ecx
			Mov Edx,Dword Ptr Ss:[Ebp+0x0C]
			Add Edx,0x128
			Push Edx
			Mov Eax,Dword Ptr Ss:[Ebp+0x0C]
			Add Eax,0x1C
			Push Eax
			Mov Ecx,Dword Ptr Ss:[Ebp+0x0C]
			Add Ecx,0x10
			Push Ecx
			Push Effect
			CALL [ItemBowAddSkillEffectAddress2]
			Add Esp,0x2C
		}
	}

	_asm
	{
		Jmp[ItemBowAddSkillEffectAddress1]
	}
}

__declspec(naked) void BundleCheckIndex1() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x0048D6A4;
	static DWORD BundleCheckIndexAddress2 = 0x0048D6DB;

	_asm
	{
		Cmp Ecx,GET_ITEM(12,30)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,136)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,137)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,138)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,139)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,140)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,141)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,142)
		Jz Exit
		Cmp Ecx,GET_ITEM(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Mov Al,2;
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex2() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005B362B;
	static DWORD BundleCheckIndexAddress2 = 0x005B361E;

	_asm
	{
		Cmp Ax,GET_ITEM(12,30)
		Jz Exit
		Cmp Ax,GET_ITEM(12,136)
		Jz Next1
		Cmp Ax,GET_ITEM(12,137)
		Jz Next2
		Cmp Ax,GET_ITEM(12,138)
		Jz Next3
		Cmp Ax,GET_ITEM(12,139)
		Jz Next4
		Cmp Ax,GET_ITEM(12,140)
		Jz Next5
		Cmp Ax,GET_ITEM(12,141)
		Jz Next6
		Cmp Ax,GET_ITEM(12,142)
		Jz Next7
		Cmp Ax,GET_ITEM(12,143)
		Jz Next8
		Jmp[BundleCheckIndexAddress1]
		Next1:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1792
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1793
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1794
		Jmp[BundleCheckIndexAddress2]
		Next4:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1795
		Jmp[BundleCheckIndexAddress2]
		Next5:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1796
		Jmp[BundleCheckIndexAddress2]
		Next6:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1797
		Jmp[BundleCheckIndexAddress2]
		Next7:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1798
		Jmp[BundleCheckIndexAddress2]
		Next8:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1799
		Jmp[BundleCheckIndexAddress2]
		Exit:
		Lea Edx,[Edi+1]
		Mov Ecx,0x0750DF88
		Push Edx
		Push 1806
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex3() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005E8D8E;
	static DWORD BundleCheckIndexAddress2 = 0x005E8E5A;

	_asm
	{
		Cmp Esi,GET_ITEM(12,30)
		Jz Exit
		Cmp Esi,GET_ITEM(12,136)
		Jz Exit
		Cmp Esi,GET_ITEM(12,137)
		Jz Exit
		Cmp Esi,GET_ITEM(12,139)
		Jz Exit
		Cmp Esi,GET_ITEM(12,140)
		Jz Exit
		Cmp Esi,GET_ITEM(12,142)
		Jz Exit
		Cmp Esi,GET_ITEM(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex4() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005E8003;
	static DWORD BundleCheckIndexAddress2 = 0x005E83D8;

	_asm
	{
		Cmp Esi,GET_ITEM_MODEL(12,136)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,137)
		Je Next
		Cmp Esi,GET_ITEM_MODEL(12,138)
		Je Next2
		Cmp Esi,GET_ITEM_MODEL(12,139)
		Je Next2
		Cmp Esi,GET_ITEM_MODEL(12,140)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,141)
		Je Next3
		Cmp Esi,GET_ITEM_MODEL(12,142)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,143)
		Je Next4
		Cmp Esi,GET_ITEM_MODEL(12,30)
		Jmp[BundleCheckIndexAddress1]
		Next:
		Mov Dword Ptr Ss:[Esp+0x10],993400000
		Jmp[BundleCheckIndexAddress2]
		Next2:
		Mov Dword Ptr Ss:[Esp+0x10],994500000
		Jmp[BundleCheckIndexAddress2]
		Next3:
		Mov Dword Ptr Ss:[Esp+0x10],990400000
		Jmp[BundleCheckIndexAddress2]
		Next4:
		Mov Dword Ptr Ss:[Esp+0x10],998900000
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void BundleCheckIndex5() // OK
{
	static DWORD BundleCheckIndexAddress1 = 0x005E7BD2;
	static DWORD BundleCheckIndexAddress2 = 0x005E7D47;

	_asm
	{
		Cmp Esi,GET_ITEM_MODEL(14,43)
		Jz Exit
		Cmp Esi,GET_ITEM_MODEL(12,142)
		Jz Exit
		Cmp Esi,GET_ITEM_MODEL(12,143)
		Jz Exit
		Jmp[BundleCheckIndexAddress1]
		Exit:
		Jmp[BundleCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem1() // OK
{
	static DWORD JewelCheckApplyItemAddress1 = 0x005CC9CD;
	static DWORD JewelCheckApplyItemAddress2 = 0x005CC9E5;

	_asm
	{
		PushAd
		Cmp Si,0x1C2C
		Jz Exit
		Push Esi
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		PopAd
		Jmp [JewelCheckApplyItemAddress1]
		Exit:
		PopAd
		Jmp [JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckApplyItem2() // OK
{
	static DWORD JewelCheckApplyItemAddress1 = 0x005DEA25;
	static DWORD JewelCheckApplyItemAddress2 = 0x005DDEA4;

	_asm
	{
		Cmp Di,0x1C2C
		Jz Exit
		Push Edi
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		Jmp [JewelCheckApplyItemAddress1]
		Exit:
		Jmp [JewelCheckApplyItemAddress2]
	}
}

__declspec(naked) void JewelCheckIndex1() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x005DEBBA;
	static DWORD JewelCheckIndexAddress2 = 0x005DEBBE;

	_asm
	{
		Cmp Ax,0x1A35
		Jz Exit
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Jnz Exit
		Jmp [JewelCheckIndexAddress1]
		Exit:
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex2() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x0061B219;
	static DWORD JewelCheckIndexAddress2 = 0x0061B1EA;

	_asm
	{
		Mov Eax,Dword Ptr Ss:[Ebp-0x04]
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		Cmp Dword Ptr Ss:[Ebp-0x04],0x1C0D
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void JewelCheckIndex3() // OK
{
	static DWORD JewelCheckIndexAddress1 = 0x006841AA;
	static DWORD JewelCheckIndexAddress2 = 0x0068415D;

	_asm
	{
		PushAd
		Push Eax
		Lea Ecx,gCustomJewel
		Call [CCustomJewel::CheckCustomJewelByItem]
		Test Eax,Eax
		Je EXIT
		PopAd
		Jmp [JewelCheckIndexAddress1]
		EXIT:
		PopAd
		Cmp Eax,0x1C0E
		Jmp [JewelCheckIndexAddress2]
	}
}

__declspec(naked) void WingMakePreviewCharSet() // OK
{
	static DWORD WingMakePreviewCharSetAddress1 = 0x0052CD6C;
	static DWORD WingMakePreviewCharSetAddress2 = 0x0052CD33;

	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp+0x0C]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x10]
		Sar Edx,0x01
		And Edx,0x0F
		Test Edx,Edx
		Je EXIT
		Mov Eax,Dword Ptr Ss:[Ebp+0x0C]
		Movzx Ecx,Byte Ptr Ds:[Eax+0x10]
		Sar Ecx,0x01
		And Ecx,0x0F
		Sub Ecx,0x01
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWing]
		Test Eax,Eax
		Je EXIT
		Mov Edx,Dword Ptr Ss:[Ebp+0x0C]
		Movzx Eax,Byte Ptr Ds:[Edx+0x10]
		Sar Eax,0x01
		And Eax,0x0F
		Sub Eax,0x01
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingItem]
		Add Eax,ITEM_BASE_MODEL
		Mov Ecx,Dword Ptr Ss:[Ebp-0x08]
		Mov Word Ptr Ds:[Ecx+0x330],Ax
		Jmp [WingMakePreviewCharSetAddress1]
		EXIT:
		Mov Ecx,Dword Ptr Ss:[Ebp-0x04]
		And Ecx,0xFF
		Jmp [WingMakePreviewCharSetAddress2]
	}
}

__declspec(naked) void WingDisableLevelGlow() // OK
{
	static DWORD WingDisableLevelGlowAddress1 = 0x0062404C;
	static DWORD WingDisableLevelGlowAddress2 = 0x00623A97;

	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp+0x0C]
		Mov Dword Ptr Ss:[Ebp-0x454],Ecx
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Dword Ptr Ss:[Ebp-0x08],0x00
		Jmp [WingDisableLevelGlowAddress1]
		EXIT:
		Jmp [WingDisableLevelGlowAddress2]
	}
}

__declspec(naked) void WingSetIncDamage() // OK
{
	static DWORD WingSetIncDamageAddress1 = 0x005B54C7;
	static DWORD WingSetIncDamageAddress2 = 0x005B54BE;
	static DWORD Damage;

	_asm
	{
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Movsx Eax,Word Ptr Ds:[Esi]
		Mov Ecx,Dword Ptr Ds:[Esi+0x02]
		Sar Ecx,0x03
		And Ecx,0x0F
		Push Ecx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingIncDamage]
		Mov Damage,Eax
		Popad
		Mov Eax,Damage
		Jmp [WingSetIncDamageAddress1]
		EXIT:
		Popad
		Cmp Cx,0x1806
		Jmp [WingSetIncDamageAddress2]
	}
}

__declspec(naked) void WingSetDecDamage() // OK
{
	static DWORD WingSetDecDamageAddress1 = 0x005B5516;
	static DWORD Damage;

	_asm
	{
		Pushad
		Movsx Ecx,Word Ptr Ds:[Esi]
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Movsx Eax,Word Ptr Ds:[Esi]
		Mov Ecx,Dword Ptr Ds:[Esi+0x02]
		Sar Ecx,0x03
		And Ecx,0x0F
		Push Ecx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingDecDamage]
		Mov Damage,Eax
		Popad
		Mov Eax,Damage
		Push Eax
		Jmp [WingSetDecDamageAddress1]
		EXIT:
		Popad
		Lea Eax,[Edi+Edi+0x19]
		Push Eax
		Jmp [WingSetDecDamageAddress1]
	}
}

__declspec(naked) void WingSetDefense() // OK
{
	static DWORD WingSetDefenseAddress1 = 0x00535D10;
	static DWORD WingSetDefenseAddress2 = 0x00535CCF;

	_asm
	{
		Mov Ecx,Dword Ptr[Ebp+0x08]
		Movsx Edx,Word Ptr[Ecx]
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Ecx,Dword Ptr[Ebp+0x08]
		Mov Ebx,Dword Ptr[Ecx+0x02]
		Sar Ebx,0x03
		And Ebx,0x0F
		Push Ebx
		Movsx Edx,Word Ptr[Ecx]
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingDefense]
		Mov Ecx,Dword Ptr[Ebp+0x08]
		Movsx Edx,Word Ptr[Ecx+0x0E]
		Add Edx,Eax
		Mov Word Ptr[Ecx+0x0E],Dx
		Popad
		Jmp [WingSetDefenseAddress1]
		EXIT:
		Popad
		Jmp [WingSetDefenseAddress2]
	}
}

__declspec(naked) void WingSetExtraDefense() // OK
{
	static DWORD WingSetExtraDefenseAddress1 = 0x00535E4B;
	static DWORD WingSetExtraDefenseAddress2 = 0x00535DCB;

	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Edx,Word Ptr Ds:[Ecx]
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Edx,Dword Ptr Ss:[Ebp-0x28]
		Cmp Edx,0x0A
		Jnz NEXT1
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Word Ptr Ds:[Eax+0x0E]
		Add Ecx,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Word Ptr Ds:[Edx+0x0E],Cx
		Popad
		Jmp [WingSetExtraDefenseAddress1]
		NEXT1:
		Mov Edx,Dword Ptr Ss:[Ebp-0x28]
		Cmp Edx,0x0B
		Jnz NEXT2
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Word Ptr Ds:[Eax+0x0E]
		Add Ecx,0x03
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Word Ptr Ds:[Edx+0x0E],Cx
		Popad
		Jmp [WingSetExtraDefenseAddress1]
		NEXT2:
		Mov Edx,Dword Ptr Ss:[Ebp-0x28]
		Cmp Edx,0x0C
		Jnz NEXT3
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Word Ptr Ds:[Eax+0x0E]
		Add Ecx,0x06
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Word Ptr Ds:[Edx+0x0E],Cx
		Popad
		Jmp [WingSetExtraDefenseAddress1]
		NEXT3:
		Mov Edx,Dword Ptr Ss:[Ebp-0x28]
		Cmp Edx,0x0D
		Jnz NEXT4
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Word Ptr Ds:[Eax+0x0E]
		Add Ecx,0x0A
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Word Ptr Ds:[Edx+0x0E],Cx
		Popad
		Jmp [WingSetExtraDefenseAddress1]
		NEXT4:
		Popad
		Jmp [WingSetExtraDefenseAddress1]
		EXIT:
		Popad
		Jmp [WingSetExtraDefenseAddress2]
	}
}

__declspec(naked) void WingSetOption() // OK
{
	static DWORD WingSetOptionAddress1 = 0x0053746C;
	static DWORD WingSetOptionAddress2 = 0x00536D49;

	_asm
	{
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Pushad
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Eax,Dword Ptr Ss:[Ebp-0x14]
		Sar Eax,0x05
		And Eax,0x01
		Je NEXT1
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Edx,Word Ptr Ds:[Ecx]
		Push 0x02
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x10]
		Imul Eax,Ecx
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x02
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Word Ptr Ds:[Ecx+Edx+0x26],Ax
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		Popad
		Jmp [WingSetOptionAddress1]
		NEXT1:
		Mov Eax,Dword Ptr Ss:[Ebp-0x14]
		Sar Eax,0x04
		And Eax,0x01
		Je NEXT2
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Edx,Word Ptr Ds:[Ecx]
		Push 0x01
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x10]
		Imul Eax,Ecx
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x01
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Word Ptr Ds:[Ecx+Edx+0x26],Ax
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		Popad
		Jmp [WingSetOptionAddress1]
		NEXT2:
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Edx,Word Ptr Ds:[Ecx]
		Push 0x00
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionValue]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x10]
		Imul Eax,Ecx
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x00
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Word Ptr Ds:[Ecx+Edx+0x26],Ax
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		Popad
		Jmp [WingSetOptionAddress1]
		EXIT:
		Popad
		Jmp [WingSetOptionAddress2]
	}
}

__declspec(naked) void WingSetNewOption() // OK
{
	static DWORD WingSetNewOptionAddress1 = 0x0053686A;
	static DWORD WingSetNewOptionAddress2 = 0x005363D6;

	_asm
	{
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Mov Edx,Dword Ptr Ss:[Ebp-0x14]
		And Edx,0x01
		Je NEXT1
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Word Ptr Ds:[Eax]
		Push 0x00
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x00
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Byte Ptr Ds:[Ecx+Edx+0x26],Al
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		NEXT1:
		Mov Edx,Dword Ptr Ss:[Ebp-0x14]
		Sar Edx,0x01
		And Edx,0x01
		Je NEXT2
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Word Ptr Ds:[Eax]
		Push 0x01
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x01
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Byte Ptr Ds:[Ecx+Edx+0x26],Al
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		NEXT2:
		Mov Edx,Dword Ptr Ss:[Ebp-0x14]
		Sar Edx,0x02
		And Edx,0x01
		Je NEXT3;
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Word Ptr Ds:[Eax]
		Push 0x02
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x02
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Byte Ptr Ds:[Ecx+Edx+0x26],Al
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		NEXT3:
		Mov Edx,Dword Ptr Ss:[Ebp-0x14]
		Sar Edx,0x03
		And Edx,0x01
		Je NEXT4
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Movsx Ecx,Word Ptr Ds:[Eax]
		Push 0x03
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionValue]
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Ecx,Byte Ptr Ds:[Edx+0x25]
		Mov Byte Ptr Ds:[Edx+Ecx+0x2E],Al
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Movsx Eax,Word Ptr Ds:[Edx]
		Push 0x03
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::GetCustomWingNewOptionIndex]
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Movzx Edx,Byte Ptr Ds:[Ecx+0x25]
		Mov Byte Ptr Ds:[Ecx+Edx+0x26],Al
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Mov Cl,Byte Ptr Ds:[Eax+0x25]
		Add Cl,0x01
		Mov Edx,Dword Ptr Ss:[Ebp+0x08]
		Mov Byte Ptr Ds:[Edx+0x25],Cl
		NEXT4:
		Popad
		Jmp [WingSetNewOptionAddress1]
		EXIT:
		Popad
		Cmp Edx,0x1806
		Jmp [WingSetNewOptionAddress2]
	}
}

__declspec(naked) void WingSetModelType() // OK
{
	static DWORD WingSetModelTypeAddress1 = 0x00526176;
	static DWORD WingSetModelTypeAddress2 = 0x00526172;

	_asm
	{
		Mov Edx,Dword Ptr Ss:[Ebp-0x394]
		Sub Edx,ITEM_BASE_MODEL
		Push 0x01
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByModelType]
		Test Eax,Eax
		Je EXIT
		Jmp [WingSetModelTypeAddress1]
		EXIT:
		Cmp Dword Ptr Ss:[Ebp-0x394],0x1AB1
		Jmp [WingSetModelTypeAddress2]
	}
}

__declspec(naked) void WingCheckIndex1() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00535622;
	static DWORD WingCheckIndexAddress2 = 0x005355C5;

	__asm
	{
		Cmp Edx,0x1806
		Jle NEXT
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex2() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00535FBF;
	static DWORD WingCheckIndexAddress2 = 0x00535FC6;

	__asm
	{
		Cmp Ecx,0x1806
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex3() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00536930;
	static DWORD WingCheckIndexAddress2 = 0x0053694F;

	__asm
	{
		Cmp Eax,0x1806
		Jle NEXT
		Pushad
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex4() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00538A72;
	static DWORD WingCheckIndexAddress2 = 0x00538A57;

	__asm
	{
		Cmp Ecx,0x1806
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex5() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00538BD6;
	static DWORD WingCheckIndexAddress2 = 0x00538BAD;

	__asm
	{
		Cmp Edx,0x1806
		Jle NEXT
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex6() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00538D11;
	static DWORD WingCheckIndexAddress2 = 0x00538CEE;

	__asm
	{
		Cmp Edx,0x1806
		Jle NEXT
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex7() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x0058DB4B;
	static DWORD WingCheckIndexAddress2 = 0x0058DA5E;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex8() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B05E7;
	static DWORD WingCheckIndexAddress2 = 0x005B05AF;

	__asm
	{
		Cmp dx,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Dx
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex9() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B15B6;
	static DWORD WingCheckIndexAddress2 = 0x005B15F1;

	__asm
	{
		Cmp Eax,0x1806
		Jle NEXT
		Pushad
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex10() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B2299;
	static DWORD WingCheckIndexAddress2 = 0x005B2287;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex11() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B32E8;
	static DWORD WingCheckIndexAddress2 = 0x005B3303;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex12() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B612F;
	static DWORD WingCheckIndexAddress2 = 0x005B6123;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex13() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B7F13;
	static DWORD WingCheckIndexAddress2 = 0x005B7F01;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex14() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005B856F;
	static DWORD WingCheckIndexAddress2 = 0x005B8455;

	__asm
	{
		Cmp cx,0x1806
		Jle NEXT
		Pushad
		Movsx Eax,Cx
		Push Eax
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex15() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005BCD94;
	static DWORD WingCheckIndexAddress2 = 0x005BCD61;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex16() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005C409B;
	static DWORD WingCheckIndexAddress2 = 0x005C4089;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex17() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005C50B1;
	static DWORD WingCheckIndexAddress2 = 0x005C40D8;

	__asm
	{
		Cmp ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex18() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005DDEFB;
	static DWORD WingCheckIndexAddress2 = 0x005DDEDD;

	__asm
	{
		Cmp Ecx,0x1806
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex19() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x005DEBBE;
	static DWORD WingCheckIndexAddress2 = 0x005DEB0B;

	__asm
	{
		Cmp Ax,0x1806
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex20() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00536024;
	static DWORD WingCheckIndexAddress2 = 0x00536006;

	__asm
	{
		Cmp Edx,0x1806
		Jle NEXT
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex21() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x0053605A;
	static DWORD WingCheckIndexAddress2 = 0x0053604D;

	__asm
	{
		Cmp Ecx,0x1807
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex22() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x00537B53;
	static DWORD WingCheckIndexAddress2 = 0x00537B5F;

	__asm
	{
		Cmp Ecx,0x1806
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex23() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x004EF18B;
	static DWORD WingCheckIndexAddress2 = 0x004EF153;

	__asm
	{
		Cmp Edx,0x1806
		Jle NEXT
		Pushad
		Push Edx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckIndex24() // OK
{
	static DWORD WingCheckIndexAddress1 = 0x004EE99F;
	static DWORD WingCheckIndexAddress2 = 0x004EE967;

	__asm
	{
		Cmp Ecx,0x1806
		Jle NEXT
		Pushad
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckIndexAddress2]
		NEXT:
		Jmp [WingCheckIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex1() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x005BBACA;
	static DWORD WingCheckModelIndexAddress2 = 0x005BBAA4;

	__asm
	{
		Cmp Ax,0x1A8F
		Jle NEXT
		Pushad
		Movsx Ecx,Ax
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckModelIndexAddress2]
		NEXT:
		Jmp [WingCheckModelIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex2() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x00627EAD;
	static DWORD WingCheckModelIndexAddress2 = 0x00627DD9;

	__asm
	{
		Cmp Ecx,0x1A8F
		Jle NEXT
		Pushad
		Sub Ecx,ITEM_BASE_MODEL
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckModelIndexAddress2]
		NEXT:
		Jmp [WingCheckModelIndexAddress1]
	}
}

__declspec(naked) void WingCheckModelIndex3() // OK
{
	static DWORD WingCheckModelIndexAddress1 = 0x00623E84;
	static DWORD WingCheckModelIndexAddress2 = 0x0062404C;

	__asm
	{
		Cmp Dword Ptr[Ebp-0x454],0x1A8F;
		Jle NEXT
		Pushad
		Mov Ecx,Dword Ptr[Ebp-0x454]
		Sub Ecx,ITEM_BASE_MODEL;
		Push Ecx
		Lea Ecx,gCustomWing
		Call [CCustomWing::CheckCustomWingByItem]
		Test Eax,Eax
		Je EXIT
		Popad
		Jmp NEXT
		EXIT:
		Popad
		Jmp [WingCheckModelIndexAddress2]
		NEXT:
		Jmp [WingCheckModelIndexAddress1]
	}
}