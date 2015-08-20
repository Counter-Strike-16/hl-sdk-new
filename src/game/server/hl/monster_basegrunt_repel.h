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

#ifndef BASEGRUNT_REPEL_H
#define BASEGRUNT_REPEL_H

class CBaseGruntRepel : public CBaseMonster
{
	DECLARE_CLASS(CBaseGruntRepel, CBaseMonster);
public:
	void Spawn(void);
	void Precache(void);
	void EXPORT RepelUse(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
	int m_iSpriteTexture;	// Don't save, precache

	virtual const char* RepelClassname(void) const = 0;
	virtual const char* RopeSpriteTexture(void) const;
};


#endif // BASEGRUNT_REPEL_H