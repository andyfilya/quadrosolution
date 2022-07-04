#include "head.h"
bool Equal_2(double x, double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return (fabs(x-y) < EPSILON);
}
bool Zero(double x)
{
    assert(isfinite(x));
    return (fabs(x) < EPSILON);
}
