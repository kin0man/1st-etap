#include <stdio.h>
#include <math.h>
#include "main.h"
#include <float.h>

double integral(func f, double a, double b, double eps){
    int n = 2;  // Минимальное четное количество интервалов
    double h = (b - a) / n;
    double sum_prev = 0.0;
    double sum_current = DBL_MAX;
    
    do {
        double x1 = a;
        double x2 = a;
        sum_prev = sum_current;
        h = (b - a) / n;
        sum_current = 0;
        for (int i = 0; i < n; i++){
            x2 += h;
            sum_current += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f((x1 + x2) / 2) + f(x2));
            x1 += h;
        }
        n *= 2;
    } while (fabs(sum_current - sum_prev) / 15 >= eps);
    return sum_current;
}
