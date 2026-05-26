#include "tools.h"

#include <stdio.h> // For intToString
#include <stdlib.h> // For stringToFloat

unsigned char* intToString(int value)
{
    static unsigned char buffer[16];

    snprintf((char*)buffer, sizeof(buffer), "%d", value);

    return buffer;
}

float stringToFloat(const char* text)
{
    return (float)atof(text);
}