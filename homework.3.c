#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double delta;
    double x1, x2;
    
    printf("请输入一元二次方程的系数(a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    printf("\n方程: ");
    if (a != 0) {
        printf("%.2fx²", a);
    }
    if (b != 0) {
        if (b > 0 && a != 0) printf(" + ");
        if (b < 0) printf(" - ");
        printf("%.2fx", fabs(b));
    }
    if (c != 0) {
        if (c > 0 && (a != 0 || b != 0)) printf(" + ");
        if (c < 0) printf(" - ");
        printf("%.2f", fabs(c));
    }
    printf(" = 0\n\n");
    
    // 情况1: a=0, 退化为一元一次方程
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("方程有无穷多解\n");
            } else {
                printf("方程无解\n");
            }
        } else {
            x1 = -c / b;
            printf("退化为一次方程:\n");
            printf("解: x = %.4f\n", x1);
        }
        return 0;
    }
    
    // 计算判别式
    delta = b * b - 4 * a * c;
    
    // 输出判别式信息
    printf("判别式 Δ = b² - 4ac = %.4f\n", delta);
    
    if (delta > 0) {
        // 两个不相等的实根
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Δ > 0, 方程有两个不相等的实根:\n");
        printf("x₁ = %.4f\n", x1);
        printf("x₂ = %.4f\n", x2);
    }
    else if (delta == 0) {
        // 两个相等的实根（重根）
        x1 = -b / (2 * a);
        printf("Δ = 0, 方程有两个相等的实根:\n");
        printf("x₁ = x₂ = %.4f\n", x1);
    }
    else {
        // 两个共轭复根
        double real_part = -b / (2 * a);
        double imag_part = sqrt(-delta) / (2 * a);
        printf("Δ < 0, 方程有两个共轭复根:\n");
        
        if (real_part == 0) {
            printf("x₁ = %.4fi\n", imag_part);
            printf("x₂ = -%.4fi\n", imag_part);
        } else {
            printf("x₁ = %.4f + %.4fi\n", real_part, imag_part);
            printf("x₂ = %.4f - %.4fi\n", real_part, imag_part);
        }
    }
    
    return 0;
}