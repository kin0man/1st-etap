#include <stdio.h>
#include <math.h>
#include "main.h"

double integral(func f, double a, double b, double eps){
    int n = 2;  // Минимальное четное количество интервалов
    double h = (b - a) / n;
    double sum_prev = 0.0;
    double sum_current = f(a) + f(b);
    
    sum_current += 4 * f(a + h);
    sum_current *= h / 3;
    
    do {
        sum_prev = sum_current;
        n *= 2;
        h = (b - a) / n;
        sum_current = f(a) + f(b);
        // Суммируем с учетом уже вычисленных точек
        for (int i = 1; i < n; i += 2)
            sum_current += 4 * f(a + i * h); // Нечетные точки (коэф. 4)
        for (int i = 2; i < n - 1; i += 2)
            sum_current += 2 * f(a + i * h);  // Четные точки (коэф. 2)
        sum_current *= h / 3;
    } while (fabs(sum_current - sum_prev) > eps);
    return sum_current;
}
