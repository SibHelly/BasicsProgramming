#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b, s;
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    s= a/b;
    printf("%.2lf / %.2lf=%.2lf\n", a, b, s);
    return 0;
}
