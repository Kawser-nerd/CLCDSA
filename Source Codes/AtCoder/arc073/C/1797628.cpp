#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }


typedef pair<long long, long long> pll;
const int MAX = 410000;

int N;

pll seg[MAX];


typedef long long VAL;
const VAL INF = 1LL << 60;
const int MAX_R = 510000;

int SIZE_R;
struct RMQ {
	pair<VAL, int> dat[4 * MAX_R];

	void init(int n = MAX_R, VAL v = INF) {
		SIZE_R = 1;
		while (SIZE_R < n) SIZE_R *= 2;
		for (int i = 0; i < 2 * MAX_R - 1; ++i) dat[i] = make_pair(v, -1);
	}

	inline void init_set(int a, VAL x) {
		int k = a + SIZE_R - 1;
		dat[k] = make_pair(x, a);
	}

	inline void init_tree(int k = 0, int l = 0, int r = SIZE_R) {
		if (r - l == 1) {}                  // leaf
		else {
			init_tree(k * 2 + 1, l, (l + r) / 2);
			init_tree(k * 2 + 2, (l + r) / 2, r);
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	inline void set(int a, VAL x) {
		int k = a + SIZE_R - 1;
		dat[k] = make_pair(x, a);
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	inline pair<VAL, int> get(int a, int b, int k = 0, int l = 0, int r = SIZE_R) {
		if (r <= a || b <= l) return make_pair(INF, -1);
		if (a <= l && r <= b) return dat[k];
		else {
			pair<VAL, int> vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
			pair<VAL, int> vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}

	inline pair<VAL, int> operator [] (int a) {
		return get(a, a + 1);
	}

	void print(int r = SIZE_R) {
		for (int i = 0; i < SIZE_R; ++i) { cout << get(i, i + 1).first << ","; }
		cout << endl;
	}
};

RMQ rmq;



int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			long long x, y;
			cin >> x >> y;
			if (x > y) swap(x, y);
			seg[i] = pll(x, y);
		}
		sort(seg, seg + N);

		long long minR = 1LL<<60, minRI = -1, maxR = -1, maxRI = -1;
		for (int i = 0; i < N; ++i) {
			if (chmax(maxR, seg[i].second)) maxRI = i;
			if (chmin(minR, seg[i].second)) minRI = i;
		}

		long long res = (seg[N - 1].first - seg[0].first) * (maxR - minR);

		//COUT(res);
		//COUT(maxRI);


		long long maxB = seg[N - 1].first;
		rmq.init(N);
		for (int i = 0; i < N; ++i) {
			rmq.init_set(i, seg[i].first);
		}
		rmq.init_tree();

		for (int i = 1; i <= maxRI; ++i) {
			chmax(maxB, seg[i - 1].second);
			rmq.set(i - 1, seg[i - 1].second);

			long long red = maxR - seg[0].first;

			long long minB = rmq.get(0, N).first;
			long long blue = maxB - minB;
			long long tmp = red * blue;

			//cout << i << ": " << red << ", " << blue << "; " << tmp << endl;
			//COUT(maxB);
			//COUT(minB);
			//rmq.print();

			chmin(res, tmp);
		}

		cout << res << endl;
	}
}