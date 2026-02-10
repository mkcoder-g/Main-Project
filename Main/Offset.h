#pragma	once

#define	MAIN_WINDOW				0x07AFEE84
#define	MAIN_CONNECTION_STATUS	0x07B06BD0
#define	MAIN_SCREEN_STATE		0x0077EBAC
#define	MAIN_CHARACTER_STRUCT	0x074D2C58
#define	MAIN_VIEWPORT_STRUCT	0x074D2B2C
#define	MAIN_PACKET_SERIAL		0x07B06BCB
#define	MAIN_FONT_SIZE			0x07513340
#define	MAIN_RESOLUTION			0x07AFEC78
#define	MAIN_RESOLUTION_X		0x0077E350
#define	MAIN_RESOLUTION_Y		0x0077E354
#define	MAIN_PARTY_MEMBER_COUNT	0x07672E50
#define	MAIN_CURRENT_MAP		0x0077038C
#define	MAIN_HOOK_RECV			0x007565D4
#define	MAIN_HOOK_SEND			0x007565E4
#define MAIN_ACTIVE_SOCKET		0x07B02978
#define MAIN_STRUCT_SERIAL		0x074D2C5C
#define MAIN_HASH_CLASS			0x07AFEA08

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x0040B3C0)((void*)MAIN_HASH_CLASS,*(void**)MAIN_STRUCT_SERIAL);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x0040B460)((void*)MAIN_HASH_CLASS,*(void**)MAIN_STRUCT_SERIAL);

#define	ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x0069C3C0)
#define	pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x00641E33)
#define	pCursorX				*(int*)0x07AFE950
#define	pCursorY				*(int*)0x07AFE94C
#define	pTextThis				((LPVOID(*)())0x0041FD65)
#define	pDrawText				((int(__thiscall*)(LPVOID,int,int,char*,int,int,int,int))0x00420024)
#define	pDrawBarForm			((void(__cdecl*)(float,float,float,float))0x006437A7)
#define	pDrawBigText			((void(*)(float,float,DWORD,float,float))0x006435D6)
#define	pDrawImage				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x006438B4)
#define	pDrawMessage			((int(__cdecl*)(char*,int))0x0053E1B0)
#define	pLoadItemModel			((void(*)(int,char*,char*,int))0x0062B803)
#define	pLoadItemTexture		((void(*)(int,char*,int,int,int))0x0062B387)

#define pWindowThis				*(DWORD*)0x07AFEE60
#define CheckWindow(x)			((bool(__thiscall*)(DWORD,int))0x0045E06F)(pWindowThis,x)
#define CloseWindow(x)			((bool(__thiscall*)(DWORD,int,int))0x0045F582)(pWindowThis,x,0)
#define OpenWindow(x)			((bool(__thiscall*)(DWORD,int,int))0x0045E696)(pWindowThis,x,0)

#define pViewportAddress		*(DWORD*)(0x074D2B28)
#define pPetMixIndex			*(BYTE*)(0x007C7184)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD))0x004EC12D)(0x88*((DWORD(__thiscall*)(DWORD*))0x004ED5D8)(&*(DWORD*)(0x007C5D20))+0x007C5D24)

#define Color3f(r,b,g)			((g<<16)+(b<<8)+r)
#define Color4f(r,b,g,o)		((o<<24)+(g<<16)+(b<<8)+r)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x0062392F)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x005020D9)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x006EE878)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x006DA9C1))
#define pCreateEffect			((void(__cdecl*)(int,float*,float*,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x006A7FB0)

#define pGetTextLine(x)			(((char*(__thiscall*)(void*,int))0x00402260)(((void(*)())0x00750DF88),x))

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x006A4C2D)
#define	pSetTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041FF35)
#define	pSetBGTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041FF97)
#define pSetTextFont			((void(__thiscall*)(LPVOID,HFONT))0x0041FFF9)
#define pLoadImageJPG			((bool(__cdecl*)(char*,GLuint,GLuint,GLuint,bool,bool))0x006F9D4F)
#define pLoadImageTGA			((bool(__cdecl*)(char*,GLuint,GLuint,GLuint,bool,bool))0x006FA244)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x006A4FB5)
#define pRenderTipText			((void(*)(int,int,char*))0x0053DEB0)
#define pMouseOnZone			((int(__cdecl*)(int,int,int,int,int))0x00416686)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x00643A89)
#define pSetPlayerStop			((void(*)(DWORD))0x00509D09)

