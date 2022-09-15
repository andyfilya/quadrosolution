/*!
\file
\brief this is the main file from which the entire program starts running
*/


#include "head.h"



int main(int argc, const char *argv[])
{

    double a = NAN, b = NAN, c = NAN;
    double x_1 = NAN, x_2 = NAN;

    Coef_scan(&a, &b, &c);
    int count_of_roots = SolveQuadratic(a, b, c, &x_1, &x_2);
    
    GiveAns(count_of_roots, x_1, x_2);
    
    if(argc > 1)
    {
        if(!strcmp(argv[1], "-t"))
        {
            bool res = func_of_test();

            if(res == true) printf("OK\n");
            else printf("Not OK\n");
        }
    }

    return 0;
}