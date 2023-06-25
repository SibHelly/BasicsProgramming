#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x, y;
    int a, b=0xFA5E4B9C;
    double n, m;
    char *uc=&b;
    printf("char:\tadress x=%p, sizeof(x)=%d\tadress y=%p, sizeof(y)=%d\n",&x, sizeof(x), &y, sizeof(y));
    printf("int:\tadress a=%p, sizeof(a)=%d\tadress b=%p, sizeof(b)=%d\n",&a, sizeof(a), &b, sizeof(b));
    printf("double:\tadress n=%p, sizeof(n)=%d\tadress m=%p, sizeof(m)=%d\n",&n, sizeof(n), &m, sizeof(m));
    printf("char pointer uc adress=%p, sizeof(uc)=%d\n", &uc, sizeof(uc));
    for (x=0; x<4;x++)
    {
        printf("%d bite = %hhx\n",x+1, *uc);
        uc++;
    }
    return 0;
}

