/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   This source code contains proprietary and confidential information of
*   Valve LLC and its suppliers.  Access to this code is restricted to
*   persons who have executed a written SDK license with Valve.  Any access,
*   use or distribution of this code by or to any unlicensed person is illegal.
*
****/

#include	"extdll.h"
#include	"plane.h"
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"schedule.h"
#include	"animation.h"
#include	"squadmonster.h"
#include	"weapons.h"
#include	"talkmonster.h"
#include	"soundent.h"
#include	"effects.h"
#include	"customentity.h"
#include	"basegrenade.h"
#include	"deadmonster.h"
#include	"monster_hgrunt.h"

//=========================================================
// DEAD HGRUNT PROP
//=========================================================
class CDeadHGrunt : public CDeadMonster
{
	DECLARE_CLASS(CDeadHGrunt, CDeadMonster);
public:
	void Spawn(void);
	void Precache();
	int	Classify(void) { return	CLASS_HUMAN_MILITARY; }

	virtual const char* GetPose(int i);

	static char *m_szPoses[3];
};

char *CDeadHGrunt::m_szPoses[] = { "deadstomach", "deadside", "deadsitting" };

LINK_ENTITY_TO_CLASS(monster_hgrunt_dead, CDeadHGrunt);

//=========================================================
// ********** DeadHGrunt SPAWN **********
//=========================================================
void CDeadHGrunt::Spawn(void)
{
	Precache();

	BaseClass::Spawn();

	SetBloodColor(BLOOD_COLOR_RED);

	// map old bodies onto new bodies
	switch (pev->body)
	{
	case 0: // Grunt with Gun
		pev->body = 0;
		pev->skin = 0;
		SetBodygroup(HEAD_GROUP, HEAD_GRUNT);
		SetBodygroup(GUN_GROUP, GUN_MP5);
		break;
	case 1: // Commander with Gun
		pev->body = 0;
		pev->skin = 0;
		SetBodygroup(HEAD_GROUP, HEAD_COMMANDER);
		SetBodygroup(GUN_GROUP, GUN_MP5);
		break;
	case 2: // Grunt no Gun
		pev->body = 0;
		pev->skin = 0;
		SetBodygroup(HEAD_GROUP, HEAD_GRUNT);
		SetBodygroup(GUN_GROUP, GUN_NONE);
		break;
	case 3: // Commander no Gun
		pev->body = 0;
		pev->skin = 0;
		SetBodygroup(HEAD_GROUP, HEAD_COMMANDER);
		SetBodygroup(GUN_GROUP, GUN_NONE);
		break;
	}
}
//=========================================================
//=========================================================
void CDeadHGrunt::Precache(void)
{
	SetModelName(MAKE_STRING(HGRUNT_MODEL));
	BaseClass::Precache();
}

const char* CDeadHGrunt::GetPose(int i)
{
	return m_szPoses[i];
}