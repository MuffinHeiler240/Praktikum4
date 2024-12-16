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
    double x = x0, delta;
    iteNewton = 0;
    do {
        delta = -f(x) / dF(f, x);
        x += delta;
    } while (++iteNewton < MAXITERATIONS && fabs(delta) > EPS);
    return (iteNewton == MAXITERATIONS) ? NAN : x;
}

/* Find x with f(x)=0 and a <= x <= b using bisection method. */
double bisection(double (*f)(double), double a, double b) {
    double c, fc;
    if (f(a) * f(b) > 0) return NAN;
    iteBisection = 0;
    do {
        c = (a + b) / 2;
        fc = f(c);
        if (f(a) * fc < 0) b = c;
        else a = c;
        iteBisection++;
    } while ((b - a > EPS) && iteBisection < MAXITERATIONS);
    return (iteBisection == MAXITERATIONS) ? NAN : c;
}

/* Find x with f(x)=0 and a <= x <= b using regular falsi method. */
double regulafalsi(double (*f)(double), double a, double b) {
    double c, fc;
    if (f(a) * f(b) > 0) return NAN;
    iteRegula = 0;
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        fc = f(c);
        if (f(a) * fc < 0) b = c;
        else a = c;
        iteRegula++;
    } while (fabs(fc) > EPS && iteRegula < MAXITERATIONS);
    return (iteRegula == MAXITERATIONS) ? NAN : c;
}