#define pGetFontDC				((HDC(__thiscall*)(LPVOID)) 0x0041FE93)
#define pFontNormal				*(HFONT*)0x07AFEE94
#define pFontBold				*(HFONT*)0x07AFEE98
#define pFontBig				*(HFONT*)0x07AFEE9C
#define pFontFixed				*(HFONT*)0x07AFEEA0

#define	EnableLightMap			((void(*)())0x00642553)
#define	EnableAlphaBlend		((void(*)())0x00642323)
#define	EnableAlphaBlend2		((void(*)())0x00642438)
#define	EnableAlphaBlendMinus	((void(*)())0x006423AC)
#define	EnableAlphaTest			((void(*)(bool))0x00642288)
#define	DisableAlphaBlend		((void(*)())0x00642209)

#define ITEM_BASE_MODEL			649

#define GET_ITEM(x,y)			(((x)*512)+(y))
#define GET_ITEM_MODEL(x,y)		((((x)*512)+(y))+ITEM_BASE_MODEL)
#define GET_ITEM_OPT_LEVEL(x)	((x>>3)&15)
#define GET_ITEM_OPT_EXC(x)		((x)-(x&64))
#define GET_MAX_WORD_VALUE(x)	(((x)>65000)?65000:((WORD)(x)))

#define pTextureBlind			((void(__cdecl*)())0x0064388A)
#define MouseLButton			*(bool*)0x07AFE998
#define MouseRButton			*(bool*)0x07AFE980
#define MouseLButtonPush		*(bool*)0x07AFE7F8
#define MouseRButtonPush		*(bool*)0x07AFE9A4
#define MouseLButtonPop			*(bool*)0x07AFE810
#define MouseRButtonPop			*(bool*)0x07AFE964
#define MouseUpdateTime			*(int*)0x075AE8E0
#define MouseUpdateTimeMax		*(int*)0x0076EF40

#define EventChipDialogEnable	*(int*)0x07672F08
#define ErrorMessage			*(int*)0x07B02758
#define MouseOnWindow			*(bool*)0x07513354

#define GetInventoryItemCount	((int(__cdecl*)(int,int))0x00541F40)

#define Attacking				*(int*)0x0076EFAC

#define AskYesOrNo				*(int*)0x07672F1C


#define Sprite_SetPosition		((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x004150DE)
#define pSetBlend				((void(__cdecl*)(BYTE))0x00642288)
#define CUIRenderText_SetFont	((int(__thiscall*)(int This, int a2)) 0x0041FFF9)
#define pTextThis				((LPVOID(*)())0x0041FD65)
#define g_fScreenRate_x			*(float*)0x0078F5C8
#define TransFormX(a)			(a / g_fScreenRate_x)
#define pBackgroundTextColor	((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x0041FF97)
#define pSetTextColor			((void(__thiscall*)(LPVOID, BYTE, BYTE, BYTE, BYTE))0x0041FF35)
#define InputBox_SetText		((void(__thiscall*)(int thisa, const char* pszText)) 0x42153C)
#define InputBox_GetText		((void(__thiscall*)(int thisa, LPSTR lpString, int nMaxCount)) 0x0042150F)
#define RequestLogin			((int(__thiscall*)(int This)) 0x0040A631)
#define pDrawTextOut			((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int size, int nTabPositions, LPINT lpnTabStopPositions, LPSIZE nTabOrigin)) 0x00420024)
#define LeftClick				*(BYTE *)0x7AFE998
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x006A4FB5)
#define PressKey				((char(__cdecl*)(int vKey)) 0x0053D8E0)
#define pRenderBitmap			((void(__cdecl*)(int Texture, float x, float y, float Width, float Height, float u, float v, float uWidth, float vHeight, bool Scale, bool StartScale, float Alpha)) 0x006438B4)
#define LoginWinCreate			((void(__thiscall*)(BYTE* This)) 0x00409ECD)
#define Instance				((int(*)()) 0x00463272)
#define g_fScreenRate_x			*(float *)0x0078F5C8
#define g_fScreenRate_y			*(float *)0x0078F5CC
#define TransFormX(a)			(a / g_fScreenRate_x)
#define TransFormY(a)			(a / g_fScreenRate_y)
#define pWinWidth				*(GLsizei*)0x077E350
#define pWinHeight				*(GLsizei*)0x0077E354

