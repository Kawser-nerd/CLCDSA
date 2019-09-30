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
const ll Mod = 1000000007;
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
int n, m;
int a[100000], b[100000];
signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n); sort(b, b + m);
	int eq = 0;
	for (int i = 0; i < n; i++) {
		int k = lower_bound(b, b + m, a[i]) - b;
		if (k < m&&a[i] == b[k]) {
			eq++;
		}
	}
	printf("%.15LF\n", (ld)eq / (ld)(n + m - eq));
	getchar(); getchar();
}