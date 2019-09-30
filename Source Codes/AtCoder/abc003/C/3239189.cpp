#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <queue>
#include <regex>
#include <cassert>
#include <map>
// #include "bits/stdc++.h"

using namespace std;
//debug

#define rep(i, N, M) for (ll i = N; i < M; ++i)
#define rrep(i, N, M) for (ll i = N; i > M; --i)
#define pb push_back


typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll, vector<pll>> pqpll;
typedef priority_queue<ll, vll, greater<ll>> pqll_greater;
typedef priority_queue<pll, vector<pll>, greater<pll>> pqpll_greater;


#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define vec(a) vector<a>
#define _CRT_SECURE_NO_WARNINGS

template<class T, class S>
T atbit(T n, S i) {
	return (n >> i) % i;
}

template<class T>
T getbit(T i) {
	return 1LL << i;
}
template<class T>
T POW(T n, T m) {
	T res = 1;
	rep(i, 0, m) {
		res *= n;
	}
	return res;
}

//#define TRANSFORM(v,w,func) decltype(v) w ; transform((v).begin(),(v).end(),back_inserter(w),func);

using namespace std;


int main() {
	ll N, K;
	cin >> N >> K;
	vll R(N);
	rep(i,0,N) cin >> R[i] ;
	sort(all(R));
	
	double  res=0;
	rep(i,0,K) res=(res+ R[N-1+i-K+1])/2;
	printf( "%.8f\n", res);
	//cout << res << endl;

}