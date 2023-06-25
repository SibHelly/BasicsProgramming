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
    //�������� ������ ��� ������ � ������
    if (argc>1)
        strcpy(filename, argv[1]);
    else
    {
        puts("������� ��� ����� ��� ��������");
        gets(filename);
    }
    if ((f=fopen(filename,"rb"))==NULL)
    {
        perror("������ �������� �����");return 2;
    }
    puts("���������� �����");
    print_file(f);//����� ����������� ����� �� �����
    printf("\n");
    if ((f1=fopen("binary_after","wb"))==NULL)
    {
        perror("������ �������� �����");return 3;
    }
    file_procces(f,f1);//��������� �����
    fclose(f);
    remove(filename);
    rewind(f1);
    if ((freopen("binary_after","rb", f1))==NULL)//������������ freopen, ����� �� ��������� ��������� ��� ���� f1
    {
        perror("������ �������� �����");return 4;
    }
    printf("���������� ����� ����� ���������:\n");
    print_file(f1);
    //�������� ������
    fclose(f);
    remove(filename);
    fclose(f1);
    rename("binary_after", filename);
    return 0;
}

void print_file(FILE *f)//����� ����������� ��������� ����� �� �����
{
    int x, sz=sizeof(int);
    rewind(f);
    while (fread(&x, sz, 1, f))//���������� ����� �� ����� � ��������� x
        printf("%d ", x);
}
void file_procces(FILE *f1, FILE *f2)//�������� ��������� ����� �� �������
{
    int x;
    rewind(f1);
    rewind(f2);
    while (fread(&x, sizeof(int), 1, f1))//���� ���� ����, ��������� ����� �� ����� � ��������� x
    {
        if(x==0)//���� x ����� 0 �� ���������� ���
            continue;
        if (x>0)//���� x ����������� �� ���������� ����� � ���������� ��� �������
        {
             fwrite(&x, sizeof(int), 1, f2);
             x=x*x;
             fwrite(&x, sizeof(int), 1, f2);
        }
        else//���� ����� ������������ �� ������ ���������� ���
            fwrite(&x, sizeof(int), 1, f2);
    }
}

