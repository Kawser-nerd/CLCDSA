#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

#define P 1000000007

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

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

long gcd(long n, long m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

long lcm(long n, long m) {
	if ((n == 0) || (m == 0)) return 0;
	return ((n / gcd(n, m)) * m);
}

int main() {
    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    long l1 = lcm(max(N, M), min(N, M));
    long n = l1 / N;
    long m = l1 / M;
    long l2 = lcm(max(n, m), min(n, m));

    bool ok = true;
    for (long i = 0; i < l1 / l2 && ok; ++i) ok = S[l2 / n * i] == T[l2 / m * i];

    cout << (ok ? l1 : -1) << endl;

    return 0;
}