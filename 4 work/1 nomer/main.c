#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[9]={5, 4, 0, 8, 2, 9, 1, 3, 7};//0,2,4,7,9,8,5,3,1//
    int index_min=0, i=0;
    int temp, index_first=0, index_last=8;
    for (index_first=0, index_last=8;index_first<index_last;index_last--)
    {
    while ( index_first<index_last)
       {
           if (a[i]<a[index_min])
            index_min=index_first;
       }
    temp=a[index_min];
    a[index_min]=a[index_first];
    a[index_first]=temp;
    ++index_first;
    while (index_first<index_last)
       {
           if (a[i]<a[index_min])
            index_min=index_first;
       }
    temp=a[index_min];
    a[index_min]=a[index_last];
    a[index_last]=temp;
    }
    for (i=0; i<9;i++)
        printf("%d ", a[i]);
    return 0;
}
