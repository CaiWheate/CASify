#include "printer.h"

#include "background.h"

#include "../platform/fxlib.h"

#include <string.h>

static Printer printer;

void Printer_setup(int x, int y)
{

	if (Background_getBackgroundStatus() == UIMODE_BORDERED)
	{
		printer.x = x + Background_getOffsetX();
		printer.y = y + Background_getOffsetY();
	}
	else
	{
		printer.x = x;
		printer.y = y;
	}
	
	locate(printer.x, printer.y);
	return printer;
}
void Printer_setupDefault()
{
	if (Background_getBackgroundStatus() == UIMODE_FULLSCREEN)
	{
		printer.x = 1;
		printer.y = 1;
	}
	else if (Background_getBackgroundStatus() == UIMODE_BORDERED)
	{
		printer.x = 2;
		printer.y = 2;
	}

	locate(printer.x, printer.y);
	Bdisp_AllClr_DDVRAM();
	return printer;
}

int Printer_getXCoordinate()
{
	return printer.x;
}
int Printer_getYCoordinate()
{
	return printer.y;
}
void Printer_setCoordinates(int x, int y)
{
	printer.x = x + Background_getOffsetX();
	printer.y = y + Background_getOffsetY();

	locate(printer.x, printer.y);
}

void Printer_print(const char* inputString)
{
	//printer.x = 1 + Background_getOffsetX();
	locate(printer.x, printer.y);
	Print((unsigned char*)inputString);
	printer.x += (int)strlen(inputString);
	//if (printer.x > Background_getDisplayAreaWidth())
	//{
	//	printer.x -= Background_getDisplayAreaWidth();
	//	printer->y += 1;
	//}
}
void Printer_printLine(const char* inputString)
{
	locate(printer.x, printer.y);
	Print((unsigned char*)inputString);
	printer.x += (int)strlen(inputString);
	
	int i = 0;
	for (i = 0; i < Background_getDisplayAreaWidth() + Background_getOffsetX() + 1 - printer.x; i++)
	{
		Print((unsigned char*)" ");
	}

	printer.x = 1 + Background_getOffsetX();
	printer.y += 1;
}

void Printer_newLine()
{
	printer.x = 1 + Background_getOffsetX();
	printer.y += 1;
}

void Printer_spot(int x, int y, char character)
{
	char text[2];
	text[0] = character;
	text[1] = '\0';

	locate(x, y);
	Print((unsigned char*)text);
	locate(printer.x, printer.y);
}
void Printer_spotDefault(int x, int y)
{
	locate(x, y);
	Print((unsigned char*)"*");
	locate(printer.x, printer.y);
}

void Printer_clearScreen()
{
	int originalX = 0;
	int originalY = 0;

	for (int y = Background_getOffsetY() + 1; y < Background_getDisplayAreaHeight() + (Background_getOffsetY() * 2); y++) // For each row.
	{
		for (int x = 1 + Background_getOffsetX(); x < Background_getDisplayAreaWidth() + (Background_getOffsetX() * 2); x++) // For each character in row.
		{
			locate(x, y);
			Print(" ");
		}
	}
}
void Printer_clearEntireScreen()
{
	Bdisp_AllClr_DDVRAM();
}