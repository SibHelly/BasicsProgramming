#include <stdio.h>
#include <stdint.h>
#define N 20

int main()
{
    char s[N];//������
    int i;
    unsigned long number=0;//����������, ������� ����� ��������� ����� �� ������
    scanf("%s", s);//���� � ���������� ���� � ������
    //�������������� ���� �� ������ � ����� �����
    for (i=0;s[i];++i)
        number=10*number+(s[i] -'0');
    if (number<=65535 && number>=0)/*���� ����� �� ������ ����� ������ ��� ����� 65535(������������ ����� � ���� unsigned short int)
    , �� ��� ����� ����������� � ���� unsigned short int, � ��� �� ��������� ����������� �� �����*/
        printf("Yep");
    else
        printf("Nope");
    return 0;
}
