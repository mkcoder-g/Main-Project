
#pragma once

class CLoginWin
{
public:
	void Load();
	static void __thiscall DoLoginWinCreate(BYTE* This);
public:
	BOOL savePass;
	char iUser[32];
	char iPassword[32];
};
extern CLoginWin gCLoginWin;