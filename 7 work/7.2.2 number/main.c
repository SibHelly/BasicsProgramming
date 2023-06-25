#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swap(double*, double*);//функция, меняем местами элементы
void sort(double*, int);// функция сортировки массива
int search_count(char*);//функция, которая считает количество чисел в строку
void str_to_array(char *, double *, int);//функция которая заполняет массив вещественными числами


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");
    FILE *f1, *f2;
    char s[1000], s1[1000];
    char filename[80];
    double *a=NULL;
    int i, count, mi_count=1000, ma_count=0, flag_count=0, k=0, t=0;
    //открытие файла и проверка открылся ли файл или нет
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("Enter the name of the file to process");
        gets(filename);
    }
    if ((f1=fopen(filename,"r"))==NULL)
    {
        perror("Error open file"); return 1;
    }
    if ((f2=fopen("matrix1.txt","w"))==NULL)
    {
        perror("Error open file"); return 2;
    }
    //проверка матрицы на корректность
    rewind(f1);
    while (fgets(s1, 1000, f1))
    {
        i++;//считаем сколько строк в файле всего
        count=search_count(s1);//ищем количество чисел в строке
        if (count)//ищем максимальное и минимальное количество чисел в строках файла
        {
            flag_count++;//если количество чисел в строке не 0, то увеличваем количество не пустых строк
            if (count>ma_count)
                ma_count=count;
            if (count<mi_count)
                mi_count=count;
        }
        else
        {
            k++;//если строка пустая увеличиваем счетчик пустых строк
            flag_count=0;//обнуляем флаг если нашли пустую строку
        }
        if (flag_count==1)//считаем сколько раз мы считали не пустые строки, то есть разделяетс яли матрица пустыми строками
            t++;//подсчет количества матриц
    }
    if (i==k)//если количество строк в файле и количество пустых строк совпадает, то файл пуст
    {
        printf("File empty");
        return 0;
    }
    if (t>1)//если количество матриц в файле больше одной
    {
        printf("In file several matrix");
        return 0;
    }
    if (ma_count==mi_count)//если матрица корректна и в каждой строке одинаковое количество чисел
    {
        rewind(f1);
        while (fgets(s,1000, f1))
        {
            count=search_count(s);//узнаем количество чисел в строке
            if (count)//если строка не пустая
            {
                a=(double*)malloc(count*sizeof(double));//создаем динамический массив для сортировки чисел в строке
                if (a==NULL)
                {
                    printf("Error");
                    return 100;
                }
                str_to_array(s, a, count);//заполняем динамический массив
                sort(a,count);//сортируем массив
                for (i=0;i<count;i++)//записываем в файл
                {
                    fprintf(f2,"%.3lf ", a[i]);
                    printf("%.3lf ", a[i]);
                }
                free(a);//освобождение
                printf("\n");
                fputc('\n', f2);
            }
        }
        fclose(f1);
        fclose(f2);
        //remove(filename);
        //rename("matrix1.txt", filename);
    }
    else//если в каждой строке не одинаковое количество чисел
    {
        printf("Marix is not correct");
    }
    return 0;
}

void swap(double *a, double *b)//функция которая меняет числа местами
{
    double temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(double *array, int n)//функция сортировки
{
    int max=0,min=0, i;
    //находим индекс максимального элемента в массиве
    for (i=0;i<n;i++)
        if (array[i]>array[max])
            max=i;
    swap(&array[max],&array[n-1]);//ставим его на последнее место в массиве
    //находим индекс минимального элемента массива
    for (i=0;i<n;i++)
        if (array[i]<array[min])
            min=i;
    swap(&array[min],&array[0]);//ставим его на первое место
}

int search_count(char *str)//функция подсчета количества чисел в строке
{
    int count=-1;//так как цикл для завершения будет пройден лишний раз, поэтому count=-1
    char* nstr = str;//создаем указатель на полученную строку
    char* tstr;//создаем указатель
    double d;//сюда записывается число из строки
    while (1)// пока в строке есть числа
    {
        tstr=nstr;//запоминаем адрес остатка строки
        d=strtod(nstr, &nstr);//преобрзовываем число из строки в вещественное число, после чего меняем адрес на оставшийся
        count++;
        if (d==0 && tstr==nstr)//пока tstr и nstr не совпадут и число не станет 0, то есть пока есть числа в строке
            break;
    }
    return count;
}

void str_to_array(char *str, double *array, int count)//заполняем массив числами из строки
{
    char* nstr = str;//указатель на строку
    int i;//индекс
    for (i=0;i<count;i++)
    {
       array[i] = strtod(nstr,&nstr);//заполняем массив
    }
}
