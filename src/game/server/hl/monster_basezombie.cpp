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
// BaseZombie
//=========================================================

// UNDONE: Don't flinch every time you get hit

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"schedule.h"
#include	"monster_basezombie.h"


//=========================================================
// Monster's Anim Events Go Here
//=========================================================
#define	ZOMBIE_AE_ATTACK_RIGHT		0x01
#define	ZOMBIE_AE_ATTACK_LEFT		0x02
#define	ZOMBIE_AE_ATTACK_BOTH		0x03

#define ZOMBIE_FLINCH_DELAY			2		// at most one flinch every n secs

BEGIN_DATADESC(CBaseZombie)
	DEFINE_FIELD(CBaseZombie, m_flAttackDamageOneSlash, FIELD_FLOAT),
	DEFINE_FIELD(CBaseZombie, m_flAttackDamageBothSlash, FIELD_FLOAT),
	DEFINE_FIELD(CBaseZombie, m_flClawAttackRange, FIELD_FLOAT),
END_DATADESC()

IMPLEMENT_SAVERESTORE(CBaseZombie, CBaseMonster);

const char *CBaseZombie::pAttackHitSounds[] = 
{
	"zombie/claw_strike1.wav",
	"zombie/claw_strike2.wav",
	"zombie/claw_strike3.wav",
};

const char *CBaseZombie::pAttackMissSounds[] = 
{
	"zombie/claw_miss1.wav",
	"zombie/claw_miss2.wav",
};

const char *CBaseZombie::pAttackSounds[] = 
{
	"zombie/zo_attack1.wav",
	"zombie/zo_attack2.wav",
};

const char *CBaseZombie::pIdleSounds[] = 
{
	"zombie/zo_idle1.wav",
	"zombie/zo_idle2.wav",
	"zombie/zo_idle3.wav",
	"zombie/zo_idle4.wav",
};

const char *CBaseZombie::pAlertSounds[] = 
{
	"zombie/zo_alert10.wav",
	"zombie/zo_alert20.wav",
	"zombie/zo_alert30.wav",
};

const char *CBaseZombie::pPainSounds[] = 
{
	"zombie/zo_pain1.wav",
	"zombie/zo_pain2.wav",
};

//=========================================================
// Classify - indicates this monster's place in the 
// relationship table.
//=========================================================
int	CBaseZombie :: Classify ( void )
{
	return	CLASS_ALIEN_MONSTER;
}

//=========================================================
// SetYawSpeed - allows each sequence to have a different
// turn rate associated with it.
//=========================================================
void CBaseZombie :: SetYawSpeed ( void )
{
	int ys;

	ys = 120;

#if 0
	switch ( m_Activity )
	{
	}
#endif

	pev->yaw_speed = ys;
}

int CBaseZombie :: TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
	// Take 30% damage from bullets
	if ( bitsDamageType == DMG_BULLET )
	{
		Vector vecDir = GetOrigin() - (pevInflictor->absmin + pevInflictor->absmax) * 0.5;
		vecDir = vecDir.Normalize();
		float flForce = DamageForce( flDamage );
		pev->velocity = pev->velocity + vecDir * flForce;
		flDamage *= 0.3;
	}

	// HACK HACK -- until we fix this.
	if ( IsAlive() )
		PainSound();
	return BaseClass::TakeDamage( pevInflictor, pevAttacker, flDamage, bitsDamageType );
}

void CBaseZombie :: PainSound( void )
{
	int pitch = 95 + RANDOM_LONG(0,9);

	if (RANDOM_LONG(0,5) < 2)
		EMIT_SOUND_DYN ( ENT(pev), CHAN_VOICE, pPainSounds[ RANDOM_LONG(0,ARRAYSIZE(pPainSounds)-1) ], 1.0, ATTN_NORM, 0, pitch );
}

void CBaseZombie :: AlertSound( void )
{
	int pitch = 95 + RANDOM_LONG(0,9);

	EMIT_SOUND_DYN ( ENT(pev), CHAN_VOICE, pAlertSounds[ RANDOM_LONG(0,ARRAYSIZE(pAlertSounds)-1) ], 1.0, ATTN_NORM, 0, pitch );
}

void CBaseZombie :: IdleSound( void )
{
	int pitch = 100 + RANDOM_LONG(-5,5);

	// Play a random idle sound
	EMIT_SOUND_DYN ( ENT(pev), CHAN_VOICE, pIdleSounds[ RANDOM_LONG(0,ARRAYSIZE(pIdleSounds)-1) ], 1.0, ATTN_NORM, 0, pitch );
}

void CBaseZombie :: AttackSound( void )
{
	int pitch = 100 + RANDOM_LONG(-5,5);

	// Play a random attack sound
	EMIT_SOUND_DYN ( ENT(pev), CHAN_VOICE, pAttackSounds[ RANDOM_LONG(0,ARRAYSIZE(pAttackSounds)-1) ], 1.0, ATTN_NORM, 0, pitch );
}


