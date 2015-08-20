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
#include	"monster_scientist.h"


//=========================================================
// Dead Scientist PROP
//=========================================================
class CDeadScientist : public CDeadMonster
{
	DECLARE_CLASS(CDeadScientist, CDeadMonster);
public:
	void Spawn(void);
	void Precache();
	int	Classify(void) { return	CLASS_HUMAN_PASSIVE; }

	virtual const char* GetPose(int i);

	static char *m_szPoses[7];
};

char *CDeadScientist::m_szPoses[] = { "lying_on_back", "lying_on_stomach", "dead_sitting", "dead_hang", "dead_table1", "dead_table2", "dead_table3" };

LINK_ENTITY_TO_CLASS(monster_scientist_dead, CDeadScientist);

//=========================================================
// ********** DeadHGrunt SPAWN **********
//=========================================================
void CDeadScientist::Spawn(void)
{
	Precache();

	BaseClass::Spawn();

	SetBloodColor(BLOOD_COLOR_RED);

	if (pev->body == -1)
	{// -1 chooses a random head
		pev->body = RANDOM_LONG(0, NUM_SCIENTIST_HEADS - 1);// pick a head, any head
	}
	// Luther is black, make his hands black
	if (pev->body == HEAD_LUTHER)
		pev->skin = 1;
	else
		pev->skin = 0;
}
//=========================================================
//=========================================================
void CDeadScientist::Precache(void)
{
	SetModelName(MAKE_STRING(SCIENTIST_MODEL));
	BaseClass::Precache();
}

const char* CDeadScientist::GetPose(int i)
{
	return m_szPoses[i];
}