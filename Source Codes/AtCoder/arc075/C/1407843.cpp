#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int size=1e6+10;
const int INF=1e9;
typedef long long LL;
LL tree[size];
LL a[size];
LL b[size];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x)
{
    while(x<size)
    {
        tree[x]+=1;
        x+=lowbit(x);
    }
}
LL ask(int x)
{
    LL sum=0;
    while(x)
    {
       sum+=tree[x];
       x-=lowbit(x);
    }
    return sum;
}
int main()
{
   int n;LL p;
   while(scanf("%d%lld",&n,&p)!=EOF)
   {
       memset(tree,0,sizeof(tree));
       LL ans=0;
     for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
     for(int i=1;i<=n;i++)
     {
         b[i]-=p;
         b[i]=b[i]+b[i-1];
            if(b[i]>=0) ans++;
         a[i-1]=b[i];
     }
     sort(a,a+n);
     int cnt=unique(a,a+n)-a;
     for(int i=1;i<=n;i++)
     {
          int temp=lower_bound(a,a+cnt,b[i])-a+1;
          ans+=ask(temp);
          update(temp);
     }
     printf("%lld\n",ans);
   }
}