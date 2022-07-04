#include "head.h"
//scancoefficients
void Coef_scan(double *a, double *b, double *c)
{
    assert( a != NULL && b != NULL && c != NULL);
    printf("You need to enter 3 coefficients a,b,c\n");
    while (1 == 1)
    {
        char str_in[256] = ""; //for chars(in)
        int counter_of_coef = 0; //for errors
        int counter_of_attempts = 0; //for cicles
        counter_of_coef = scanf("%lf %lf %lf", a, b, c);
        if(counter_of_coef != 3)
        {
            scanf("%255s\n", str_in);
            counter_of_attempts += 1;
            if (counter_of_attempts > 2)
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

void GiveAns(int counter_of_roots, double x_1, double x_2)
{
    assert(isfinite(x_1) && isfinite(x_2));
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

int main()
{
    //coefficients 
    double a = NAN, b = NAN, c = NAN;
    //roots
    double x_1 = NAN, x_2 = NAN;
    Coef_scan(&a, &b, &c);
    int count_of_roots = SolveEquation_2(a, b, c, &x_1, &x_2);
    
    GiveAns(count_of_roots, x_1, x_2);

    return 0;
}