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
#include <cmath>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-8;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

template<class T> class bit {
public:
	vector<T> dat;
	ll N;

	bit() {}
	bit(ll N) : N(N) { dat.assign(N, 0); }
	// sum [0,i)
	T sum(ll i) {
		ll ret = 0;
		for (--i; i >= 0; i = (i&(i + 1)) - 1) ret += dat[i];
		return ret;
	}
	// sum [i,j)
	T sum(ll i, ll j) { return sum(j) - sum(i); }
	// add x to i
	void add(ll i, T x) {
		for (; i < N; i |= i + 1)
			dat[i] += x;
	}
};

template<class T> class bitr {
public:

	bit<T> b, c;

	bitr() {}
	bitr(ll N) {
		b = bit<T>(N);
		c = bit<T>(N);
	}
	// add x to [i,j) 
	void add(ll i, ll j, T x) {
		b.add(i, -i*x); b.add(j, j*x);
		c.add(i, x); c.add(j, -x);
	}
	// sum [0,i)
	T sum(ll i) { return b.sum(i + 1) + c.sum(i + 1)*i; }
	// sum [i,j)
	T sum(ll i, ll j) { return sum(j) - sum(i); }
};

bool ans;

void plus1(vector<ll>& number, ll add, ll base, bitr<ll>& bit) {
	add--;
	if (add < 0) {
		ans = false;
		return;
	}
	if (add >= (ll)number.size()-1)
		return;
	ll flag = bit.sum(add, add + 1);
	if (flag < 0)
		number[add] = 0;
	bit.add(add, add + 1, -flag);
	bit.add(add + 1, bit.b.N-2, -1);
	number[add]++;
	if (number[add] >= base) {
		number[add] = 0;
		plus1(number, add, base, bit);
	}
}

int main() {
	ll N;
	cin >> N;
	ll before = -10;
	vector<ll> a;
	for (int i = 0;i < N;i++) {
		ll now;
		cin >> now;
		if (now <= before)
			a.push_back(now);
		before = now;
	}
	if (a.empty()) {
		cout << 1 << endl;
		return 0;
	}
	ll l = 1;
	ll r = N;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		ans = true;
		bitr<ll> bit(N+10);
		vector<ll> number(N + 5);
		for (auto &&x : a) {
			plus1(number, x, m, bit);
		}
		if (ans)
			r = m;
		else
			l = m;
	}
	cout << r << endl;
	return 0;
}
/*
10
1 1 1 2 3 3 3 3 3 3

*/