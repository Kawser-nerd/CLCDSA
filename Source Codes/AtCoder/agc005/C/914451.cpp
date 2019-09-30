#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define pb push_back
#define mkp make_pair
using namespace std;

const int maxn = 200005;
typedef long long ll;

int n,ma;
int cnt[maxn];

bool check()
{
    int mi = (ma+1)/2;
    for(int i=1;i<mi;i++)
        if(cnt[i])
            return 0;
    if(ma&1)
    {
        if(cnt[mi]!=2)
            return 0;
    }
    else
    {
        if(cnt[mi]!=1)
            return 0;
    }
    for(int i=mi+1;i<=ma;i++)
        if(cnt[i]<2)
            return 0;
    return 1;
}
int main()
{
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        ma = max(ma,x);
        cnt[x]++;
    }
    if(check())
        puts("Possible");
    else
        puts("Impossible");
}