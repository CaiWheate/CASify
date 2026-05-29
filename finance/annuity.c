#include "annuity.h"

#include "../tools/tools.h" // For string to float conversion.

void Annuity_startAnnuity()
{
	Printer_printLine("1. Formula");
	Printer_printLine("2. Calculate");

	char option;
	do
	{
		option = Scanner_getKeySilent();

	} while (option != '1' && option != '2');

	Printer_clearScreen();
	Printer_setCoordinates(1, 1);

	switch (option)
	{
	case '1':
		Annuity_printFormula();
		break;
	case '2':
		Annuity_calculate();
		break;
	}

	Printer_clearScreen();
	Printer_setCoordinates(1, 1);
}

void Annuity_printFormula()
{
	Printer_printLine("FV= P* [(1+r)^n -1]");
	Printer_printLine(" / r");
	Printer_printLine("PV = Present Value");
	Printer_printLine("P = Period Payment");
	Printer_printLine("r = Int % Period");
	Printer_printLine("n = Num of Payments");

	Scanner_waitForKeyDefault();
}

void Annuity_calculate()
{
	Printer_printLine("1. Solve FV");
	Printer_printLine("2. Solve Payment");
	Printer_printLine("3. Solve Rate");
	Printer_printLine("4. Solve Periods");

	char option;
	do
	{
		option = Scanner_getKeySilent();

	} while (option != '1' && option != '2'
		&& option != '3' && option != '4');

	float answer;

	Printer_clearScreen();
	Printer_setCoordinates(1, 1);

	switch (option)
	{
	case '1':
		answer = Annuity_solveFutureValue();
		break;
	case '2':
		answer = Annuity_solvePeriodicPayment();
		break;
	case '3':
		answer = Annuity_solveInterestRatePerPeriod();
		break;
	case '4':
		answer = Annuity_solveNumberOfPeriods();
		break;
	}
}

float Annuity_solveFutureValue()
{
	char buffer[16];

	Printer_print("Periodic Payment?");
	Scanner_getString(buffer, 16);
	float periodicPayment = stringToFloat(buffer);

	Printer_clearLine(6);

	Sleep(10000);
}
float Annuity_solvePeriodicPayment()
{

}
float Annuity_solveInterestRatePerPeriod()
{

}
float Annuity_solveNumberOfPeriods()
{

}