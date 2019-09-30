#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 100100100;

int dp[41][401][401];
int N, Ma, Mb;
int a[40], b[40], c[40];

int main()
{
    cin >> N >> Ma >> Mb;
    for (int i = 1; i <= N;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int ag = 0; ag < 401; ag++)
        {
            for (int bg = 0; bg < 401; bg++)
            {
                dp[i][ag][bg] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 1; i <= N;i++)
    {
        for (int ag = 0; ag <= 400;ag++)
        {
            for (int bg = 0; bg <= 400;bg++)
            {
                dp[i][ag][bg] = min(dp[i][ag][bg], dp[i - 1][ag][bg]);
                if (ag - a[i] >= 0 && bg - b[i] >= 0)
                {
                    dp[i][ag][bg] = min(dp[i][ag][bg], dp[i - 1][ag - a[i]][bg - b[i]] + c[i]);
                }
            }
        }
    }

    int ans = INF;
    int g = max( Ma, Mb);
    int i = 1;
    while (i * g <= 400)
    {
        ans = min(ans, dp[N][i * Ma][i * Mb]);
        i++;
    }

    if(ans == INF)
    {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}