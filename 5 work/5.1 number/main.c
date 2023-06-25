#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 6
#define L 18

double average(int *, int);//подсчет среднего арифметического
void input_array(int *, int);//заполнение массива
void output_array(const int *, int, int);//вывод массива


int main()
{
    int a[N][M], b[L];
    double average_a, average_b;
    int i, count;//count переменная, которая считает в скольки строчках матрицы a среднее арифметическое больше среднего арифметического массива b
    input_array(b, L);//заполняем одномерный массив b случайнми числами
    printf("Array b\n");
    output_array(b,1,L);//выводим массив b на экран, 1 так одномерный массив из одной строки
    input_array(a[0], M*N);//заполняем случайными числами двумерный массив а, M*N количество элементов в массиве а
    printf("Array a\n");
    output_array(a[0], N, M);//выводим двумерный массив а на экран
    average_b=average(b, L);//присваиваем переменной average_b среднее арифметическое массива b
    count=0;//обнуляем количество
    for (i=0;i<N;i++)/*получаем среднее арифметическое кажой строки матрицы а и считаем количество строк
    , где среднее арифметическо строки больше среднего арифметического массива b*/
    {
        average_a=average(a[i],M);//присваиваем переменной average_а среднее арифметическое строки с индексом i
        printf("%lf\n", average_a);
        if (average_a>average_b)//сравниваем среднее арифметическое строки с среднем арифметическим массива b
            count+=1;//если больше, то увеличиваем колтичество
    }
    printf("Count\n");
    printf("%3d", count);
    return 0;
}

//заполняем массив случайными числами
void input_array(int *array, int n)
{
    int i;
    for (i=0;i<n; i++)
        array[i]=rand()%10;
}
//выводим массив на экран с помощью указателя
void output_array(const int *a, int n, int m)
{
    int i;
    for (;n>0;n--)//если количество строк больше нуля, то выводим значения этой строки
    {
        for(i=0;i<m;i++)
            printf("%3d ", *a++);
        printf("\n");
    }
}
//подсчет среднего арифмитического в строке
double average(int *a, int n)
{
    int i, sum=0;
    double average=0;//обнуляем переменные суммы строки и среднего арифмитического
    for (i=0; i<n; i++)
        sum+=a[i];//считаем сумму всех элементов в строке, n-количество элементов в строке
    average=(double)sum/n;//вычисляем среднее арифметическое, явно приводим n к double
    return average;
}
