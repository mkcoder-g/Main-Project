#pragma once

#define MAX_MAIN_VIEWPORT 400
#define MAX_CUSTOM_RANK 10000 // NOVO: Limite ajustado para a escala real de IDs do GameServer

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
};

// --- INÍCIO DO CUSTOM RANK ---
void InsertCustomRank(WORD index, WORD rankIndex);
WORD GetCustomRank(WORD index);
// --- FIM DO CUSTOM RANK ---

void HealthBarToggle();
void ClearNewHealthBar();
void InsertNewHealthBar(WORD index, BYTE type, BYTE rate);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type);
void DrawNewHealthBar();

extern bool MonsterHPBarMode;