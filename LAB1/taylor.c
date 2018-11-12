#include "taylor.h"

double tcos(double x)
{
	return 1.0 - ((x * x) / 2.0) + ((x * x * x * x) / 24.0);
}

double tcos_erro(double x)
{
	return (x * x * x * x * x * x) / 720.0;
}

double tsqrt(double x)
{
	return 1.0 + (0.5 * (x - 1.0)) - (0.125 * (x - 1) * (x - 1)) + (0.0625 * (x - 1) * (x - 1) * (x - 1));
}

double tsqrt_erro(double x)
{
	return (0.0390625 * (x - 1) * (x - 1) * (x - 1) * (x - 1)) * 0.9375;
}