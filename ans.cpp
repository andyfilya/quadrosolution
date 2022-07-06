/*!
\file 
\brief functions of solution quadratic equation
*/

#include "head.h"
/*!
 * \brief this function says if number is zero
 *
 * \param[in] x - number, which we want to compare with zero
 * \return true if number is equal to zero
 */

bool Zero(double x)
{
    return (fabs(x) < EPSILON);
}
/*!
 * \brief this function checks two numbers is equal
 * 
 * \param[in] x, y - numbers which we want to comare
 * \return true if two numbers is equal
 */

bool Equal_2(double x, double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return Zero(x-y);
}
/*!
 * \brief Solves Linear Equation (when coefficient a = 0)
 *
 * Solve equation 0*a + bx + c = 0 -> bx + c = 0
 * \param[in] b - coefficient of quadratic equation
 * \param[in] c - coefficient of quadratic equation
 * \param[out] x_2 - root of linear equation
 * \return count of roots, if return R3 - inf roots
 */

int SolveLinear(double b, double c, double *x_2)
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
/*!
 * \brief Solves Quadratic Equation
 *
 * solve quadratic equation ax^2 + bx + c = 0 (a != 0)
 * \param[in] a - coefficient in quadratic equation
 * \param[in] b - coefficient in quadratic equation
 * \param[in] c - coefficient in quadratic equation
 * \param[out] x_1 - root of quadratic equation
 * \param[out] x_2 - root of quadratic equation
 * \return counter of roots
 */

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

/*!
 * \brief this function scans the coefficients from quadratic equation
 *
 *  the function accepts coefficients and says that you need to enter
 *  \param[out] a, b, c - the coefficient quadratic equation ax^2 + bx + c = 0
 */

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
                printf("Incorrectly values");
                exit(1);
            }
        }
        else
        {
            break;
        }
    }

}
/*!
 * \brief this function gives the answer about the solution of the quadratic equation
 * 
 * GiveAns accepts the counter_of_roots variable and answers the question of the task
 * Prints roots
 * \param[in] counter_of_roots - count of the roots
 * \param[in] x_1 - first root
 * \param[in] x_2 - second root
 */

void GiveAns(int counter_of_roots, double x_1, double x_2)
{
   // assert(isfinite(x_1) && isfinite(x_2));
    switch(counter_of_roots)
    {
        case R0:
            printf("No roots.");
            break;
        case R1:
            printf("One root: x = %.6lf\n", x_2);
            break;
        case R2:
            printf("Two roots x1 = %.6lf x2 = %.6lf\n", x_1, x_2);
            break;
        case R3:
            printf("Infinite roots");
            break;
        default:
            printf("Error");
            break;
    }
}