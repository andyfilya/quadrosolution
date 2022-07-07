/*!
\file
\brief this is the main file from which the entire program starts running
*/


#include "head.h"

#define DEBUG

struct param_of_quadroeq
{
    double a;
    double b;
    double c;
    double x_1;
    double x_2;
    int counter_of_roots;
};
bool test_prog(const struct param_of_quadroeq *test_of_equation, struct param_of_quadroeq *temp_of_equation)
{
    assert(test_of_equation != NULL);
    assert(temp_of_equation != NULL);

    double x_1 = NAN, x_2 = NAN;

    int counter_of_roots = SolveQuadratic(test_of_equation->a, test_of_equation->b, test_of_equation->c, &x_1, &x_2);
    temp_of_equation->x_1 = x_1;
    temp_of_equation->x_2 = x_2;
    temp_of_equation->counter_of_roots = counter_of_roots;

    switch(counter_of_roots)
    {
        case R2:
            return ((Equal_2(test_of_equation->x_1, x_1) && Equal_2(test_of_equation->x_2, x_2)) || (Equal_2(test_of_equation->x_1, x_2) && (Equal_2(test_of_equation->x_2, x_1)))) && (test_of_equation->counter_of_roots == counter_of_roots);
            break;
        case R1:
            return Equal_2(test_of_equation->x_1, x_1) && (test_of_equation->counter_of_roots == counter_of_roots);
            break;
        case R0:
        case R3: 
            return (test_of_equation->counter_of_roots == counter_of_roots);
            break;
    }
}

bool func_of_test()
{
    bool flag = true;
    const struct param_of_quadroeq test_of_equation[] = 
{
        {0,   0,  0,   0,      0, R3},
        {1,  -5,  6,   3,      2, R2},
        {1,   -2, -3,   3,     -1, R2},
        {0,  -2,  8,   4,      0, R1},
        {1,   -7,  0,  7,      0, R2},
        {5, 0, 30,   0, 0, R0},
        {1,   1,  1, 0,      0, R0},
    };
    struct param_of_quadroeq temp_of_equation = {0};
    int cnt = 1;
    for (int i = 0; i < 7; i++)
    {
        bool res_of_program = test_prog(&test_of_equation[i], &temp_of_equation);
        if (res_of_program)
        {
            printf("Test #%d is passed !!!\n", cnt);
        }
        temp_of_equation.x_1 = NAN;
        temp_of_equation.x_2 = NAN;
        temp_of_equation.counter_of_roots = NAN;
        flag &= res_of_program;
        cnt += 1;
    }
    return flag;
}

int main()
{
    double a = NAN, b = NAN, c = NAN;
    double x_1 = NAN, x_2 = NAN;

    Coef_scan(&a, &b, &c);
    int count_of_roots = SolveQuadratic(a, b, c, &x_1, &x_2);
    
    GiveAns(count_of_roots, x_1, x_2);
    #ifdef DEBUG
    bool res = func_of_test();
    if(res == true)
    {
        printf("OK\n");
    }
    else
    {
        printf("Not OK\n");
    }
    #endif
    return 0;
}