#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int search_word(char *);//�������� �������� ����������� �� ������� ����� � ����� ������� o

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Rus");
    setlocale(LC_ALL, "ru.UTF-8");
    FILE *f1, *f2;
    char filename[80], s[1000];
    int flag_sentence, i=0;
    //�������� ������ ���� ��� ������ ������ ��� ������
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("������� ��� ����� ��� ���������");
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
    while (!feof(f1))//���� �� ����� �����
    {
        fscanf(f1, "%c", &s[i]);//��������� ����������� � ������ s
        if (s[i]=='.' || s[i]=='!' || s[i]=='?' || s[i]==NULL)//���� ����� ����������� ��� ����� �����
        {
            i=0;//������� ������� �������� � �����������
            flag_sentence=search_word(s);//��������� ���� �� � ����������� ����� � ����� ������� �
            if (flag_sentence==0)//���� ��� �� ���������� ��� ����������� � ������ ����
            {
                puts(s);
                fprintf(f2,"%s",s);
            }
            memset(s,0,sizeof(s));//������� ������
        }
        else
            i++;//������� �������
    }
    fclose (f1);fclose(f2);
    remove(filename);
    rename("temp.txt", filename);
    return 0;
}

int search_word(char *s)//�������� �������� ����������� �� ������� ����� � ����� ������� o
{
    int i, n, flag=0;//i ������ ��� �����, n ������� ���� � � �����
    char stroka[1000];
    char *word, *ptr;
    strcpy(stroka,s);//������������ ������������ � ������
    word=strtok_s(stroka," .?!,:-\n", &ptr);//��������� ����������� �� �����
    while (word!=NULL)//���� ���� �����
    {
        n=0;//������� ���� � � �����
        for (i=0;word[i];i++)//������������� ������� � �����
        {
                if (word[i]=='o'|| word[i]=='O'|| word[i]=='�'|| word[i]=='�')
                    n++;//���� ������� � ����������� �������
        }
        if (n==2)//���� ���� ����� � ����� ������� �
        {
            flag=1;//��������� ���� � ��������� ����
            break;
        }
        else//���� � ����� ��� ���� ���� � ��������� ��������� �����
            word=strtok_s(NULL," .,:-\n", &ptr);
    }
    return flag;//���������� ����
}

