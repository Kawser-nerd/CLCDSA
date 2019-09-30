#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int testCount, test;
LL n, k;
map<LL, LL> ma;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &testCount);
    for (test = 1; test <= testCount; ++test) {
        printf("Case #%d: ", test);

        cin >> n >> k;
        ma.clear();
        ma[n] = 1;
        while (true) {
            assert(!ma.empty());
            auto it = prev(ma.end());
            pair<LL, LL> p = *it;
            ma.erase(it);
            LL mn = (p.first - 1) / 2;
            LL mx = p.first / 2;
            if (p.second >= k) {
                cout << mx << ' ' << mn << endl;
                break;
            }
            k -= p.second;
            if (mn > 0) {
                ma[mn] += p.second;
            }
            if (mx > 0) {
                ma[mx] += p.second;
            }
        }

        cerr << "Done #" << test << endl;
    }
    return 0;
}
