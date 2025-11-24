#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0.0;
    int n = 1;
    int sign = 1;
    double term;
    
    while (1) {
        term = 1.0 / n;
        if (term < 1e-4) {
            break;
        }
        sum += sign * term;
        sign = -sign;
        n++;
    }
    
    printf("sum = %.7f\n", sum);
    
    return 0;
}