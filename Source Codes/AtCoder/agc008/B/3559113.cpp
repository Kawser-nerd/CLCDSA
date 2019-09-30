#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long a[100005];
long long pac[100005];
long long ac[100005];

int main()
{
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N;i++)
    {
        cin >> a[i];
        
        pac[i + 1] = pac[i] + max(a[i], 0LL);
        ac[i + 1] = ac[i] + a[i];
    }

    long long ans = -1e16L;

    long long base = pac[N];

    if(N == 1)
    {
        if(a[0] >= 0)
        {
            cout << a[0] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }

    for (int i = 0; i <= N - K;i++)
    {
        long long t = base - (pac[i + K] - pac[i]);
        ans = max(max(t + ac[i + K] - ac[i], t), ans);
    }

    cout << ans << endl;

    return 0;
}