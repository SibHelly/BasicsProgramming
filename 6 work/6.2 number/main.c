#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[80];//������
    char temp;//���������� ��� ������ �������� � ������
    int i, k=0;//������ ��� �����, ���������� k ������ ������� ����� � �����
    scanf("%[^.]", s);//������ ������ � ���������� �� .
    for (i=0;s[i];i++)//������������� ������ �� ����-�����������
        if (s[i]==' ')/*���� ��������� ������ ��� �����, �� ��� ������ ��� ������� �����
        ������� ������ ������� ������ ����� � ��������� � ���� �����*/
        {
            temp=s[k];//������ ����� ������� ����� ����� ����� ������ 0, ����������� ���������� temp ������ �����
            s[k]=s[i-1];//����������� ������ ����� ��������� �����, ������� ����� ����� ������ � ������ �� 1 ������ �� ���������� �������
            s[i-1]=temp;//����������� ��������� ����� � �����, ������ �����
            k=i+1;//�������� ������ ������ �����, � ���������� ����� ������ ����� ����� ����� ������ �� 1 ������ �� ���������� ��������
        }
        //������ ������� ������ � ��������� ����� � ��������� ����� � ������
        temp=s[k];
        s[k]=s[i-1];
        s[i-1]=temp;
    puts(s);//������� ���������� ������
    return 0;
}
