#include "stdafx.h"
#include "Monster.h"
#include "CustomMonster.h"
#include "Offset.h"
#include "Util.h"

void InitMonster() // OK
{
	SetByte(0x00513A8B,0xFF); // Monster Kill
	
	SetByte(0x00513A8C,0xFF); // Monster Kill

	SetCompleteHook(0xE8,0x0048E342,&CreateMonster);
	
	SetCompleteHook(0xE8,0x00531E90,&CreateMonster);
	
	SetCompleteHook(0xE8,0x00539A0D,&CreateMonster);
	
	SetCompleteHook(0xE8,0x005A2F91,&CreateMonster);
	
	SetCompleteHook(0xE8,0x0067AB1C,&CreateMonster);
	
	SetCompleteHook(0xE8,0x0067B81D,&CreateMonster);
	
	SetCompleteHook(0xE8,0x0067BFB5,&CreateMonster);
	
	SetCompleteHook(0xE8,0x00699CD7,&CreateMonster);

	//SetCompleteHook(0xE9,0x005133FA,&OnlyNpcChatProcess);
}

DWORD CreateMonster(int index,int x,int y,int key) // OK
{
	CUSTOM_MONSTER_INFO* lpInfo = gCustomMonster.GetInfoByIndex(index);

	if(lpInfo != 0)
	{
		index += MONSTER_BASE_MODEL;

		DWORD o = *(DWORD*)0x05801AE8 + 240 * index;

		if(lpInfo->Type == 0 || lpInfo->Type == 2)
		{
			if(*(short*)(o + 38) <= 0)
			{
				char path[MAX_PATH] = {0};

				wsprintf(path,"Data\\%s",lpInfo->FolderPath);

				pLoadItemModel(index,path,lpInfo->ModelName,-1);

				for(int n = 0;n < *(short*)(o + 38);++n)
				{
					*(float*)(*(DWORD*)(o + 48) + 16 * n + 4) = 0.25f;
				}
			}
		}
		else
		{
			if(*(short*)(o + 38) <= 0  && *(short*)(o + 36) <= 0)
			{
				char path[MAX_PATH] = {0};

				wsprintf(path,"Data\\%s",lpInfo->FolderPath);

				pLoadItemModel(index,path,lpInfo->ModelName,-1);

				if(*(short*)(o + 36) > 0)
				{
					*(float*)(*(DWORD*)(o + 48) + 4) = 0.25f;
					*(float*)(*(DWORD*)(o + 48) + 20) = 0.2f;
					*(float*)(*(DWORD*)(o + 48) + 36) = 0.34f;
					*(float*)(*(DWORD*)(o + 48) + 52) = 0.33f;
					*(float*)(*(DWORD*)(o + 48) + 68) = 0.33f;
					*(float*)(*(DWORD*)(o + 48) + 84) = 0.5f;
					*(float*)(*(DWORD*)(o + 48) + 100) = 0.55f;
					*(bool*)(*(DWORD*)(o + 48) + 96) = true;
				}
			}
		}

		if(*(short*)(o + 36) > 0)
		{
			pLoadItemTexture(index,lpInfo->FolderPath,GL_REPEAT,GL_NEAREST,GL_TRUE);
		}

		DWORD pCharacter = ((DWORD(*)(int,int,BYTE,BYTE,float))0x0052B5BE)(key,((lpInfo->Type>1)?641:index),x,y,0.0f);

		if(pCharacter)
		{
			memcpy((DWORD*)(pCharacter + 529),lpInfo->Name,sizeof(lpInfo->Name));

			*(DWORD*)(pCharacter + 942) = ((lpInfo->Effect!=-1)?lpInfo->Effect:index);

			*(BYTE*)(pCharacter + 188) = ((lpInfo->Type == 0 || lpInfo->Type == 2)?4:2);

			*(float*)(pCharacter + 12) = lpInfo->Scale;

			*(BYTE*)(pCharacter + 8) = 0;

			*(short*)(pCharacter + 988) = *(short*)(0x07B06B68);

			if(lpInfo->Type >= 2)
			{
				*(BYTE*)(pCharacter + 524) = lpInfo->NpcClass;

				*(BYTE*)(pCharacter + 941) = lpInfo->PKLevel;

				for(int n=0;n < 5;n++)
				{
					*(WORD*)(pCharacter + 592 + 32 * n) = (lpInfo->NpcClass & 7) + 8841 + 8 * n;
				}

				for(int n=0;n < MAX_SKIN_SLOT;n++)
				{
					if(lpInfo->SkinInfo[n].Use == true)
					{
						*(WORD*)(pCharacter + 592 + 32 * n) = lpInfo->SkinInfo[n].ItemIndex+ITEM_BASE_MODEL;
						*(BYTE*)(pCharacter + 594 + 32 * n) = lpInfo->SkinInfo[n].ItemLevel;
						*(BYTE*)(pCharacter + 595 + 32 * n) = lpInfo->SkinInfo[n].SetOption;
						*(BYTE*)(pCharacter + 596 + 32 * n) = lpInfo->SkinInfo[n].NewOption;
					}
				}

				((void(*)(DWORD))0x0052B72C)(pCharacter);
			}

			return pCharacter;
		}
	}

	return ((DWORD(*)(int,int,int,int))0x0052D92B)(index,x,y,key);
}

#define	CreateChat ((void(__cdecl*)(char*,char*,DWORD,int,int))0x005406B0)

void OnlyNpcChatProcess(DWORD c,DWORD o) // OK
{
	if(*(BYTE *)(o + 188) == 4 && (rand()%2) == 0)
    {
		switch(*(WORD*)(c + 942))
		{
			case 241: // Royal Guard Captain Lorence
				CreateChat((char*)(c+529),pGetTextLine(1976),c,0,-1);
				break;
			case 242: // Elf Lala
				CreateChat((char*)(c+529),pGetTextLine(1975),c,0,-1);
				break;
			case 253: // Potion Girl Amy
				if(*(int*)MAIN_CURRENT_MAP != 30)
				{
					CreateChat((char*)(c+529),pGetTextLine(1974),c,0,-1);
				}
				break;
			case 257: // Shadow Phantom Soldier
				CreateChat((char*)(c+529),pGetTextLine(1827),c,0,-1);
				break;
		}
	}
}