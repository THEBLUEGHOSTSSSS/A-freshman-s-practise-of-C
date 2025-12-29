#include <stdio.h>
int main()
{
    double h, w, t;
    printf("Please enter h,w:\n");
    scanf("%lf %lf", &h, &w);
    t = w / (h * h);
    if (t < 18) {
        printf("t=%.6f    Lower weight!\n", t);
    } else if (t < 25) {
        printf("t=%.6f    Standard weight!\n", t);
    } else if (t < 27) {
        printf("t=%.6f    Higher weight!\n", t);
    } else {
        printf("t=%.6f    Too fat!\n", t);
    }
    
    return 0;
}