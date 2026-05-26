#ifndef APPS_H
#define APPS_H

#include "../ui/printer.h"
#include "../ui/scanner.h"

typedef enum {
	CAS,
	COMPLEX,
	CONSTANTS,
	CONVERSION,
	FINANCE,
	FORMULA,
	GEOMETRY,
	LINEARALGEBRA,
	NUMERICAL,
	PROBABILITY,
	SOLVER,
	STATS
} AppList;


void Apps_StartApp(AppList app);

#endif