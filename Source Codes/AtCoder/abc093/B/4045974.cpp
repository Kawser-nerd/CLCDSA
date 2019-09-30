#include <stdio.h>
int main()
{
    int a, b, k;
    scanf("%d%d%d",&a,&b,&k);
    int i;
    for (i = a; i <= b; i++)
    {
        if (i - a < k || b - i < k)
        {
            printf("%d\n",i);
         
        }
    }
    return 0;

}