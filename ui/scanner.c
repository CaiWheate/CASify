#include "scanner.h"

#include "../platform/fxlib.h"
#include "../platform/keybios.h" // For Scanner_mapKey

#include "background.h" // For offsets

char Scanner_mapKey(unsigned int keyCode)
{
	switch (keyCode)
	{
	case KEY_CTRL_F1: return 'Y';
	case KEY_CTRL_F2: return 'U';
	case KEY_CTRL_F3: return 'I';
	case KEY_CTRL_F4: return 'O';
	case KEY_CTRL_F5: return 'P';
	case KEY_CHAR_K: return 'K';
	case KEY_CHAR_M: return 'M';
	case KEY_CHAR_0: return '0';
	case KEY_CHAR_1: return '1';
	case KEY_CHAR_2: return '2';
	case KEY_CHAR_3: return '3';
	case KEY_CHAR_4: return '4';
	case KEY_CHAR_5: return '5';
	case KEY_CHAR_6: return '6';
	case KEY_CHAR_7: return '7';
	case KEY_CHAR_8: return '8';
	case KEY_CHAR_9: return '9';
	case KEY_CHAR_S: return 'S';
	case KEY_CHAR_C: return 'C';
	case KEY_CHAR_T: return 'T';
	case KEY_CHAR_X: return 'X';
	case KEY_CHAR_LPAR: return '(';
	case KEY_CHAR_RPAR: return ')';
	case KEY_CHAR_PLUS: return '+';
	case KEY_CHAR_MINUS: return '-';
	case KEY_CTRL_DEL: return 'Y';
	case KEY_CTRL_EXE: return 'A';
	default: return 'Z';
	}
}

void Scanner_waitForKey(unsigned int keyCode)
{
	unsigned int kc = 0;
	while (kc != keyCode)
	{
		GetKey(&kc);
	}
}
void Scanner_waitForKeyDefault()
{
	unsigned int keyCode;
	GetKey(&keyCode);
}

char Scanner_getKey()
{
	unsigned int keyCode;
	char c;
	unsigned char str[2];

	locate(1 + Background_getOffsetX(), 8 - Background_getOffsetY());
	GetKey(&keyCode);

	c = Scanner_mapKey(keyCode);

	while (c == 'Z')
	{
		GetKey(&keyCode);
		c = Scanner_mapKey(keyCode);
	}

	str[0] = (unsigned char)c;
	str[1] = '\0';

	Print(str);


	return c;
}
char Scanner_getKeySilent()
{
	unsigned int keyCode;
	char c;
	unsigned char str[2];

	locate(1 + Background_getOffsetX(), 8 - Background_getOffsetY());
	GetKey(&keyCode);

	c = Scanner_mapKey(keyCode);

	while (c == 'Z')
	{
		GetKey(&keyCode);
		c = Scanner_mapKey(keyCode);
	}

	str[0] = (unsigned char)c;
	str[1] = '\0';

	return c;
}

void Scanner_getString(unsigned char* buffer, int bufferCapacity)
{
	unsigned int keyCode;
	int index = 0;

	locate(1 + Background_getOffsetX(), 8 - Background_getOffsetY());

	while (index < bufferCapacity - 1)
	{
		char c;
		unsigned char str[2];

		GetKey(&keyCode);

		if (keyCode == KEY_CTRL_EXE)
		{
			break;
		}

		c = Scanner_mapKey(keyCode);

		if (c != 'Z' && c != 'Y' && c != 0)
		{
			str[0] = (unsigned char)c;
			str[1] = '\0';

			Print(str);

			buffer[index++] = c;
		}
		else if (c == 'Y')
		{
			if (index > 0)
			{
				index--;

				locate(index + 1 + Background_getOffsetX(), 8);
				Print(" ");
				locate(index + 1 + Background_getOffsetX(), 8);
			}
		}
	}
	buffer[index] = '\0';
}
void Scanner_getStringSilent(unsigned char* buffer, int bufferCapacity)
{
	unsigned int keyCode;
	int index = 0;

	locate(1 + Background_getOffsetX(), 8 - Background_getOffsetY());

	while (index < bufferCapacity - 1)
	{
		char c;
		unsigned char str[2];

		GetKey(&keyCode);

		if (keyCode == KEY_CTRL_EXE)
		{
			break;
		}

		c = Scanner_mapKey(keyCode);

		if (c != 'Z' && c != 'Y' && c != 0)
		{
			str[0] = (unsigned char)c;
			str[1] = '\0';

			buffer[index++] = c;
		}
		else if (c == 'Y')
		{
			if (index > 0)
			{
				index--;

				locate(index + 1 + Background_getOffsetX(), 8);
				Print(" ");
				locate(index + 1 + Background_getOffsetX(), 8);
			}
		}
	}
	buffer[index] = '\0';
}