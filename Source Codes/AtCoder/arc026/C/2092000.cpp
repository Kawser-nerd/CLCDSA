#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
//---------------------------------------------------
//????????????
typedef long long ll;
typedef long double ld;
#define str string
#define rep(i,j) for(ll i=0;i<(long long)(j);i++)
const ll Mod = 1777777777;
const ll gosenchou = 5000000000000000;
short gh[2][4] = { { 0,0,-1,1 },{ -1,1,0,0 } };
struct P {
	ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {//???????
	ll to;
	ld cost;
};
struct E {//??????????
	ll from, to, cost;
};
bool operator<(E a, E b) {
	return a.cost < b.cost;
}
struct H {
	ld x, y;
};
bool operator<(H a, H b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool operator>(H a, H b) {
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
bool operator==(H a, H b) {
	return a.x == b.x&&a.y == b.y;
}
bool operator!=(H a, H b) {
	return a.x != b.x || a.y != b.y;
}
ll gcm(ll i, ll j) {//?????
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcm(j%i, i);
}
ld rad(H a, H b) {
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}//rad?????2?????
ll ari(ll a, ll b, ll c) {
	return (a + b)*c / 2;
}//??????
bool suf(ld a, ld b, ld c, ld d) {
	if (b <= c || d <= a) return 0;
	return 1;
}//[a,b),[c,d)
ll fact(ll i, ll z) {
	ll sum = 1;
	for (ll j = max(z, 2LL); j <= i; j++)
		sum = (sum* j) % Mod;
	return sum;
}//??(??
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res*x%Mod;
		x = x*x%p;
		n >>= 1;
	}
	return res;
}
#define int long long
const long long inf = 4523372036854775807;
const int iinf = 1500000000;
//----------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++
struct A {
	int l, r, c;
};
bool operator<(A a, A b) { return a.r < b.r; }
int n, l, u;
A a[100000];
int b[300000];
int dp[100002];
void update(int k, int x) {
	k += u;
	k--;
	b[k] = x;
	do {
		k = (k - 1) / 2;
		b[k] = min(b[k * 2 + 1], b[k * 2 + 2]);
	} while (k > 0);
}
int query(int i, int c, int d, int l, int r) {
	if (c <= l&&r <= d) return b[i];
	if (d <= l || r <= c) return inf;
	int res = inf;
	res = min(res, query(i * 2 + 1, c, d, l, (l + r) / 2));
	res = min(res, query(i * 2 + 2, c, d, (l + r) / 2, r));
	return res;
}
signed main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i].l >> a[i].r >> a[i].c;
	sort(a, a + n);
	for (int i = 0; i < 300000; i++)
		b[i] = inf;
	for (int i = 0; i <= l; i++)
		dp[i] = inf;
	l++;
	u = 1;
	while (u < l) u *= 2;
	for (int i = 0; i < n; i++) {
		if (a[i].l == 0) {
			dp[a[i].r] = min(dp[a[i].r], a[i].c);
		}
		else {
			dp[a[i].r] = min(dp[a[i].r], query(0, a[i].l, a[i].r, 0, u) + a[i].c);
		}
		update(a[i].r, dp[a[i].r]);
	}
	cout << dp[l - 1] << endl;
	getchar(); getchar();
}