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
#ifndef BASEZOMBIE_H
#define BASEZOMBIE_H

class CBaseZombie : public CBaseMonster
{
	DECLARE_CLASS(CBaseZombie, CBaseMonster);
public:
	virtual void Spawn( void );
	virtual void Precache(void);
	virtual void SetYawSpeed(void);
	virtual int  Classify(void);
	virtual void HandleAnimEvent(MonsterEvent_t *pEvent);
	virtual int IgnoreConditions(void);

	float m_flNextFlinch;

	virtual void PainSound(void);
	virtual void AlertSound(void);
	virtual void IdleSound(void);
	virtual void AttackSound(void);

	static const char *pAttackSounds[];
	static const char *pIdleSounds[];
	static const char *pAlertSounds[];
	static const char *pPainSounds[];
	static const char *pAttackHitSounds[];
	static const char *pAttackMissSounds[];

	// No range attacks
	virtual BOOL CheckRangeAttack1(float flDot, float flDist) { return FALSE; }
	virtual BOOL CheckRangeAttack2(float flDot, float flDist) { return FALSE; }
	virtual int TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);

	DECLARE_DATADESC();

	virtual float GetClawAttackRange(void)			const	{ return m_flClawAttackRange; }
	virtual float GetAttackDamageOneSlash(void)		const	{ return m_flAttackDamageOneSlash; }
	virtual float GetAttackDamageBothSlash(void)	const	{ return m_flAttackDamageBothSlash; }

	virtual CBaseEntity* ClawAttack(float flDist, float flDamage, const Vector& qaViewpunch, const Vector& vecVelocityPunch, int bitsDamageType);

protected:
	float m_flAttackDamageOneSlash;
	float m_flAttackDamageBothSlash;
	float m_flClawAttackRange;

};


#endif // 