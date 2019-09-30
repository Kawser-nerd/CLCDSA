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

ll X;

int main() {
	cin >> X;

	ll Y;
	for (int i = 1; i*i <= X; i++) {
		Y = i;
	}
	
	ll ans;
	for (int i = 1; i*i <= Y; i++) {
		ans = i;
	}
	cout << ans << endl;
}