#include<iostream>
#include<map>
using namespace std;
const int maxn=16;
int t,tt,n,s[maxn];
double p,st,;
pair<double,double> a[maxn][1<<maxn];
map<double,double> hash;
void init()
{
     scanf("%d%lf%lf",&n,&p,&st);      
}

double calc(int x,double y)
{
       if (!x) 
       {
          if (y>=1000000) return 1;
          return 0;
       }
       int i;
       double r;
       r=calc(x-1,y);
       for (i=0;i<s[x-1];i++)
       if (y>a[x-1][i].first) r>?=calc(x-1,a[x-1][i].first)*(1-p)+calc(x-1,2*y-a[x-1][i].first)*p;
       else
       if (y*2>=a[x-1][i].first) r>?=calc(x-1,a[x-1][i].first)*p+calc(x-1,2*y-a[x-1][i].first)*(1-p);
       return r;
}

void print()
{
     printf("Case #%d: %.6lf\n",t+1,calc(n,st));
}

void work()
{
     memset(s,0,sizeof(s));
     a[0][0].first=0;
     a[0][0].second=1;
     a[0][1].second=1;
     a[0][1].first=1000000;
     s[0]=2;
     int i,j,k;
     map<double,double>::iterator it;
     for (i=1;i<=n;i++)
     {
         hash.clear();
         for (j=0;j<s[i-1];j++)
             for (k=j;k<s[i-1];k++) 
             hash[(a[i-1][j].first+a[i-1][k].first)/2]=1;
         s[i]=0;
         for (it=hash.begin();it!=hash.end();it++)
         {
             a[i][s[i]]=*it;
             s[i]++;
         }
         sort(a[i],a[i]+s[i]);
     }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for (scanf("%d",&tt),t=0;t<tt;t++)
    {
        init();
        work();
        print();
    }
    return 0;
}
