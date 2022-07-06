/*!
\file
\brief this is the main file from which the entire program starts running
*/


#include "head.h"

/*!
 * \brief Launch the program
 */

int main()
{
    //coefficients 
    double a = NAN, b = NAN, c = NAN;
    //roots
    double x_1 = NAN, x_2 = NAN;
    Coef_scan(&a, &b, &c);
    int count_of_roots = SolveQuadratic(a, b, c, &x_1, &x_2);
    
    GiveAns(count_of_roots, x_1, x_2);

    return 0;
}