#include "menu.h"

#include "../apps/apps.h"
#include "../platform/console.h"

#include "printer.h" // Output
#include "scanner.h" // Input
#include "loading.h" // Loading screens
#include "background.h" // Background

#include "../tools/tools.h"

#include <stdio.h> // For snprintf.

void Menu_goUp(Menu* menu)
{
	if (menu -> selectedIndex > 0)
	{
		menu -> selectedIndex -= 1;
	}
}
void Menu_goDown(Menu* menu)
{
	if (menu->selectedIndex < menu -> itemCount - 5)
	{
		menu->selectedIndex += 1;
	}
}

void Menu_selectItem(Menu* menu, int option)
{
	const char* selectedOption = menu->items[menu->selectedIndex - 1 + option];

	Printer_clearScreen();

	//Printer_setCoordinates(printer, 1, 1);
	//Printer_print(printer, "Remember to load...");
	Printer_setCoordinates(1, 1);

	
	Sleep(100);

	if (selectedOption == "CAS")
	{
		Apps_StartApp(CAS);
	}
	else if (selectedOption == "Complex")
	{
		Apps_StartApp(COMPLEX);
	}
	else if (selectedOption == "Constants")
	{
		Apps_StartApp(CONSTANTS);
	}
	else if (selectedOption == "Conversion")
	{
		Apps_StartApp(CONVERSION);
	}
	else if (selectedOption == "Finance")
	{
		Apps_StartApp(FINANCE);
	}
	else if (selectedOption == "Formula")
	{
		Apps_StartApp(FORMULA);
	}
	else if (selectedOption == "Geometry")
	{
		Apps_StartApp(GEOMETRY);
	}
	else if (selectedOption == "Linear Algebra")
	{
		Apps_StartApp(LINEARALGEBRA);
	}
	else if (selectedOption == "Numerical")
	{
		Apps_StartApp(NUMERICAL);
	}
	else if (selectedOption == "Probability")
	{
		Apps_StartApp(PROBABILITY);
	}
	else if (selectedOption == "Solver")
	{
		Apps_StartApp(SOLVER);
	}
	else if (selectedOption == "Stats")
	{
		Apps_StartApp(STATS);
	}
}

void Menu_render(Menu* menu)
{
	Printer_setCoordinates(1, 1);

	int i;
	for (i = 0; (i < menu -> itemCount - 5 && i < 5); i++)
	{
		char buffer[100];

		snprintf(buffer, sizeof(buffer),
			"%s. %s",
			intToString(menu->selectedIndex + i + 1),
			menu->items[menu->selectedIndex + i]);
		Printer_printLine(buffer);
	}
}

void Menu_startMenu()
{
	Printer_setupDefault();

	Background_startBackground();
	Background_setBackgroundStyle(UISTYLE_LINES);

	Background_render();

	Printer_setCoordinates(1, 1);

	Printer_printLine("Welcome to CASify");
	Printer_printLine("Press any key...");

	Scanner_waitForKeyDefault();

	Printer_clearScreen();
	Menu menu = {
		0,
		12,
		{
			"CAS",
			"Complex",
			"Constant",
			"Conversion",
			"Finance",
			"Formula",
			"Geometry",
			"Linear Algebra",
			"Numerical",
			"Probability",
			"Solver",
			"Statistics"
		}
	};

	// Main loop:
	while (1)
	{
		Menu_render(&menu);

		char key = Scanner_getKeySilent();

		if (key == 'K')
		{
			Menu_goUp(&menu);
		}
		else if (key == 'M')
		{
			Menu_goDown(&menu);
		}

		else if (key == 'Y')
		{
			Menu_selectItem(&menu, 1);
		}
		else if (key == 'U')
		{
			Menu_selectItem(&menu, 2);
		}
		else if (key == 'I')
		{
			Menu_selectItem(&menu, 3);
		}
		else if (key == 'O')
		{
			Menu_selectItem(&menu, 4);
		}
		else if (key == 'P')
		{
			Menu_selectItem(&menu, 5);
		}
	}
}