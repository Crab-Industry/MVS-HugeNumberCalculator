#include "ShowHugeNumber.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_EXPONENT_MARKUP 2
#define EXPONENT_MARKUP " E"

static char SignToChar (const Sign sign) {
    return 0;
}

static char* HugeUnsignedIntToString (const HugeUnsignedInt* hugeUnsignedInt) {
    return NULL;
}

static char* HugeIntToString (const HugeInt* hugeInt) {
    return NULL;
}

static char* HugeFloatToString (const HugeFloat* hugeFloat) {
    return NULL;
}

void printHugeUnsignedInt(const HugeUnsignedInt* hugeUnsignedInt) {
    char* hugeUnsignedIntString = HugeUnsignedIntToString(hugeUnsignedInt);
    printf("%s\n", hugeUnsignedIntString);
    free(hugeUnsignedIntString);
}

void printHugeInt (const HugeInt* hugeInt) {
}

void printHugeFloat (const HugeFloat* hugeFloat) {
}