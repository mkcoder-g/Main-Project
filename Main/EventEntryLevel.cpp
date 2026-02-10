#include "stdafx.h"
#include "EventEntryLevel.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"

void InitEventEntryLevel() // OK
{
	MemoryCpy(0x007586FC,gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelCommon));

	MemoryCpy(0x00758734,gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_BloodCastleEntryLevelSpecial));

	MemoryCpy(0x0075869C,gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelCommon));

	MemoryCpy(0x007586CC,gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_DevilSquareEntryLevelSpecial));

	MemoryCpy(0x0075876C,gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelCommon));

	MemoryCpy(0x0075879C,gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_ChaosCastleEntryLevelSpecial));

	MemoryCpy(0x007582B0,gProtect.m_MainInfo.m_KalimaEntryLevelCommon,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelCommon));

	MemoryCpy(0x007582E8,gProtect.m_MainInfo.m_KalimaEntryLevelSpecial,sizeof(gProtect.m_MainInfo.m_KalimaEntryLevelSpecial));

	SetDword(0x005B5F8D,0x270F); // Chaos Castle MaxLevel

	SetDword(0x004D9487,0x270F); // Kalima MaxLevel

	SetDword(0x00667180+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[0]);

	SetDword(0x00667187+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[1]);

	SetDword(0x0066718E+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[2]);

	SetDword(0x00667195+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[3]);

	SetDword(0x0066719C+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[4]);

	SetDword(0x006671A3+6,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[0]);

	SetDword(0x006671AD+6,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[1]);

	SetDword(0x006671B7+6,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[2]);

	SetDword(0x006671C1+6,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[3]);

	SetDword(0x006671CB+3,gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[4]);

	SetCompleteHook(0xE8,0x00666BEC,&CheckIllusionTemple);

	SetCompleteHook(0xE8,0x00666E08,&CheckIllusionTemple);

	SetCompleteHook(0xE8,0x006670F6,&CheckIllusionTemple);
}

bool CheckIllusionTemple(int* value)
{
	STRUCT_DECRYPT

	WORD Level = *(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E);

	STRUCT_ENCRYPT

	for(int n=0;n < 5;n++)
	{
		if(Level >= gProtect.m_MainInfo.m_IllusionTempleEntryLevelMin[n] && Level <= gProtect.m_MainInfo.m_IllusionTempleEntryLevelMax[n])
		{
			(*value) = n+1;
			return 1;
		}
	}

	return 0;
}