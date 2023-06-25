#include <stdlib.h>
#include <stdio.h>
#define N 3
#define M 4

void inputMatrix(double *, int, int);
void showMatrix(double *, int, int);
void productNumbers(double *, int, int, double *);

int main()
{
    double A[N][M], result[M];
    int i;
    inputMatrix(&A[0][0], N, M);
    showMatrix(&A[0][0], N, M);
    productNumbers(&A[0][0], N, M, result);
    printf("The product of numbers of all columns\n");
    for (i = 0; i < M; i++)
        printf("%2.3lf ", result[i]);
    return 0;
    return 0;
}

void inputMatrix(double *a, int n, int m)
{
    int i, j;
    printf("Input elements of matrix size %d x %d\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%lg", a + i * m + j);
        }
    puts("Inputing is ready\n");
}

void showMatrix(double *a, int n, int m)
{
    int i, j;
    puts("Show matrix");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%-8.2lf", *(a + i * m + j));
        printf("\n");
    }
}

void productNumbers(double *a, int n, int m, double *s)
{
    int i, j;
    double pr;
    for (i = 0; i < m; i++)
    {
        pr = 1;
        puts("");
        for (j = 0; j < n; j++)
            pr *= *(a + i + j * m);
        s[i] = pr;
    }
}