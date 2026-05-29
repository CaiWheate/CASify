#include "apps.h"

#include "../cas/cas.h"
#include "../complex/complex.h"
#include "../constants/constants.h"
#include "../conversion/conversion.h"
#include "../finance/finance.h"
#include "../formula/formula.h"
#include "../geometry/geometry.h"
#include "../linearalgebra/linear_algebra.h"
#include "../numerical/numerical.h"
#include "../probability/probability.h"
#include "../solver/solver.h"
#include "../stats/stats.h"
#include "../settings/settings.h"

void Apps_StartApp(AppList app)
{
	switch (app)
	{
	case CAS:
		CAS_startCasSystem();
		break;
	case COMPLEX:
		Complex_startComplexSystem();
		break;
	case CONSTANTS:
		Constants_startConstantsSystem();
		break;
	case CONVERSION:
		Conversion_startConversionSystem();
		break;
	case FINANCE:
		Finance_startFinanceSystem();
		break;
	case FORMULA:
		Formula_startFormulaSystem();
		break;
	case GEOMETRY:
		Geometry_startGeometrySystem();
		break;
	case LINEARALGEBRA:
		LinearAlgebra_startLinearAlgebraSystem();
		break;
	case NUMERICAL:
		Numerical_startNumericalSystem();
		break;
	case PROBABILITY:
		Probability_startProbabilitySystem();
		break;
	case SOLVER:
		Solver_startSolverSystem();
		break;
	case STATS:
		//Stats_startStatsSystem();
		break;
	case SETTINGS:
		Settings_startSettingsSystem();
		break;
	}
}