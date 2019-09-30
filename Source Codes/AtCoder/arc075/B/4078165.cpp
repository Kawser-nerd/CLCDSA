#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1e5+5;

long long a[maxn],n,A,B;

bool check(long long x)
{
    long long  sum=0;
    for(long long i=1;i<=n;i++)
    {
        if(a[i]-x*B<=0)continue;
        sum=sum+(a[i]-x*B)/(A-B);
        if((a[i]-x*B)%(A-B)!=0)
			sum++;
    }
    return sum<=x;
}

int main()
{
    long long l,r,mid;
    scanf("%lld%lld%lld",&n,&A,&B);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    //cout<<"!!"<<endl;
    l=1;
	r=1e9;
    while(r-l>1)
    {
        mid=(l+r)/2;
        if(check(mid))
			r=mid;
        else l=mid;
    }
    printf("%lld\n",check(l)?l:r);
    return 0;
}