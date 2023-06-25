#include <stdio.h>
#include <stdlib.h>
#include <limits.h>/*эта библиотека включает определение характеристик общих типов переменных*/

int main()
{
    char c;
    unsigned char uc;
    printf("sizeof(c)=%d\tsizeof(uc)=%d\n\n", sizeof(c),sizeof(uc));/*выводим на экран обьем хранения данных в байтах
    для переменной типа char и unsigned char*/
    uc=c=CHAR_MAX;/* присваеваем переменным uc и с значение
    char_max(с помощью библиотеки limits.h)- предельное значение типа данных char*/
    printf("CHAR_MAX : c=%d uc=%d\n", c, uc);/*выводим на экран максимальное значение в типе данных char равное 127*/
    c = c + 1; uc = uc + 1;/*прибавляем единицу в типе данных char и получаем минимальное в типе char(01111111+1=11111111=-128),
    в типе данных unsigned char 127+1=128*/
    printf("CHAR_MAX+1 : c=%d uc=%d\n", c, uc);
    uc = c = CHAR_MIN;/*присваеваем переменным c и uc минимальное значение
    в типе данных char_min(с помощью библиотеки limits.h)
    в типе данных unsigned char(0 до 255), поэтому us получила значение 128,так как(10000000=128 в unsigned char) */
    printf("CHAR_MIN : c=%d uc=%d\n", c, uc);
    c = uc = UCHAR_MAX;/*присваевам максимальное значение типа unsigned char перменным
    uc=255(так uc типа unsigned char), c=-1 ,так как в char 11111111=-1*/
    printf("UCHAR_MAX : c=%d uc=%d\n", c, uc);
    c = c + 1; uc = uc + 1;/* в переменной с -1+1=0(11111111+1=100000000 первая единица отбрасывается, так как 8 битовое представление),
    в uc типа unsigned char 11111111+1=100000000 первой единицы не где храниться и она отбрасывается
    (переполнение) uc=0*/
    printf("UCHAR_MAX+1 : c=%d uc=%d\n", c, uc);
    uc = c = -5;/*присваеваем переменной c и uc -5, с=-5=11111011,uc=11111111-100=11111011=251,*/
    printf("-5 : c=%d uc=%d\n", c, uc);
    c = -5; uc = 5;/*присваеваем переменной c=-5 и переменной uc=5*/
    printf("char and unsigned char -5>5 : %d\n\n", c>uc);/* при сравнение 5 в типе данных unsigned char и -5 в char получаем ложное неравенство между с>uc*/
    return 0;
}
