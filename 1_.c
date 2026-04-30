#include <stdio.h>

int main () {

    float a, b, c, x;

    a = 250;
    b = 85;
    c = 25;
    x = a / b - c;
    printf("For a=250, b=85, c=25 -> x = %.2f\n", x);

    a = 300;
    b = 70;
    c = 70;
    x = a / b - c;
    printf("For a=300, b=70, c=70 -> x = %.2f\n", x);

    return 0;

}