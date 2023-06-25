#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_file(FILE *);
void file_procces(FILE *, FILE *);

int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"");
    FILE *f, *f1;
    char filename[80];
    //открытие файлов для чтения и записи
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("Введите имя файла для открытия");
        gets(filename);
    }
    if ((f=fopen(filename,"rb"))==NULL)
    {
        perror("Ошибка открытия файла");return 2;
    }
    puts("Содержимое файла");
    print_file(f);//вывод содержимого файла на экран
    printf("\n");
    if ((f1=fopen("binary_after","wb"))==NULL)
    {
        perror("Ошибка открытия файла");return 3;
    }
    file_procces(f,f1);//обработка файла
    fclose(f);
    remove(filename);
    rewind(f1);
    if ((freopen("binary_after","rb", f1))==NULL)//используется freopen, чтобы не закрывать несколько раз файл f1
    {
        perror("Ошибка открытия файла");return 4;
    }
    printf("Содержимое файла после обработки:\n");
    print_file(f1);
    //закрытие файлов
    fclose(f);
    remove(filename);
    fclose(f1);
    rename("binary_after", filename);
    return 0;
}

void print_file(FILE *f)//вывод содержимого бинарного файла на экран
{
    int x, sz=sizeof(int);
    rewind(f);
    while (fread(&x, sz, 1, f))//считывание числа из файла в перменную x
        printf("%d ", x);
}
void file_procces(FILE *f1, FILE *f2)//алгоритм обработки файла по условию
{
    int x;
    rewind(f1);
    rewind(f2);
    while (fread(&x, sizeof(int), 1, f1))//пока есть чила, считываем числа из файла в перменную x
    {
        if(x==0)//если x равен 0 то пропускаем его
            continue;
        if (x>0)//если x положителен то записываем число и записываем его квадрат
        {
             fwrite(&x, sizeof(int), 1, f2);
             x=x*x;
             fwrite(&x, sizeof(int), 1, f2);
        }
        else//если число отрицателное то просто записываем его
            fwrite(&x, sizeof(int), 1, f2);
    }
}

