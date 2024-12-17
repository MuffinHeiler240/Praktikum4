#ifndef NEWTON_H
#define NEWTON_H
#define MAXITERATIONS 128 /** maximal number of iterations */
#define EPS 1.E-12 /** precision to reach */

extern int iteNewton;
extern int iteRegula;
extern int iteBisection;

/*
* calculate point x with f(x)=0 within EPS precision.
* If no solution found return IEEE NaN (not a number).
* @param f function to use
* @param x0 the starting point.
* @return x with f(x)=0 (or NaN in case of an error)
*/
double newton(double (*f)(double), double x0);

/* Find x with f(x)=0 and a <= x <= b using bisection method. */
double bisection(double (*f)(double), double a, double b);

/* Find x with f(x)=0 and a <= x <= b using regular falsi method. */
double regulafalsi(double (*f)(double), double a, double b);

extern int iteNewton;
extern int iteRegula;
extern int iteBisection;
#endif /* NEWTON_H */
