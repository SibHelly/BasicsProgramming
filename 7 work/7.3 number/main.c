#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    FILE *f, *f1;
    setlocale(LC_ALL,"");
    int count, x;
    char filename[80];
    //создание бинароного файла
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("Введите имя файла для создания");
        gets(filename);
    }
    if ((f=fopen(filename,"wb"))==NULL)
    {
        perror("Ошибка открытия файла");return 2;
    }
    printf("Сколько целых чисел будет в файле: ");
    scanf("%d", &count);
    //заполнение бинарного файла
    while (count--)
    {
        scanf("%d", &x);
        fwrite(&x, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
