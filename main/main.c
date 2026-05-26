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
Change Printer to not need to be parsed in to EVERYTHING. Declare globally in Printer, perhaps?
^ moving includes from .h to .c may be required.
Stats system and subsystem implementation
Loading screen
Add static functions to scanner
printer set coordinates and other similar could be COORD
perhaps we dont need all the apps.h stuff.
apply same printer fix to menu if possible
refine scanner to be ilent boolean triggered
fix menu letters
*/