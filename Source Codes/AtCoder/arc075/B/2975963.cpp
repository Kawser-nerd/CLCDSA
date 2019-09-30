#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<algorithm>
#define L long long
#include<string.h>
#include <math.h>
#define N 100009
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f;

LL h[N];
LL n, a, b;

bool judge(LL mid)
{
    LL ans = mid;
    for(int i = 1; i <= n; i++)
    {
        LL tm = h[i] - b*mid;
        if(tm > 0)
        {
            LL cnt = tm / (a - b) + (tm % (a - b) == 0 ? 0 : 1);
            ans -= cnt;
            if(ans < 0) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    LL l = 0, r = INF;
    LL ans = INF;
    while(l <= r)
    {
        LL mid = (l + r)>>1;
        if(judge(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}