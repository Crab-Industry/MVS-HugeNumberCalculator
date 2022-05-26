#include "ShowHugeNumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_EXPONENT_MARKUP 2
#define EXPONENT_MARKUP " E"

static char SignToChar (const Sign sign) {
    switch (sign) {
        case PLUS:
            return '+';
        case MINUS:
            return '-';
        default:
            return 'E';
    }
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
    const int stringLength = getHugeIntLength (hugeInt) + 1;
    char* hugeIntInString = NULL;

    if (hugeInt != NULL) {
        hugeIntInString = malloc (stringLength * sizeof (HugeInt));
        if (hugeIntInString != NULL) {
            char* absoluteValueInString = HugeUnsignedIntToString (hugeInt->absoluteValue);
            hugeIntInString[0] = SignToChar (hugeInt->sign);
            memcpy (hugeIntInString + 1, absoluteValueInString, stringLength);
            free (absoluteValueInString);
        }
    }

    return hugeIntInString;
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