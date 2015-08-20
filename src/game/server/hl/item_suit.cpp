/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
/*

===== items.cpp ========================================================

  functions governing the selection/use of weapons for players

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "weapons.h"
#include "player.h"
#include "skill.h"
#include "items.h"
#include "gamerules.h"

#define SF_SUIT_SHORTLOGON		0x0001

class CItemSuit : public CItem
{
	void Spawn( void );
	void Precache( void );
	BOOL MyTouch( CBasePlayer *pPlayer );
};

LINK_ENTITY_TO_CLASS(item_suit, CItemSuit);

void CItemSuit::Spawn( void )
{ 
	Precache( );
	SET_MODEL(ENT(pev), "models/w_suit.mdl");
	CItem::Spawn( );
}
void CItemSuit::Precache( void )
{
	PRECACHE_MODEL ("models/w_suit.mdl");
}
BOOL CItemSuit::MyTouch( CBasePlayer *pPlayer )
{
	if ( pPlayer->pev->weapons & (1<<WEAPON_SUIT) )
		return FALSE;

	if ( pev->spawnflags & SF_SUIT_SHORTLOGON )
		EMIT_SOUND_SUIT(pPlayer->edict(), "!HEV_A0");		// short version of suit logon,
	else
		EMIT_SOUND_SUIT(pPlayer->edict(), "!HEV_AAx");	// long version of suit logon

	pPlayer->pev->weapons |= (1<<WEAPON_SUIT);
	return TRUE;
}



