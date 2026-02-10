#include "stdafx.h"
#include "Effect.h"
#include "Offset.h"
#include "Util.h"

void InitEffect()
{
	SetCompleteHook(0xE9,0x006A0A10,&RegisterBuff);

	SetCompleteHook(0xE9,0x006A1210,&UnRegisterBuff);
}

void RegisterBuff(eEffectNumber buff,DWORD o) // OK
{
	#pragma region STRUCT

	WORD Type = *(WORD*)(o + 2);

	float Position[3], Angle[3], Light[3];

	VectorCopy ((float*)o + 16, Position);
	VectorCopy ((float*)o + 28, Angle);
	VectorCopy ((float*)o + 296, Light);

	#pragma endregion

	#pragma region SECTION ONE (Complete)

	if(FindEffect(buff,STATE_POISON) != 0)
	{
		InsertEffect(o,STATE_POISON);
	}

	if(FindEffect(buff,STATE_FREEZE) != 0)
	{
		InsertEffect(o,STATE_FREEZE);
	}

	if(FindEffect(buff,STATE_ATTACK) != 0)
	{
		InsertEffect(o,STATE_ATTACK);
	}

	if(FindEffect(buff,STATE_DEFENSE) != 0)
	{
		InsertEffect(o,STATE_DEFENSE);
	}

	if(FindEffect(buff,STATE_ADD_LIFE) != 0)
	{
		InsertEffect(o,STATE_ADD_LIFE);

		if(Type == MODEL_PLAYER)
		{
			DeleteEffect(BITMAP_LIGHT, o, 1);
			pCreateEffect(BITMAP_LIGHT, Position, Angle, Light, 1, o, -1, 0, 0, 0, 0);
		}
	}

	if(FindEffect(buff,STATE_HARDEN) != 0)
	{
		InsertEffect(o,STATE_HARDEN);

		VectorCopy((float*)o + 28, Angle);

		DeleteEffect (MODEL_ICE,o,1);
		pCreateEffect(MODEL_ICE, Position, Angle, Light, 1, o, -1, 0, 0, 0, 0);
			
		Angle[2] += 180.f;
		pCreateEffect(MODEL_ICE, Position, Angle, Light, 2, o, -1, 0, 0, 0, 0);

		VectorCopy((float*)o + 28, Angle);
	}

	if(FindEffect(buff,STATE_REDUCE_DEFENSE) != 0)
	{
		InsertEffect(o,STATE_REDUCE_DEFENSE);

		Vector ( 1.f, 1.f, 1.f, Light );

		DeleteEffect(BITMAP_SKULL,o,0);
		pCreateEffect(BITMAP_SKULL, Position, Angle, Light, 0, o, -1, 0, 0, 0, 0);

		pPlayBuffer(133,o,0);
	}

	if(FindEffect(buff,STATE_REDUCE_ATTACKDAMAGE) != 0)
	{
		InsertEffect(o,STATE_REDUCE_ATTACKDAMAGE);
	}

	#pragma endregion

	#pragma region SECTION TWO (Complete)

	if(FindEffect(buff,STATE_REDUCE_MAGICDEFENSE) != 0) 
	{
		InsertEffect(o,STATE_REDUCE_MAGICDEFENSE);

		if(Type == MODEL_PLAYER)
		{
			pPlayBuffer(132,0,0);
			DeleteJoint(MODEL_SPEARSKILL, o, 0);

			for ( int j = 0; j < 5; ++j)
			{
				CreateJoint(MODEL_SPEARSKILL, Position, Position, Angle, 0, o, 50.0, -1, 0, 0, -1, 0);
			}
		}
	}

	if(FindEffect(buff,STATE_REDUCE_MAGICPOWER) != 0)
	{
		InsertEffect(o,STATE_REDUCE_MAGICPOWER);
	}

	if(FindEffect(buff,STATE_ADD_AG) != 0)
	{
		InsertEffect(o,STATE_ADD_AG);

		DeleteEffect(BITMAP_LIGHT, o, 2);
		pCreateEffect(BITMAP_LIGHT, Position, Angle, Light, 2, o, -1, 0, 0, 0, 0);
	}

	if(FindEffect(buff,STATE_ADD_CRITICAL_DAMAGE) != 0)
	{
		InsertEffect(o,STATE_ADD_CRITICAL_DAMAGE);
	}

	#pragma endregion

	#pragma region SECTION THREE (Complete)

	if(FindEffect(buff,STATE_ADD_GM_MARK) != 0)
	{
		InsertEffect(o,STATE_ADD_GM_MARK);
	}

	#pragma endregion

	#pragma region SECTION FOUR (Complete)

	if(FindEffect(buff,STATE_STUNED) != 0)
	{
		InsertEffect(o,STATE_STUNED);

		DeleteEffect(BITMAP_SKULL,o,5);

		Vector ( 0.f, 0.f, 90.f, Angle );
		CreateJoint(MODEL_SPEARSKILL, Position, Position, Angle, 8, o, 30.0f, -1, 0, 0, -1, 0);
		Position[2] -= 10.f;
		Vector ( 0.f, 0.f, 180.f, Angle );
		CreateJoint(MODEL_SPEARSKILL, Position, Position, Angle, 8, o, 30.0f, -1, 0, 0, -1, 0);
		Position[2] -= 10.f;
		Vector ( 0.f, 0.f, 270.f, Angle );
		CreateJoint(MODEL_SPEARSKILL, Position, Position, Angle, 8, o, 30.0f, -1, 0, 0, -1, 0);
	}

	if(FindEffect(buff,STATE_ADD_MANA) != 0)
	{
		InsertEffect(o,STATE_ADD_MANA);
	}

	if(FindEffect(buff,STATE_CLOAKING) != 0)
	{
		InsertEffect(o,STATE_CLOAKING);
	}

	if(FindEffect(buff,STATE_BLESS_POTION) != 0)
	{
		InsertEffect(o,STATE_BLESS_POTION);
	}

	if(FindEffect(buff,STATE_SOUL_POTION) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_SOUL_POTION);
		}
	}

	if(FindEffect(buff,STATE_REMOVAL_MAGIC) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_REMOVAL_MAGIC,2);
		}
	}

	#pragma endregion

	#pragma region SECTION FIVE (Complete)

	if(FindEffect(buff,STATE_IMMUNE_TO_SKILL) != 0)
	{
		InsertEffect(o,STATE_IMMUNE_TO_SKILL,2);
	}

	if(FindEffect(buff,STATE_INFINITY_ARROW) != 0)
	{
		InsertEffect(o,STATE_INFINITY_ARROW);
	}

	if(FindEffect(buff,STATE_NPC_HELP) != 0)
	{
		InsertEffect(o,STATE_NPC_HELP);
	}

	#pragma endregion

	#pragma region SECTION CRYWOLF (Complete)

	if(FindEffect(buff,STATE_CRYWOLF_NPC_HIDE) != 0)
	{
		InsertEffect(o,STATE_CRYWOLF_NPC_HIDE,2);
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_ENABLE) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CRYWOLF_ALTAR_ENABLE,3);
		}
	}
	
	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_DISABLE) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CRYWOLF_ALTAR_DISABLE,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_CONTRACTED) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CRYWOLF_ALTAR_CONTRACTED,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_ATTEMPT) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CRYWOLF_ALTAR_ATTEMPT,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_OCCUFIED) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CRYWOLF_ALTAR_OCCUFIED,3);
		}
	}

	#pragma endregion

	#pragma region SECTION SIEGUE (Complete)

	if(FindEffect(buff,STATE_CASTLE_SIEGUE) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_CASTLE_SIEGUE);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_DEFEND) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_JOIN_SIDE_DEFEND);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			InsertEffect(o,STATE_JOIN_SIDE_ATTACK);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK_2) != 0) 
	{
		InsertEffect(o,STATE_JOIN_SIDE_ATTACK_2);
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK_3) != 0)
	{
		InsertEffect(o,STATE_JOIN_SIDE_ATTACK_3);
	}

	#pragma endregion

	#pragma region SECTION SEAL (Complete)

	if(FindEffect(buff,STATE_SEAL_ITEM) != 0)
	{
		InsertEffect(o,STATE_SEAL_ITEM);
	}

	#pragma endregion

	#pragma region SECTION TEMPLE (Complete)

	if (*(DWORD*)MAIN_CURRENT_MAP >= 45 && *(DWORD*)MAIN_CURRENT_MAP <= 50)
	{
		if(FindEffect(buff,STATE_ILLUSION_TEMPLE_PRODECTION) != 0)
		{
			if(Type == MODEL_PLAYER)
			{
				InsertEffect(o,STATE_ILLUSION_TEMPLE_PRODECTION,1);

				DeleteEffect(MODEL_CURSEDTEMPLE_PRODECTION_SKILL,o,-1);
				DeleteEffect(MODEL_SHIELD_CRASH,o,-1);
				DeleteEffect(BITMAP_SHOCK_WAVE,o,-1);
				
				Vector(0.3f, 0.3f, 0.8f, Light);
				pCreateEffect(MODEL_CURSEDTEMPLE_PRODECTION_SKILL, Position, Angle, Light, 0, o, -1, 0, 0, 0, 0);
				pCreateEffect(MODEL_SHIELD_CRASH, Position, Angle, Light, 1, o, -1, 0, 0, 0, 0);
				pCreateEffect(BITMAP_SHOCK_WAVE, Position, Angle, Light, 10, o, -1, 0, 0, 0, 0);
			}
		}

		if(FindEffect(buff,STATE_ILLUSION_TEMPLE_RESTRAINT) != 0)
		{
			InsertEffect(o,STATE_ILLUSION_TEMPLE_RESTRAINT,1);
		}
	}

	#pragma endregion
}

