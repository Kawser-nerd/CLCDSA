#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const LL MOD = 1000002013;

LL max_gr(LL N, LL P) {
    if (P >= (1LL << N)) return P - 1;
    if (P <= (1LL << (N - 1))) {
        return 0;
    } else {
        LL r = max_gr(N - 1, P - (1LL << (N-1)));
        return r * 2 + 2;
    }
}

LL max_cn(LL N, LL P) {
    if ((1LL << N) <= P) 
        return (1LL << N) - 1;
    else {
        LL r = max_cn(N - 1, P);
        return r * 2;
    }
}

void solve() {
    LL N, P;
    cin >> N >> P;

    static int testid;
    cout << "Case #" << ++testid << ": " << max_gr(N, P) << ' ' << max_cn(N, P) << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();
    return 0;
}
