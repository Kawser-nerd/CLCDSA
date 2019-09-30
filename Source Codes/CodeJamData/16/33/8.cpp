#include<cstdio>

using namespace std;

int T;
int a,b,c,K;

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&K);
        printf("Case #%d: ",t);
        if(c<=K)
        {
            printf("%d\n",a*b*c);
            for(int i=1;i<=a;i++)
                for(int j=1;j<=b;j++)
                    for(int k=1;k<=c;k++)
                        printf("%d %d %d\n",i,j,k);
        }
        else
        {
            printf("%d\n",a*b*K);
            for(int i=1;i<=a;i++)
                for(int j=1;j<=b;j++)
                    for(int k=1;k<=K;k++)
                        printf("%d %d %d\n",i,j,(i+j+k)%c+1);
        }
    }
    return 0;
}
