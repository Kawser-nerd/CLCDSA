#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdio>

using namespace std;

const long long M = 1e9 + 7;

long long dp[100005];

int main()
{
    long long N, A, B;
    vector<long long> S;

    cin >> N >> A >> B;

    if(A > B)
    {
        swap(A, B);
    }

    S.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
    }
    S[0] = -10e9;

    for (int i = 1; i <= N - 2;i++)
    {
        if(S[i + 2] - S[i] < A)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    dp[0] = 1;
    dp[1] = 1;

    long long dpsum = 1;
    long long l = 0;
    long long r = 1;
    // Sum up values from l to r - 1 to dpsum.

    for (int i = 2; i <= N;i++)
    {
    //    printf("l = %lld, r = %lld, dpsum = %lld\n", l, r, dpsum);
        r = max(r, l);
        while (S[i] - S[r] >= B)
        {
            dpsum += dp[r];
            dpsum %= M;
            r++;
        }
        
        dp[i] = dpsum;

        if(S[i] - S[i - 1] < A)
        {
            for (int j = l; j < r;j++)
            {
                dpsum = (dpsum + M) - dp[j];
                dpsum %= M;
            }
            l = i - 1;
        }
    }
    long long ans = 0;
    for (int i = l; i <= N;i++)
    {
        ans = (ans + dp[i]) % M;
    }

    cout << ans << endl;

    return 0;
}