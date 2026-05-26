#include "apps.h"

#include "cas_app.h"
#include "complex_app.h"
#include "constants_app.h"
#include "conversion_app.h"
#include "finance_app.h"
#include "formula_app.h"
#include "geometry_app.h"
#include "linearalgebra_app.h"
#include "numerical_app.h"
#include "probability_app.h"
#include "solver_app.h"
#include "stats_app.h"

void Apps_StartApp(AppList app)
{
	switch (app)
	{
	case CAS:
		Cas_App_Start();
		break;
	case COMPLEX:
		Complex_App_Start();
		break;
	case CONSTANTS:
		Constants_App_Start();
		break;
	case CONVERSION:
		Conversion_App_Start();
		break;
	case FINANCE:
		Finance_App_Start();
		break;
	case FORMULA:
		Formula_App_Start();
		break;
	case GEOMETRY:
		Geometry_App_Start();
		break;
	case LINEARALGEBRA:
		LinearAlgebra_App_Start();
		break;
	case NUMERICAL:
		Numerical_App_Start();
		break;
	case PROBABILITY:
		Probability_App_Start();
		break;
	case SOLVER:
		Solver_App_Start();
		break;
	case STATS:
		Stats_App_Start();
		break;
	}
}