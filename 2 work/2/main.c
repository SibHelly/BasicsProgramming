#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, k, d, z, n=-1/6.;
    printf ("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    if (cos(a))
    {
        k=a*a+log(fabs(b));
        z=2*cos(a*a*a)*cos(a*a*a);
        if  (k>=0 && z)
        {
            d=(exp(n)*sqrt(k)-tan(a))/z*1000000;
            printf("d=%lf\n", d);
        }
        else
            printf("error");
        return 0;
    }
    else
        printf("error\n");
    system("pause");
    return 0;
}
