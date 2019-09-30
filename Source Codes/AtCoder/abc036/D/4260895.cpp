#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const long long black = 0;
const long long white = 1;

const long long mod = 1e9 + 7;
long long N;
vector<vector<long long> > v;

long long used[100005];
long long memo[100005][2];

long long dfs(long long i, long long c)
{
    //cout << i << endl;
    if(memo[i][c] != -1)
    {
        return memo[i][c];
    }
    used[i] = 1;
    long long ret = 1;
    if (c == white)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            long long ni = v[i][j];
            if (used[ni] == 1)
            {
                continue;
            }
            ret = ret * (dfs(ni, black) + dfs(ni, white));
            ret %= mod;
        }
    }
    else
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            long long ni = v[i][j];
            if (used[ni] == 1)
            {
                continue;
            }
            ret = ret * dfs(ni, white);
            ret %= mod;
        }
    }
    used[i] = 0;
    memo[i][c] = ret;
    return ret;
}

int main()
{
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        v[f].push_back(t);
        v[t].push_back(f);
    }

    for (int i = 0; i < N;i++)
    {
        memo[i][0] = -1;
        memo[i][1] = -1;
    }

    cout << (dfs(0, black) + dfs(0, white)) % mod << endl;

    return 0;
}