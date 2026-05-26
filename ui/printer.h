#ifndef PRINTER_H
#define PRINTER_H

#define SCREEN_WIDTH 21
#define SCREEN_HEIGHT 8

typedef struct {
	int x;
	int y;
} Printer;

void Printer_setup(int x, int y);
void Printer_setupDefault();

int Printer_getXCoordinate();
int Printer_getYCoordinate();
void Printer_setCoordinates(int x, int y);

void Printer_print(const char* insputString);
void Printer_printLine(const char* inputString);

void Printer_newLine();

void Printer_spot(int x, int y, char character);
void Printer_spotDefault(int x, int y);

void Printer_clearScreen();
void Printer_clearEntireScreen();

#endif