#ifndef ANNUITY_H
#define ANNUITY_H

#include "../ui/printer.h"
#include "../ui/scanner.h"

void Annuity_startAnnuity();

void Annuity_printFormula();

void Annuity_calculate();

float Annuity_solveFutureValue();
float Annuity_solvePeriodicPayment();
float Annuity_solveInterestRatePerPeriod();
float Annuity_solveNumberOfPeriods();

#endif