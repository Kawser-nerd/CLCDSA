#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn=100000+10;
int id;
int t;
int n,m;
double P[maxn];
double Q[maxn];

int main()
{
    for (scanf("%d",&t);t--;)
    {
        scanf("%d%d",&n,&m);
        double A=0,B=0,C=0;
        double PP=1;
        
        P[0]=1;
        for (int i=1;i<=n;i++)
        {
            double x;
            scanf("%lf",&x);
            P[i]=PP*(1-x);
            PP*=x;
        }
        double PS=PP;

        for (int i=1;i<=n;i++) A+=P[i]*(m-n+1+m+1);
        A+=PP*(m-n+1);
        C=(m+1+1);
        
        PP=0;
        for (int i=1;i<n;i++)
        {
            PP+=P[i];
            Q[i]=PP*(n-i+m-i+1+m+1);
        }
        PP=PS;
        for (int i=n-1;i;i--)
        {
            PP+=P[i+1];
            Q[i]+=PP*(n-i+m-i+1);
        }

        double res=min(A,C);
        for (int i=1;i<n;i++) res=min(res,Q[i]);
        printf("Case #%d: %.6lf\n",++id,res);
    }
}


        
