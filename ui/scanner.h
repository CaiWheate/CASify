#ifndef SCANNER_H
#define SCANNER_H

char Scanner_mapKey(unsigned int keyCode);

void Scanner_waitForKey(unsigned int keyCode);
void Scanner_waitForKeyDefault();

char Scanner_getKey();
char Scanner_getKeySilent();

void Scanner_getString(unsigned char* buffer, int bufferCapacity);
void Scanner_getStringSilent(unsigned char* buffer, int bufferCapacity);

#endif