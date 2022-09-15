/*!
\file 
\brief functions of solution quadratic equation
*/

#include "head.h"

bool Zero(double x)
{
    return (fabs(x) < EPSILON);
}

bool IsEqual(double x, double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return Zero(x-y);
}

COUNT_OF_ROOTS SolveLinear(double b, double c, double *x_1)
{
    assert(isfinite(b) && isfinite(c));
    assert(x_1 != NULL);
    if (Zero(b))
    {
        if(Zero(c))
        {
            return ROOT_3;
        }
        return ROOT_0;
    }
    *x_1 = (-c) / b;
    
    return ROOT_1;
}

COUNT_OF_ROOTS SolveQuadratic(double a, double b, double c, double *x_1, double *x_2)
{
    assert(isfinite(a) && isfinite(b) && isfinite(c));
    assert(x_1 != NULL && x_2 != NULL);
    assert(x_1 != x_2);
    if (Zero(a))
    {
        return SolveLinear(b, c, x_1);
    }

    double D = b * b - 4 * a * c;

    if (D < 0)
    {
        return ROOT_0;
    }
    if (Zero(D))
    {
        *x_1 = (-b) / (2 * a);
        return ROOT_1;
    }
    if (D > 0)
    {
        double sqD = sqrt(D);

        *x_1 = (-b + sqD) / (2 * a);
        *x_2 = (-b - sqD) / (2 * a);

        return ROOT_2; 
    }
}
