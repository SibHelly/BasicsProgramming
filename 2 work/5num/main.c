#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double w, pr, sum;
    unsigned int n=0;
    printf("initial deposit w=");
    scanf("%lf", &w);
    printf("percentage of annual growth pr=");
    scanf("%lf", &pr);
    printf("amount to be accumulated sum=");
    scanf("%lf", &sum);/*���� �������� ������*/
    if (sum<w)/* ��������� �� ��������� �� ��� �����*/
        printf("accumulated amount\n");
    else
    {
        do /*����������� �������� �����, ������ ��� ���������� n(������� ���), �� ��� ��� ���� �� ��������� ����������� ��� ���������� �����   */
        {
            w+=w*pr/100;/*����� ��������� �������� + ���������� �� ���������� ������ �� ���=�������� ����� � ����� ����*/
            n++;
        }
        while (w<sum);/*����������� �������� �������� ���� �� ��������� sum */
        printf("number of years to accumulate n=%d\n", n);/*���������� ��� �� ������� ����� ��������� ������ �����*/
    }
    system("pause");
    return 0;
}
