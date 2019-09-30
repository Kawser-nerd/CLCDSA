#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long sum1[100010],sum2[100010],x[100010],v[100010],f[100010],a[100010],b[100010],ff[100010],t,n,c,ans,i,j;
void qt(long long l, long long r)
{
    long long i,j;
    long long m,p;
    i=l; j=r;
    m=x[(l+r)/2];
    while (i<=j)
    {
        while (x[i]<m) i++;
        while (x[j]>m) j--;
        if (i<=j)
        {
            p=x[i]; x[i]=x[j]; x[j]=p;
            p=v[i]; v[i]=v[j]; v[j]=p;
            i++; j--;
        }
    }
if (i<r) qt(i,r);
if (l<j) qt(l,j);
}

int main()
{
    scanf("%lld%lld",&n,&c);
    for (i=1;i<=n;i++)
        scanf("%lld%lld",&x[i],&v[i]);
    qt(1,n);
    ans=0;
    memset(sum1,0,sizeof(sum1));
    for (i=1;i<=n;i++)
        sum1[i]=sum1[i-1]+v[i];
    for (i=1;i<=n;i++)
        if (sum1[i]-x[i]>ans) ans=sum1[i]-x[i];
    memset(sum2,0,sizeof(sum2));
    for (i=n;i>=1;i--)
    sum2[i]=sum2[i+1]+v[i];
    for (i=1;i<=n;i++)
        if (sum2[i]-(c-x[i])>ans) ans=sum2[i]-(c-x[i]);
     memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    memset(b,0,sizeof(b));
    for (i=1;i<=n;i++)
    {
      if (sum1[i]-x[i]>f[i-1]) f[i]=sum1[i]-x[i]; else f[i]=f[i-1];
      if ((sum1[i]-x[i])>f[i-1]) a[i]=i; else a[i]=a[i-1];
    }

    for (i=n;i>=1;i--)
    {
      if (sum2[i]-(c-x[i])>ff[i+1]) ff[i]=sum2[i]-(c-x[i]); else ff[i]=ff[i+1];
      if ((sum2[i]-(c-x[i]))>ff[i+1]) b[i]=i; else b[i]=b[i+1];
    }

    for (i=1;i<=n;i++)
    {
      if (sum2[i]-(c-x[i])+f[i-1]-x[a[i-1]]>sum2[i]-(c-x[i])+f[i-1]-(c-x[i])) t=sum2[i]-(c-x[i])+f[i-1]-x[a[i-1]]; else
      t=sum2[i]-(c-x[i])+f[i-1]-(c-x[i]);
      if (t>ans)
      ans=t;
    }

    for (i=n;i>=1;i--)
    {
      if (sum1[i]-x[i]+ff[i+1]-(c-x[b[i+1]])>sum1[i]-x[i]+ff[i+1]-x[i]) t=sum1[i]-x[i]+ff[i+1]-(c-x[b[i+1]]); else
      t=sum1[i]-x[i]+ff[i+1]-x[i];
      if (t>ans)
      ans=t;
    }

    printf("%lld\n",ans);
    return(0);
}