
/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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
#ifndef UTIL_AUX_H
#define UTIL_AUX_H

extern int UTIL_PrecacheModel(const char* name);
extern int UTIL_PrecacheSound(const char* name);
extern void UTIL_PrecacheSoundArray(const char** pArray, const int count);
extern unsigned short UTIL_PrecacheEvent(int type, const char* name);

extern int PrecacheModel(const char* name);
extern int PrecacheSound(const char* name);
extern void PrecacheSoundArray(const char** pArray, const int count);
extern unsigned short PrecacheEvent(int type, const char* name);

#define DECLARE_CLASS( dllclass, baseclass ) \
	typedef dllclass ThisClass; \
	typedef baseclass BaseClass;


#define DECLARE_CLASS_NOBASE( dllclass ) \
	typedef dllclass ThisClass;



#define DECLARE_DATADESC() \
	virtual int		Save( CSave &save );\
	virtual int		Restore(CRestore &restore);\
	\
	static	TYPEDESCRIPTION m_SaveData[];

#define BEGIN_DATADESC( dllclass ) \
	TYPEDESCRIPTION dllclass::m_SaveData[] = {

#define END_DATADESC() };


#endif // UTIL_AUX_H