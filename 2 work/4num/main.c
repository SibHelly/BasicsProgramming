#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b;
    unsigned n, k;
    printf("Input a=");
    scanf("%lf", &a);/*������ a */
    printf("input n=");
    scanf("%d",&n);/*������ n */
    b=a;/*����������� b ����������� �������� a,�����
        ���������� � ��� ��������� ���������*/
    k=1;/*����������� ���������� k=1, ��� �������� */
    while (k<=n)/*���� k �� > n ����������� �� ������ ������� k �� 1, ��� �������� ���������*/
    {
        b*=a-k*n;/*����������� �������� ��������� ���� k �� ����� ������ n
            ��������(n=3, �� ������ ������� ����� �� �������� kn=n �� ������ �������� kn=2n �� ������� �������� kn=3n=n^2)*/
        k++;/*����������� ���������� ���������� n */
    }
        printf("b=%.3lf", b);/*������� �������� ���������*/
    return 0;
}
