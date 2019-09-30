#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <functional>
#include <numeric>
#include <cstring>

using namespace std;

int main()
{
    long long a[4], N;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> N;
    vector<pair<long long, long long> > b(4);
    b[0] = make_pair(a[0] * 8, 0);
    b[1] = make_pair(a[1] * 4, 1);
    b[2] = make_pair(a[2] * 2, 2);
    b[3] = make_pair(a[3], 3);
    sort(b.begin(), b.end());
    long long ans = 0;
    if (N % 2 == 0)
    {
        ans = b[0].first * (N / 2);
    }
    else
    {
        ans = b[0].first * (N / 2);
        long long t1 = a[0] * 4;
        long long t2 = a[1] * 2;
        long long t3 = a[2];
        ans += min(t1, min(t2, t3));
    }

    cout << ans << endl;

    return 0;
}