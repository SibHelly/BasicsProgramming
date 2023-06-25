#include <stdio.h>
#include <stdint.h>
#define N 20

int main()
{
    char s[N];//строка
    int i;
    unsigned long number=0;//переменная, которой будет присвоено число из строки
    scanf("%s", s);//ввод с калвиатуры цифр в строку
    //преобразование цифр из строки в целое число
    for (i=0;s[i];++i)
        number=10*number+(s[i] -'0');
    if (number<=65535 && number>=0)/*если число из строки будет меньше или равно 65535(максимальное число в типе unsigned short int)
    , то его можно предстваить в типе unsigned short int, и так же проверяем натуральное ли число*/
        printf("Yep");
    else
        printf("Nope");
    return 0;
}
