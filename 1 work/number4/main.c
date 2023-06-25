#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    double s;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    s=(double) a/b;
    printf("%d / %d = %lf", a, b, s);
    return 0;
}
