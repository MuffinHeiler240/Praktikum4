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
    printf("Root of f1: %.6f\n\n", root1);

    /* Test f2(x) = x^2 - 3 */
    printf("Finding root of f2(x) = x^2 - 3:\n");
    root2 = newton(f2, 2.0); /* Initial guess close to sqrt(3)  */
    printf("Root of f2: %.6f\n\n", root2);

    /* Test f3(x) = tan(x) - x */
    printf("Finding root of f3(x) = tan(x) - x:\n");
    root3 = newton(f3,  4.5); /* Initial guess close to first positive root  */
    printf("Root of f3: %.6f\n\n", root3);

    return 0;
}