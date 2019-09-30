#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

const long long inf = 1e8 + 5;

int main()
{
    long long N;
    cin >> N;
    vector<long long> a(N);

    long long maxa = -inf;
    long long mina = inf;

    map<long long, long long> m;

    for (long long i = 0; i < N;i++)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    for (long long i = 0; i < N;i++)
    {
        if(a[i] == maxa)
        {
            m[maxa]++;
        }
        else
        {
            m[mina]++;
        }
    }
    //cout << "m[maxa] = " << m[maxa] << endl;
    //cout << "m[mina] = " << m[mina] << endl;
    string ans;
    long long val = (long long)(m[maxa] / 2);
    if (maxa - mina >= 2 || m[maxa] == 1)
    {
        ans = "No";
    }
    else if(maxa - mina == 0)
    {
        if(maxa <= val || maxa == N - 1)
        {
            ans = "Yes";
        }
        else
        {
            ans = "No";
        }
    }
    else
    {
        if (mina <= m[mina] - 1 + val && m[mina] <= mina )
        {
            ans = "Yes";
        }
        else
        {
            ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}