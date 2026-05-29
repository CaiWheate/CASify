#include "menu.h"

#include "../apps/apps.h"
#include "../platform/console.h"

#include "printer.h" // Output
#include "scanner.h" // Input
#include "loading.h" // Loading screens
#include "background.h" // Background

#include "../tools/tools.h"

#include <stdio.h> // For snprintf.

Menu menu;

void Menu_goUp()
{
	if (menu.selectedIndex > 0)
	{
		menu.selectedIndex -= 1;
	}
}
void Menu_goDown()
{
	if (menu.selectedIndex < menu.itemCount - 5 - (2 - Background_getOffsetY() * 2))
	{
		menu.selectedIndex += 1;
	}
}

void Menu_selectItem(int option)
{
	// Check that only options 6 and 7 are being used when there is no background.
	if (Background_getDisplayAreaHeight() == 8 || (option <= 5 && Background_getDisplayAreaHeight() == 6))
	{
		const char* selectedOption = menu.items[menu.selectedIndex - 1 + option];

		Printer_clearScreen();

		//Printer_setCoordinates(printer, 1, 1);
		//Printer_print(printer, "Remember to load...");

		Printer_setCoordinates(1, 1);

		if (selectedOption == "CAS") Apps_StartApp(CAS);
		else if (selectedOption == "Complex") Apps_StartApp(COMPLEX);
		else if (selectedOption == "Constants") Apps_StartApp(CONSTANTS);
		else if (selectedOption == "Conversion") Apps_StartApp(CONVERSION);
		else if (selectedOption == "Finance") Apps_StartApp(FINANCE);
		else if (selectedOption == "Formula") Apps_StartApp(FORMULA);
		else if (selectedOption == "Geometry") Apps_StartApp(GEOMETRY);
		else if (selectedOption == "Linear Algebra") Apps_StartApp(LINEARALGEBRA);
		else if (selectedOption == "Numerical") Apps_StartApp(NUMERICAL);
		else if (selectedOption == "Probability") Apps_StartApp(PROBABILITY);
		else if (selectedOption == "Solver") Apps_StartApp(SOLVER);
		else if (selectedOption == "Stats") Apps_StartApp(STATS);
		else if (selectedOption == "Settings") Apps_StartApp(SETTINGS);
	}
}

void Menu_render()
{
	Background_render(); // Render background before anything!

	Printer_setCoordinates(1, 1);

	int i;
	for (i = 0; (i < menu.itemCount - 5 + (2 - Background_getOffsetY() * 2) && i < 5 + (2 - Background_getOffsetY() * 2)); i++)
	{
		char buffer[100];

		snprintf(buffer, sizeof(buffer),
			"%s. %s",
			intToString(menu.selectedIndex + i + 1),
			menu.items[menu.selectedIndex + i]);
		Printer_printLine(buffer);
	}
	Printer_printLine("Use arrows/numbers.");
}

void Menu_startMenu()
{
	Background_startBackground();
	Background_setBackgroundStyle(UISTYLE_LINES);
	Background_setBackgroundStatus(UIMODE_BORDERED);
	Background_render();

	Printer_setupDefault();
	Printer_printLine("Welcome to CASify");
	Printer_printLine("Press any key...");

	Scanner_waitForKeyDefault();

	Printer_clearScreen();

	menu.selectedIndex = 0;
	menu.itemCount = 13;

	const char* menuItems[] =
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
		"Statistics",
		"Settings"
	};
	menu.items = menuItems;

	// Main loop:
	while (1)
	{
		Menu_render();

		char key = Scanner_getKeySilent();

		if (key == 'K')	Menu_goUp();
		else if (key == 'M') Menu_goDown();

		else if (key == '1') Menu_selectItem(1);
		else if (key == '2') Menu_selectItem(2);
		else if (key == '3') Menu_selectItem(3);
		else if (key == '4') Menu_selectItem(4);
		else if (key == '5') Menu_selectItem(5);
		else if (key == '6') Menu_selectItem(6);
		else if (key == '7') Menu_selectItem(7);
	}
}