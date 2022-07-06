#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>

int SolveQuadratic(double a, double b, double c, double *x_1, double *x_2);
bool Equal_2(double x, double y);
int SolveLinear(double b, double c, double *x_2);
void Coef_scan(double *a, double *b, double *c);
void GiveAns(int counter_of_roots, double x_1, double x_2);

const double EPSILON = 1E-4;

//forswitch
const int R1 = 1;
const int R2 = 2;
const int R3 = 3;
const int R0 = 0;