void UnRegisterBuff(eEffectNumber buff,DWORD o) // OK
{
	WORD Type = *(WORD*)(o + 2);

	#pragma region SECTION ONE (Complete)

	if(FindEffect(buff,STATE_POISON) != 0)
	{
		RemoveEffect(o,STATE_POISON);
	}

	if(FindEffect(buff,STATE_FREEZE) != 0)
	{
		RemoveEffect(o,STATE_FREEZE);
	}

	if(FindEffect(buff,STATE_ATTACK) != 0)
	{
		RemoveEffect(o,STATE_ATTACK);
	}

	if(FindEffect(buff,STATE_DEFENSE) != 0)
	{
		RemoveEffect(o,STATE_DEFENSE);
		
		DeleteJoint(MODEL_SPEARSKILL,o,4);
		DeleteJoint(MODEL_SPEARSKILL,o,9);
	}

	if(FindEffect(buff,STATE_ADD_LIFE) != 0)
	{
		RemoveEffect(o,STATE_ADD_LIFE);
		
		DeleteEffect(BITMAP_LIGHT,o,1);
	}

	if(FindEffect(buff,STATE_HARDEN) != 0)
	{
		RemoveEffect(o,STATE_HARDEN);
	}

	if(FindEffect(buff,STATE_REDUCE_DEFENSE) != 0)
	{
		RemoveEffect(o,STATE_REDUCE_DEFENSE);
		
		DeleteEffect(BITMAP_SKULL,o,0);
	}

	if(FindEffect(buff,STATE_REDUCE_ATTACKDAMAGE) != 0)
	{
		RemoveEffect(o,STATE_REDUCE_ATTACKDAMAGE);
	}

	#pragma endregion

	#pragma region SECTION TWO (Complete)

	if(FindEffect(buff,STATE_REDUCE_MAGICDEFENSE) != 0) 
	{
		RemoveEffect(o,STATE_REDUCE_MAGICDEFENSE);
	
		if(Type == MODEL_PLAYER)
		{
			DeleteJoint(MODEL_SPEARSKILL,o,0);
		}
	}

	if(FindEffect(buff,STATE_REDUCE_MAGICPOWER) != 0)
	{
		RemoveEffect(o,STATE_REDUCE_MAGICPOWER);
	}

	if(FindEffect(buff,STATE_ADD_AG) != 0)
	{
		RemoveEffect(o,STATE_ADD_AG);
		
		DeleteEffect(BITMAP_LIGHT,o,2);
	}

	if(FindEffect(buff,STATE_ADD_CRITICAL_DAMAGE) != 0)
	{
		RemoveEffect(o,STATE_ADD_CRITICAL_DAMAGE);
	}

	#pragma endregion

	#pragma region SECTION THREE (Complete)

	if(FindEffect(buff,STATE_ADD_GM_MARK) != 0)
	{
		RemoveEffect(o,STATE_ADD_GM_MARK);
		
		DeleteEffect(BITMAP_LIGHT,o,2);
		DeleteEffect(BITMAP_LIGHT,o,1);
		DeleteEffect(BITMAP_SKULL,o,0);
		DeleteJoint(MODEL_SPEARSKILL,o,4);
		DeleteJoint(MODEL_SPEARSKILL,o,9);
		DeleteJoint(MODEL_SPEARSKILL,o,0);
	}

	#pragma endregion

	#pragma region SECTION FOUR (Complete)

	if(FindEffect(buff,STATE_STUNED) != 0)
	{
		RemoveEffect(o,STATE_STUNED);
		
		DeleteEffect(BITMAP_SKULL,o,5);
	}

	if(FindEffect(buff,STATE_ADD_MANA) != 0)
	{
		RemoveEffect(o,STATE_ADD_MANA);
	}

	if(FindEffect(buff,STATE_CLOAKING) != 0)
	{
		RemoveEffect(o,STATE_CLOAKING);
	}

	if(FindEffect(buff,STATE_BLESS_POTION) != 0)
	{
		RemoveEffect(o,STATE_BLESS_POTION);
	}

	if(FindEffect(buff,STATE_SOUL_POTION) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_SOUL_POTION);
		}
	}

	if(FindEffect(buff,STATE_REMOVAL_MAGIC) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_REMOVAL_MAGIC,2);
		}
	}

	#pragma endregion

	#pragma region SECTION FIVE (Complete)

	if(FindEffect(buff,STATE_IMMUNE_TO_SKILL) != 0)
	{
		RemoveEffect(o,STATE_IMMUNE_TO_SKILL,2);
	}

	if(FindEffect(buff,STATE_INFINITY_ARROW) != 0)
	{
		RemoveEffect(o,STATE_INFINITY_ARROW);
	}

	if(FindEffect(buff,STATE_NPC_HELP) != 0)
	{
		RemoveEffect(o,STATE_NPC_HELP);
		
		DeleteJoint(MODEL_SPEARSKILL,o,4);
		DeleteJoint(MODEL_SPEARSKILL,o,9);
	}

	#pragma endregion

	#pragma region SECTION CRYWOLF (Complete)

	if(FindEffect(buff,STATE_CRYWOLF_NPC_HIDE) != 0)
	{
		RemoveEffect(o,STATE_CRYWOLF_NPC_HIDE,2);
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_ENABLE) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CRYWOLF_ALTAR_ENABLE,3);
		}
	}
	
	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_DISABLE) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CRYWOLF_ALTAR_DISABLE,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_CONTRACTED) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CRYWOLF_ALTAR_CONTRACTED,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_ATTEMPT) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CRYWOLF_ALTAR_ATTEMPT,3);
		}
	}

	if(FindEffect(buff,STATE_CRYWOLF_ALTAR_OCCUFIED) != 0)
	{
		if(Type >= MODEL_CRYWOLF_ALTAR1 && Type <= MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CRYWOLF_ALTAR_OCCUFIED,3);
		}
	}

	#pragma endregion

	#pragma region SECTION SIEGUE (Complete)

	if(FindEffect(buff,STATE_CASTLE_SIEGUE) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_CASTLE_SIEGUE);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_DEFEND) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_JOIN_SIDE_DEFEND);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK) != 0)
	{
		if(Type < MODEL_CRYWOLF_ALTAR1 || Type > MODEL_CRYWOLF_ALTAR5)
		{
			RemoveEffect(o,STATE_JOIN_SIDE_ATTACK);
		}
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK_2) != 0) 
	{
		RemoveEffect(o,STATE_JOIN_SIDE_ATTACK_2);
	}

	if(FindEffect(buff,STATE_JOIN_SIDE_ATTACK_3) != 0)
	{
		RemoveEffect(o,STATE_JOIN_SIDE_ATTACK_3);
	}

	#pragma endregion

	#pragma region SECTION SEAL (Complete)

	if(FindEffect(buff,STATE_SEAL_ITEM) != 0)
	{
		RemoveEffect(o,STATE_SEAL_ITEM);
	}

	#pragma endregion

	#pragma region SECTION TEMPLE (Complete)

	if (*(DWORD*)MAIN_CURRENT_MAP >= 45 && *(DWORD*)MAIN_CURRENT_MAP <= 50)
	{
		if(FindEffect(buff,STATE_ILLUSION_TEMPLE_PRODECTION) != 0)
		{
			if(Type == MODEL_PLAYER)
			{
				RemoveEffect(o,STATE_ILLUSION_TEMPLE_PRODECTION,1);
			}
		}

		if(FindEffect(buff,STATE_ILLUSION_TEMPLE_RESTRAINT) != 0)
		{
			RemoveEffect(o,STATE_ILLUSION_TEMPLE_RESTRAINT,1);
			
			DeleteEffect(MODEL_CURSEDTEMPLE_RESTRAINT_SKILL,o,-1);
		}
	}

	#pragma endregion
}

void InsertEffect(DWORD o,eEffectNumber buff,int type) // OK
{
	switch(type)
	{
		case 0:
			*(DWORD *)(o + 168) |= buff;
			break;
		case 1:
			*(DWORD *)(o + 172) |= buff;
			break;
		case 2:
			*(DWORD *)(o + 176) |= buff;
			break;
		case 3:
			*(DWORD *)(o + 176) = buff;
			break;
	}
}

void RemoveEffect(DWORD o,eEffectNumber buff,int type) // OK
{
	switch(type)
	{
		case 0:
			*(DWORD *)(o + 168) &= ~buff;
			break;
		case 1:
			*(DWORD *)(o + 172) &= ~buff;
			break;
		case 2:
			*(DWORD *)(o + 176) &= ~buff;
			break;
		case 3:
			*(DWORD *)(o + 176) = buff;
			break;
	}
}