#include "stdafx.h"
#include "HealthBar.h"
#include "CustomMessage.h"
#include "Offset.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Util.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];
WORD gCustomRankData[MAX_CUSTOM_RANK] = { 0 }; // Array otimizado (Sem necessidade de structs)

bool MonsterHPBarMode = 0;

void HealthBarToggle() // OK
{
	if (*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		MonsterHPBarMode ^= 1;

		pDrawMessage(gCustomMessage.GetMessage(4 + MonsterHPBarMode), 1);
	}
}

// --- FUNÇÕES DO CUSTOM RANK (OTIMIZADAS) ---
void InsertCustomRank(WORD index, WORD rankIndex)
{
	// Acesso direto na memória, sem loops que causam Lag/Bugs!
	if (index < MAX_CUSTOM_RANK)
	{
		gCustomRankData[index] = rankIndex;
	}
}

WORD GetCustomRank(WORD index)
{
	if (index < MAX_CUSTOM_RANK)
	{
		return gCustomRankData[index];
	}
	return 0;
}
// ------------------------------

void ClearNewHealthBar() // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
	}
}

void InsertNewHealthBar(WORD index, BYTE type, BYTE rate) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = index;
			gNewHealthBar[n].type = type;
			gNewHealthBar[n].rate = rate;
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

void DrawNewHealthBar() // OK
{
	((void(*)())0x0059E7A0)();

	if (MonsterHPBarMode != 0)
	{
		return;
	}

	DWORD ViewportAddress;
	NEW_HEALTH_BAR* lpHealthBar;
	float Angle[3];
	int PosX, PosY;
	float LifeBarWidth = 50.0f;
	char LifeDisplay[64];

	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		ViewportAddress = pViewportAddress + (n * 0x47C);

		if (!ViewportAddress)
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress) == 0)
		{
			continue;
		}

		Angle[0] = *(float*)(ViewportAddress + 0x10);
		Angle[1] = *(float*)(ViewportAddress + 0x14);
		Angle[2] = *(float*)(ViewportAddress + 0x16C) + *(float*)(ViewportAddress + 0x18) + 100.0f;

		pGetPosFromAngle(Angle, &PosX, &PosY);
		PosX -= (int)floor((double)LifeBarWidth / 2.0);

		// ==========================================
		// DESENHO DA PATENTE NA TELA (CUSTOM RANK)
		// ==========================================
		WORD ObjectIndex = *(WORD*)(ViewportAddress + 0x22C);
		WORD rankIndex = GetCustomRank(ObjectIndex);

		// Trava de segurança: só desenha se o ID for de 1 a 15
		if (rankIndex > 0 && rankIndex <= 15)
		{
			char rankName[32];

			switch (rankIndex)
			{
			case 1: wsprintf(rankName, "Recruta"); break;
			case 2: wsprintf(rankName, "Aprendiz"); break;
			case 3: wsprintf(rankName, "Soldado"); break;
			case 4: wsprintf(rankName, "Cabo"); break;
			case 5: wsprintf(rankName, "Sargento"); break;
			case 6: wsprintf(rankName, "Tenente"); break;
			case 7: wsprintf(rankName, "Capitão"); break;
			case 8: wsprintf(rankName, "Major"); break;
			case 9: wsprintf(rankName, "Ten. Coronel"); break;
			case 10: wsprintf(rankName, "Coronel"); break;
			case 11: wsprintf(rankName, "General"); break;
			case 12: wsprintf(rankName, "Marechal"); break;
			case 13: wsprintf(rankName, "Gladiador"); break;
			case 14: wsprintf(rankName, "Grande Herói"); break;
			case 15: wsprintf(rankName, "Supremo"); break;
			}

			EnableAlphaTest(true);
			EnableAlphaBlend(); // Ativa a transparência nativa do TGA
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // Restaura as cores reais da imagem

			// 1. DESENHA A IMAGEM (ÍCONE À ESQUERDA)
			float imgSize = 12.0f; // <-- REDUZIDO DE 16.0f PARA 12.0f (Mude este número se quiser menor ainda, ex: 10.0f)

			// Ajustei a posição X para -24 para que ele fique um pouquinho mais perto do texto
			float imgX = (float)PosX + (LifeBarWidth / 2.0f) - 20.0f;

			// Ajustei a posição Y para -19 para manter o ícone centralizado na altura da letra
			float imgY = (float)PosY - 21.0f;

			pRenderBitmap(9000 + rankIndex, imgX, imgY, imgSize, imgSize, 0.0f, 0.0f, 1.0f, 1.0f, 1, 1, 0.0f);

			// 2. DESENHA O TEXTO
			pSetTextFont(pTextThis(), pFontNormal);
			pSetTextColor(pTextThis(), 255, 215, 0, 255);
			pSetBGTextColor(pTextThis(), 0, 0, 0, 0);

			// Empurra o texto um pouquinho para a direita (+8 pixels) para não atropelar a imagem
			pDrawText(pTextThis(), (PosX + (int)(LifeBarWidth / 2)) + 8, PosY - 20, rankName, 0, 0, 8, 0);
		}

		lpHealthBar = GetNewHealthBar(ObjectIndex, *(BYTE*)(ViewportAddress + 0xBC));

		if (lpHealthBar == 0)
		{
			continue; // Se não tiver barra de vida, pula essa parte, mas já desenhou o Rank!
		}

		if ((pCursorX >= PosX) && (pCursorX <= PosX + (int)LifeBarWidth) && (pCursorY >= PosY - 2) && (pCursorY < PosY + 6))
		{
			EnableAlphaTest(true);
			wsprintf(LifeDisplay, "%s: %d%%", (char*)(ViewportAddress + 529), lpHealthBar->rate);
			pSetTextFont(pTextThis(), pFontNormal);
			pSetBGTextColor(pTextThis(), 0, 0, 0, 192);
			pSetTextColor(pTextThis(), 255, 255, 255, 255);
			pDrawText(pTextThis(), (PosX + (int)(LifeBarWidth / 2)), PosY - 8, LifeDisplay, 0, 0, 8, 0);
		}

		EnableAlphaTest(true);
		glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
		pDrawBarForm((float)PosX, (float)PosY, LifeBarWidth, 6.0f);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		pDrawBarForm((float)PosX + 2, (float)PosY + 2, ((LifeBarWidth - 4) * lpHealthBar->rate) / 100, 2.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glEnable(GL_TEXTURE_2D);
		DisableAlphaBlend();
	}
}