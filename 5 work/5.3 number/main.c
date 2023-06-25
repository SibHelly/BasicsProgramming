#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30
#define L -1
#define M 4
#define K 1

double cube_parabola(double);//������������ ��������  ���������� �������� 2*x^3+1
double logarifm(double);//������� �������� ln(x^2+1)
double integral(double, double, double (*)(double));//��������� �������� ��������� ������� ���������������

int main()
{
    double integral_1, integral_2;
    integral_1=integral(L,M,cube_parabola);//��������� �������� ��������� 2*x^3+1 ��� x �� -1 �� 4
    printf("%3.5lf\n", integral_1);
    integral_2=integral(K,M,logarifm);//��������� �������� ��������� ln(x^2+1) ��� x �� -1 �� 4
    printf("%3.5lf\n", integral_2);
    return 0;
}

double cube_parabola(double x)//���������� �������� ���������� � ���������� ����������� x
{
    return 2*x*(x*x+1);
}

double logarifm(double x)//���������� �������� ���������� � ���������� ����������� x
{
    return log(x*x+1);
}



double integral(double a, double b, double (*f)(double))//������� �������� ������� ���������������, � ������� 30 �����
{
    double h=(b-a)/N, s=0;//h-���� ���,s-������� ����� ���� �����
    for (a+=h/2;a<b;a+=h)//���� �������� ���������
        s+=f(a);
    return s*h;

}
