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
#include	"monster_barney.h"


//=========================================================
// DEAD BARNEY PROP
//
// Designer selects a pose in worldcraft, 0 through num_poses-1
// this value is added to what is selected as the 'first dead pose'
// among the monster's normal animations. All dead poses must
// appear sequentially in the model file. Be sure and set
// the m_iFirstPose properly!
//
//=========================================================
class CDeadBarney : public CDeadMonster
{
	DECLARE_CLASS(CDeadBarney, CDeadMonster);
public:
	void Spawn(void);
	void Precache();
	int	Classify(void) { return	CLASS_HUMAN_MILITARY; }

	virtual const char* GetPose(int i);

	static char *m_szPoses[3];
};

char *CDeadBarney::m_szPoses[] = { "lying_on_back", "lying_on_side", "lying_on_stomach" };

LINK_ENTITY_TO_CLASS(monster_barney_dead, CDeadBarney);

//=========================================================
// ********** DeadBarney SPAWN **********
//=========================================================
void CDeadBarney::Spawn(void)
{
	Precache();

	BaseClass::Spawn();

	SetBloodColor(BLOOD_COLOR_RED);

}
//=========================================================
//=========================================================
void CDeadBarney::Precache(void)
{
	SetModelName(MAKE_STRING(BARNEY_MODEL));
	BaseClass::Precache();
}

const char* CDeadBarney::GetPose(int i)
{
	return m_szPoses[i];
}