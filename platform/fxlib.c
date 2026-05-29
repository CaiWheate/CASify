#include "fxlib.h"

#include "console.h"
#include "keybios.h"

#include <Windows.h> // For setting the console cursor position for locate().
#include <conio.h> // For monitoring key presses.
#include <stdio.h> // For printf in Print().

// Definitions for functions in fxlib.h. This converts the code for the console.

void locate(int x, int y)
{
	// Create new cursor coordinate according to parameters.
	COORD coordinate;
	coordinate.X = x - 1; // Windows starts from (0, 0)...
	coordinate.Y = y - 1; // ...CASIO starts from (1, 1).

	// Apply new cursor coordinates to console.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void Print(unsigned char* inputString)
{
	printf("%s", inputString); // Print the input string. Protects against crashes.
}

void Bdisp_AllClr_DDVRAM()
{
	COORD consoleCursorPosition = Console_getConsoleCursorPosition();

	Console_clearConsole(); // Calls clear console function in console.h.

	locate(consoleCursorPosition.X, consoleCursorPosition.Y);
}

// GetKey function used in scanner and menu. Converts to calculator keycodes.

void GetKey(unsigned int* keyCode)
{
	// Wait for key press and store ASCII code as int.
	char key = getch();

	// Convert char to calculator character as defined in keybios.h.
	switch (key)
	{
		case 'y': *keyCode = KEY_CTRL_F1; 
			break;
		case 'u': *keyCode = KEY_CTRL_F2; 
			break;
		case 'i': *keyCode = KEY_CTRL_F3; 
			break;
		case 'o': *keyCode = KEY_CTRL_F4; 
			break;
		case 'p': *keyCode = KEY_CTRL_F5; 
			break;
		case 'k': *keyCode = KEY_CHAR_K; 
			break;
		case 'm': *keyCode = KEY_CHAR_M; 
			break;
		case '0': *keyCode = KEY_CHAR_0; 
			break;
		case '1': *keyCode = KEY_CHAR_1; 
			break;
		case '2': *keyCode = KEY_CHAR_2; 
			break;
		case '3': *keyCode = KEY_CHAR_3; 
			break;
		case '4': *keyCode = KEY_CHAR_4; 
			break;
		case '5': *keyCode = KEY_CHAR_5; 
			break;
		case '6': *keyCode = KEY_CHAR_6; 
			break;
		case '7': *keyCode = KEY_CHAR_7; 
			break;
		case '8': *keyCode = KEY_CHAR_8; 
			break;
		case '9': *keyCode = KEY_CHAR_9; 
			break;
		case 's': *keyCode = KEY_CHAR_S; 
			break;
		case 'c': *keyCode = KEY_CHAR_C; 
			break;
		case 't': *keyCode = KEY_CHAR_T; 
			break;
		case 'x': *keyCode = KEY_CHAR_X; 
			break;
		case '(': *keyCode = KEY_CHAR_LPAR; 
			break;
		case ')': *keyCode = KEY_CHAR_RPAR; 
			break;
		case '+': *keyCode = KEY_CHAR_PLUS; 
			break;
		case '-': *keyCode = KEY_CHAR_MINUS; 
			break;
		case 'd': *keyCode = KEY_CTRL_DEL; 
			break; // Replace DELETE key with D key.
		case 'a': *keyCode = KEY_CTRL_EXE; 
			break;
		default: *keyCode = KEY_CHAR_Z; 
			break;
	}
}