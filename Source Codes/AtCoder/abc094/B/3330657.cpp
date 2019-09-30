#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

int main() {
    int n, m, x; cin >> n >> m >> x;
    vi vc(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int j; cin >> j;
        ++vc[j];
    }

    int l = 0, r = 0;
    for (int i = x; i <= n; ++i) r += vc[i];
    for (int i = x; i >= 0; --i) l += vc[i];

    cout << min(l, r) << endl;

    return 0;
}