#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **a, i, j, temp, M;
    printf("Input size of matrix M=");
    scanf("%d", &M);
//��������� ������ ��� ������ ���������� � ��� �������� �������
    a=calloc (M, sizeof(int*));
    if (a==NULL)
    {
        printf("Error");
        return 100;
    }
    a[0]=calloc(M*M, sizeof(int));//��������� ������ ��� �������� �������
    if (a[0]==NULL)
    {
        printf("Error");
        return 100;
    }
    for (i=1; i<M; i++)
        a[i]=a[i-1]+M;
//���������� ������� ��������� �������
    for (i=0;i<M;i++)
        {
            for (j=0;j<M;j++)
            {
                a[i][j]=rand()%100 -30;
                printf("%4d ", a[i][j]);
            }
            printf("\n");
        }
    printf("\n");
//���������� ������� ��������� �������
    for (i=0; i<M;i++)
        for (j=0; j<M; j++)
            if (a[i][i]<a[j][j])//���������: ���� ������� � �������� [0][0]< �������� � �������� [1][1], �� ������ �� �������, ��� ����� �������� ������� ���������
            {
                //������ ������� �������� �� ������� ���������
                temp=a[i][i];
                a[i][i]=a[j][j];
                a[j][j]=temp;
            }
//����� ���������������� �������
    for (i=0;i<M; i++)
    {
        for (j=0; j<M; j++)
            printf("%4d ",a[i][j]);
        printf("\n");
    }
    //������������ ������
    free(a[0]);
    free(a);
    return 0;
}
