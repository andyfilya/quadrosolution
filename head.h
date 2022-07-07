/*!
\file

this is header of program
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>

/*!
 * \brief this function says if number is zero
 *
 * \param[in] x - number, which we want to compare with zero
 * \return true if number is equal to zero
 */
bool Zero(double x);

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

int SolveQuadratic(double a, double b, double c, double *x_1, double *x_2);
/*!
 * \brief this function checks two numbers is equal
 * 
 * \param[in] x, y - numbers which we want to comare
 * \return true if two numbers is equal
 */
bool Equal_2(double x, double y);

/*!
 * \brief Solves Linear Equation (when coefficient a = 0)
 *
 * Solve equation 0*a + bx + c = 0 -> bx + c = 0
 * \param[in] b - coefficient of quadratic equation
 * \param[in] c - coefficient of quadratic equation
 * \param[out] x_1 - root of linear equation
 * \return count of roots, if return R3 - inf roots
 */

int SolveLinear(double b, double c, double *x_2);

/*!
 * \brief this function scans the coefficients from quadratic equation
 *
 *  the function accepts coefficients and says that you need to enter
 *  \param[out] a, b, c - the coefficient quadratic equation ax^2 + bx + c = 0
 */

void Coef_scan(double *a, double *b, double *c);

/*! 
 * \brief this function gives the answer about the solution of the quadratic equation
 * 
 * GiveAns accepts the counter_of_roots variable and answers the question of the task
 * Prints roots
 * \param[in] counter_of_roots - count of the roots
 * \param[in] x_1 - first root
 * \param[in] x_2 - second root
 */

void GiveAns(int counter_of_roots, double x_1, double x_2);
/*!
 * \brief  this function is compare result of right answers and answers from this program
 * 
 * \param[in] test_of_equation - struct of tests
 * \param[out] temp_of_equation - struct with roots
 */
bool test_prog(const struct param_of_quadroeq *test_of_equation, struct param_of_quadroeq *temp_of_equation);

const double EPSILON = 1E-4;

const int R1 = 1;
const int R2 = 2;
const int R3 = 3;
const int R0 = 0;
