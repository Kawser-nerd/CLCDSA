#include<stdio.h>
int a[200050], b[200050];
int main()
{
    int n,j=0,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&b[i]);
    if(n%2==0)
    {
        for(i=n,j=0; i>=1; i--)
        {
            if(i%2==0&&i!=1)
            {
                a[j]=i;
                j++;
            }
        }
        a[j++]=1;
        for(i=3; i<n; i++)
        {
            if(i%2==1)
            {
                a[j]=i;
                j++;
            }
        }
    }
    else
    {
        for(i=n,j=0; i>=1; i--)
        {
            if(i%2==1&&i!=1)
            {
                a[j]=i;
                j++;
            }
        }
        a[j++]=1;
        for(i=2; i<n; i++)
        {
            if(i%2==0)
            {
                a[j]=i;
                j++;
            }
        }
    }
    for(i=0; i<j; i++)
        printf("%d ",b[a[i]]);
    printf("\n");
    return 0;
}