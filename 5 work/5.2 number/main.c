#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int, int);//выделение памяти под динамическую матрицу по столбцам
void input_array(int **, int, int);//заполнение матрицы случайными числами по столбцам
void output_array(const int**,int,int);// вывоод матрицы по столбцам
int search_delete(int **, int, int, int);//поиск и удаление столбцов с недопустимым количеством отрицательных чисел, возвращает количество оставшихся столбцов
void free_memory(int **, int);//освобождает память


int main()
{
    srand(time(0));
    int **A, **B;
    int N=5, M=7, L=7, L_after, M_after;
    A=create_matrix(M,N);//выделяем память динамически под матрицу A
    if (A==NULL)
    {
        printf("Error");
        return 100;
    }
    input_array(A, M, N);// заполняем матрицу А по столбцам
    printf("Array A\n");
    output_array(A, M, N);//выводим матрицу А на экран по столбцам
    printf("Array A after deleting\n");
    M_after=search_delete(A, M, N, 2);/*запоминаем в переменную M_after количество столбцов, которое осталось после удаления
    столбцов с недопустимым количеством отрицательных чисел count_negative_A*/
    output_array(A,M_after,N);//выводим все оставшиеся столбцы матрицы А
    free_memory(A,M_after);// освобождаем память
    B=create_matrix(L,L);//выделяем память динамически под матрицу B
    if (B==NULL)
    {
        printf("Error");
        return 100;
    }
    input_array(B,L,L);// заполняем матрицу B по столбцам
    printf("Array B\n");
    output_array(B,L,L);//выводим матрицу B на экран по столбцам
    printf("Array B after deleting\n");
    L_after=search_delete(B,L,L,3);/*запоминаем в переменную L_after количество столбцов, которое осталось после удаления
    столбцов с недопустимым количеством отрицательных чисел count_negative_B*/
    output_array(B,L_after,L);//выводим все оставшиеся столбцы матрицы B
    free_memory(B,L_after);//освобождаем память
    return 0;
}
void input_array(int **a, int n, int m)//n-столбцы, m-строки,заполнение матрицы случайными числами
{
    int i, j;
    for (i = 0; i<m; i++)//цикл по строкам
    {
        for (j = 0; j<n; j++)//цикл по столбца
        {
            a[j][i] = rand()%100-50;//заполнение по столбцам
        }
    }
}

int **create_matrix(int n, int m)//n-столбцы, m-строки, выделение памяти по столбцам для матрицы
{
    int **a, i;
    a=calloc(n, sizeof(int*));
    if (a==NULL)
    {
        printf("Error");
        return NULL;
    }
    for (i=0;i<n;i++)
    {
        a[i]=calloc(m,sizeof(int));
        if (a[i]==NULL)
        {
            for (--i;i>=0;i--)
                free(a[i]);
            free(a);
            printf("Error");
            return NULL;
        }
    }
    return a;
}

void output_array(const int **a, int n, int m)//n-столбцы, m-строки, вывод матрицы на экран по столбцам
{
    int i, j;
    if (n)//если количество столбцов не 0, то выводим матрицу, иначе выводим матрица пустая
        for (i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
                printf("%4d", a[j][i]);//выводим по столбцам
            printf("\n");
        }
    else
        printf("Matrix empty\n");
}


int search_delete(int **a, int n, int m, int count_negative)//n-столбцы, m-строки, count_negative-недопустимое количество отрицательных чисел в столбце
{
    int i, j, k, count;//k-количество оставшихся столбцов,count-количество отрицательных чисел в столбце
    for (j=0, k=0;j<n; j++)//цикл по столбцам
    {
        count=0;//обнуляем для подсчета отрицательных чисел в столбце
        for (i=0;i<m;i++)//цикл по строкам
            if (a[j][i]<0)//считаем количество отрицательных чисел в столбце
                count++;
        if (count<count_negative)//ищем столбцы, в которых количество отрицательных чисел больше недопустимого
            a[k++]=a[j]; //если в столбце количество отрицательных чисел меньше недопустимого количества отрицательных чисел, увеличиваем количество оставшихся столбцов и смещаем его
        else//если в столбце количество отрицательных чисел больше недопустимого количества отрицательных чисел, то удаляем этот столбец
            if (i<m)
            {
                free(a[j]);//освобождаем память
                a[j]=NULL;//обнуляем указатель
            }
    }
    n=k;//новое число столбцов в матрице
    return n;
}

void free_memory(int **a, int n)//освобождаем память из под динамической матрицы
{
    int i;
    for (i=0;i<n;i++)
        free(a[i]);
    free(a);
}
