#ifndef MENU_H
#define MENU_H

#include "printer.h"

typedef struct
{
	int selectedIndex;
	
	int itemCount;
	const char* items[]; // Pointer to an array of strings.
} Menu;

void Menu_goUp(Menu* menu);
void Menu_goDown(Menu* menu);

void Menu_selectItem(Menu* menu, int option);

void Menu_render(Menu* menu);

void Menu_startMenu();

#endif