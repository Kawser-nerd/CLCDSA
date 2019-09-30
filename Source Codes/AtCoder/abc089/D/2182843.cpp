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
	ll x, y;
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
ll fact(ll x, ll k) {//??????
	ll sum = 1;
	for (int i = 0; i < k; i++)
		sum *= (x--);
	return sum;
}//??(??
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res*x%p;
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
int h, w, d, q;
int a[300][300];
int b[90001][60];
H c[90001];
signed main() {
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			c[a[i][j]] = H{ i,j };
		}
	}
	for (int i = 1; i+d <= h*w; i++) {
		b[i][0] = abs(c[i].x - c[i + d].x) + abs(c[i].y - c[i + d].y);
	}
	for (int i = 1; d*pow(2, i) <= h*w; i++) {
		int k = d*pow(2, i);
		for (int j = 1; j + k <= h*w; j++) {
			b[j][i] = b[j][i - 1] + b[j + k / 2][i - 1];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		y -= x;
		y /= d;
		int sum = 0, r = 0;
		while (y > 0) {
			if (y & 1) {
				sum += b[x][r];
				y ^= 1;
				x += d*pow(2, r);
			}
			y >>= 1;
			r++;
		}
		cout << sum << endl;
	}
	getchar(); getchar();
}