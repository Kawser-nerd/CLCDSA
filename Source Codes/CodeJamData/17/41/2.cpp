#line 1 "A.cpp"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <random>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}




///////////////////////////////// BEGIN util.h /////////////////////////////////


#line 1 "util.h"
template <class T, class U>
ostream& operator<<(ostream &o, const pair<T,U> &p) {
	return o << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& print_list(ostream &o, const T &v) {
	o << "[";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t;
	}
	return o << "]";
}

template <class T>
ostream& print_map(ostream &o, const T &v) {
	o << "{";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t.first << " => " << t.second;
	}
	return o << "}";
}

template <class T>
ostream& operator<<(ostream &o, const vector<T> &v) {
	return print_list(o, v);
}

template <class T>
ostream& operator<<(ostream &o, const set<T> &v) {
	return print_list(o, v);
}

template <class T,size_t N>
ostream& operator<<(ostream &o, const array<T,N> &v) {
	return print_list(o, v);
}

template <class T,class U>
ostream& operator<<(ostream &o, const map<T,U> &v) {
	return print_map(o, v);
}

template <class T, size_t N>
struct TuplePrintHelper {
	static ostream& print(ostream& o, const T &t) {
		TuplePrintHelper<T,N-1>::print(o, t);
		o << ", ";
		return o << get<N-1>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,1> {
	static ostream& print(ostream& o, const T &t) {
		return o << get<0>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,0> {
	static ostream& print(ostream& o, const T &) {
		return o;
	}
};

template <class... Args>
ostream& operator<<(ostream &o, const tuple<Args...> &t) {
	o << "(";
	TuplePrintHelper<tuple<Args...>, sizeof...(Args)>::print(o, t);
	return o << ")";
}


template <class T>
T fastpow(const T &a, ll n) {
	T r = 1, e = a;
	for (int i = 0; (1ll<<i) <= n; i++, e *= e) {
		if (n&(1ll<<i))
			r *= e;
	}
	return r;
}



///////////////////////////////// END util.h /////////////////////////////////


#line 30 "A.cpp"

int testcasenr;

void docase() {
	int N, P;
	scanf("%d%d", &N, &P);
	vector<int> cnt(P);
	REP(i,0,N) {
		int g;
		scanf("%d", &g);
		cnt[g%P]++;
	}
	if (P == 2) {
		vector<vector<int> > dp(P, vector<int>(cnt[1]+1, - 1E9));
		dp[0][cnt[1]] = cnt[0];
		for (int a1 = cnt[1]; a1 >= 0; a1--)
		REP(r,0,P) {
			if (a1 > 0)
				setmax(dp[(r+1)%P][a1-1], dp[r][a1]+(r==0 ? 1 : 0));
		}
		int res = 0;
		REP(r,0,P)
			setmax(res, dp[r][0]);
		printf("%d\n", res);
	} else if (P == 3) {
		vector<vector<vector<int> > > dp(P, vector<vector<int> >(cnt[1]+1, vector<int>(cnt[2]+1, - 1E9)));
		dp[0][cnt[1]][cnt[2]] = cnt[0];
		for (int a1 = cnt[1]; a1 >= 0; a1--)
		for (int a2 = cnt[2]; a2 >= 0; a2--)
		REP(r,0,P) {
			if (a1 > 0)
				setmax(dp[(r+1)%P][a1-1][a2], dp[r][a1][a2]+(r==0 ? 1 : 0));
			if (a2 > 0)
				setmax(dp[(r+2)%P][a1][a2-1], dp[r][a1][a2]+(r==0 ? 1 : 0));
		}
		int res = 0;
		REP(r,0,P)
			setmax(res, dp[r][0][0]);
		printf("%d\n", res);
	} else if (P == 4) {
		vector<vector<vector<vector<int> > > > dp(P, vector<vector<vector<int> > >(cnt[1]+1, vector<vector<int> >(cnt[2]+1, vector<int>(cnt[3]+1,- 1E9))));
		dp[0][cnt[1]][cnt[2]][cnt[3]] = cnt[0];
		for (int a1 = cnt[1]; a1 >= 0; a1--)
		for (int a2 = cnt[2]; a2 >= 0; a2--)
		for (int a3 = cnt[3]; a3 >= 0; a3--)
		REP(r,0,P) {
			if (a1 > 0)
				setmax(dp[(r+1)%P][a1-1][a2][a3], dp[r][a1][a2][a3]+(r==0 ? 1 : 0));
			if (a2 > 0)
				setmax(dp[(r+2)%P][a1][a2-1][a3], dp[r][a1][a2][a3]+(r==0 ? 1 : 0));
			if (a3 > 0)
				setmax(dp[(r+3)%P][a1][a2][a3-1], dp[r][a1][a2][a3]+(r==0 ? 1 : 0));
		}
		int res = 0;
		REP(r,0,P)
			setmax(res, dp[r][0][0][0]);
		printf("%d\n", res);
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for (testcasenr = 1; testcasenr <= T; testcasenr++) {
		fprintf(stderr, "Test %d/%d\n", testcasenr, T);
		printf("Case #%d: ", testcasenr);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
