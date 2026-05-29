#include "../platform/fxlib.h"

#include "../platform/console.h"
#include "../ui/menu.h"

int main()
{
	Console_startConsole();
	Menu_startMenu();

	return 0; // Automatically called after menu functions terminate.
}

/*
TODO: matrix 6x6 - 8x8
Stats system and subsystem implementation
Loading screen
Add static functions to scanner
printer set coordinates and other similar could be COORD
refine scanner to be silent boolean triggered
fix menu letters
keycodes are messed up - change from char to word
each app needs main loop
fix backspace issue
settings menu for background removal and change
print and printLine should extend past borders
*/