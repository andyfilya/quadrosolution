#include "head.h"

bool func_of_test()
{
    bool flag = true;
    const struct param_of_quadroeq test_of_equation[] = 
    {
        {0,   0,  0,   0,      0, ROOT_3},
        {1,  -5,  6,   3,      2, ROOT_2},
        {1,   -2, -3,   3,     -1, ROOT_2},
        {0,  -2,  8,   4,      0, ROOT_1},
        {1,   -7,  0,  7,      0, ROOT_2},
        {5, 0, 30,   0, 0,  ROOT_0},
        {1,   1,  1, 0,      0, ROOT_0},
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
        case ROOT_2:
            return ((IsEqual(test_of_equation->x_1, x_1) && IsEqual(test_of_equation->x_2, x_2)) || (IsEqual(test_of_equation->x_1, x_2) && (IsEqual(test_of_equation->x_2, x_1)))) && (test_of_equation->counter_of_roots == counter_of_roots);
            break;
        case ROOT_1:
            return (IsEqual(test_of_equation->x_1, x_1) && (test_of_equation->counter_of_roots == counter_of_roots));
            break;
        case ROOT_0:
        case ROOT_3: 
            return (test_of_equation->counter_of_roots == counter_of_roots);
            break;
    }
}
