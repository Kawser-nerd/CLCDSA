#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
typedef vector<long long> vll;

// ?????
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a/ gcd(a,b)*b;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,a[100010],c1=0,c2= 0, c4 = 0;
	scanf("%d", &N);
	vll T(N);
	REP(i, N) {
		cin >> T[i];
	}
	ll ans = 1;
	REP(i, N) {
		ans = lcm(ans, T[i]);
	}
	cout << ans << endl;
	return 0;
}