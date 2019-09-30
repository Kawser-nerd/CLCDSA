#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=2e5+5;

map<long long,int>mp;
long long a[maxn],b[maxn],c[maxn],d[maxn],n,m,K,ans=0;

int lowbit(int x)
{
    return x&(-x);
}
int getsum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

void add(int x)
{
    while(x<maxn)
    {
        c[x]++;
        x+=lowbit(x);
    }
}

int main()
{
    cin>>n>>K;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]+a[i-1];
        b[i]=a[i]-K*i;
        d[i]=b[i];
    }
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b;
    for(long long i=1;i<m;i++)
    {
        mp[b[i]]=i;
    }
    for(long long i=1;i<=n;i++)
    {
        if(d[i]>=0)ans++;
        ans=ans+getsum(mp[d[i]]);
        add(mp[d[i]]);
    }
    cout<<ans;
    return 0;
}