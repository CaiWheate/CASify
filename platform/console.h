#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h> // For grabbing console handle.

void Console_startConsole(); // Start console.
void Console_stopConsole(); // Stop console.

void Console_clearConsole(); // system("cls") doesn't work for AllocConsole().

COORD Console_getConsoleCursorPosition(); // Grabs the console cursor position.
// Useful for resetting cursor position after clearing the console,
// as we are forced to change it.

#endif