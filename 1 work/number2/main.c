#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, s;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    s=a/b;
    printf("%d/%d=%d", a, b, s);

    return 0;
}
