#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

const int L = 1000002013;

using namespace std;

int tc, n, m;

long long res1, res2, res;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

long long calc(int k, int n)
{
    return ((long long)k * (long long)n - (long long)k * (long long)(k - 1) / 2) % L;
}

void input()
{
    int i, o, e, p;
    
    res1 = 0;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &o, &e, &p);
        o--, e--;
        que.push(pair<int, int>(o, -p));
        que.push(pair<int, int>(e, p));
        res1 = (res1 + calc(e - o, n) * (long long)p) % L;
    }
}

void process()
{
    int t;
    stack<pair<int, int> > stk;
    pair<int, int> now;
    
    res2 = 0;
    for(; !que.empty(); que.pop())
    {
        now = que.top();
        if(que.top().second < 0)
        {
            stk.push(pair<int, int>(now.first, -now.second));
        }
        else
        {
            for(; 0 < now.second; )
            {
                t = min(stk.top().second, now.second);
                stk.top().second -= t;
                now.second -= t;
                res2 = (res2 + calc(now.first - stk.top().first, n) * (long long)t) % L;
                if(stk.top().second == 0)
                {
                    stk.pop();
                }
            }
        }
    }
    res = res1 - res2;
    for(res %= L; res < 0; res += L);
}

void output()
{
    printf("Case #%d: %lld\n", tc, res);
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/A-large.in", "r", stdin);
    freopen("/Users/protos37/Downloads/output.txt", "w", stdout);
    
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++)
    {
        input();
        process();
        output();
    }
    return 0;
}