#include "stdafx.h"
#include "Util.h"
#include "QuickAccess.h"
#include "Offset.h"

CLoginWin gCLoginWin;

bool WriteString(const std::string& name, const std::string& value) 
{
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = value.size();

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_SZ, (CONST BYTE*)value.c_str(), dwSize);
	RegCloseKey(hKey);
	return true;
}

bool WriteDword(const std::string& name, DWORD value) 
{
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = sizeof(DWORD);

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_DWORD, (BYTE*)&value, dwSize);
	RegCloseKey(hKey);
	return true;
}

void CButtonAutoLogin(int This, int a2)
{
	CUIRenderText_SetFont((int)pTextThis(),*(int*)0x7AFEEA0);

	float startX = (640.0 - getX(329)) / 2;
	float startY = (480.0 - getY(245)) * 2.0 / 3.0;

	if (IsCursorInZone(startX + getX(246.0), startY + getY(156), 15, 15))
	{
		if (PressKey(VK_LBUTTON))
		{
			pRenderBitmap(151, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.02999999747, 0.5799999952, 0.3700000346, 1, 1, 0);
			gCLoginWin.savePass = !gCLoginWin.savePass;
			pPlayBuffer(25, 0, 0);
		}
	}
	if (gCLoginWin.savePass)
	{
		pRenderBitmap(151, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	else
	{
		pRenderBitmap(151, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.49999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
}

void DoRequestLogin()
{
	int Struct = *(DWORD*)0x7AFEE38;

	InputBox_GetText((Struct + 4), gCLoginWin.iUser, 11);
	InputBox_GetText((Struct + 240), gCLoginWin.iPassword, 11);

	if (gCLoginWin.savePass)
	{
		WriteString("ID", gCLoginWin.iUser);
		WriteString("PW", gCLoginWin.iPassword);
		WriteDword("SavePass", 1);
	}
	else
	{
		WriteDword("SavePass", 0);
	}

	RequestLogin(Struct);
}

void CLoginWin::DoLoginWinCreate(BYTE* This)
{
	int Struct = *(DWORD*)0x7AFEE38;
	
	LoginWinCreate(This);

	if (gCLoginWin.savePass)
	{
		InputBox_SetText((Struct + 4), gCLoginWin.iUser);
		InputBox_SetText((Struct + 240), gCLoginWin.iPassword);
	}
}

void TextLogin(int X, int Y, LPCTSTR Text)
{
	float startX = (640.0 - getX(329)) / 2;
	float startY = (480.0 - getY(245)) * 2.0 / 3.0;

	pDrawTextOut(pTextThis(), X, Y, Text, 0, 0, (PINT)1, 0);
	pDrawTextOut(pTextThis(), startX + getX(124), startY + getY(158), "Save password", getX(120), 0, (PINT)4, 0);
}

void CLoginWin::Load()

{	//read data
	HKEY hKey;
	DWORD dwDisp;
	DWORD dwSize;
	if (ERROR_SUCCESS == RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
	{
		dwSize = 11;
		if (RegQueryValueEx(hKey, "ID", 0, NULL, (LPBYTE)gCLoginWin.iUser, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(gCLoginWin.iUser, sizeof(gCLoginWin.iUser));
		}

		dwSize = 11;
		if (RegQueryValueEx(hKey, "PW", 0, NULL, (LPBYTE)gCLoginWin.iPassword, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(gCLoginWin.iPassword, sizeof(gCLoginWin.iPassword));
		}

		dwSize = sizeof(int);
		if (RegQueryValueEx(hKey, "SavePass", 0, NULL, (LPBYTE)&gCLoginWin.savePass, &dwSize) != ERROR_SUCCESS)
		{
			gCLoginWin.savePass = false;
		}
	}

	SetCompleteHook(0xE8, 0x0040A4F0, &TextLogin);
	SetCompleteHook(0xE8, 0x0040A2DB, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x0040A32B, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x0040A476, &CButtonAutoLogin);
	SetCompleteHook(0xE8, 0x00463A1F, &DoLoginWinCreate);
}