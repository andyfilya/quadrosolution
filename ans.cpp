/*!
\file 
\brief functions of solution quadratic equation
*/

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

int SolveLinear(double b, double c, double *x_1)
{
    assert(isfinite(b) && isfinite(c));
    assert(x_1 != NULL);
    if (Zero(b))
    {
        if(Zero(c))
        {
            return R3;
        }
        return R0;
    }
    *x_1 = (-c) / b;
    return R1;
}

int SolveQuadratic(double a, double b, double c, double *x_1, double *x_2)
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
        return R0;
    }
    if (Zero(D))
    {
        *x_1 = (-b) / (2 * a);
        return R1;
    }
    if (D > 0)
    {
        *x_1 = (-b + sqrt(D)) / (2 * a);
        *x_2 = (-b - sqrt(D)) / (2 * a);
        return R2; 
    }
}

void Coef_scan(double *a, double *b, double *c)
{
    assert( a != NULL && b != NULL && c != NULL);
    assert( a != b && a != c && c != b);

    printf("You need to enter 3 coefficients a,b,c\n");
    
    char str_in[256] = ""; //for chars(in)
    int counter_of_coef = 0; //for errors
    int counter_of_attempts = 0; //for cicles

    while (1)
    {
        counter_of_coef = scanf("%lf %lf %lf", a, b, c);
        if(counter_of_coef != 3)
        {
            printf("You have to enter numbers, not letters\n");
            scanf("%255s\n", str_in);
            counter_of_attempts++;
            if (counter_of_attempts == 3)
            {
                printf("Incorrectly values\n");
                exit(1);
            }
        }
        else
        {
            break;
        }
    }

}

void GiveAns(int counter_of_roots, double x_1, double x_2)
{
    switch(counter_of_roots)
    {
        case R0:
            printf("No roots.\n");
            break;
        case R1:
            printf("One root: x = %.3lf\n", x_1);
            break;
        case R2:
            printf("Two roots x1 = %.3lf x2 = %.3lf\n", x_1, x_2);
            break;
        case R3:
            printf("Infinite roots\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}