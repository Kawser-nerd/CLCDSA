#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 200000
typedef long long ll;
int main()
{
	ll x,sum[MAX],tot,MIN;
	int n;
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        sum[i]=sum[i-1]+x;
    }
    tot=sum[n];
    MIN=abs(tot-2*sum[1]);
    for(int i=2;i<=n-1;i++)
    {
        MIN=min(MIN,abs(tot-2*sum[i]));
    }
    printf("%lld",MIN);
    return 0;
}