#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    printf("input n=");
    scanf("%d", &n);/* ���� ����� n*/
    while (n)/*��������� ������� � ����� 3 ����� ����������� ��������� ����� � 3
    ���� ��� ������� ����� �� 10 � ��������, ������� ����� 3, �� ������������� ���������, �����
    ��������� ����� ������ ��������� ����� ���� ����� �� 10 ������������, �������� ������� �������� ���� �� ������ ����� 3 � �����
    ���� ����� �� ������ ����� 0*/
    {
        if (n%10==3)/*���������� ��������� ����� ����� � 3*/
        {
            printf("number contains 3");
            break;/*���������� ������ ���������, ��� ��� ����� 3 */
        }
        else
            n/=10;/*������� ��������� ����� � �����, ���� ��� �� 3, ��� ��� �� �� ��������� */
    }
    if (n==0)/*��������� ���� ����� ����� ����� n, ���� ���� ���������� � � ����� �� ������� ����� 3 �������
    ��������� � ��� ��� � ����� ��� ����� 3 */
        printf("number does not contain 3");
    return 0;
}