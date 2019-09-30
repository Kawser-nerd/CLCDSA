#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <sys/time.h>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<int, int> P;
typedef complex<double> comp;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

ll n, A, B;
vector<ll> a;

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
	if (n & 1) res = (res * x) % mod;
	x = (x * x) % mod;
	n >>= 1;
    }
    return res;
}

bool near() {
    return a[0] * A >= a[n-1];
}

void solve() {
    sort(all(a));
    if (A == 1) {
        for (int i = 0; i < n; i++)
            cout << a[i] << endl;
        return;
    }
    while (B > 0) {
        if (near()) break;
        a[0] *= A;
        sort(all(a));
        B--;
    }

    ll r = B % n;
    for (int i = 0; i < r; i++) {
        a[0] *= A;
        sort(all(a));
    }
    
    ll q = B / n;
    ll p = mod_pow(A, q);
    for (int i = 0; i < n; i++) {
        cout << (((a[i] % mod) * p) % mod) << endl;
    }
}

void input() {
    cin >> n >> A >> B;
    ll v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        a.push_back(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}