
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    char c;
    unsigned char uc;
    int i;
    unsigned u;
    short s;
    long l;
    printf("sizeof(i)=%d\tsizeof(u)=%d\tsizeof(s)=%d\tsizeof(l)=%d\n\n",
          sizeof(i), sizeof(u), sizeof(s), sizeof(l));/*������� �� ����� ����� ����� ������ � ������*/
    c = s = SHRT_MAX;/*����������� ���������� ������������ �������� ���� ������ short int
    � ���������� � ���� char ������������ ������� ����(11111111=-1 � ���� char)*/
    uc = s;/*� ���������� uc ������������ ������� ������ ������������� �������� short int
    11111111=255 � ���� unsigned char*/
    printf("SHRT_MAX : c=%d uc=%d s=%d\n", c, uc, s);
    s = s + 1;/*�������� ����������� �������� ���� short int
    0111111111111111+1=1000000000000000=-32768*/
    printf("SHRT_MAX+1 : s=%d\n", s);
    c = s; uc = s;/*����������� 1 �������� ���������� ���� char � unsigned char
    ����������� �������� ���� short int(1000000000000000)
    � ���������� c � uc ������������ ������ ������� ������(�=0, uc=0) */
    printf("%d : c=%d uc=%d\n", SHRT_MIN, c, uc);
    s = 0; c = s; uc = s;/*�������� ���������� */
    printf("0 : c=%d uc=%d s=%d\n", c, uc, s);
    i = INT_MAX;/*����������� ������������ �������� ���� ������ int */
    l = i; u = i;/* ����������� ������������ �������� ���� int ����������
    l(��� long int) � u(��� unsigned int)*/
    printf("INT_MAX : i=%d u=%u l=%ld\n", i, u, l);
    i = i + 1; l = l + 1; u = u + 1;/*���������� i � l ����������� ����������� �������� ���� int
    ��� ��� ��� int � long int ���������� 4 �����(01111111111111111111111111111111+1=10000000000000000000000000000000),
    � ������ ����� � �������� ���� �������� �� ���� i=l=-2147483648,
    ���������� u ��� ����������� 1 ����������� �� �������(���� ������� ��� ����)
    u=2147483648 � ���� unsigned int */
    printf("INT_MAX+1 : i=%d u=%u l=%ld\n", i, u, l);
    i = INT_MIN;/*�������� ���������� i ����������� �������� ���� int */
    l = i; u = i;/*�������� ���������� l ���� long int ����������� �������� ���� int
    (�������� long int �������� � ��������� int, ��� ��� � int � long int 4 ����� � �����-2147483648),
    ���������� u ����� ����� 2147483648, ��� ��� 10000000000000000000000000000000=2147483648 � ����
    unsigned int*/
    printf("INT_MIN : i=%d u=%u l=%ld\n", i, u, l);
    u = UINT_MAX;/*����������� u ������������ �������� ���� unsigned char*/
    i = u; l = u;/*���������� i � l ����������� ������������ ������������� ���������(� �������� ���� ��� 1)
    11111111111111111111111111111111 � ���� int � long int(4 �����) ����� ����� -1(������ ������� ��� ����)*/
    printf("UINT_MAX : i=%d u=%u l=%ld\n", i, u, l);
    u = i = -5;/*���������� i=-5 ��� ��� int, ���������� u ���� unsigned int
    ������ ����� 11111111111111111111111111111111-101(4)=11111111111111111111111111111011
    =4294967291*/
    printf("-5 : i=%d u=%u\n", i, u);/* */
    i = -5; u = 5;/*i ���� int ����������� ��� ������ ��������
    ������������ � ���� unsigned int � -5 ���������� 4294967291 � ��� ����� > 5
    (4294967291(-5 ����� �������� ����������)>5), ������� ���������� �������*/
    printf("int and unsigned int -5>5 : %d\n", i > u);
    c = -5; u = 5;/*� ���� char ����������� ��� ������ ��������
    ������������ � ���� unsigned int � -5 ���������� 4294967291 � ��� ����� > 5
    (4294967291(-5 ����� �������� ����������)>5), ������� ��������� �������*/
    printf("char and unsigned int -5>5 : %d\n\n", c > u);
    i = 5.1;/*��� ������������ ���������� i ���� int ��������� ���������� ������ ����� ����� �����,
    ��� ��� ������� ����� ����� �� ������� �����*/
    printf("i=5.1 : i=%d\n", i);
    i = 5.9;/*��� ������������ ���������� i ���� int ��������� ���������� ������ ����� ����� �����,
    ��� ��� ������� ����� ����� �� ������� �����*/
    printf("i=5.9 : i=%d\n", i);
    return 0;
}


