#include <iostream>
#include <cmath>
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
#include <type_traits>
#include <array>
#include <cassert>
#include <typeinfo>
#include <time.h>
#include <iomanip>
//#include "boost/variant.hpp"

// #include "bits/stdc++.h"

using namespace std;



#define rep(i, N, M) for(ll i=N, i##_len=(M); i<i##_len; ++i)
#define rep_skip(i, N, M, ...) for(ll i=N, i##_len=(M); i<i##_len; i+=(skip))
#define rrep(i, N, M)  for(ll i=(M)-1, i##_len=(N-1); i>i##_len; --i)
#define pb push_back

typedef pair<double, double> pd;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;
typedef tuple<ll, ll, ll, ll, ll, ll> tll6;

typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
template<typename T>
using pq_greater = priority_queue<T, vector<T>, greater<T>>;


#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define vec(a) vector<a>
#define perm(c) sort(all(c));for(bool c##perm=1;c##perm;c##perm=next_permutation(all(c)))

template<typename T> void chmin(T &a, T b) {
	if (a > b) a = b;
}
template<typename T> void chmax(T &a, T b) {
	if (a < b) a = b;
}

vll seq(ll i, ll j) {
	vll res(j - i);
	rep(k, i, j) res[k] = i + k;
	return res;
}

constexpr ll POW_(ll n, ll m) {
	ll res = 1;
	rep(i, 0, m) {
		res *= n;
	}
	return res;
}

template<ll mod = 0>
constexpr ll POW(ll x, ll n) {
	if (x == 2)
	{
		return (1LL << n) % mod;
	}
	if (n == 0)return 1;
	if (n == 1)return x % mod;
	if (n % 2 == 0)return POW_(POW<mod>(x, n / 2), 2LL) % mod;
	return ((POW_(POW<mod>(x, n / 2), 2LL) % mod)*(x%mod)) % mod;
}
template<>
constexpr ll POW<0>(ll x, ll n) {
	if (x == 2)
	{
		return 1LL << n;
	}
	if (n == 0)return 1;
	if (n == 1)return x;
	if (n % 2 == 0) return POW_(POW(x, n / 2), 2);
	return (POW_(POW(x, n / 2), 2))*x;
}

template<ll mod>
constexpr ll Plus(ll x, ll y) {
	return (x + y) % mod;
}

template<ll mod>
constexpr ll Minus(ll x, ll y) {
	return (x + mod - y) % mod;
}

template<ll mod>
constexpr ll Prod(ll x, ll y) {
	return (x * y) % mod;
}

template<ll mod>
constexpr ll Inv(ll x) {
	assert(x%mod != 0);
	return POW<mod>(x, mod - 2);
}

template<ll mod>
constexpr ll Dev(ll x, ll y) {
	return x * Inv<mod>(y);
}


template<ll bit = 2LL>
ll at_bit(ll n, ll i) {
	return n / POW(bit, i) % bit;
}

template<>
ll at_bit<2>(ll n, ll i) {
	return (n >> i) % 2LL;
}

template<ll bit>
ll get_bit(ll i) {
	return POW(bit, i);
}

template<>
ll get_bit<2>(ll i) {
	return 1LL << i;
}

template<ll bit = 2>
ll get_max_bit(ll n) {
	ll tmp = bit;
	ll at = 0;
	while (tmp <= n) {
		at++;
		tmp *= bit;
	}
	return at;
}

template<>
ll get_max_bit<2>(ll n) {
	ll tmp = 2;
	ll at = 0;
	while (tmp <= n) {
		at++;
		tmp <<= 1;
	}
	return at;
}

vll getDivisors(ll n) {
	vll res;
	ll i = 1;

	for (; i*i < n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			res.push_back(n / i);
		}
	}
	if (i*i == n)res.push_back(i);
	sort(res.begin(), res.end());
	return res;
}

