#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF_LL (ll)1e18
#define INF (int)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
using ll = long long;
using PII = pair<int, int>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

class Union_find{
private:
	vector<int> par;
	vector<int> rank;
	int n;

public:
	Union_find(int a){
		n = a;
		for(int i = 0;i < n;i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

class LazySegTree{
private:
	int n;
	vector<ll> node, lazy;
	vector<bool> lazyFlag;
public:
	LazySegTree(vector<ll> v){
		int sz = v.size();
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1, 0);
		lazy.resize(2*n-1, 0);
		lazyFlag.resize(2*n-1, false);
		REP(i, sz) node[i+n-1] = v[i];
		for(int i = n-2;i >= 0;i--) node[i] = node[2*i+1]+node[2*i+2];
	}

	void eval(int k, int l, int r){
		if(lazyFlag[k]){
			node[k] += lazy[k] * (r-l);
			if(r-l > 1){
				lazy[2*k+1] += lazy[k];
				lazy[2*k+2] += lazy[k];
				lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
			}
			lazy[k] = 0;
			lazyFlag[k] = false;
		}
	}

	void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return;

		if(a <= l && r <= b){
			lazy[k] += x;
			lazyFlag[k] = true;
			eval(k, l, r);
		}else{
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
			node[k] = node[k*2+1] + node[k*2+2];
		}
	}

	ll query(int a, int b, int k=0, int l=0, int r=-1){
		if(r < 0) r = n;
		eval(k, l, r);

		if(b <= l || r <= a) return 0;
		if(a <= l && r <= b) return node[k];

		return query(a, b, k*2+1, l, (l+r)/2) + query(a, b, k*2+2, (l+r)/2, r);
	}
};

class Bucket{
private:
	int n, bs, bn;
	vector<ll> data;
	vector<ll> bucket, lazy;
	vector<bool> lazyFlag;
public:
	Bucket(vector<ll> v, int sz){
		data = v;
		n = v.size();
		bs = sz;
		bn = (n + bs - 1) / bs;
		data.resize(bn*bs, INF_LL);
		bucket.assign(bn, INF_LL);
		lazy.assign(bn, 0);
		lazyFlag.assign(bn, 0);
		REP(i, bn){
			ll minx = INF_LL;
			REP(j, bs){
				chmin(minx, data[i*bs+j]);
			}
			bucket[i] = minx;
		}
	}

	void eval(int k){
		if(lazyFlag[k]){
			lazyFlag[k] = false;
			FOR(i, bs*k, bs*(k+1)){
				data[i] = lazy[k];
			}
			lazy[k] = 0;
		}
	}

	void update(int s, int t, int x){
		REP(k, bn){
			int l = k*bs, r = (k+1)*bs;
			if(r <= s || t <= l) continue;
			if(s <= l && r <= t){
				lazyFlag[k] = true;
				bucket[k] = x;
				lazy[k] = x;
			}else{
				eval(k);
				FOR(i, max(s, l), min(t, r)){
					data[i] = x;
				}
				bucket[k] = INF_LL;
				FOR(i, l, r){
					chmin(bucket[k], data[i]);
				}
			}
		}
	}

	ll query(int s, int t){
		ll res = INF_LL;
		REP(k, bn){
			int l = k*bs, r = (k+1)*bs;
			if(r <= s || t <= l) continue;
			if(s <= l && r <= t){
				chmin(res, bucket[k]);
			}else{
				eval(k);
				FOR(i, max(s, l), min(t, r)){
					chmin(res, data[i]);
				}
			}
		}
		return res;
	}

};

const ll mod = 1e9+7;

ll dp[114514][2] = {};
vector<int> G[114514];
int N;

ll g(int, int);

ll f(int v, int p){
	if(~dp[v][0]) return dp[v][0];
	ll r1 = 1;
	REP(i, G[v].size()){
		if(G[v][i] == p) continue;
		r1 *= g(G[v][i], v);
		r1 %= mod;
	}
	return dp[v][0] = (r1+g(v, p))%mod;
}

ll g(int v, int p){
	if(~dp[v][1]) return dp[v][1];
	ll r1 = 1;

	REP(i, G[v].size()){
		if(G[v][i] == p) continue;
		r1 *= f(G[v][i], v);
		r1 %= mod;
	}
	return dp[v][1] = r1;
}

int main(void){
	cin >> N;
	REP(i, N-1){
		int a, b;
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(dp, -1, sizeof dp);
	cout << f(0, -1) << endl;
}