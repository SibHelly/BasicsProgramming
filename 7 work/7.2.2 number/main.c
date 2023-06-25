#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swap(double*, double*);//�������, ������ ������� ��������
void sort(double*, int);// ������� ���������� �������
int search_count(char*);//�������, ������� ������� ���������� ����� � ������
void str_to_array(char *, double *, int);//������� ������� ��������� ������ ������������� �������


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");
    FILE *f1, *f2;
    char s[1000], s1[1000];
    char filename[80];
    double *a=NULL;
    int i, count, mi_count=1000, ma_count=0, flag_count=0, k=0, t=0;
    //�������� ����� � �������� �������� �� ���� ��� ���
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
    //�������� ������� �� ������������
    rewind(f1);
    while (fgets(s1, 1000, f1))
    {
        i++;//������� ������� ����� � ����� �����
        count=search_count(s1);//���� ���������� ����� � ������
        if (count)//���� ������������ � ����������� ���������� ����� � ������� �����
        {
            flag_count++;//���� ���������� ����� � ������ �� 0, �� ���������� ���������� �� ������ �����
            if (count>ma_count)
                ma_count=count;
            if (count<mi_count)
                mi_count=count;
        }
        else
        {
            k++;//���� ������ ������ ����������� ������� ������ �����
            flag_count=0;//�������� ���� ���� ����� ������ ������
        }
        if (flag_count==1)//������� ������� ��� �� ������� �� ������ ������, �� ���� ���������� ��� ������� ������� ��������
            t++;//������� ���������� ������
    }
    if (i==k)//���� ���������� ����� � ����� � ���������� ������ ����� ���������, �� ���� ����
    {
        printf("File empty");
        return 0;
    }
    if (t>1)//���� ���������� ������ � ����� ������ �����
    {
        printf("In file several matrix");
        return 0;
    }
    if (ma_count==mi_count)//���� ������� ��������� � � ������ ������ ���������� ���������� �����
    {
        rewind(f1);
        while (fgets(s,1000, f1))
        {
            count=search_count(s);//������ ���������� ����� � ������
            if (count)//���� ������ �� ������
            {
                a=(double*)malloc(count*sizeof(double));//������� ������������ ������ ��� ���������� ����� � ������
                if (a==NULL)
                {
                    printf("Error");
                    return 100;
                }
                str_to_array(s, a, count);//��������� ������������ ������
                sort(a,count);//��������� ������
                for (i=0;i<count;i++)//���������� � ����
                {
                    fprintf(f2,"%.3lf ", a[i]);
                    printf("%.3lf ", a[i]);
                }
                free(a);//������������
                printf("\n");
                fputc('\n', f2);
            }
        }
        fclose(f1);
        fclose(f2);
        //remove(filename);
        //rename("matrix1.txt", filename);
    }
    else//���� � ������ ������ �� ���������� ���������� �����
    {
        printf("Marix is not correct");
    }
    return 0;
}

void swap(double *a, double *b)//������� ������� ������ ����� �������
{
    double temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(double *array, int n)//������� ����������
{
    int max=0,min=0, i;
    //������� ������ ������������� �������� � �������
    for (i=0;i<n;i++)
        if (array[i]>array[max])
            max=i;
    swap(&array[max],&array[n-1]);//������ ��� �� ��������� ����� � �������
    //������� ������ ������������ �������� �������
    for (i=0;i<n;i++)
        if (array[i]<array[min])
            min=i;
    swap(&array[min],&array[0]);//������ ��� �� ������ �����
}

int search_count(char *str)//������� �������� ���������� ����� � ������
{
    int count=-1;//��� ��� ���� ��� ���������� ����� ������� ������ ���, ������� count=-1
    char* nstr = str;//������� ��������� �� ���������� ������
    char* tstr;//������� ���������
    double d;//���� ������������ ����� �� ������
    while (1)// ���� � ������ ���� �����
    {
        tstr=nstr;//���������� ����� ������� ������
        d=strtod(nstr, &nstr);//�������������� ����� �� ������ � ������������ �����, ����� ���� ������ ����� �� ����������
        count++;
        if (d==0 && tstr==nstr)//���� tstr � nstr �� �������� � ����� �� ������ 0, �� ���� ���� ���� ����� � ������
            break;
    }
    return count;
}

void str_to_array(char *str, double *array, int count)//��������� ������ ������� �� ������
{
    char* nstr = str;//��������� �� ������
    int i;//������
    for (i=0;i<count;i++)
    {
       array[i] = strtod(nstr,&nstr);//��������� ������
    }
}
