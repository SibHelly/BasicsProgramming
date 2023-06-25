#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double k, m, f;
    printf("k=");
    scanf("%lf", &k);
    printf("m=");
    scanf("%lf", &m);
    f=k>0?m/k:m<0?fabs(m+k):k*m;
    printf("%lf", f);
    return 0;
}
