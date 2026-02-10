#pragma once

class cInterface
{
public:
	void Init();
	static void LoadImages();
	static void	Work();
	void ChangeWindowText();
	static void DrawSelectCharacter(HDC Hdc);
	static void DrawSelectServer(HDC Hdc);
	void LoadImagesType(int Type, char* Folder, int ImageID);
};

extern cInterface gInterface;