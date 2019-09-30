#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int cal(int base, int x) {
	if (base < x)
		return (x - base);
	int sa = abs(base - x);
	return (sa+1) / 2 + sa % 2;
}

int main() {
	ll Q;
	cin >> Q;
	for (int i = 0;i < Q;i++) {
		ll A, B;
		cin >> A >> B;
		if (B < A)
			swap(A, B);
		ll ans = A - 1;
		ll hoge = sqrt(A*B) - eps;
		ll left = hoge * (hoge + 1) < A * B ? hoge + 1 : hoge;
		ll right = hoge;
		if (A == B)
			cout << right * 2 << endl;
		else
			cout << left + right - 2 << endl;
	}
	return 0;
}