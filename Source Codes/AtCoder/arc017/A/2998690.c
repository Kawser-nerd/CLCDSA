#include<stdio.h>
int a[10000001];
int main()
{
    int n,i,j,t;
    a[1]=1;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {if(a[i]==0)
    for(j=i*2;j<=n;j+=i)
    if(a[j]==0)
    {a[j]=1;}}
    if(a[n]==0)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^