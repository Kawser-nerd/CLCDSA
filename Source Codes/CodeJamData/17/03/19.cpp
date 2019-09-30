#include <bits/stdc++.h>
using namespace std;

int dat[105];

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);

        long long n, k;
        scanf("%lld%lld", &n, &k);

        map<long long, long long> mp;
        mp[n] = 1;

        for (;;)
        {
            auto itr2 = prev(mp.end());
            auto itr = *itr2;

            long long L = (itr.first - 1) / 2, R = itr.first / 2;

            if (itr.second >= k)
            {
                printf("%lld %lld\n", max(L, R), min(L, R));
                break;
            }
            else
            {
                k -= itr.second;

                mp.erase(itr2);

                if (L) mp[L] += itr.second;
                if (R) mp[R] += itr.second;
            }
        }
    }
}
