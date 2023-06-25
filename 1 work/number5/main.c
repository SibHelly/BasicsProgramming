#include <stdio.h>
#include <stdlib.h>
#include <limits.h>/*��� ���������� �������� ����������� ������������� ����� ����� ����������*/

int main()
{
    char c;
    unsigned char uc;
    printf("sizeof(c)=%d\tsizeof(uc)=%d\n\n", sizeof(c),sizeof(uc));/*������� �� ����� ����� �������� ������ � ������
    ��� ���������� ���� char � unsigned char*/
    uc=c=CHAR_MAX;/* ����������� ���������� uc � � ��������
    char_max(� ������� ���������� limits.h)- ���������� �������� ���� ������ char*/
    printf("CHAR_MAX : c=%d uc=%d\n", c, uc);/*������� �� ����� ������������ �������� � ���� ������ char ������ 127*/
    c = c + 1; uc = uc + 1;/*���������� ������� � ���� ������ char � �������� ����������� � ���� char(01111111+1=11111111=-128),
    � ���� ������ unsigned char 127+1=128*/
    printf("CHAR_MAX+1 : c=%d uc=%d\n", c, uc);
    uc = c = CHAR_MIN;/*����������� ���������� c � uc ����������� ��������
    � ���� ������ char_min(� ������� ���������� limits.h)
    � ���� ������ unsigned char(0 �� 255), ������� us �������� �������� 128,��� ���(10000000=128 � unsigned char) */
    printf("CHAR_MIN : c=%d uc=%d\n", c, uc);
    c = uc = UCHAR_MAX;/*���������� ������������ �������� ���� unsigned char ���������
    uc=255(��� uc ���� unsigned char), c=-1 ,��� ��� � char 11111111=-1*/
    printf("UCHAR_MAX : c=%d uc=%d\n", c, uc);
    c = c + 1; uc = uc + 1;/* � ���������� � -1+1=0(11111111+1=100000000 ������ ������� �������������, ��� ��� 8 ������� �������������),
    � uc ���� unsigned char 11111111+1=100000000 ������ ������� �� ��� ��������� � ��� �������������
    (������������) uc=0*/
    printf("UCHAR_MAX+1 : c=%d uc=%d\n", c, uc);
    uc = c = -5;/*����������� ���������� c � uc -5, �=-5=11111011,uc=11111111-100=11111011=251,*/
    printf("-5 : c=%d uc=%d\n", c, uc);
    c = -5; uc = 5;/*����������� ���������� c=-5 � ���������� uc=5*/
    printf("char and unsigned char -5>5 : %d\n\n", c>uc);/* ��� ��������� 5 � ���� ������ unsigned char � -5 � char �������� ������ ����������� ����� �>uc*/
    return 0;
}
