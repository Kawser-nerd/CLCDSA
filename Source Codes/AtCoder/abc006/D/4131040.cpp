#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<int> c;
vector<int> dp;

const int inf = 1000000;

int main()
{
    cin >> N;
    c.resize(N);
    dp.resize(N+1);
    fill(dp.begin(), dp.end(), -inf);

    for (int i = 0; i < N;i++)
    {
        cin >> c[i];
    }

    int ans = 0;

    for (int i = 1; i <= N;i++)
    {
        int card = c[i - 1];
        std::vector<int>::iterator p = upper_bound(dp.begin(), dp.begin() + ans + 1, card);
        int d = distance(dp.begin(), p);
        ans = max(ans, d);
        if(dp[d] == -inf)
        {
            dp[d] = card;
        }
        else
        {
            dp[d] = min(dp[d], card);
        }
    }

    cout << N - ans << endl;

    return 0;
}