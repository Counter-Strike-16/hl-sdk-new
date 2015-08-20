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
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"schedule.h"
#include 	"deadmonster.h"

void CDeadMonster::KeyValue( KeyValueData *pkvd )
{
	if (FStrEq(pkvd->szKeyName, "pose"))
	{
		m_iPose = atoi(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}
	else 
		CBaseMonster::KeyValue( pkvd );
}

//=========================================================
// ********** DeadMonster SPAWN **********
//=========================================================
void CDeadMonster :: Spawn( void )
{
	SetModel( STRING( GetModelName() ) );

	pev->effects		= 0;
	pev->yaw_speed		= 8;
	pev->sequence		= 0;
	m_bloodColor		= BLOOD_COLOR_RED;
	
	SetBloodColor( DONT_BLEED );

	pev->sequence = LookupSequence( GetPose(m_iPose) );

	if (pev->sequence == -1)
	{
		ALERT ( at_console, "Warning: %s with bad pose\n", STRING( GetClassname() ) );
	}

	// Corpses have less health
	SetHealth( 8 );

	MonsterInitDead();
}

void CDeadMonster::Precache( void )
{
	PrecacheModel( STRING( GetModelName() ) );
}
