#include "stdafx.h"
#include "WindowTime.h"
#include "CustomMessage.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

std::vector<EVENT_TIME_INFO> m_EventTimeInfo;

void InitWindowTime() // OK
{
	if(gProtect.m_MainInfo.WindowEventTimeSwitch == 0)
	{
		return;
	}

	SetCompleteHook(0xE9,0x00601DB0,&DrawWindowTime);

	SetCompleteHook(0xE9,0x005EF010,&ControlWindowTime);
}

void WindowButtonToggle() // OK
{
	if(gProtect.m_MainInfo.WindowEventTimeSwitch == 0)
	{
		return;
	}

	if(*(BYTE*)0x0076EFC9 || *(BYTE*)0x075AE938)
	{
		return;
	}

	if(CheckWindow(WINDOWS_MOVING_SERVER))
	{
		CloseWindow(WINDOWS_MOVING_SERVER);
	}
	else
	{
		OpenWindow(WINDOWS_MOVING_SERVER);

		PBMSG_HEAD pMsg;

		pMsg.set(0x06,sizeof(pMsg));

		DataSend((BYTE*)&pMsg,pMsg.size);
	}
}

void DrawWindowTime() // OK
{
	//WindowRenderText(15, 15, true, 8, 0, "Mouse [X: %d] [Y: %d]", pCursorX, pCursorY);

	if(CheckWindow(WINDOWS_MOVING_SERVER))
	{
		pDrawImage(260, WINDOW_POSX, WINDOW_POSY, 190.0f, 256.0f, 0.0f, 0.0f, 0.7421875f, 1, 1, 1, 0.0f);

		pDrawImage(261, WINDOW_POSX, WINDOW_POSY + 256, 190.0f, 177.0f, 0.0f, 0.0f, 0.7421875f, 0.69140625, 1, 1, 0.0f);

		pDrawImage(280, CLOSE_BT_POSX, CLOSE_BT_POSY, 24.0f, 24.0f, 0.0f, 0.0f, 24.0f / 32.0f, 24.0f / 32.0f, 1, 1, 0.0f);

		WindowRenderText((int)WINDOW_POSX + 95, 15, pFontBold, 8, 0, gCustomMessage.GetMessage(33));

		int count = 0;

		for each(EVENT_TIME_INFO lpInfo in m_EventTimeInfo)
		{
			EnableAlphaTest(true);

			glColor4f(0.0f, 0.0f, 0.0f, 0.55f);

			pDrawBarForm((float)WINDOW_POSX + 19, (float)WINDOW_POSY + 48 + (10 * count), 152, 8);

			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

			pTextureBlind();

			DisableAlphaBlend();

			WindowRenderText(WINDOW_POSX + 20, WINDOW_POSY + 52 + (10 * count), pFontBold, 0, 0, "%s", lpInfo.name);

			WindowRenderText(WINDOW_POSX + 170, WINDOW_POSY + 52 + (10 * count), pFontNormal, 7, GetEventRenderColor(lpInfo.status, lpInfo.time), "%s", GetEventRemainTime(lpInfo.status, lpInfo.time));

			count++;
		}

		if(pMouseOnZone(CLOSE_BT_POSX, CLOSE_BT_POSY, 24, 24, 1))
		{
			pRenderTipText(CLOSE_BT_POSX + 2, CLOSE_BT_POSY-13, gCustomMessage.GetMessage(39));
		}
	}
}

void ControlWindowTime() // OK
{
	if(CheckWindow(WINDOWS_MOVING_SERVER))
	{
		if(pMouseOnZone(WINDOW_POSX, WINDOW_POSY, 190, 433, 1))
		{
			MouseOnWindow = true;

			if(pMouseOnZone(CLOSE_BT_POSX, CLOSE_BT_POSY, 24, 24, 1) && MouseLButtonPush)
			{
				MouseLButtonPush = 0;

				MouseUpdateTime = 0;
				MouseUpdateTimeMax = 6;

				pPlayBuffer(25, 0, 0);

				CloseWindow(WINDOWS_MOVING_SERVER);
			}
		}
	}
}

void WindowRenderText(int x,int y,HFONT fold,int align,int color,char* text,...) // OK
{
	char buff[256];

	memset(buff, 0, sizeof(buff));

	va_list arg;
	va_start(arg, text);
	vsprintf_s(buff, text, arg);
	va_end(arg);

	SIZE sz;

	GetTextExtentPoint(pGetFontDC(pTextThis()), buff, strlen(buff), &sz);

	int py = (y - (480 * sz.cy / *(DWORD*)MAIN_RESOLUTION_Y >> 1));

	EnableAlphaTest(true);

	pSetTextFont(pTextThis(),fold);

	pSetBGTextColor(pTextThis(), 0, 0, 0, 0);

	if(color == 0)
	{
		pSetTextColor(pTextThis(), 220, 220, 220, 255);
	}
	else if(color == 1)
	{
		pSetTextColor(pTextThis(), 223, 191, 103, 255);
	}
	else if(color == 2)
	{
		pSetTextColor(pTextThis(), 230, 5, 5, 255);
	}
	else if(color == 3)
	{
		pSetTextColor(pTextThis(), 73, 183, 0, 255);
	}
	else if(color == 4)
	{
		pSetTextColor(pTextThis(), 100, 150, 255, 255);
	}

	pDrawText(pTextThis(), x, py, buff, 0, 0, align, 0);
}

int GetEventRenderColor(int status, int time) // OK
{
	int color = 1;

	if(status == EVENT_STATE_BLANK)
	{
		color = 2;
	}
	else if(status == EVENT_STATE_STAND)
	{
		if(time >= 0 && time <= 300)
		{
			color = 2;
		}
	}
	else if(status == EVENT_STATE_OPEN)
	{
		color = 3;
	}
	else if(status == EVENT_STATE_START)
	{
		color = 4;
	}

	return color;
}

char* GetEventRemainTime(int status,int time) // OK
{
	static char buff[256];

	memset(buff, 0, sizeof(buff));

	if(status == EVENT_STATE_BLANK)
	{
		sprintf_s(buff, gCustomMessage.GetMessage(34));
	}
	else if(status == EVENT_STATE_STAND)
	{
		int day = time/86400;
		time %= 86400;

		int hr = time/3600;
		time %= 3600;

		int min = time/60;
		time %= 60;

		if(day > 0)
		{
			sprintf_s(buff, gCustomMessage.GetMessage(35), day);
		}
		else
		{
			sprintf_s(buff, gCustomMessage.GetMessage(36), hr, min, time);
		}
	}
	else if(status == EVENT_STATE_OPEN)
	{
		sprintf_s(buff, gCustomMessage.GetMessage(37));
	}
	else if(status == EVENT_STATE_START)
	{
		sprintf_s(buff, gCustomMessage.GetMessage(38));
	}

	return buff;
}

void GCEventTimeListRecv(PMSG_EVENT_TIME_LIST_RECV* lpMsg) // OK
{
	m_EventTimeInfo.clear();

	if(CheckWindow(WINDOWS_MOVING_SERVER))
	{
		for(int n = 0; n < lpMsg->count; n++)
		{
			EVENT_TIME_INFO* lpInfo = (EVENT_TIME_INFO*)(((BYTE*)lpMsg) + sizeof(PMSG_EVENT_TIME_LIST_RECV) + (sizeof(EVENT_TIME_INFO)*n));

			EVENT_TIME_INFO info;

			strcpy_s(info.name, lpInfo->name);

			info.status = lpInfo->status;

			info.time = lpInfo->time;

			m_EventTimeInfo.push_back(info);
		}
	}
}