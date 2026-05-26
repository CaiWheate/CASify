#include "console.h"

#include <stdio.h> // For console window, input and output.
#include <stdlib.h>

#include <WinUser.h> // For removing scroll bars.

void Console_startConsole()
{

}

void Console_stopConsole()
{
	FreeConsole();
}

void Console_clearConsole()
{
	HANDLE consoleHandle;
	COORD home = { 0, 0 };
	
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(consoleHandle, home);

	for (int y = 0; y < 8; y++) // For each row.
	{
		for (int x = 0; x < 21; x++) // For each character in row.
		{
			printf(" ");
		}

		printf("\n");
	}

}

COORD Console_getConsoleCursorPosition()
{
	HANDLE consoleHandle;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(consoleHandle, &screenBufferInfo);

	return screenBufferInfo.dwCursorPosition;
}