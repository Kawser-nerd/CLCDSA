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
int n, k;
H a[50];
vector<int>x, y;
signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		for (int j = 0; j < x.size(); j++) {
			if (x[j] == a[i].x)
				goto stop;
		}
		x.push_back(a[i].x);
	stop:;
		for (int j = 0; j < y.size(); j++) {
			if (y[j] == a[i].y)
				goto loop;
		}
		y.push_back(a[i].y);
	loop:;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int ans = inf;
	for (int xi = 0; xi < x.size(); xi++) {
		for (int xj = xi; xj < x.size(); xj++) {
			for (int yi = 0; yi < y.size(); yi++) {
				for (int yj = yi; yj < y.size(); yj++) {
					int sum = 0;
					for (int z = 0; z < n; z++) {
						if (x[xi] <= a[z].x&&a[z].x <= x[xj] &&
							y[yi] <= a[z].y&&a[z].y <= y[yj]) {
							sum++;
						}
					}
					if (sum >= k) {
						ans = min(ans, (x[xj] - x[xi])*(y[yj] - y[yi]));
					}
				}
			}
		}
	}
	cout << ans << endl;
	getchar(); getchar();
}