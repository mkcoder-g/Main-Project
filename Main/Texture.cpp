#include "stdafx.h"
#include "Texture.h"
#include "CustomItem.h"
#include "CustomItemBow.h"
#include "CustomJewel.h"
#include "CustomWing.h"
#include "Offset.h"
#include "Item.h"
#include "Util.h"

int& TextureBegin = *(int*)0x007AFE7DC;

int& TextureCurrent = *(int*)0x07AFE7E0;

TEXTURE m_Texture[MAX_TEXTURE];

void InitTexture() // OK
{
	SetTextures();

	SetCompleteHook(0xE8,0x0064C431,&OpenBasicData);

	SetCompleteHook(0xE9,0x0062B1F0,&SetMaxTextures);
}

void OpenBasicData(HDC hDC) // OK
{
	((void(*)(HDC))0x0063C177)(hDC); // OpenBasicData

	TextureCurrent = 6000;

	LoadItemModel(GET_ITEM_MODEL(12,136),"Item\\","Jewel03");
	LoadItemTexture(GET_ITEM_MODEL(12,136),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,137),"Item\\","jewel22");
	LoadItemTexture(GET_ITEM_MODEL(12,137),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,138),"Item\\","suho");
	LoadItemTexture(GET_ITEM_MODEL(12,138),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,139),"Item\\","rs");
	LoadItemTexture(GET_ITEM_MODEL(12,139),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,140),"Item\\","jos");
	LoadItemTexture(GET_ITEM_MODEL(12,140),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,141),"Item\\","Jewel15");
	LoadItemTexture(GET_ITEM_MODEL(12,141),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,142),"Item\\","LowRefineStone");
	LoadItemTexture(GET_ITEM_MODEL(12,142),"Item\\");

	LoadItemModel(GET_ITEM_MODEL(12,143),"Item\\","HighRefineStone");
	LoadItemTexture(GET_ITEM_MODEL(12,143),"Item\\");
	

	for(int n=0;n<MAX_CUSTOM_JEWEL;n++)
	{
		if(gCustomJewel.m_CustomJewelInfo[n].Index != -1)
		{
			LoadItemModel((gCustomJewel.m_CustomJewelInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\",gCustomJewel.m_CustomJewelInfo[n].ModelName);
			LoadItemTexture((gCustomJewel.m_CustomJewelInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\");
		}
	}

	for(int n=0;n<MAX_CUSTOM_WING;n++)
	{
		if(gCustomWing.m_CustomWingInfo[n].Index != -1)
		{
			LoadItemModel((gCustomWing.m_CustomWingInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\",gCustomWing.m_CustomWingInfo[n].ModelName);
			LoadItemTexture((gCustomWing.m_CustomWingInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\");
		}
	}

	for(int n=0;n<MAX_CUSTOM_ITEM;n++)
	{
		if(gCustomItem.m_CustomItemInfo[n].Index != -1)
		{
			LoadItemModel((gCustomItem.m_CustomItemInfo[n].ItemIndex+ITEM_BASE_MODEL),((gCustomItem.m_CustomItemInfo[n].ItemIndex >= GET_ITEM(7,0) && gCustomItem.m_CustomItemInfo[n].ItemIndex<GET_ITEM(12,0)) ? "Player\\" : "Item\\"),gCustomItem.m_CustomItemInfo[n].ModelName);
			LoadItemTexture((gCustomItem.m_CustomItemInfo[n].ItemIndex+ITEM_BASE_MODEL),((gCustomItem.m_CustomItemInfo[n].ItemIndex >= GET_ITEM(7,0) && gCustomItem.m_CustomItemInfo[n].ItemIndex<GET_ITEM(12,0)) ? "Player\\" : "Item\\"));
		}
	}

	for(int n=0;n<MAX_CUSTOM_ITEM_BOW;n++)
	{
		if(gCustomItemBow.m_CustomItemBowInfo[n].Index != -1)
		{
			LoadItemModel((gCustomItemBow.m_CustomItemBowInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\",gCustomItemBow.m_CustomItemBowInfo[n].ModelName);
			LoadItemTexture((gCustomItemBow.m_CustomItemBowInfo[n].ItemIndex+ITEM_BASE_MODEL),"Item\\");
		}
	}
}

void SetMaxTextures(DWORD count) // OK
{
	TextureBegin = 0;
	TextureCurrent = count;
}

void SetTextures() // OK
{
	memset(m_Texture,0,sizeof(m_Texture));

	SetDword(0x004203BC+3,(DWORD)&m_Texture);
	SetDword(0x0042048D+3,(DWORD)&m_Texture);
	SetDword(0x00421AF6+3,(DWORD)&m_Texture);
	SetDword(0x00421DA4+3,(DWORD)&m_Texture);
	SetDword(0x005FA38D+3,(DWORD)&m_Texture);
	SetDword(0x00606967+1,(DWORD)&m_Texture);
	SetDword(0x00607A8D+2,(DWORD)&m_Texture);
	SetDword(0x0062B242+2,(DWORD)&m_Texture);
	SetDword(0x0062B25F+1,(DWORD)&m_Texture);
	SetDword(0x0062B32C+2,(DWORD)&m_Texture);
	SetDword(0x0062B4DF+1,(DWORD)&m_Texture);
	SetDword(0x006366DA+1,(DWORD)&m_Texture);
	SetDword(0x00642025+2,(DWORD)&m_Texture);
	SetDword(0x00642087+1,(DWORD)&m_Texture);
	SetDword(0x0064C350+1,(DWORD)&m_Texture);
	SetDword(0x006F28D3+1,(DWORD)&m_Texture);
	SetDword(0x006F3193+1,(DWORD)&m_Texture);
	SetDword(0x006F31A1+2,(DWORD)&m_Texture);
	SetDword(0x006F9E06+1,(DWORD)&m_Texture);
	SetDword(0x006FA2FB+1,(DWORD)&m_Texture);
	SetDword(0x006FA832+1,(DWORD)&m_Texture);

	SetDword(0x004074EB+2,(DWORD)&m_Texture->Width);
	SetDword(0x00414D88+2,(DWORD)&m_Texture->Width);
	SetDword(0x00414DBE+2,(DWORD)&m_Texture->Width);
	SetDword(0x00414E00+2,(DWORD)&m_Texture->Width);
	SetDword(0x00414E42+2,(DWORD)&m_Texture->Width);
	SetDword(0x00414ECF+2,(DWORD)&m_Texture->Width);
	SetDword(0x00415296+2,(DWORD)&m_Texture->Width);
	SetDword(0x004152EC+2,(DWORD)&m_Texture->Width);
	SetDword(0x005FA386+3,(DWORD)&m_Texture->Width);
	SetDword(0x006ED616+2,(DWORD)&m_Texture->Width);
	SetDword(0x006EE1D9+2,(DWORD)&m_Texture->Width);
	SetDword(0x006EE329+2,(DWORD)&m_Texture->Width);
	SetDword(0x006EEA3A+2,(DWORD)&m_Texture->Width);

	SetDword(0x00414DA3+2,(DWORD)&m_Texture->Height);
	SetDword(0x00414DDF+2,(DWORD)&m_Texture->Height);
	SetDword(0x00414E21+2,(DWORD)&m_Texture->Height);
	SetDword(0x00414E5D+2,(DWORD)&m_Texture->Height);
	SetDword(0x00414EFA+2,(DWORD)&m_Texture->Height);
	SetDword(0x00415358+2,(DWORD)&m_Texture->Height);
	SetDword(0x004153AE+2,(DWORD)&m_Texture->Height);
	SetDword(0x0048C08B+2,(DWORD)&m_Texture->Height);
	SetDword(0x00606F24+2,(DWORD)&m_Texture->Height);
	SetDword(0x006E9FFA+2,(DWORD)&m_Texture->Height);
	SetDword(0x006ED62E+2,(DWORD)&m_Texture->Height);
	SetDword(0x006EE1F7+2,(DWORD)&m_Texture->Height);
	SetDword(0x006EE347+2,(DWORD)&m_Texture->Height);
	SetDword(0x006EEA50+2,(DWORD)&m_Texture->Height);

	SetDword(0x004F915B+3,(DWORD)&m_Texture->Component);
	SetDword(0x004F9228+3,(DWORD)&m_Texture->Component);
	SetDword(0x004FA3A3+3,(DWORD)&m_Texture->Component);
	SetDword(0x004FA445+3,(DWORD)&m_Texture->Component);
	SetDword(0x00503B6E+3,(DWORD)&m_Texture->Component);
	SetDword(0x00503BB4+3,(DWORD)&m_Texture->Component);
	SetDword(0x00504CBD+3,(DWORD)&m_Texture->Component);
	SetDword(0x00504D03+3,(DWORD)&m_Texture->Component);
	SetDword(0x00506361+3,(DWORD)&m_Texture->Component);
	SetDword(0x00506391+3,(DWORD)&m_Texture->Component);
	SetDword(0x006430D8+3,(DWORD)&m_Texture->Component);
	SetDword(0x006ED643+3,(DWORD)&m_Texture->Component);
	SetDword(0x006F42B9+3,(DWORD)&m_Texture->Component);

	SetDword(0x00606F11+2,(DWORD)&m_Texture->Ref);

	SetDword(0x005FA173+2,(DWORD)&m_Texture+1732);
	SetDword(0x005FA71C+2,(DWORD)&m_Texture+1732);

	SetDword(0x005FA182+2,(DWORD)&m_Texture+1736);
	SetDword(0x005FA72A+2,(DWORD)&m_Texture+1736);

	SetDword(0x005FA2F3+3,(DWORD)&m_Texture+1740);
	SetDword(0x005FA7CF+3,(DWORD)&m_Texture+1740);

	SetDword(0x005FA2DC+1,(DWORD)&m_Texture+1741);
	SetDword(0x005FA7B8+1,(DWORD)&m_Texture+1741);

	SetDword(0x005FA193+2,(DWORD)&m_Texture+1746);
	SetDword(0x005FA2ED+2,(DWORD)&m_Texture+1746);
	SetDword(0x005FA73B+2,(DWORD)&m_Texture+1746);
	SetDword(0x005FA7C9+2,(DWORD)&m_Texture+1746);

	SetDword(0x005A3832+3,(DWORD)&m_Texture+1790);
}

void LoadItemModel(int index,char* folder,char* name) // OK
{
	if(name[0] == 0)
	{
		return;
	}

	char path[MAX_PATH]={ 0 };

	wsprintf(path,"Data\\%s",folder);

	pLoadItemModel(index,path,name,-1);
}

void LoadItemTexture(int index,char* folder) // OK
{
	pLoadItemTexture(index,folder,GL_REPEAT,GL_NEAREST,GL_TRUE);
}