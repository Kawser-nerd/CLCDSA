// vim:set ts=8 sw=4 et smarttab:
// Round 1C 2012

#include <cstdio>
#include <cassert>
#include <map>
#include <algorithm>

long long a[200], b[200];
int A[200], B[200];
int n, m;
long long memo[200][200];
std::map<long long, long long> memo_box[200][200];
std::map<long long, long long> memo_toy[200][200];

long long recur(int i, int j);
long long recur_box(int i, int j, long long remained);
long long recur_toy(int i, int j, long long remained);

long long recur(int i, int j)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (memo[i][j] >= 0)
    {
        return memo[i][j];
    }
    long long ret = 0;
    long long cur;
    if (A[i] == B[j])
    {
        if (a[i] == b[j])
        {
            cur = a[i] + recur(i + 1, j + 1);
        }
        else if (a[i] > b[j])
        {
            cur = b[j] + recur_box(i, j + 1, a[i] - b[j]);
        }
        else if (a[i] < b[j])
        {
            cur = a[i] + recur_toy(i + 1, j, b[j] - a[i]);
        }
        if (cur > ret)
        {
            ret = cur;
        }
    }
    cur = std::max(recur(i + 1, j), recur(i, j + 1));
    if (cur > ret)
    {
        ret = cur;
    }
    memo[i][j] = ret;
    return ret;
}

long long recur_box(int i, int j, long long remained)
{
    assert(i < n);
    if (j >= m)
    {
        return 0;
    }
    std::map<long long, long long>::const_iterator it = memo_box[i][j].find(remained);
    if (it != memo_box[i][j].end())
    {
        return it->second;
    }
    long long ret;
    long long cur;
    ret = recur(i + 1, j);
    if (A[i] == B[j])
    {
        if (remained == b[j])
        {
            cur = remained + recur(i + 1, j + 1);
        }
        else if (remained > b[j])
        {
            cur = b[j] + recur_box(i, j + 1, remained - b[j]);
        }
        else if (remained < b[j])
        {
            cur = remained + recur_toy(i + 1, j, b[j] - remained);
        }
    }
    else
    {
        cur = recur_box(i, j + 1, remained);
    }
    if (cur > ret)
    {
        ret = cur;
    }
    memo_box[i][j][remained] = ret;
    return ret;
}

long long recur_toy(int i, int j, long long remained)
{
    assert(j < m);
    if (i >= n)
    {
        return 0;
    }
    std::map<long long, long long>::const_iterator it = memo_toy[i][j].find(remained);
    if (it != memo_toy[i][j].end())
    {
        return it->second;
    }
    long long ret;
    long long cur;
    ret = recur(i, j + 1);
    if (A[i] == B[j])
    {
        if (a[i] == remained)
        {
            cur = remained + recur(i + 1, j + 1);
        }
        else if (a[i] > remained)
        {
            cur = remained + recur_box(i, j + 1, a[i] - remained);
        }
        else if (a[i] < remained)
        {
            cur = a[i] + recur_toy(i + 1, j, remained - a[i]);
        }
    }
    else
    {
        cur = recur_toy(i + 1, j, remained);
    }
    if (cur > ret)
    {
        ret = cur;
    }
    memo_toy[i][j][remained] = ret;
    return ret;
}

long long solve()
{
    for (int i = 0; i < 200; ++i)
    {
        for (int j = 0; j < 200; ++j)
        {
            memo[i][j] = -1;
            memo_box[i][j].clear();
            memo_toy[i][j].clear();
        }
    }
    return recur(0, 0);
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int tc = 1; tc <= ntc; ++tc)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld%d", &a[i], &A[i]);
        }
        for (int j = 0; j < m; ++j)
        {
            scanf("%lld%d", &b[j], &B[j]);
        }
        long long ans = solve();
        printf("Case #%d: %lld\n", tc, ans);
    }
}
