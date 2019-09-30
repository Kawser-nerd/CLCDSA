#include<cstdio>

double a[5][33],p;
int h,i,j,n,t,x;

double f(int n,int x)
{
    int i;
    double m,u;
    if(x>31)return 1;
    if(!n)
    {
        if(x+x>31)return p;
        else return 0;
    }
    if(!x)return 0;
    if(a[n][x]>-1)return a[n][x];
    m=0;
    for(i=1;i<=x;i++)
    {
        u=f(n-1,x+i)*p+f(n-1,x-i)*(1-p);
        if(u>m)m=u;
    }
    a[n][x]=m;
    return m;
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&t);
    for(h=0;h<t;h++)
    {
        scanf("%d %lf %d",&n,&p,&x);
        for(i=0;i<5;i++)
            for(j=0;j<33;j++)a[i][j]=-2;
        for(i=0;i<n;i++)
            for(j=0;j<33;j++)
                a[i][j]=f(i,j);
        x=x*32/1000000;
        printf("Case #%d: %.6lf\n",h+1,a[n-1][x]);
    }
    return 0;
}
