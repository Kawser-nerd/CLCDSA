#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

long long N, H;
vector<pair<long long, long long> > x;

bool pairGreater(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}

int main()
{
    cin >> N >> H;
    for (int i = 0;i < N;i++)
    {
        long long a, b;
        cin >> a >> b;
        x.push_back(make_pair(a, 0));
        x.push_back(make_pair(b, 1));
    }

    sort(x.begin(), x.end(), pairGreater);

    long long ans = 0;
    long long rh = H;
    long long cnt = 0;
    while (rh > 0)
    {
        pair<long long, long long> t = x[cnt];
        if(t.second == 0)
        {
            if(rh % t.first == 0)
            {
                ans += rh / t.first;
            }
            else
            {
                ans += rh / t.first + 1;
            }
            break;
        }
        else
        {
            cnt++;
            ans++;
            rh -= t.first;
        }
    }

    cout << ans << endl;

    return 0;
}