#include<stdio.h>
#include<math.h>
int power(int a, int b)
{
    int j,f=1;
    for(j=1; j<=b; j++)
    {
        f=f*a;
    }
    return f;
}
int main()
{
    int n,i,sum,s;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        sum=power(2,i);
        if(sum>n)
            break;
    }
    s=power(2,i-1);
    printf("%d\n",s);

    return 0;
}