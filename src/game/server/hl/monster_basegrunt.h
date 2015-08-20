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

#ifndef BASEGRUNT_H
#define BASEGRUNT_H

enum GRUNT_BODYGROUPS
{
	HEAD_GROUP	= 1,
	GUN_GROUP	= 2,
};

enum GRUNT_HEADS
{
	HEAD_GRUNT = 0,
	HEAD_COMMANDER,
	HEAD_SHOTGUN,
	HEAD_M203,
};

enum GRUNT_GUNS
{
	GUN_MP5 = 0,
	GUN_SHOTGUN,
	GUN_NONE,
};

//=========================================================
// monster-specific DEFINE's
//=========================================================

#define	GRUNT_CLIP_SIZE					36 // how many bullets in a clip? - NOTE: 3 round burst sound, so keep as 3 * x!
#define GRUNT_VOL						0.35		// volume of grunt sounds
#define GRUNT_ATTN						ATTN_NORM	// attenutation of grunt sentences
#define HGRUNT_LIMP_HEALTH				20
#define HGRUNT_DMG_HEADSHOT				( DMG_BULLET | DMG_CLUB )	// damage types that can kill a grunt with a single headshot.
#define HGRUNT_NUM_HEADS				2 // how many grunt heads are there? 
#define HGRUNT_MINIMUM_HEADSHOT_DAMAGE	15 // must do at least this much damage in one shot to head to score a headshot kill
#define	HGRUNT_SENTENCE_VOLUME			(float)0.35 // volume of grunt sentences

#define HGRUNT_9MMAR					( 1 << 0 )
#define HGRUNT_HANDGRENADE				( 1 << 1 )
#define HGRUNT_GRENADELAUNCHER			( 1 << 2 )
#define HGRUNT_SHOTGUN					( 1 << 3 )

class CBaseGrunt : public CSquadMonster
{
	DECLARE_CLASS(CBaseGrunt, CSquadMonster);
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	int ISoundMask(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	BOOL FCanCheckAttacks(void);
	BOOL CheckMeleeAttack1(float flDot, float flDist);
	BOOL CheckRangeAttack1(float flDot, float flDist);
	BOOL CheckRangeAttack2(float flDot, float flDist);
	void CheckAmmo(void);
	void SetActivity(Activity NewActivity);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	Vector GetGunPosition(void);
	void Shoot(void);
	void Shotgun(void);
	void PrescheduleThink(void);
	void GibMonster(void);
	void SpeakSentence(void);

	DECLARE_DATADESC();

	CBaseEntity	*Kick(void);
	Schedule_t	*GetSchedule(void);
	Schedule_t  *GetScheduleOfType(int Type);
	virtual void TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType);
	int TakeDamage(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType);

	int IRelationship(CBaseEntity *pTarget);

	BOOL FOkToSpeak(void);
	void JustSpoke(void);

	CUSTOM_SCHEDULES;

	// checking the feasibility of a grenade toss is kind of costly, so we do it every couple of seconds,
	// not every server frame.
	float m_flNextGrenadeCheck;
	float m_flNextPainTime;
	float m_flLastEnemySightTime;

	Vector	m_vecTossVelocity;

	BOOL	m_fThrowGrenade;
	BOOL	m_fStanding;
	BOOL	m_fFirstEncounter;// only put on the handsign show in the squad's first encounter.
	int		m_cClipSize;

	int m_voicePitch;

	int		m_iBrassShell;
	int		m_iShotgunShell;

	int		m_iSentence;

	static const char *pGruntSentences[];

	static const char *pPainSounds[];
	static const char *pDeathSounds[];

};


#endif // BASEGRUNT_H