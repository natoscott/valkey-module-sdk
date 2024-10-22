#include <string.h>
#include <sys/param.h>
#include <ctype.h>
#include "strings.h"


#include "sds.h"

// ValkeyModuleString *VKMUtil_CreateFormattedString(ValkeyModuleCtx *ctx, const char *fmt, ...) {
//     sds s = sdsempty();
    
//     va_list ap;
//     va_start(ap, fmt);
//     s = sdscatvprintf(s, fmt, ap);
//     va_end(ap);
    
//     ValkeyModuleString *ret = ValkeyModule_CreateString(ctx, (const char *)s, sdslen(s));
//     sdsfree(s);
//     return ret;
// }

int VKMUtil_StringEquals(ValkeyModuleString *s1, ValkeyModuleString *s2) {
    
    
    const char *c1, *c2;
    size_t l1, l2;
    c1 = ValkeyModule_StringPtrLen(s1, &l1);
    c2 = ValkeyModule_StringPtrLen(s2, &l2);
    if (l1 != l2) return 0;

    return strncmp(c1, c2, l1) == 0;
}

int VKMUtil_StringEqualsC(ValkeyModuleString *s1, const char *s2) {
    
    
    const char *c1;
    size_t l1, l2 = strlen(s2);
    c1 = ValkeyModule_StringPtrLen(s1, &l1);
    if (l1 != l2) return 0;
    
    return strncmp(c1, s2, l1) == 0;
}

void VKMUtil_StringToLower(ValkeyModuleString *s) {
    
    size_t l;
    char *c = (char *)ValkeyModule_StringPtrLen(s, &l);
    size_t i;
    for (i = 0; i < l; i++) {
        *c = tolower(*c);
        ++c;
    }
    
}

void VKMUtil_StringToUpper(ValkeyModuleString *s) {
    size_t l;
    char *c = (char *)ValkeyModule_StringPtrLen(s, &l);
    size_t i;
    for (i = 0; i < l; i++) {
        *c = toupper(*c);
        ++c;
    }
    
    
}
