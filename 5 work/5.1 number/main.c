#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 6
#define L 18

double average(int *, int);//������� �������� ���������������
void input_array(int *, int);//���������� �������
void output_array(const int *, int, int);//����� �������


int main()
{
    int a[N][M], b[L];
    double average_a, average_b;
    int i, count;//count ����������, ������� ������� � ������� �������� ������� a ������� �������������� ������ �������� ��������������� ������� b
    input_array(b, L);//��������� ���������� ������ b ��������� �������
    printf("Array b\n");
    output_array(b,1,L);//������� ������ b �� �����, 1 ��� ���������� ������ �� ����� ������
    input_array(a[0], M*N);//��������� ���������� ������� ��������� ������ �, M*N ���������� ��������� � ������� �
    printf("Array a\n");
    output_array(a[0], N, M);//������� ��������� ������ � �� �����
    average_b=average(b, L);//����������� ���������� average_b ������� �������������� ������� b
    count=0;//�������� ����������
    for (i=0;i<N;i++)/*�������� ������� �������������� ����� ������ ������� � � ������� ���������� �����
    , ��� ������� ������������� ������ ������ �������� ��������������� ������� b*/
    {
        average_a=average(a[i],M);//����������� ���������� average_� ������� �������������� ������ � �������� i
        printf("%lf\n", average_a);
        if (average_a>average_b)//���������� ������� �������������� ������ � ������� �������������� ������� b
            count+=1;//���� ������, �� ����������� �����������
    }
    printf("Count\n");
    printf("%3d", count);
    return 0;
}

//��������� ������ ���������� �������
void input_array(int *array, int n)
{
    int i;
    for (i=0;i<n; i++)
        array[i]=rand()%10;
}
//������� ������ �� ����� � ������� ���������
void output_array(const int *a, int n, int m)
{
    int i;
    for (;n>0;n--)//���� ���������� ����� ������ ����, �� ������� �������� ���� ������
    {
        for(i=0;i<m;i++)
            printf("%3d ", *a++);
        printf("\n");
    }
}
//������� �������� ��������������� � ������
double average(int *a, int n)
{
    int i, sum=0;
    double average=0;//�������� ���������� ����� ������ � �������� ���������������
    for (i=0; i<n; i++)
        sum+=a[i];//������� ����� ���� ��������� � ������, n-���������� ��������� � ������
    average=(double)sum/n;//��������� ������� ��������������, ���� �������� n � double
    return average;
}
