#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int main()
{
    int c, d;
    double a, b;
    a=c=5;
    printf("a=%.2lf c=%d\n", a, c);
    printf("b=");
    scanf("%lf", &b);
    printf("d=");
    scanf("%d", &d);
    a+=b-2;
    printf("a=%.2lf\n", a);
    d+=++c-a;
    printf("a=%.2lf c=%d d=%d\n", a, c, d);
    a*=c--;
    printf("a=%.2lf c=%d\n", a, c);
    d*=(a/=10)+--b+(c/=2);
    printf("a=%.2lf b=%.2lf c=%d d=%d\n", a, b, c, d);
    return 0;
}
