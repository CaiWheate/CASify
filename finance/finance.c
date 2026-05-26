#include "finance.h"

#include "annuity.h"
#include "depreciation.h"
#include "interest.h"
#include "loans.h"

void Finance_startFinanceSystem()
{
	Printer_printLine("1. Annuity");
	Printer_printLine("2. Depreciation");
	Printer_printLine("3. Interest");
	Printer_printLine("4. Loans");

	char option;
	do
	{
		option = Scanner_getKeySilent();

	} while (option != '1' &&
		option != '2' &&
		option != '3' &&
		option != '4');

	Printer_clearScreen();
	Printer_setCoordinates(1, 1);

	switch (option)
	{
	case '1':
		Annuity_startAnnuity();
		break;
	case '2':
		Depreciation_startDepreciation();
		break;
	case '3':
		Interest_startInterest();
		break;
	case '4':
		Loans_startLoans();
		break;
	}
}