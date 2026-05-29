#include "settings.h"

#include "../ui/printer.h"
#include "../ui/scanner.h"

#include "../ui/background.h"

void Settings_startSettingsSystem()
{
	Printer_printLine("1. Background");
	Printer_printLine("2. About");

	char key;

	do {
		key = Scanner_getKeySilent();
	} while (key != '1' && key != '2');

	if (key == '1') Settings_Background();
	else if (key == '2') Settings_About();
}

void Settings_Background()
{
	Printer_clearScreen();
	Printer_setCoordinates(1, 1);

	Printer_printLine("1. Toggle");
	Printer_printLine("2. Theme");

	char key;

	do {
		key = Scanner_getKeySilent();
	} while (key != '1' && key != '2');

	if (key == '1') // Toggle
	{
		Printer_clearScreen();
		Printer_setCoordinates(1, 1);

		Printer_printLine("1. Enable");
		Printer_printLine("2. Disable");
		Printer_printLine("3. Get status");

		do {
			key = Scanner_getKeySilent();
		} while (key != '1' && key != '2' && key != '3');

		if (key == '1') Background_setBackgroundStatus(UIMODE_BORDERED);
		else if (key == '2') Background_getBackgroundStatus(UIMODE_FULLSCREEN);
		else if (key == '3')
		{
			Printer_clearScreen();
			Printer_setCoordinates(1, 1);
			Printer_printLine("Current status:");
			if (Background_getBackgroundStatus() == UIMODE_BORDERED) Printer_printLine("Enabled");
			else if (Background_getBackgroundStatus() == UIMODE_FULLSCREEN) Printer_printLine("Disabled");
		}

		Scanner_waitForKeyDefault();
	}

	else if (key == '2') // Theme
	{
		Printer_clearScreen();
		Printer_setCoordinates(1, 1);

		Printer_printLine("1. Stars");
		Printer_printLine("2. Lines");
		Printer_printLine("3. Hashtags");
		Printer_printLine("4. Circles");
		Printer_printLine("5. Get status");

		do {
			key = Scanner_getKeySilent();
		} while (key != '1' && key != '2' && key != '3'
			&& key != '4' && key != '5');

		if (key == '1') Background_setBackgroundStyle(UISTYLE_STARS);
		else if (key == '2') Background_setBackgroundStyle(UISTYLE_LINES);
		else if (key == '3') Background_setBackgroundStyle(UISTYLE_HASHTAGS);
		else if (key == '4') Background_setBackgroundStyle(UISTYLE_CIRCLES);
		else if (key == '5')
		{
			Printer_clearScreen();
			Printer_setCoordinates(1, 1);

			Printer_printLine("Currently selected:");
			if (Background_getBackgroundStyle() == UISTYLE_STARS) Printer_printLine("Stars");
			else if (Background_getBackgroundStyle() == UISTYLE_LINES) Printer_printLine("Lines");
			else if (Background_getBackgroundStyle() == UISTYLE_HASHTAGS) Printer_printLine("Hashtags");
			else if (Background_getBackgroundStyle() == UISTYLE_CIRCLES) Printer_printLine("Circles");

			// Warn user if backgroud is not enabled.
			if (Background_getBackgroundStatus() == UIMODE_FULLSCREEN)
			{
				Printer_printLine("Note, the background");
				Printer_printLine("is not enabled.");
			}
		}

		Scanner_waitForKeyDefault();
	}
}

void Settings_About()
{
	Printer_clearScreen();
	Printer_setCoordinates(1, 1);

	Printer_printLine("CWCas");
	Printer_printLine("By Cai Wheate");
	Printer_newLine();
	Printer_printLine("A multi tool.");

	Scanner_waitForKeyDefault();
}