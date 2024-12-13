#include "newton.h"
#include <math.h>

int iteNewton = 0;
int iteRegula = 0;
int iteBisection = 0;

double dF(double (*f)(double), double x) {
    double h = 0.000001;
    return (f(x + h) - f(x - h)) / (2 * h);
}

double newton(double (*f)(double), double x0) {
    double x = x0;
    double delta;
    iteNewton = 0;
    do {
        double xn1 = x - f(x) / dF(f, x);
        delta = (xn1 > x) ? (xn1 - x) : (x - xn1);
        x = xn1;
        iteNewton++;
    } while (delta > EPS && iteNewton < MAXITERATIONS);
    return (iteNewton == MAXITERATIONS ? NAN : x);
}

/* Please check for errors and correct the following functions */
/* Is this the correct way to implement the bisection method? */

/* Find x with f(x)=0 and a <= x <= b using bisection method. */
double bisection(double (*f)(double), double a, double b) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    if (fa * fb > 0) {
        return NAN;
    }
    iteBisection = 0;
    do {
        c = (a + b) / 2;

        fa = f(a);
        fc = f(c);

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }
        iteBisection++;
    } while ((b - a > EPS) && (iteBisection < MAXITERATIONS));
    return (iteBisection == MAXITERATIONS ? NAN : c);
}

/* Please check for errors and correct the following functions */
/* Is this the correct way to implement the regular falsi method? */

/* Find x with f(x)=0 and a <= x <= b using regular falsi method. */
double regualarfalsi(double (*f)(double), double a, double b) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    if (fa * fb > 0) {
        return NAN;
    }
    iteRegula = 0;
    do {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        iteRegula++;
    } while (fabs(fc) > EPS && iteRegula < MAXITERATIONS);
    return (iteRegula == MAXITERATIONS ? NAN : c);
}