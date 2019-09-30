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
#include <list>
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
#include <unordered_set>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 10000000
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
typedef pair<ll, ll> pll;
mt19937 ran;

int Has[4] = { (int)(ran() / 100),(int)(ran() / 100),(int)(ran() / 100),(int)(ran() / 100) };

struct RollingHash {
	const pll bai = { 181243 ,2251 };
	vector<pll> hash;
	vector<pll> base;
	int len;
	RollingHash(string str) : hash(str.length() + 1), base(str.length() + 1) {
		len = str.length();
		base[0].first = 1;
		base[0].second = 1;

		REP(i, len) {
			int num = str[i] == 'A' ? 0 : str[i] == 'T' ? 1 : str[i] == 'G' ? 2 : 3;
			(hash[i + 1].first = hash[i].first * bai.first + Has[num]) %= MODU;
			(hash[i + 1].second = hash[i].second * bai.second + Has[num]) %= 129402307;
			(base[i + 1].first = base[i].first * bai.first) %= MODU;
			(base[i + 1].second = base[i].second * bai.second) %= 129402307;
		}
	}

	pll Gethash(int l, int r) {
		return { (hash[r].first - (hash[l].first * base[r - l].first) % MODU + MODU) % MODU, (hash[r].second - (hash[l].second * base[r - l].second) % 129402307 + 129402307) % 129402307 };
	}

};

struct BIT {
	vector<ll> x;

#define SZ(a) (a&-a)
#define UP(a) (a+SZ(a))
#define LEFT(a) (a-SZ(a))

	BIT(int n) : x(n + 1) {}

	int sum(int r) {
		ll ret = 0;
		for (int i = r; 0 < i; i = LEFT(i)) {
			ret = x[i];
		}
		return ret;
	}
	void add(int r, int v) {
		for (int i = r; 0 < i; i = UP(i)) {
			x[i] += v;
		}
	}
};

int main()
{
	int n;
	string s;
	cin >> n >> s;

	reverse(ALL(s));
	int c = 0;
	REP(i, s.length()) {
		if (s[i] == ')') c++;
		else c--;
		if (c < 0) {
			c = 0;
		}
	}
	s += string(c, '(');

	reverse(ALL(s));
	c = 0;
	REP(i, s.length()) {
		if (s[i] == '(') c++;
		else c--;
		if (c < 0) {
			c = 0;
		}
	}
	s += string(c, ')');

	

	cout << s << endl;

	return 0;
}