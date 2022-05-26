#include "ShowHugeNumber.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_EXPONENT_MARKUP 2
#define EXPONENT_MARKUP " E"

static char SignToChar (const Sign sign) {
    return 0;
}

static char* HugeUnsignedIntToString (const HugeUnsignedInt* hugeUnsignedInt) {
    const int stringLength = getHugeUnsignedIntLength (hugeUnsignedInt) + 1;
    char* hugeUnsignedIntInString = NULL;

    if (hugeUnsignedInt != NULL) {
        hugeUnsignedIntInString = malloc (stringLength * sizeof (HugeUnsignedInt));
        if (hugeUnsignedIntInString != NULL) {
            Node* node = hugeUnsignedInt->start;;
            for (int digitCounter = 0; (!isNodeEmpty (node)) && (digitCounter < stringLength); digitCounter++) {
                hugeUnsignedIntInString[digitCounter] = digitToChar (node->digit);
                node = node->next;
            }
            hugeUnsignedIntInString[stringLength - 1] = '\0';
        }
    }

    return hugeUnsignedIntInString;
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
    char* hugeIntString = HugeIntToString (hugeInt);
    printf ("%s\n", hugeIntString);
    free (hugeIntString);
}

void printHugeFloat (const HugeFloat* hugeFloat) {
}