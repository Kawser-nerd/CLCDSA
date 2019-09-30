#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

long long N, M, P, Q, R;

long long ans = 0;
long long used[500];
long long x[500], y[500], z[500];

long long getmax()
{
    long long p[500] = {0};
    for (int i = 0; i < R; i++)
    {
        if(used[x[i]] == 1)
        {
            p[y[i]] += z[i];
        }
    }
    sort(p, p + M, greater<long long>());
    long long sum = 0;
    for (int i = 0; i < Q; i++)
    {
        sum += p[i];
    }
    return sum;
}
void rec(long long n, long long sum)
{
    if(sum == P)
    {
        ans = max(getmax(), ans);
        //cout << "ans = " << ans << endl;
        return;
    }
    if(N - n + sum <= P)
    {
        for (int i = n; i < N;i++)
        {
            used[i] = 1;
        }
        ans = max(getmax(), ans);
        for (int i = n; i < N; i++)
        {
            used[i] = 0;
        }
        return;
    }
    rec(n + 1, sum);
    used[n] = 1;
    rec(n + 1, sum + 1);
    used[n] = 0;
}

int main()
{
    cin >> N >> M >> P >> Q >> R;
    for (int i = 0; i < R;i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
    }
    rec(0, 0);
    cout << ans << endl;
    return 0;
}