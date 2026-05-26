// This file is normally used to communicate with the calculator.
// Instead, I have kept a few vital functions and directed them
// to the console.

#ifndef FXLIB_H
#define FXLIB_H

void locate(int x, int y); // Specifies specific pixel on 21x8 grid.

void Print(unsigned char* inputString); // Output text.

void Bdisp_AllClr_DDVRAM(); // Clear screen.

void GetKey(unsigned int* keyCode); // Gets key input

#endif