#include "head.h"

int main()
{
    //coefficients 
    double a = NAN, b = NAN, c = NAN;
    //roots
    double x_1 = NAN, x_2 = NAN;
}

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

