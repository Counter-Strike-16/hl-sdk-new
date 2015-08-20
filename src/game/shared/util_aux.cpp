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
#include "extdll.h"
#include "enginecallback.h"
#include "util_aux.h"


int UTIL_PrecacheModel(const char* name)
{
	return PRECACHE_MODEL((char*)name);
}

int UTIL_PrecacheSound(const char* name)
{
	return PRECACHE_SOUND((char*)name);
}

void UTIL_PrecacheSoundArray(const char** pArray, const int count)
{
	for (int i = 0; i < count; i++)
		PRECACHE_SOUND((char*)*(pArray + i));
}

unsigned short UTIL_PrecacheEvent(int type, const char* name)
{
	return PRECACHE_EVENT(type, name);
}

int PrecacheModel(const char* name)
{
	return UTIL_PrecacheModel((char*)name);
}

int PrecacheSound(const char* name)
{
	return UTIL_PrecacheSound((char*)name);
}

void PrecacheSoundArray(const char** pArray, const int count)
{
	UTIL_PrecacheSoundArray(pArray, count);
}

unsigned short PrecacheEvent(int type, const char* name)
{
	return UTIL_PrecacheEvent(type, name);
}