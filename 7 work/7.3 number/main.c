#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    FILE *f, *f1;
    setlocale(LC_ALL,"");
    int count, x;
    char filename[80];
    //�������� ���������� �����
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("������� ��� ����� ��� ��������");
        gets(filename);
    }
    if ((f=fopen(filename,"wb"))==NULL)
    {
        perror("������ �������� �����");return 2;
    }
    printf("������� ����� ����� ����� � �����: ");
    scanf("%d", &count);
    //���������� ��������� �����
    while (count--)
    {
        scanf("%d", &x);
        fwrite(&x, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
