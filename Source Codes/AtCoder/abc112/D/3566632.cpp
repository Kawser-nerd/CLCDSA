#include <iostream>
using namespace std;
#define ll long long
signed main()
{
    ll N, M;
    cin >> N >> M;

    // a1~aN ???????d => a1~aN????d*i(i:???)???????
    for (ll i = M / N; i >= 2; --i) {
        if ((M - i * N) % i == 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 1 << endl;
}