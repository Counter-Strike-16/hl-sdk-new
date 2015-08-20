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

#ifndef DEADMONSTER_H
#define DEADMONSTER_H

//=========================================================
// DEAD MONSTER
//=========================================================
class CDeadMonster : public CBaseMonster
{
	DECLARE_CLASS(CDeadMonster, CBaseMonster);
public:

	virtual void Spawn( void );
	virtual void Precache( void );
	virtual int	Classify ( void ) { return CLASS_NONE; }
	
	virtual const char* GetPose(int i) = 0;

	void KeyValue( KeyValueData *pkvd );

	int	m_iPose;// which sequence to display	-- temporary, don't need to save
};



#endif // DEADMONSTER_H