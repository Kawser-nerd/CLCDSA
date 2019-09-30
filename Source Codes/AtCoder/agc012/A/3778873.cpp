#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long N;
vector<long long> a;

int main()
{
    cin >> N;
    long long ans = 0;
    a.resize(3 * N);
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N;i++)
    {
        ans += a[3 * N - 1 - 1 - 2 * i];
    }

    cout << ans << endl;

    return 0;
}