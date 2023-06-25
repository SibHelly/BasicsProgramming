#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double w, pr, sum;
    unsigned int n=0;
    printf("initial deposit w=");
    scanf("%lf", &w);
    printf("percentage of annual growth pr=");
    scanf("%lf", &pr);
    printf("amount to be accumulated sum=");
    scanf("%lf", &sum);/*ввод исходных данных*/
    if (sum<w)/* проверяем не накоплена ли уже сумма*/
        printf("accumulated amount\n");
    else
    {
        do /*увеличиваем исходную сумму, каждый раз увеличивая n(счетчик лет), до тех пор пока не преодалем необходимую для накопления сумму   */
        {
            w+=w*pr/100;/*сумма исходного значения + увелечения по процентной ставке за год=получаем сумму в конце года*/
            n++;
        }
        while (w<sum);/*увеличиваем исходное значение пока не преодолем sum */
        printf("number of years to accumulate n=%d\n", n);/*количество лет за которое будет накоплена нужная сумма*/
    }
    system("pause");
    return 0;
}
