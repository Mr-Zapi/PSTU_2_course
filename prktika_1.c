#include <stdio.h>
#include <locale.h>
#include <math.h>

float f(float x, float y) {
    if (fabs(x) > 2) {
        printf("Первый вариант -- ");
        return sqrt((2 * x + sin(fabs(3 * y))) / 3.56);
    }
    else if (fabs(y) < 2) {
        printf("Второй вариант -- ");
        return cos(fabs(x / y) * log(x));
    }
    return exp(x + y);
}

int main() {
    setlocale(LC_ALL, "Russian");
    float x, y;
    printf("Введите x, y: ");
    scanf("%f", &x); 
    scanf("%f", &y);
    printf("Введенные значения: %.2f %.2f\n", x, y); 
    printf("Результат: %.2f\n", f(x, y));
    return 0;
}
