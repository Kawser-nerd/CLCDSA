#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,k,i;
    while(scanf("%d%d%d",&a,&b,&k)!=EOF)
    {
        if(k<1||k>100)
            break;
        if(b-a+1<k*2)
        {
            for(i=a;i<=b;i++)
                printf("%d\n",i);
        }
        else
        {
            for(i=a;i<=a+k-1;i++)
                printf("%d\n",i);
            for(i=b-k+1;i<=b;i++)
                printf("%d\n",i);
        }
    }
    return 0;
}