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
//#define int long long
const long long inf = 4523372036854775807;
const int iinf = 1500000000;
//----------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++
int n;
string s, t;
string b[1002];
vector<int>e[1002];
int a[1002], prv[1002];
signed main() {
	cin >> s >> t >> n;
	n++;
	b[0] = s; b[n] = t;
	for (int i = 1; i < n; i++)
		cin >> b[i];
	if (s == t) {
		cout << 0 << endl << s << endl << s << endl;
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j) {
				int sum = 0;
				for (int k = 0; k < b[i].size(); k++) {
					if (b[i][k] != b[j][k]) sum++;
				}
				if (sum == 1) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		a[i] = iinf;
	}
	a[0] = 0;
	priority_queue<P, vector<P>, greater<P>>p;
	p.push(P{ 0,0 });
	while (!p.empty()) {
		P t = p.top(); p.pop();
		for (int i = 0; i < e[t.pos].size(); i++) {
			if (a[e[t.pos][i]] > a[t.pos] + 1) {
				a[e[t.pos][i]] = a[t.pos] + 1;
				prv[e[t.pos][i]] = t.pos;
				p.push(P{ e[t.pos][i],a[e[t.pos][i]] });
			}
		}
	}
	if (a[n] == iinf) {
		cout << -1 << endl;
		return 0;
	}
	cout << a[n] - 1 << endl;
	vector<string>v;
	int r = n;
	while (r > 0) {
		v.push_back(b[r]);
		r = prv[r];
	}
	v.push_back(b[0]);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	getchar(); getchar();
}