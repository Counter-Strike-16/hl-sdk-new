
#include "extdll.h"
#include "enginecallback.h"
#include "gamestringpool.h"

string_t AllocPooledString(const char *pszValue)
{
	return ALLOC_STRING(pszValue);
}