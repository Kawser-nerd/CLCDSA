#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 1000+10

int work(int n,int a[MAX],int b[MAX])
{
    int i,j,sum=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if (j!=i)
            {
                if ((a[j]-a[i])*(b[j]-b[i])<0) sum++;
            }
    }
    return (sum/2);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,n,ans;
    int a[MAX],b[MAX];
    int i,j,k;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for (j=1;j<=n;j++)  scanf("%d%d",&a[j],&b[j]);
        ans=work(n,a,b);
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
