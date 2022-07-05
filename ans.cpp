#include "head.h"
bool Zero(double x)
{
    return (fabs(x) < EPSILON);
}

bool Equal_2(double x, double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return Zero(x-y);
}
int SolveEquation_1(double b, double c, double *x_2)
{
    assert(isfinite(b) && isfinite(c));
    assert(x_2 != NULL);
    if (Zero(b))
    {
        if(Zero(c))
        {
            return R3;
        }
        return R0;
    }
    *x_2 = (-c) / b;
    return R1;
}
int SolveEquation_2(double a, double b, double c, double *x_1, double *x_2)
{
    assert(isfinite(a) && isfinite(b) && isfinite(c));
    assert(x_1 != NULL && x_2 != NULL);
    assert(x_1 != x_2);
    if (Zero(a))
    {
        return SolveEquation_1(b, c, x_1);
    }
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        return R0;
    }
    if (Zero(D))
    {
        *x_2 = (-b) / (2 * a);
        return R1;
    }
    if (D > 0)
    {
        *x_1 = (-b + sqrt(D)) / (2 * a);
        *x_2 = (-b - sqrt(D)) / (2 * a);
        return R2; 
    }
}