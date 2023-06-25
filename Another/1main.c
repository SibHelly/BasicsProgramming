#include <stdlib.h>
#include <stdio.h>
#define N 5

void inputArray(double *);
void showArray(double *);
double average(double *);

int main()
{
    double a[N];
    inputArray(a);
    showArray(a);
    printf("Average (elements array >0) = %.3lf", average(a));
    return 0;
}

void inputArray(double *a)
{
    int i;
    printf("Input elements of array\n");
    printf("Count of elements array: %d\n", N);
    for (i = 0; i < N; i++)
        scanf("%lf", a++);
    printf("Inputing is ready\n");
}

void showArray(double *a)
{
    int i;
    printf("Show Array\n");
    for (i = 0; i < N; i++)
        printf("a[%d] = %g\n", i, *a++);
}

double average(double *a)
{
    int i, count = 0;
    double sum = 0;
    for (i = 0; i < N; i++, a++)
    {
        if (*a > 0)
        {
            sum += *a;
            count++;
        }
    }
    return sum / count;
}