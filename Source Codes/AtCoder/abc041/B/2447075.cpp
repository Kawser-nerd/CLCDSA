#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;

constexpr int INF = (1 << 30) - 1;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;

ll gcd(ll a, ll b) {
	if (a < b) {
		swap(a, b);
	}
	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

constexpr int MOD = 1000000000 + 7;
ll A, B, C;

int main() {
	cin >> A >> B >> C;
	ll X = A * B % MOD;
	X = X * C % MOD;

	cout << X << endl;
}