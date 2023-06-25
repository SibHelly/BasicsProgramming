#include <stdlib.h>
#include <stdio.h>

void inputArray(int *, int);
void showArray(int *, int);
void replace(int *, int);
void swap(int *, int *);

int main()
{
    int M = 8;
    int q[8] = {-1, 8, -3, -4, 3, 0, 0, -7};
    // inputArray(q, M);
    printf("Array before replace\n");
    showArray(q, M);
    replace(q, M);
    printf("Array after replace\n");
    showArray(q, M);
    return 0;
}

void inputArray(int *a, int n)
{
    int i;
    printf("Input elements of array\n");
    printf("Count of elements array: %d\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("Inputing is ready\n");
}

void showArray(int *a, int n)
{
    int i;
    printf("Show Array\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, *(a + i));
}

void replace(int *a, int M)
{
    int i, j, count = 0;
    for (i = 0; i < M; i++)
    {
        if (*(a + i) < 0)
            for (j = i + 1; j < M; j++)
            {
                if (*(a + j) >= 0)
                {
                    swap(a + j, a + i);
                    break;
                }
            }
        if (*(a + i) == 0)
            count++;
    }
    for (j = 0; j < count; j++)
        for (i = 0; i < M - 1; i++)
            if (*(a + i) == 0)
                swap(a + i, a + i + 1);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
