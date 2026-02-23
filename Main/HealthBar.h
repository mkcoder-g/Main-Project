#pragma once

#define MAX_MAIN_VIEWPORT 400

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
};

// --- INÍCIO DO CUSTOM RANK ---
struct CUSTOM_RANK_DATA
{
	WORD index;
	WORD rankIndex;
};

void ClearCustomRank();
void InsertCustomRank(WORD index, WORD rankIndex);
CUSTOM_RANK_DATA* GetCustomRank(WORD index);
// --- FIM DO CUSTOM RANK ---

void HealthBarToggle();
void ClearNewHealthBar();
void InsertNewHealthBar(WORD index, BYTE type, BYTE rate);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type);
void DrawNewHealthBar();

extern bool MonsterHPBarMode;