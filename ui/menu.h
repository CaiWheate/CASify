#ifndef MENU_H
#define MENU_H

#include "printer.h"

typedef struct
{
    int selectedIndex;
    int itemCount;
    const char** items;
} Menu;

void Menu_goUp();
void Menu_goDown();

void Menu_selectItem(int option);

void Menu_render();

void Menu_startMenu();

#endif