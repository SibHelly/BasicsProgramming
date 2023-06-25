#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int, int);//��������� ������ ��� ������������ ������� �� ��������
void input_array(int **, int, int);//���������� ������� ���������� ������� �� ��������
void output_array(const int**,int,int);// ������ ������� �� ��������
int search_delete(int **, int, int, int);//����� � �������� �������� � ������������ ����������� ������������� �����, ���������� ���������� ���������� ��������
void free_memory(int **, int);//����������� ������


int main()
{
    srand(time(0));
    int **A, **B;
    int N=5, M=7, L=7, L_after, M_after;
    A=create_matrix(M,N);//�������� ������ ����������� ��� ������� A
    if (A==NULL)
    {
        printf("Error");
        return 100;
    }
    input_array(A, M, N);// ��������� ������� � �� ��������
    printf("Array A\n");
    output_array(A, M, N);//������� ������� � �� ����� �� ��������
    printf("Array A after deleting\n");
    M_after=search_delete(A, M, N, 2);/*���������� � ���������� M_after ���������� ��������, ������� �������� ����� ��������
    �������� � ������������ ����������� ������������� ����� count_negative_A*/
    output_array(A,M_after,N);//������� ��� ���������� ������� ������� �
    free_memory(A,M_after);// ����������� ������
    B=create_matrix(L,L);//�������� ������ ����������� ��� ������� B
    if (B==NULL)
    {
        printf("Error");
        return 100;
    }
    input_array(B,L,L);// ��������� ������� B �� ��������
    printf("Array B\n");
    output_array(B,L,L);//������� ������� B �� ����� �� ��������
    printf("Array B after deleting\n");
    L_after=search_delete(B,L,L,3);/*���������� � ���������� L_after ���������� ��������, ������� �������� ����� ��������
    �������� � ������������ ����������� ������������� ����� count_negative_B*/
    output_array(B,L_after,L);//������� ��� ���������� ������� ������� B
    free_memory(B,L_after);//����������� ������
    return 0;
}
void input_array(int **a, int n, int m)//n-�������, m-������,���������� ������� ���������� �������
{
    int i, j;
    for (i = 0; i<m; i++)//���� �� �������
    {
        for (j = 0; j<n; j++)//���� �� �������
        {
            a[j][i] = rand()%100-50;//���������� �� ��������
        }
    }
}

int **create_matrix(int n, int m)//n-�������, m-������, ��������� ������ �� �������� ��� �������
{
    int **a, i;
    a=calloc(n, sizeof(int*));
    if (a==NULL)
    {
        printf("Error");
        return NULL;
    }
    for (i=0;i<n;i++)
    {
        a[i]=calloc(m,sizeof(int));
        if (a[i]==NULL)
        {
            for (--i;i>=0;i--)
                free(a[i]);
            free(a);
            printf("Error");
            return NULL;
        }
    }
    return a;
}

void output_array(const int **a, int n, int m)//n-�������, m-������, ����� ������� �� ����� �� ��������
{
    int i, j;
    if (n)//���� ���������� �������� �� 0, �� ������� �������, ����� ������� ������� ������
        for (i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
                printf("%4d", a[j][i]);//������� �� ��������
            printf("\n");
        }
    else
        printf("Matrix empty\n");
}


int search_delete(int **a, int n, int m, int count_negative)//n-�������, m-������, count_negative-������������ ���������� ������������� ����� � �������
{
    int i, j, k, count;//k-���������� ���������� ��������,count-���������� ������������� ����� � �������
    for (j=0, k=0;j<n; j++)//���� �� ��������
    {
        count=0;//�������� ��� �������� ������������� ����� � �������
        for (i=0;i<m;i++)//���� �� �������
            if (a[j][i]<0)//������� ���������� ������������� ����� � �������
                count++;
        if (count<count_negative)//���� �������, � ������� ���������� ������������� ����� ������ �������������
            a[k++]=a[j]; //���� � ������� ���������� ������������� ����� ������ ������������� ���������� ������������� �����, ����������� ���������� ���������� �������� � ������� ���
        else//���� � ������� ���������� ������������� ����� ������ ������������� ���������� ������������� �����, �� ������� ���� �������
            if (i<m)
            {
                free(a[j]);//����������� ������
                a[j]=NULL;//�������� ���������
            }
    }
    n=k;//����� ����� �������� � �������
    return n;
}

void free_memory(int **a, int n)//����������� ������ �� ��� ������������ �������
{
    int i;
    for (i=0;i<n;i++)
        free(a[i]);
    free(a);
}
