#include "stdafx.h"
#include "Common.h"
#include "Attack.h"
#include "ItemMove.h"
#include "Notice.h"
#include "Offset.h"
#include "Protect.h"
#include "Protocol.h"
#include "Util.h"

char WindowName[128];

BYTE Joints[12920000]; // struct size to 5000 joints.

void InitCommon() // OK
{
	ChangeAddress(0x00618FBB + 2, (int)&Joints);
	ChangeAddress(0x006C4781 + 2, (int)&Joints);
	ChangeAddress(0x006CBA58 + 2, (int)&Joints);
	ChangeAddress(0x006CBB01 + 2, (int)&Joints);
	ChangeAddress(0x006D959D + 2, (int)&Joints);
	ChangeAddress(0x006D95F8 + 2, (int)&Joints);
	SetDword(0x00618FA9 + 3, 5000);
	SetDword(0x006C476B + 3, 5000);
	SetDword(0x006CBA42 + 3, 5000);
	SetDword(0x006CBAEF + 3, 5000);
	SetDword(0x006D958B + 3, 5000);
	SetDword(0x006D95E2 + 3, 5000);

	if(gProtect.m_MainInfo.IncreaseFPSSwitch != 0)
	{
		SetByte(0x00662716+6,32);
	}

	SetCompleteHook(0xE8,0x00661A9C,&CalcFPS);

	SetCompleteHook(0xE9,0x00403262,&CharacterCreationLevel);
	
	SetCompleteHook(0xE9,0x005430D2,&FixChasingAttackMovement);

	SetCompleteHook(0xE9,0x0066271F,&CheckTickCount);
}

void CalcFPS() // OK
{
	if(gProtect.m_MainInfo.IncreaseFPSSwitch != 0)
	{
		*(int*)0x0077ECE8 += 8;
	}

	((void(*)())0x004FFC66)();

	if(*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		ScrollNotice();

		RightClickMove();

		if(WindowName[0] == 0)
		{
			SetWindowText(*(HWND*)(MAIN_WINDOW),gProtect.m_MainInfo.WindowName);
		}
		else
		{
			SetWindowText(*(HWND*)(MAIN_WINDOW),WindowName);
		}

		if(CustomAttack != 0)
		{
			if((Attacking != -1 || MouseRButton || MouseRButtonPush) && !MouseOnWindow)
			{
				CustomAttack = 0;

				PBMSG_HEAD pMsg;

				pMsg.set(0x04,sizeof(pMsg));

				DataSend((BYTE*)&pMsg,pMsg.size);
			}
		}
	}
	else
	{
		ClearNotice();
		CustomAttack = 0;
		WindowName[0] = 0;
		SetWindowText(*(HWND*)(MAIN_WINDOW),gProtect.m_MainInfo.WindowName);
	}
}

__declspec(naked) void CharacterCreationLevel() // OK
{
	static DWORD CheckCreateClassAddress1 = 0x004032D3;
	static DWORD CheckCreateClassAddress2 = 0x00404090;
	
	_asm
	{
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*0+0x270]
		Call[CheckCreateClassAddress2]
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*1+0x270]
		Call[CheckCreateClassAddress2]
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*2+0x270]
		Call[CheckCreateClassAddress2]
		Movzx Edx,Byte Ptr Ds:[0x07B0274C]
		And Edx,0x04
		Sar Edx,0x02
		Push Edx
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*3+0x270]
		Call[CheckCreateClassAddress2]
		Movzx Edx,Byte Ptr Ds:[0x07B0274C]
		And Edx,0x02
		Sar Edx,0x01
		Push Edx
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*4+0x270]
		Call[CheckCreateClassAddress2]
		Jmp[CheckCreateClassAddress1]
	}
}

void __declspec(naked) FixChasingAttackMovement()
{
	static DWORD FixChasingAttackMovementAddress1 = 0x005430D9;
	static DWORD FixChasingAttackMovementAddress2 = 0x005567B0;

	_asm
	{
		Mov Byte Ptr[Edi+0x3B1],5
		Push Edi
		Push Edi
		Call[FixChasingAttackMovementAddress2]
		Add Esp,0x08
		Jmp[FixChasingAttackMovementAddress1]
	}
}

void __declspec(naked) CheckTickCount() // OK
{
	static DWORD CheckTickCountAddress1 = 0x00662725;

	_asm
	{
		Push 1
		Call Dword Ptr Ds:[Sleep]
		Call Dword Ptr Ds:[GetTickCount]
		Jmp[CheckTickCountAddress1]
	}
}