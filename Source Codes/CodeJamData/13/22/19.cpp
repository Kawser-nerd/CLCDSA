#include<cstdio>
#include<algorithm>
using namespace std;

double f[5000][5000];

double p()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    if (x<0) x=-x;

    if ((x+y)==0 )
    {
        if (n>0) return 1;
        return 0;
    }

    int len=-1;
    int tot=0;
    int xx=0;
    while (xx<x+y && tot<=n) {tot+=(len+1)*2+1;len+=2;xx+=2;}
    if (tot>n) return 0;

    n-=tot;
    int lvl=xx-x+1;
    if (x==0)
    {
        if (n>=len*2+3) return 1;
        return 0;
    }
    if (n>=len+1+lvl) return 1;

    for (int i=0;i<=n;i++)
    for (int j=0;j<=i;j++)
        f[i][j]=0;
    f[0][0]=1;
    for (int i=0;i<n;i++)
    for (int j=0;j<=i;j++)
    if (f[i][j])
    {
        if (j==len+1)
        {
            f[i+1][j]+=f[i][j];
        } else
        if (i-j==len+1)
        {
            f[i+1][j+1]+=f[i][j];
        } else
        {
            f[i+1][j+1]+=f[i][j]*0.5;
            f[i+1][j]+=f[i][j]*0.5;
        }
    }
    double res=0;
    for (int i=0;i<=len+1;i++)
    if (n-i>=lvl) res+=f[n][i];
    return res;

}

int main()
{
    freopen("b2.in","r",stdin);
    int t,id;
    scanf("%d",&t);
    for (int id=1;id<=t;id++)
    {
        printf("Case #%d: %.9lf\n",id,p());

    }

}