vll getDivisors(ll n, ll m) {
	if (n > m) swap(n, m);
	vll res;
	ll i = 1;

	for (; i*i < n; i++) {
		if (n%i == 0) {
			if (m%i == 0) res.push_back(i);
			if (m % (n / i) == 0) res.push_back(n / i);
		}
	}
	if (i*i == n) if (m%i == 0) res.push_back(i);
	sort(res.begin(), res.end());
	return res;
}


ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void sort_by(Inputs& inputs, Functor f) {
	std::sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void stable_sort_by(Inputs& inputs, Functor f) {
	std::stable_sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

// Functor is expected to be functional<val ,bool>
// This function returns the maximum iterator that stisfies f(*it) == f(* inputs.begin())
template<
	typename Inputs,
	typename Functor,
	typename ValType = typename Inputs::value_type>
	pair<typename Inputs::iterator, typename Inputs::iterator> binary_solve(Inputs& inputs, Functor f)
{

	auto left = inputs.begin();
	auto right = inputs.end();
	auto n = inputs.size();

	auto left_val = f(*left);
	auto right_val = f(*(right - 1));

	// check 
	assert(n >= 2);
	assert(left_val != right_val);

	while (left + 1 != right)
	{
		auto mid = left + (right - left) / 2;
		if (f(*mid) == left_val)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return { left,right };
}

template<typename T>
bool check_binary_solve(T left, T right) {
	return left != right;
}
template<>
bool check_binary_solve<double>(double left, double right) {
	return abs(left - right) > 0.0000000000001;
}

template<typename T, typename Functor>
	pair<T, T > binary_solve(T left, T right, Functor f)
{
	auto left_val = f(left);
	auto right_val = f(right);

	// check 
	assert(left < right);
	if (right_val == left_val)
		throw invalid_argument("right_val == left_val");

	while (check_binary_solve<T>(left, right))
	{
		auto mid = left + (right - left) / 2;
		if (f(mid) == left_val)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return { left,right };
}


template<int I>
vll proj(vpll v) {
	vll res(v.size());
	rep(i, 0, v.size()) {
		if (!I) res[i] = v[i].first;
		else res[i] = v[i].second;
	}
	return res;
}


template<int I, class T>
vll proj(T v) {
	vll res(v.size());
	rep(i, 0, v.size()) {
		res[i] = get<I>(v[i]);
	}
	return res;
}
vector<pll >prime_factorize(ll n) {
	vector<pll> res;
	for (ll p = 2; p*p <= n; ++p) {
		if (n%p != 0)continue;
		ll num = 0;
		while (n%p == 0) { ++num; n /= p; }
		res.push_back({ p,num });
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 62;

template <typename Monoid>
struct segment_tree
{

	using underlying_type = typename  Monoid::underlying_type;

	segment_tree(ll a_n) : size_original(a_n)
	{
		vector<underlying_type> initial_value = vector<underlying_type>(a_n, Monoid::unit());
		segment_tree_impl(a_n, initial_value);
	}

	segment_tree(ll a_n, vector<underlying_type>& initial_value) : size_original(a_n)
	{
		segment_tree_impl(a_n, initial_value);
	}

	void update(int i, underlying_type z) { // 0-based
		assert(0 <= i && i < 2 * n - 1);
		a[i + n - 1] = z;
		for (i = (i + n) / 2; i > 0; i /= 2) { // 1-based
			a[i - 1] = Monoid::append(a[2 * i - 1], a[2 * i]);
		}
	}

	underlying_type query(ll l, ll r) { // 0-based, [l, r)
		underlying_type lacc = Monoid::unit(), racc = Monoid::unit();
		assert(l <= r && r <= n);
		l += n; r += n;
		for (; l < r; l /= 2, r /= 2) { // 1-based loop, 2x faster than recursion
			if (l % 2 == 1) lacc = Monoid::append(lacc, a[(l++) - 1]);
			if (r % 2 == 1) racc = Monoid::append(a[(--r) - 1], racc);
		}
		return Monoid::append(lacc, racc);
	}

	ll size() { return size_original; }

private:
	ll size_original;
	ll n;
	vector<underlying_type> a;
	void segment_tree_impl(ll a_n, vector<underlying_type>& initial_value)
	{
		assert(a_n == initial_value.size());
		n = 1; while (n < a_n) n *= 2;
		a.resize(2 * n - 1, Monoid::unit());
		rep(i, 0, initial_value.size()) {
			a[i + (n - 1)] = initial_value[i];
		}
		rrep(i, 0, n - 1) a[i] = Monoid::append(a[2 * i + 1], a[2 * i + 2]); // propagate initial values
	}
};


template <typename T>
struct min_indexed_t {
	typedef pair<T, ll> underlying_type;
	static underlying_type make_indexed(vector<T> v)
	{
		underlying_type w(v.size());
		rep(i, 0, v.size()) {
			w[i] = { v[i],i };
		}
		return w;
	}
	static underlying_type unit() { return make_pair(numeric_limits<T>::max(), -1); }
	static underlying_type append(underlying_type a, underlying_type b) { return min(a, b); }
};
template <typename T>
struct min_t {
	typedef T underlying_type;
	static underlying_type unit() { return numeric_limits<T>::max(); }
	static underlying_type append(underlying_type a, underlying_type b) { return min(a, b); }
};

struct linear_t {
	typedef pd underlying_type;
	static underlying_type unit() { return underlying_type{ 1.,0. }; }
	static underlying_type append(underlying_type a, underlying_type b) {
		return underlying_type{ a.first*b.first, b.first*a.second + b.second };
	}
};



vll get_topologically_sorted_nodes(const vvll& graph)
{
	// graph needs to be represented by adjacent list.
	// complexity: O( node size + edge size)
	ll nodeSize = graph.size();

	// find root
	vll roots;
	vll inDegree(nodeSize);
	rep(i, 0, nodeSize)
	{
		for (ll sibling : graph[i]) {
			inDegree[sibling]++;
		}
	}

	rep(i, 0, nodeSize) {
		if (inDegree[i] == 0) {
			roots.push_back(i);
		}
	}

	stack<ll> parents;
	for (ll i : roots)
		parents.push(i);

	vll sortedNodes;
	while (!parents.empty()) {
		ll parent = parents.top();
		parents.pop();
		sortedNodes.push_back(parent);
		for (ll sibling : graph[parent]) {
			inDegree[sibling]--;
			if (inDegree[sibling] == 0) {
				parents.push(sibling);
			}
		}
	}
	return sortedNodes;
}

struct Edge
{
	ll from;
	ll to;
	ll cost;
};

using Graph = vector<vector<Edge>>;

pair<vll, vll> dijkstra(const Graph& graph, size_t start) {
	// graph: weighted directed graph of adjacent representation
	// start: index of start point
	// return1: minimum path length from start
	// return2: concrete shortest path info
	ll node_size = graph.size();
	vll dist(node_size, 1LL<< 60);
	vll from_list(node_size,-1);
	dist[start] = 0;
	pq_greater<pair<ll,pll>> pq;
	pq.push({ 0, {start, start} });
	while (!pq.empty()) {
		auto node = pq.top(); pq.pop();
		// if not shortest path fixed, fix
		ll from = node.second.first;
		ll to = node.second.second;
		if (from_list[to] != -1)
			continue;
		from_list[to] = from;
		
		for(Edge edge : graph[to]) {
			ll adj = edge.to;
			ll cost = dist[to] + edge.cost;
			if (dist[adj] > cost) {
				dist[adj] = min(dist[adj], cost);
				pq.push({ cost ,{to, adj} });
			}
		}
	}
	return { dist, from_list };

}

vll shortest_path(const vll& from_list, ll start,  ll goal) {
	vll path;
	path.emplace_back(goal);
	while(true) {
		ll from = from_list[goal];
		path.emplace_back(from);
		if (from == start) {
			break;
		}
		goal = from;
	}
	reverse(all(path));
	return path;
}

struct UnionFind {
	vector<ll> data;
	vll querySize_;
	set<ll> roots;
	UnionFind(ll size) : data(size, -1), querySize_(size, 0) {
		rep(i, 0, size) roots.insert(i);
	}

	ll unite(ll x, ll y) {
		// return: root
		x = operator[](x); y = operator[](y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			querySize_[x] += querySize_[y] + 1;
			roots.erase(y);
			return x;
		}
		else {
			querySize_[x]++;
			return x;
		}
	}
	bool is_same(ll x, ll y) {
		// check whether x and y are connected
		return operator[](x) == operator[](y);
	}
	ll operator[](ll x) {
		// get root
		return data[x] < 0 ? x : data[x] = operator[](data[x]);
	}
	ll size(ll x) {
		return -data[operator[](x)];
	}
	ll  query_size(ll x) {
		return querySize_[operator[](x)];
	}
	const set<ll>& getRoots() {
		return roots;
	}
	ll rank(ll x) {
		return -data[operator[](x)];
	}
	void initialize() {
		for (auto& i : data) {
			i = -1;
		}
	}
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;

	vvll data(n+1,vll(POW(4,3),0));
	rep(j, 0, POW(4, 3)) {
		ll fir = j / 16 % 4;
		ll sec = j / 4 % 4;
		ll thir = j % 4;
		
		data[3][j] = (j == 16*0 + 4* 2+ 1 || j == 16 * 2+ 4 * 0 + 1 || j == 16 * 0 + 4 *1 + 2)?0:1;
	}

	rep(i, 4, n + 1)rep(j,0, POW(4, 3)) {
		ll fir = j / 16 %4;
		ll sec = j /4  % 4;
		ll thir = j % 4;

		ll val = data[i-1][j];
		vll ng;

		if (sec == 2 && thir == 0) {
			// *GA
			ng.push_back(1);
		}
		if (fir == 0  && thir == 2) {
			// A*G
			ng.push_back(1);
		}
		if (fir == 0 && sec == 2) {
			// AG*
			ng.push_back(1);
		}
		if (sec == 0 && thir == 2 ) {
			//*AG
			ng.push_back(1);
		}
		if (sec == 0 && thir == 1) {
			//*AC
			ng.push_back(2);
		}
		rep(k, 0, 4) {
			if (find(all(ng),k) == ng.end())
			{
				data[i][sec * 16 + 4* thir + k] += val;
				data[i][sec * 16 + 4 * thir + k] %= MOD;
			}
		}
	}


	ll res = 0;
	for (auto x : data[n ]) {
		res += x;
		res %= MOD;
	}

	cout << res;


	return 0;
}