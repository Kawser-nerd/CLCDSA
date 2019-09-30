#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <unordered_map>
#include <complex>
#include <deque>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <tuple>
#include <cstring>
using namespace std;

#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))
#define sz(x) ((int)(x).size())
#define TEN(n) ((ll)(1e##n))
#define fst first
#define snd second

string DBG_DLM(int &i){return(i++==0?"":", ");}
#define DBG_B(exp){int i=0;os<<"{";{exp;}os<<"}";return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v);
template<class T>ostream&operator<<(ostream&os,set<T>v);
template<class T>ostream&operator<<(ostream&os,queue<T>q);
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q);
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p);
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>mp);
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>mp);
template<int I,class TPL>void DBG(ostream&os,TPL t){}
template<int I,class TPL,class H,class...Ts>void DBG(ostream&os,TPL t){os<<(I==0?"":", ")<<get<I>(t);DBG<I+1,TPL,Ts...>(os,t);}
template<class T,class K>void DBG(ostream&os,pair<T,K>p,string delim){os<<"("<<p.first<<delim<<p.second<<")";}
template<class...Ts>ostream&operator<<(ostream&os,tuple<Ts...>t){os<<"(";DBG<0,tuple<Ts...>,Ts...>(os,t);os<<")";return os;}
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p){DBG(os,p,", ");return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v){DBG_B(forr(t,v){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,set<T>s){DBG_B(forr(t,s){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.front();});}
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.top();});}
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
#define DBG_OVERLOAD(_1,_2,_3,_4,_5,_6,macro_name,...)macro_name
#define DBG_LINE(){char s[99];sprintf(s,"line:%3d | ",__LINE__);cerr<<s;}
#define DBG_OUTPUT(v){cerr<<(#v)<<"="<<(v);}
#define DBG1(v,...){DBG_OUTPUT(v);}
#define DBG2(v,...){DBG_OUTPUT(v);cerr<<", ";DBG1(__VA_ARGS__);}
#define DBG3(v,...){DBG_OUTPUT(v);cerr<<", ";DBG2(__VA_ARGS__);}
#define DBG4(v,...){DBG_OUTPUT(v);cerr<<", ";DBG3(__VA_ARGS__);}
#define DBG5(v,...){DBG_OUTPUT(v);cerr<<", ";DBG4(__VA_ARGS__);}
#define DBG6(v,...){DBG_OUTPUT(v);cerr<<", ";DBG5(__VA_ARGS__);}
#define DEBUG0(){DBG_LINE();cerr<<endl;}
#ifdef LOCAL
#define out(...){DBG_LINE();DBG_OVERLOAD(__VA_ARGS__,DBG6,DBG5,DBG4,DBG3,DBG2,DBG1)(__VA_ARGS__);cerr<<endl;}
#else
#define out(...)
#endif

using ll=long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;using pli=pair<ll,int>;
using vs=vector<string>;using vvs=vector<vs>;using vvvs=vector<vvs>;
using vb=vector<bool>;using vvb=vector<vb>;using vvvb=vector<vvb>;
using vi=vector<int>;using vvi=vector<vi>;using vvvi=vector<vvi>;
using vl=vector<ll>;using vvl=vector<vl>;using vvvl=vector<vvl>;
using vd=vector<double>;using vvd=vector<vd>;using vvvd=vector<vvd>;
using vpii=vector<pii>;using vvpii=vector<vpii>;using vvvpii=vector<vvpii>;
template<class A,class B>bool amax(A&a,const B&b){return b>a?a=b,1:0;}
template<class A,class B>bool amin(A&a,const B&b){return b<a?a=b,1:0;}
ll ri(){ll l;cin>>l;return l;} string rs(){string s;cin>>s;return s;}

int gcd(int a, int b) {
	if (a == 0 || b == 0) return a ? a : b;
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	int s, t;
	a >>= (s = __builtin_ctz(a));
	b >>= (t = __builtin_ctz(b));
	while (a != b) {
		if (a > b) {
			a -= b;
			a >>= __builtin_ctz(a);
		}
		else {
			b -= a;
			b >>= __builtin_ctz(b);
		}
	}
	return a << (s < t ? s : t);
}

