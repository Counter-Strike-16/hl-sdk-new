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
//=========================================================
// Zombie
//=========================================================

// UNDONE: Don't flinch every time you get hit

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"monster_basezombie.h"

//=========================================================
// Monster's Anim Events Go Here
//=========================================================

class CZombie : public CBaseZombie
{
	DECLARE_CLASS(CZombie, CBaseZombie);
public:
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( monster_zombie, CZombie );

//=========================================================
// Precache - precaches all resources this monster needs
//=========================================================
void CZombie :: Precache()
{
	SetModelName( AllocPooledString( "models/zombie.mdl" ) );
	BaseClass::Precache();
}