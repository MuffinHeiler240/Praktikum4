#include <stdio.h>
#include <math.h>
#include "newton.h"

double f1(double x) {
    return sin(x);
}

double f2(double x) {
    return x * x - 3;
}

double f3(double x) {
    return tan(x) - x;
}

int main(void) {
    double zeroPoint1, zeroPoint2, zeroPoint3;
    double startFct1 = 3.0;
    double startFct2 = 2.0;
    double startFct3 = 4.5;

    printf("-- Newton -- \n");
    /* Test f1(x) = sin(x) */
    zeroPoint1 = newton(f1, startFct1); /* Initial guess close to pi */
    printf("Zero point of sin(x): %.6f, Start point: %.2f, Iterations: %d\n", zeroPoint1, startFct1, iteNewton);

    /* Test f2(x) = x^2 - 3 */
    zeroPoint2 = newton(f2, startFct2); /* Initial guess close to sqrt(3)  */
    printf("Zero point of x^2 - 3: %.6f, Start point: %.2f, Iterations: %d\n", zeroPoint2, startFct2, iteNewton);

    /* Test f3(x) = tan(x) - x */
    zeroPoint3 = newton(f3, startFct3); /* Initial guess close to first positive root  */
    printf("Zero point of tan(x) - x: %.6f, Start point: %.2f, Iterations: %d\n\n", zeroPoint3, startFct3, iteNewton);

    printf("-- Bisection -- \n");

    zeroPoint1 = bisection(f1, startFct1, startFct1 + 1); /* Interval around pi */
    printf("Zero point of sin(x): %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n", zeroPoint1, startFct1, startFct1 + 1, iteBisection);

    zeroPoint2 = bisection(f2, startFct2 - 1, startFct2); /* Interval around sqrt(3) */
    printf("Zero point of x^2 - 3: %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n", zeroPoint2, startFct2 - 1, startFct2, iteBisection);

    zeroPoint3 = bisection(f3, startFct3 - 0.1,startFct3); /* Interval around first positive root */
    printf("Zero point of tan(x) - x: %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n\n", zeroPoint3, startFct3 - 0.1, startFct3, iteBisection);

    printf("-- Regula-Falsi -- \n");

    zeroPoint1 = regulafalsi(f1, startFct1, startFct1 + 1); /* Interval around pi */
    printf("Zero point of sin(x): %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n", zeroPoint1, startFct1, startFct1 + 1, iteRegula);

    zeroPoint2 = regulafalsi(f2, startFct2 - 1, startFct2); /* Interval around sqrt(3) */
    printf("Zero point of x^2 - 3: %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n", zeroPoint2, startFct2 - 1, startFct2, iteRegula);

    zeroPoint3 = regulafalsi(f3, startFct3 - 0.1, startFct3); /* Interval around first positive root */
    printf("Zero point of tan(x) - x: %.6f, Start point a: %.2f, Start point b: %.2f, Iterations: %d\n", zeroPoint3, startFct3 - 0.1, startFct3, iteRegula);

    return 0;
}