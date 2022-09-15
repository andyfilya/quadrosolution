#include "head.h"

void Coef_scan(double *a, double *b, double *c)
{
    assert( a != NULL && b != NULL && c != NULL);
    assert( a != b && a != c && c != b);

    printf("You need to enter 3 coefficients a, b, c\n");
    
    int counter_of_coef = 0; //for errors
    int counter_of_attempts = 0; //for cicles

    while (1)
    {
        counter_of_coef = scanf("%lf %lf %lf", a, b, c);

        if(counter_of_coef != 3)
        {
            printf("You have to enter numbers, not letters\n");

            while (getchar () != '\n'); // clean buffer

            counter_of_attempts++;
            if (counter_of_attempts == 3)
            {
                printf("Incorrectly values\n");

                return;
            }
        }
        else break;
    }

}

void GiveAns(int counter_of_roots, double x_1, double x_2)
{
    switch(counter_of_roots)
    {
        case ROOT_0:
            printf("No roots.\n");
            break;
        case ROOT_1:
            printf("One root: x = %.3lf\n", x_1);
            break;
        case ROOT_2:
            printf("Two roots x1 = %.3lf x2 = %.3lf\n", x_1, x_2);
            break;
        case ROOT_3:
            printf("Infinite roots\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}