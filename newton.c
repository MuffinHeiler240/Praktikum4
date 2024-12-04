#include "newton.h"
#include <math.h>

double dF(double (*f)(double), double x) {
    double h = 0.000001;
    return (f(x + h) - f(x - h)) / (2 * h);
}

double newton(double (*f)(double), double x0) {
    double x = x0;
    double delta;
    int n = 0;
    do {
        double xn1 = x - f(x) / dF(f, x);
        delta = (xn1 > x) ? (xn1 - x) : (x - xn1);
        x = xn1;
        n++;
    } while (delta > EPS && n < MAXITERATIONS);
    return (n == MAXITERATIONS ? NAN:x);
}

