#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<string.h>
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<limits.h>
#define int long long
#define mod 1000000007
using namespace std;

int a[100000];
int b = 0;
int K(int c) {
	if (c == 0)return 1;
	int d = 2, e = 1;
	while (c > 1) {
		if (c & 1)e = e*d%mod;
		d = d*d%mod;
		c >>= 1;
	}
	return d*e%mod;
}
signed main() {
	int c; cin >> c;
	for (int d = 0; d < c; d++) {
		cin >> a[d];
		if (a[d] == 0) {
			b++;
		}
	}
	if (a[0] != 0) { puts("0"); return 0; }
	if (b != 1) { puts("0"); return 0; }
	int ans = 1;
	map<int, int>M;
	for (int e = 0; e < c; e++) {
		M[a[e]]++;
	}
	for (int i = 1; i < 200000; i++) {
		if (M[i] != 0 && M[i - 1] == 0) {
			puts("0");
			return 0;
		}
	}
	for (int e = 0; e < c; e++) {
		if (a[e]) {
			ans = ans*(K(M[a[e]-1]) - 1) % mod;
		}
	}
	for (auto i : M) {
		if (i.first) {
			ans = ans*K(i.second*(i.second-1)/2) % mod;
		}
	}
	cout << ans << endl;
}