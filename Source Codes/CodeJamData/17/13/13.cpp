#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
int dp[105][105][105][105];

int b, d;
int fhd;

int D(int hd, int hk, int ad, int ak)
{
    if (hd <= 0) return INF;
    if (hk <= 0) return 0;

    auto &ans = dp[hd][hk][ad][ak];

    if (ans == -1)
    {
        ans = INF;
        int ret = INF;

        // attack
        ret = min(ret, D(hk > ad ? hd - ak : hd, hk - ad, ad, ak) + 1);

        // cure
        ret = min(ret, D(fhd - ak, hk, ad, ak) + 1);

        // debuff
        if (d && ak) ret = min(ret, D(hd - max(0, ak - d), hk, ad, max(0, ak - d)) + 1);

        // buff
        if (b && ad < hk) ret = min(ret, D(hd - ak, hk, min(hk, ad + b), ak) + 1);

        ans = ret;
    }

    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);

        int hd, ad, hk, ak;
        scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
        fhd = hd;

        memset(dp, -1, sizeof(dp));

        int res = D(hd, hk, ad, ak);
        if (res == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", res);
    }
}

