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

#ifndef MONSTER_HGRUNT_H
#define MONSTER_HGRUNT_H

#include "monster_basegrunt.h"

#define HGRUNT_MODEL	"models/hgrunt.mdl"

class CHGrunt : public CBaseGrunt
{
	DECLARE_CLASS(CHGrunt, CBaseGrunt);
public:
	void Spawn(void);
	void Precache(void);

	Schedule_t	*GetSchedule(void);
	Schedule_t  *GetScheduleOfType(int Type);
	void TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);

	int IRelationship(CBaseEntity *pTarget);

	CUSTOM_SCHEDULES;
};

#endif // MONSTER_HGRUNT_H