//=========================================================
// HandleAnimEvent - catches the monster-specific messages
// that occur when tagged animation frames are played.
//=========================================================
void CBaseZombie :: HandleAnimEvent( MonsterEvent_t *pEvent )
{
	switch( pEvent->event )
	{
		case ZOMBIE_AE_ATTACK_RIGHT:
		{
			// do stuff for this event.
	//		ALERT( at_console, "Slash right!\n" );

			Vector vecVel = gpGlobals->v_forward * 100;
			Vector qaPunch(5, 0, -18);
			ClawAttack(GetClawAttackRange(), GetAttackDamageOneSlash(), qaPunch, vecVel, DMG_SLASH);
		}
		break;

		case ZOMBIE_AE_ATTACK_LEFT:
		{
			// do stuff for this event.
	//		ALERT( at_console, "Slash left!\n" );

			Vector vecVel = gpGlobals->v_forward * -100;
			Vector qaPunch( 5, 0, 18 );
			ClawAttack(GetClawAttackRange(), GetAttackDamageOneSlash(), qaPunch, vecVel, DMG_SLASH);

		}
		break;

		case ZOMBIE_AE_ATTACK_BOTH:
		{
			// do stuff for this event.
			Vector vecVel = gpGlobals->v_forward * -100;
			Vector qaPunch(5, 0, 0);
			ClawAttack(GetClawAttackRange(), GetAttackDamageBothSlash(), qaPunch, vecVel, DMG_SLASH);
		}
		break;

		default:
			BaseClass::HandleAnimEvent( pEvent );
			break;
	}
}

//=========================================================
// Spawn
//=========================================================
void CBaseZombie :: Spawn()
{
	Precache( );

	SetModel( STRING( GetModelName() ) );
	SetSize( VEC_HUMAN_HULL_MIN, VEC_HUMAN_HULL_MAX );

	SetSolid(SOLID_SLIDEBOX);
	SetMoveType(MOVETYPE_STEP);
	SetBloodColor(BLOOD_COLOR_GREEN);

	SetHealth( gSkillData.zombieHealth );

	SetViewOffset(VEC_VIEW);// position of the eyes relative to monster's origin.
	SetFieldOfView(0.5);// indicates the width of this monster's forward view cone ( as a dotproduct result )
	SetState(MONSTERSTATE_NONE);
	SetCapabilities( bits_CAP_DOORS_GROUP );

	m_flAttackDamageOneSlash	= gSkillData.zombieDmgOneSlash;
	m_flAttackDamageBothSlash	= gSkillData.zombieDmgBothSlash;
	m_flClawAttackRange			= 70;

	MonsterInit();
}

//=========================================================
// Precache - precaches all resources this monster needs
//=========================================================
void CBaseZombie :: Precache()
{
	int i;
	PrecacheModel( (char*)STRING( GetModelName() ) );

	for ( i = 0; i < ARRAYSIZE( pAttackHitSounds ); i++ )
		PrecacheSound((char *)pAttackHitSounds[i]);

	for ( i = 0; i < ARRAYSIZE( pAttackMissSounds ); i++ )
		PrecacheSound((char *)pAttackMissSounds[i]);

	for ( i = 0; i < ARRAYSIZE( pAttackSounds ); i++ )
		PrecacheSound((char *)pAttackSounds[i]);

	for ( i = 0; i < ARRAYSIZE( pIdleSounds ); i++ )
		PrecacheSound((char *)pIdleSounds[i]);

	for ( i = 0; i < ARRAYSIZE( pAlertSounds ); i++ )
		PrecacheSound((char *)pAlertSounds[i]);

	for ( i = 0; i < ARRAYSIZE( pPainSounds ); i++ )
		PrecacheSound((char *)pPainSounds[i]);
}	

//=========================================================
// AI Schedules Specific to this monster
//=========================================================



int CBaseZombie::IgnoreConditions ( void )
{
	int iIgnore = BaseClass::IgnoreConditions();

	if ((m_Activity == ACT_MELEE_ATTACK1) || (m_Activity == ACT_MELEE_ATTACK1))
	{
#if 0
		if (pev->health < 20)
			iIgnore |= (bits_COND_LIGHT_DAMAGE|bits_COND_HEAVY_DAMAGE);
		else
#endif			
		if (m_flNextFlinch >= gpGlobals->time)
			iIgnore |= (bits_COND_LIGHT_DAMAGE|bits_COND_HEAVY_DAMAGE);
	}

	if ((m_Activity == ACT_SMALL_FLINCH) || (m_Activity == ACT_BIG_FLINCH))
	{
		if (m_flNextFlinch < gpGlobals->time)
			m_flNextFlinch = gpGlobals->time + ZOMBIE_FLINCH_DELAY;
	}

	return iIgnore;
	
}

CBaseEntity* CBaseZombie::ClawAttack(float flDist, float flDamage, const Vector& qaViewpunch, const Vector& vecVelocityPunch, int bitsDamageType)
{
	CBaseEntity *pHurt = CheckTraceHullAttack(flDist, flDamage, bitsDamageType);
	if (pHurt)
	{
		if (pHurt->GetFlags() & (FL_MONSTER | FL_CLIENT))
		{
			pHurt->pev->punchangle = qaViewpunch;
			pHurt->SetVelocity(pHurt->GetVelocity() + vecVelocityPunch);
		}
		// Play a random attack hit sound
		EMIT_SOUND_DYN(ENT(pev), CHAN_WEAPON, pAttackHitSounds[RANDOM_LONG(0, ARRAYSIZE(pAttackHitSounds) - 1)], 1.0, ATTN_NORM, 0, 100 + RANDOM_LONG(-5, 5));
	}
	else // Play a random attack miss sound
		EMIT_SOUND_DYN(ENT(pev), CHAN_WEAPON, pAttackMissSounds[RANDOM_LONG(0, ARRAYSIZE(pAttackMissSounds) - 1)], 1.0, ATTN_NORM, 0, 100 + RANDOM_LONG(-5, 5));

	if (RANDOM_LONG(0, 1))
		AttackSound();

	return pHurt;
}