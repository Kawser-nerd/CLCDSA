#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    int N;
    vector<ll> A;
    vector<ll> B;
    cin >> N;
    A.resize(N);
    B.resize(N, 0LL);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if(i - 1 >= 0)
        {
            B[i] = A[i] + B[i - 1];
        }
        else
        {
            B[i] += A[i];
        }
    }

    sort(B.begin(), B.end(), greater<ll>());

    ll v = B[0];
    ll cnt = v == 0 ? 2 : 1;
    ll ans = 0LL;

    for (int i = 1; i < N; i++)
    {
        if (v == B[i])
        {
            cnt++;
        }
        else
        {
            ans += (cnt * (cnt - 1)) / 2;

            v = B[i];
            cnt = v == 0 ? 2 : 1;
        }
    }

    ans += (cnt * (cnt - 1)) / 2;

    cout << ans << endl;

    return 0;
}