#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (unsigned (i)(0); (i)<(v.size()); ++(i))
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define sortgi(v) sort(all(v), greater<int>())
#define sortgd(v) sort(all(v), greater<double>())
#define sortgll(v) sort(all(v), greater<ll>())
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using ll = long long;
using pllll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using pqi = priority_queue<int>;
using pqd = priority_queue<double>;
using pqll = priority_queue<ll>;
using pqvi = priority_queue<vi>;
using pqvll = priority_queue<vll>;

ll GCD(ll a, ll b) {
	ll c = max(a, b);
	ll d = min(a, b);
	while (c%d != 0) {
		ll t = d;
		d = c % d;
		c = t;
	}
	return d;
}

int main(){
	int T;
	cin >> T;
	vvll v;
	rep(i, 0, T) { 
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({a,b,c,d});
	}
	repv(i, v) {
		ll a = v[i][0], b = v[i][1], c = v[i][2], d = v[i][3];
		if (a < b || b > d) {
			cout << "No" << endl;
			continue;
		}
		else if (a%b == 0 && d%b == 1) {
			 if (b - 1 > c) {
				 cout << "No" << endl;
				 continue;
			 }
		}
		else if (d%b == 0) {
			if (a%b > c) {
				cout << "No" << endl;
				continue;

			} 
		}
		else {
			ll G =GCD(b, d%b); 
			if (b%G == 0) {
				if (b - G > c) {
					cout << "No" << endl;
					continue;
				}
			}
			else if (b - (b - a%b)%G > c ) {
				cout << "No" << endl;
				continue;
			}
		}
		cout << "Yes" << endl;
	}
}