#define INVENTORY_WEAR_SIZE 12
#define GetChangeUp(x) (((x>>4)&0x01)?3:(((x>>3)&0x01)?2:1))
#define PointerDeleteItem ((void(__cdecl*)(int,WORD*,int))0x005BE1B0)
#define SendRequestEquipmentItem ((bool(_cdecl*)(int,int,int,int))0x004F28E0)
#define DeleteEquippingEffect ((void(*)(DWORD))0x0052B8BF)
#define DeleteBugOrPet ((void(*)(DWORD))0x004E54E0)
#define DeletePetRaven ((void(*)(DWORD))0x004AA62A)
#define DeleteWingEffect ((void(_cdecl*)(DWORD,DWORD,int))0x0051249A)
#define GetItemEquiped(x) (*(DWORD*)(MAIN_STRUCT_SERIAL)+(2932+(68*x)))
#define GetItemEquipedIndex(x) (*(WORD*)(GetItemEquiped(x)))
#define InventoryMap (&*(WORD*)0x07671100)
#define InventoryBackup *(DWORD*)(0x07672DC0)
#define EquipmentItem *(bool*)(0x007672F41)
#define PointerSlot *(DWORD*)(0x0766DF8C)
#define ItemTarget *(DWORD*)(0x07672EB0)
#define PickedItem *(DWORD*)(0x07641800)
#define SlotType *(DWORD*)(0x07672F30)
#define InventorySlot *(DWORD*)(0x07672F34)
#define ItemSelect *(WORD*)(0x07641D90)
#define RenderBitmap      ((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x006438B4)

enum eWindowsType
{
	WINDOWS_NONE				= 0,
	WINDOWS_FRIEND_LIST			= 1,
	WINDOWS_MOVE_LIST			= 2,
	WINDOWS_PARTY				= 3,
	WINDOWS_QUEST				= 4,
	WINDOWS_GUILD				= 5,
	WINDOWS_TRADE				= 6,
	WINDOWS_WAREHOUSE			= 7,
	WINDOWS_UNKNOWN_1			= 8,
	WINDOWS_CHAOS_MIX			= 9,
	WINDOWS_COMMAND				= 10,
	WINDOWS_PET					= 11,
	WINDOWS_STORE				= 12,
	WINDOWS_DEVIL_SQUARE		= 13,
	WINDOWS_MOVING_SERVER		= 14,
	WINDOWS_BLOOD_CASTLE		= 15,
	WINDOWS_PET_TRAINER			= 16,
	WINDOWS_SHOP				= 17,
	WINDOWS_STORE_OTHER			= 18,
	WINDOWS_GUILD_MASTER		= 19,
	WINDOWS_GUARDMAN_SIEGUE		= 20,
	WINDOWS_SENIOR_MIX			= 21,
	WINDOWS_GUARDMAN_LAND		= 22,
	WINDOWS_CATAPULT_INVADING	= 23,
	WINDOWS_CATAPULT_DEFENDING	= 24,
	WINDOWS_CASTLE_GATE_SWITCH	= 25,
	WINDOWS_CHARACTER			= 26,
	WINDOWS_INVENTORY			= 27,
	WINDOWS_REFINERY			= 28,
	WINDOWS_REFINERY_WARNING	= 29,
	WINDOWS_KANTURU_GATE		= 30,
	WINDOWS_WEREWOLF			= 31,
	WINDOWS_ILLUSION_TEMPLE1	= 32,
	WINDOWS_ILLUSION_TEMPLE2	= 34,
};

struct CHARACTER_ATTRIBUTE
{
	char Name[11];
	BYTE Class;
	BYTE Skin;
	WORD Level;
	DWORD Experience;
	DWORD NextExperince;
	WORD Strength;
	WORD Dexterity;
	WORD Vitality;
	WORD Energy;
	WORD Leadership;
	WORD Life;
	WORD Mana;
	WORD LifeMax;
	WORD ManaMax;
	WORD Shield;
	WORD ShieldMax;
	WORD AttackRatingPK;
	WORD SuccessfulBlockingPK;
	WORD AddStrength;
	WORD AddDexterity;
	WORD AddVitality;
	WORD AddEnergy;
	WORD AddLifeMax;
	WORD AddManaMax;
	WORD AddLeadership;
	WORD SkillMana;
	WORD SkillManaMax;
	BYTE Ability;
	WORD AbilityTime[3];
	short AddPoint;
	short MaxAddPoint;
	WORD MinusPoint;
	WORD MaxMinusPoint;
	WORD AttackSpeed;
	WORD AttackRating;
	WORD AttackDamageMinRight;
	WORD AttackDamageMaxRight;
	WORD AttackDamageMinLeft;
	WORD AttackDamageMaxLeft;
	WORD MagicSpeed;
	WORD MagicDamageMin;
	WORD MagicDamageMax;
	WORD CriticalDamage;
	WORD SuccessfulBlocking;
	WORD Defense;
	WORD MagicDefense;
	WORD WalkSpeed;
	WORD LevelUpPoint;
};