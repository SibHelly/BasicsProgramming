#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30
#define L -1
#define M 4
#define K 1

double cube_parabola(double);//подсчитывает значение  кубической параболы 2*x^3+1
double logarifm(double);//считает значение ln(x^2+1)
double integral(double, double, double (*)(double));//вычисляет значение интеграла методом прямоугольников

int main()
{
    double integral_1, integral_2;
    integral_1=integral(L,M,cube_parabola);//вычисляем значение интеграла 2*x^3+1 для x от -1 до 4
    printf("%3.5lf\n", integral_1);
    integral_2=integral(K,M,logarifm);//вычисляем значение интеграла ln(x^2+1) для x от -1 до 4
    printf("%3.5lf\n", integral_2);
    return 0;
}

double cube_parabola(double x)//возвращает значение полученное в результате подстановки x
{
    return 2*x*(x*x+1);
}

double logarifm(double x)//возвращает значение полученное в результате подстановки x
{
    return log(x*x+1);
}



double integral(double a, double b, double (*f)(double))//считает интеграл методом прямоугольников, с помощью 30 точек
{
    double h=(b-a)/N, s=0;//h-один шаг,s-считает сумму всех шагов
    for (a+=h/2;a<b;a+=h)//цикл подсчета интеграла
        s+=f(a);
    return s*h;

}
