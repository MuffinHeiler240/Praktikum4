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

int main() {
    double root1, root2, root3;

    /* Test f1(x) = sin(x) */
    printf("Finding root of f1(x) = sin(x):\n");
    root1 = newton(f1, 3.0); /* Initial guess close to pi */
    printf("Root of f1: %.6f, Iterations: %d\n\n", root1, iteNewton);

    /* Test f2(x) = x^2 - 3 */
    printf("Finding root of f2(x) = x^2 - 3:\n");
    root2 = newton(f2, 2.0); /* Initial guess close to sqrt(3)  */
    printf("Root of f2: %.6f, Iterations: %d\n\n", root2, iteNewton);

    /* Test f3(x) = tan(x) - x */
    printf("Finding root of f3(x) = tan(x) - x:\n");
    root3 = newton(f3, 4.5); /* Initial guess close to first positive root  */
    printf("Root of f3: %.6f, Iterations: %d\n\n", root3, iteNewton);

    /* Additional tests for bisection and regula falsi methods */
    printf("Finding root of f1(x) = sin(x) using bisection:\n");
    root1 = bisection(f1, 3.0, 4.0); /* Interval around pi */
    printf("Root of f1: %.6f, Iterations: %d\n\n", root1, iteBisection);

    printf("Finding root of f2(x) = x^2 - 3 using bisection:\n");
    root2 = bisection(f2, 1.0, 2.0); /* Interval around sqrt(3) */
    printf("Root of f2: %.6f, Iterations: %d\n\n", root2, iteBisection);

    printf("Finding root of f3(x) = tan(x) - x using bisection:\n");
    root3 = bisection(f3, 4.4,4.5); /* Interval around first positive root */
    printf("Root of f3: %.6f, Iterations: %d\n\n", root3, iteBisection);

    printf("Finding root of f1(x) = sin(x) using regula falsi:\n");
    root1 = regualarfalsi(f1, 3.0, 4.0); /* Interval around pi */
    printf("Root of f1: %.6f, Iterations: %d\n\n", root1, iteRegula);

    printf("Finding root of f2(x) = x^2 - 3 using regula falsi:\n");
    root2 = regualarfalsi(f2, 1.0, 2.0); /* Interval around sqrt(3) */
    printf("Root of f2: %.6f, Iterations: %d\n\n", root2, iteRegula);

    printf("Finding root of f3(x) = tan(x) - x using regula falsi:\n");
    root3 = regualarfalsi(f3, 4.4, 4.5); /* Interval around first positive root */
    printf("Root of f3: %.6f, Iterations: %d\n\n", root3, iteRegula);

    return 0;
}