#pragma once

#include "MathLib.h"

typedef struct _OBJECT
{
	bool          Live; //0
	short         Type; //1
	int           SubType; //3
	BYTE		  ExtState; //
	float         Scale;
	vec3_t        Position;
	vec3_t	 	  Angle;

	vec3_t	 	  HeadAngle;
	vec3_t	   	  HeadTargetAngle;
	vec3_t  	  EyeLeft;
	vec3_t  	  EyeRight;

	/*1.04.10 new pointer*/
	vec3_t  	  EyeUp;
	vec3_t  	  EyeDown;
	vec3_t  	  EyeMiddle;
	vec3_t  	  EyeBottom;
	/*48 here*/

	int           HiddenMesh;
	short         ScreenX;
	short         ScreenY;
	int           LifeTime;
	int           BlendMesh;
	float         BlendMeshLight;
	float         BlendMeshTexCoordU;
	float         BlendMeshTexCoordV;

	int           RenderType;
	int           State;
	int           Unknow; // -> 1.04.10
	int           CrywolfAltarState; // only for CryWolf Altar

	BYTE          Teleport;
	float         Timer;

	BYTE          Kind;
	BYTE          Skill;
	short         PKKey;
	short         Weapon;
	BYTE          WeaponLevel;
	bool          bBillBoard;
	bool          DamageTime;
	bool          m_bCollisionCheck;
	bool          m_bRenderShadow;
	BYTE          m_byBuildTime;
	float		  m_fEdgeScale;

	bool          EnableShadow;
	float	 	  Matrix[3][4];
	vec3_t        Direction;
	float         Velocity;
	float		  CollisionRange;
	float         ShadowScale;
	float         Gravity;
	bool		  LightEnable;
	float         Distance;
	bool		  ContrastEnable;
	vec3_t        Light;
	int           AttackPoint[2];

	_OBJECT* Owner;
	int           LinkBone;

	unsigned char AI;
	unsigned char CurrentAction;
	unsigned char PriorAction;
	float         AnimationFrame;
	float         PriorAnimationFrame;

	bool          EnableBoneMatrix;
	vec34_t* BoneTransform;
	vec3_t        BoundingBoxMin;
	vec3_t        BoundingBoxMax;
	OBB_t		  OBB;

	bool	      Visible;
	bool	      AlphaEnable;
	float	      AlphaTarget;
	float	      Alpha;
	bool          ChromeEnable;
	vec3_t		  StartPosition;
	int           InitialSceneFrame;

	BYTE          m_byNumCloth;
	void* m_pCloth;

	vec3_t        m_vPosSword;

	BYTE          m_byHurtByOneToOne;

	bool          m_bActionStart;
	vec3_t        m_vDownAngle;
	vec3_t        m_vDeadPosition;

	BYTE          m_bySkillSerialNum;

	DWORD         m_dwTime;

	int           m_iAnimation;

	BOOL          m_bpcroom; // pc room npc

	BYTE          Block;

	_OBJECT* Prior;
	_OBJECT* Next;

	_OBJECT()
	{
		memset(this, 0, sizeof(_OBJECT)); // 0x1D0 Total
	}

} OBJECT;

typedef struct
{
	short Type;
	BYTE  Level;
	BYTE  NewOption;
	BYTE  SetOption;
	BYTE  LinkBone;
	BYTE  CurrentAction;
	BYTE  PriorAction;
	float AnimationFrame;
	float PriorAnimationFrame;
	float PlaySpeed;
	BYTE	m_byNumCloth;
	void* m_pCloth[2];
} PART_t;

typedef struct _CHARACTER
{
	OBJECT	    Object; // 0 (0x0)
	BYTE	    Class; // 452 (0x1C4)
	BYTE	    Skin; // 453 (0x1C5)
	WORD        Level; // 454 (0x1C6)
	BYTE		Authority; // 456 (0x1C8)
	char        ID[24]; // 457 (0x1C9)
	short       GuildKey; // 482 (0x1E2)
	SHORT       Key; // 484 (0x1E4)
	PART_t    	BodyPart[6]; // +0x1e8(0x20) // +0x208(0x20) // +0x228(0x20) // +0x248(0x20) // +0x268(0x20) // +0x288(0x20)
	PART_t		Weapon[2]; // +0x2a8(0x20) // +0x2c8(0x20)
	PART_t		Wing; // +0x2e8(0x20)
	PART_t		Helper; // +0x308(0x20)
	PART_t		Flag; // +0x328(0x20)

	BYTE		m_filler[0xEB];

	// ------------~~OK~~~-------------

	// max size 0x47C -> 1148
} CHARACTER;

extern CHARACTER*& Hero;
extern CHARACTER*& CharactersClient;