template<class V, class Merge> struct SegmentTree {
	const int n;
	const V unit_value;
	vector<V> val;

	SegmentTree(int _n) : n(1 << (32-__builtin_clz(_n-1))), unit_value(Merge::unit()), val(n * 2, unit_value) {}

	V get(int i) const { return val[i + n]; }
	void set(int i, const V &v) { val[i + n] = v; }

	void build() {
		for (int i = n - 1; i > 0; i--) val[i] = Merge::merge(val[i << 1], val[i << 1 | 1]);
	}

	void update(int i, const V &v) {
		i += n;
		val[i] = v;
		while (i > 1) {
			i >>= 1;
			val[i] = Merge::merge(val[i << 1], val[i << 1 | 1]);
		}
	}

	V query(int l, int r) const {
		l = max(0, min(n, l)) + n;
		r = max(0, min(n, r)) + n;
		V ret1 = unit_value, ret2 = unit_value;
		while (l < r) {
			if (l & 1) ret1 = Merge::merge(ret1, val[l++]);
			if (r & 1) ret2 = Merge::merge(val[--r], ret2);
			l >>= 1;
			r >>= 1;
		}
		return Merge::merge(ret1, ret2);
	}
};
template<class V, class Merge> ostream& operator<<(ostream& os, const SegmentTree<V, Merge>& seg) {
	vector<V> vec;
	for (int i = 0; i < seg.n; i++) {
		vec.emplace_back(seg.get(i));
	}
	os << vec;
	return os;
}

template <class V> struct MergeRangeGcdQ {
	static V merge(const V &l, const V &r) {
		if (l == 0) return r;
		if (r == 0) return l;
		return __gcd(l, r);
	}
	static V unit() { return 0; }
};
template<class V> using SegTreeGcd = SegmentTree<V, MergeRangeGcdQ<V>>;

template <class V = int, bool MAX = true> struct SegmentTree_RAQ_RMQ {
	struct Node {
		V dat;
		V lazy;
		bool flag;
		Node() : dat(0), lazy(0), flag(false) {}
	};

	const int n;
	vector<Node> seg;
	SegmentTree_RAQ_RMQ(int size) : n(1 << (32 - __builtin_clz(size - 1))), seg(n * 2) {};

	void set(int i, const V v) { seg[i + n].dat = v; }
	void build() { for (int i = n - 1; i > 0; i--) seg[i].dat = merge(seg[i * 2].dat, seg[i * 2 + 1].dat); }
	void update(int qbegin, int qend, V val) { update_range_rec(1, 0, n, qbegin, qend, val); }
	V query(int qbegin, int qend) { return query_rec(1, 0, n, qbegin, qend); }

private:
	V merge(const V l, const V r) { return MAX ? max(l, r) : min(l, r); }

	void propagate(int node, int l, int r) {
		if (seg[node].flag) {
			seg[node].dat += seg[node].lazy;
			if (r - l > 1) {
				for (int child = 2 * node; child <= 2 * node + 1; child++) {
					seg[child].lazy += seg[node].lazy;
					seg[child].flag = true;
				}
			}
			seg[node].lazy = 0;
			seg[node].flag = false;
		}
	}

	void update_range_rec(int node, int l, int r, int qbegin, int qend, V val) {
		propagate(node, l, r);
		if (r <= qbegin || qend <= l) {
			return;
		}
		if (qbegin <= l && r <= qend) {
			seg[node].lazy = val;
			seg[node].flag = true;
			propagate(node, l, r);
		}
		else {
			int m = (l + r) >> 1;
			update_range_rec(2 * node + 0, l, m, qbegin, qend, val);
			update_range_rec(2 * node + 1, m, r, qbegin, qend, val);
			seg[node].dat = merge(seg[2 * node].dat, seg[2 * node + 1].dat);
		}
	}

	V query_rec(int node, int l, int r, int qbegin, int qend) {
		propagate(node, l, r);
		if (qbegin <= l && r <= qend) {
			return seg[node].dat;
		}
		if (r <= qbegin || qend <= l) {
			return MAX ? numeric_limits<V>::min() : numeric_limits<V>::max();
		}
		int m = (l + r) >> 1;
		return merge(query_rec(2 * node, l, m, qbegin, qend), query_rec(2 * node + 1, m, r, qbegin, qend));
	}
};

void Main() {
	int n = ri();
	vector<int> A(n);
	rep(i, n) A[i] = ri();

	SegTreeGcd<int> seg(n);
	SegmentTree_RAQ_RMQ<int> raq(n);

	raq.set(0, A[0]);
	rep(i, 1, n) {
		seg.set(i, A[i] - A[i-1]);
		raq.set(i, A[i]);
	}
	seg.build();
	raq.build();

	int q = ri();
	rep(_, q) {
		int t = ri();
		int l = ri()-1;
		int r = ri()-1+1;
		out(t, l, r);


		if (t == 0) {
			int g1 = seg.query(l+1, r);
			int a = raq.query(l, l+1);
			cout << abs(gcd(a, g1)) << endl;
		}
		else {
			raq.update(l, r, t);
			seg.update(l, seg.query(l, l+1) + t);
			seg.update(r, seg.query(r, r+1) - t);
		}
	}
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	Main();
	return 0;
}