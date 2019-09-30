#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>

#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to, weight;

	bool operator < (const Edge& obj) const {
		return weight < obj.weight;
	}
	bool operator > (const Edge& obj) const {
		return weight > obj.weight;
	}
};

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //????????? y??????????
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //x?y??????????????????
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int arr[100001];
void Eratosthenes(int N) {//N??????
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < sqrt(N); i++) {
		if (arr[i]) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = 0;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<pii> box(n);
	REP(i, n) {
		scnaf("%d %d", &box[i].first, &box[i].second);
	}

	sort(ALL(box));
	box.push_back({});
	int dp[100001] = {};
	Fill(dp, INT_MAX);
	REP(i, n) {
		vector<pii> dif;
		for (; n > i; i++) {

			int ind = lower_bound(begin(dp), end(dp), box[i].second) - begin(dp);
			dif.push_back({ ind, i });
			if (box[i].first != box[i + 1].first) break;
		}
		int use[100001] = {};
		for (auto itr : dif) {
			if (!use[itr.first])
				dp[itr.first] = box[itr.second].second, use[itr.first] = 1;
		}
	}
	int ans = 0;
	REP(i, 100001) {
		if (dp[i] != INT_MAX)
			ans = max(ans, i);
	}
	cout << ans + 1 << endl;
	return 0;
}