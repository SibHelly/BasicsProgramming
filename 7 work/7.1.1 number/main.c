#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int search_word(char *);//алгоритм проверки предложения на наличие слова с двумя буквами o

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Rus");
    setlocale(LC_ALL, "ru.UTF-8");
    FILE *f1, *f2;
    char filename[80], s[1000];
    int flag_sentence, i=0;
    //открытие файлов один для чтения другой для записи
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("Введите имя файла для обработки");
        gets(filename);
    }
    if ((f1=fopen(filename,"r"))==NULL)
    {
        perror("Error open file");return 1;
    }
    if ((f2=fopen("temp.txt","w"))==NULL)
    {
        perror("Error open file");return 2;
    }
    while (!feof(f1))//пока не конец файла
    {
        fscanf(f1, "%c", &s[i]);//считываем посимвольно в строку s
        if (s[i]=='.' || s[i]=='!' || s[i]=='?' || s[i]==NULL)//если конец предложения или конец файла
        {
            i=0;//обнуяем счетчик символов в предложении
            flag_sentence=search_word(s);//проверяем есть ли в предложении слова с двумя буквами о
            if (flag_sentence==0)//если нет то записываем это предложение в другой файл
            {
                puts(s);
                fprintf(f2,"%s",s);
            }
            memset(s,0,sizeof(s));//очищаем строку
        }
        else
            i++;//считаем символы
    }
    fclose (f1);fclose(f2);
    remove(filename);
    rename("temp.txt", filename);
    return 0;
}

int search_word(char *s)//алгоритм проверки предложения на наличие слова с двумя буквами o
{
    int i, n, flag=0;//i индекс для цикла, n счетчик букв о в слове
    char stroka[1000];
    char *word, *ptr;
    strcpy(stroka,s);//переписываем предлложение в строку
    word=strtok_s(stroka," .?!,:-\n", &ptr);//разбиваем предложение на слова
    while (word!=NULL)//пока есть слова
    {
        n=0;//счетчик букв о в слове
        for (i=0;word[i];i++)//просмтариваем символы в слове
        {
                if (word[i]=='o'|| word[i]=='O'|| word[i]=='о'|| word[i]=='О')
                    n++;//если нашлась о увеличиваем счетчик
        }
        if (n==2)//если есть слово с двумя буквами о
        {
            flag=1;//поднимаем флаг и прерываем цикл
            break;
        }
        else//если в слове нет двух букв о проверяем следующее слово
            word=strtok_s(NULL," .,:-\n", &ptr);
    }
    return flag;//возвращаем флаг
}

