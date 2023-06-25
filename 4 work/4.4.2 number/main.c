#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **a, i, j, temp, M;
    printf("Input size of matrix M=");
    scanf("%d", &M);
//выделение памяти под массив указателей и под элементы массива
    a=calloc (M, sizeof(int*));
    if (a==NULL)
    {
        printf("Error");
        return 100;
    }
    a[0]=calloc(M*M, sizeof(int));//выделение памяти под элементы массива
    if (a[0]==NULL)
    {
        printf("Error");
        return 100;
    }
    for (i=1; i<M; i++)
        a[i]=a[i-1]+M;
//заполнение массива случайным образом
    for (i=0;i<M;i++)
        {
            for (j=0;j<M;j++)
            {
                a[i][j]=rand()%100 -30;
                printf("%4d ", a[i][j]);
            }
            printf("\n");
        }
    printf("\n");
//сортировка главной диагонали матрицы
    for (i=0; i<M;i++)
        for (j=0; j<M; j++)
            if (a[i][i]<a[j][j])//напрмимер: если элемент с индексом [0][0]< элемента с индексом [1][1], то меняем их местами, тем саммы сортирем главную диагональ
            {
                //меняем местами элементы на главной диагонали
                temp=a[i][i];
                a[i][i]=a[j][j];
                a[j][j]=temp;
            }
//вывод отсортированного массива
    for (i=0;i<M; i++)
    {
        for (j=0; j<M; j++)
            printf("%4d ",a[i][j]);
        printf("\n");
    }
    //освобождение памяти
    free(a[0]);
    free(a);
    return 0;
}
