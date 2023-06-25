#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int main()
{
    char c;
    unsigned char uc;
    int i;
    unsigned u;
    short s;
    long l;
    printf("sizeof(i)=%d\tsizeof(u)=%d\tsizeof(s)=%d\tsizeof(l)=%d\n\n",
          sizeof(i), sizeof(u), sizeof(s), sizeof(l));/*������� �� ����� ����� �������� ������
    � ������ ��� ���������� ����: int, unsigned int, short int, long int*/
    c = s = SHRT_MAX;/*����������� ���������� c � s ������������ �������� ���� ������ short int*/
    uc=s;/*����������� us �������� ������������� �������� short int*/
    printf("SHRT_MAX : c=%d uc=%d s=%d\n", c, uc, s);
    s = s + 1;/*   ����� ����������� 1 �������� ����������� �������� ���� ������ short int
    (��� ��� ����� ����������� 1 ���������� �������� ��������� �������� short int � ��������
     ����������� ������ -32768,��������� �� ������ ���������*/
    printf("SHRT_MAX+1 : s=%d\n", s);
    c = s; uc = s;/*����������� ���������� c ���� char �����������
    �������� ���� short int(��� ���������� ��� ���������, ������� ������ ��������� �������� ����� ��������� ������������ � 0),
    ����������� uc ���� unsinged char �����������
    �������� ���� short int(��� ���������� ��� ���������, ������� ������ ��������� �������� ����� ��������� ������������ � 0)*/
    printf("%d : c=%d uc=%d\n", SHRT_MIN, c, uc);
    s = 0; c = s; uc = s;/*�������� ����������*/
    printf("0 : c=%d uc=%d s=%d\n", c, uc, s);
    i = INT_MAX;/*����������� i ������������ �������� ���� int*/
    l = i; u = i;/*����������� ���������� l � ���������� u �������� ���������� i
    (������������ �������� ���� int)*/
    printf("INT_MAX : i=%d u=%u l=%ld\n", i, u, l);/*������� �� ����� ������������ �������� ���� int, long int*/
    i = i + 1; l = l + 1; u = u + 1;/* ����������� �� ������� �������� ��������� i ���� int (-2147483648 �� 2147483647),
    ��� ����� �������� ������� �� ������� ��������� � ����������� ����������� ��������� ���� int(-2147483648 �� 2147483647),
    ����������� �� 1 ���������� l ���� long int, ��� ����� �������� ������� �� ������� ��������� � ����������� ����������� ��������� ���� long int,
    ��� ����������� 1 � ���������� u ���� unsigned int, �������� ������������� �� 1 � ����������� ����� 2147483648*/
    printf("INT_MAX+1 : i=%d u=%u l=%ld\n", i, u, l);
    i = INT_MIN;/*����������� i ����������� �������� ���� int*/
    l = i; u = i;/*����������� l ���� long int ����������� �������� ���� int,
    ����������� u ���� unsigned int ����������� �������� ���� int, ��� ���������� ��� ���������, ������� ��� �������� �����������
    2147483648(��� ������ �� ������� ��������� 0 ���� ��������� �� �������������+1)*/
    printf("INT_MIN : i=%d u=%u l=%ld\n", i, u, l);
    u = UINT_MAX;/*����������� ���������� ���� unsigned int ������������ �������� ���� unsigned int*/
    i = u; l = u;/*����������� ���������� ���� int � long int ������������ �������� ���� unsigned int,
    ��� ���������� ��� ��������� ���� int � long int(-2147483648 �� 2147483647), ������� ��� ������ �� �������
    ����� ��������� �������� ���� ���������� ����������� -1(��� ������ �� ������� 2147483647+1=-2147483648,
    -2147483648+2147483647=-1*/
    printf("UINT_MAX : i=%d u=%u l=%ld\n", i, u, l);
    u = i = -5;/*��������� ���������� i -5  � ���������� u ���� unsigned int -5,
    -5 ���������� �� ��������� ���� unsigned int, ��� ������ �� ������ ��������� ��������
    ���������� �� ������������ �������� ���� +1 � -5= 4294967291*/
    printf("-5 : i=%d u=%u\n", i, u);
    i = -5; u = 5;/*��������  ���������� i �������� -5, � ���������� u �������� 5*/
    printf("int and unsigned int -5>5 : %d\n", i > u);
    c = -5; u = 5;/*��������  ���������� c �������� -5, � ���������� u �������� 5*/
    printf("char and unsigned int -5>5 : %d\n\n", c > u);
    i = 5.1;/*����������� i ���� int ������������ �����, �� � ���������� ������������ ������ ����� ����� �����*/
    printf("i=5.1 : i=%d\n", i);
    i = 5.9;/*����������� i ���� int ������������ �����, �� � ���������� ������������ ������ ����� ����� �����*/
    printf("i=5.9 : i=%d\n", i);
    return 0;
}
