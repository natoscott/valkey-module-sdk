#ifndef __VKMUTIL_STRINGS_H__
#define __VKMUTIL_STRINGS_H__

#include <valkeymodule.h>

/*
* Create a new ValkeyModuleString object from a printf-style format and arguments.
* Note that ValkeyModuleString objects CANNOT be used as formatting arguments.
*/
// DEPRECATED since it was added to the ValkeyModule API. Replaced with a macro below
//ValkeyModuleString *VKMUtil_CreateFormattedString(ValkeyModuleCtx *ctx, const char *fmt, ...);
#define VKMUtil_CreateFormattedString ValkeyModule_CreateStringPrintf

/* Return 1 if the two strings are equal. Case *sensitive* */
extern int VKMUtil_StringEquals(ValkeyModuleString *s1, ValkeyModuleString *s2);

/* Return 1 if the string is equal to a C NULL terminated string. Case *sensitive* */
extern int VKMUtil_StringEqualsC(ValkeyModuleString *s1, const char *s2);

/* Converts a valkey string to lowercase in place without reallocating anything */
extern void VKMUtil_StringToLower(ValkeyModuleString *s);

/* Converts a valkey string to uppercase in place without reallocating anything */
extern void VKMUtil_StringToUpper(ValkeyModuleString *s);
#endif
