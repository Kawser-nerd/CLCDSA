#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
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
#include <list>
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
#define PI 3.141592653589
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

class Bitvector {
	//4byte???? ?????0-index
	const int bsize = 8;
	static const int popc[256];
public:

	unsigned char* st;
	unsigned int* blockrank;
	int sz;
	Bitvector(int n) {
		sz = n;
		st = (unsigned char*)calloc((n + bsize - 1) / bsize, sizeof(char));
		blockrank = (unsigned int*)calloc((n + bsize - 1) / bsize + 1, sizeof(int));
		if (st == NULL || blockrank == NULL)
			abort();
	}
	inline void set(int a, bool f) {//??????????
		if (f)bitset(st[a / bsize], (bsize - 1 - a % bsize));
	}
	inline bool get(int a) { return bitcheck(st[a / bsize], (bsize - 1 - a % bsize)); }
	inline void calcblock() {
		int cou = 0;
		REP(i, sz + 1) {
			if (i && !(i % 8))blockrank[i / bsize] = cou;
			if (i<sz)cou += bitcheck(st[i / bsize], (bsize - 1 - i % bsize));
		}
	}
	int rank(int a, bool t) {
		int ret = blockrank[a / bsize] + (((bsize - a % bsize) >= bsize) ? 0 : popc[st[a / bsize] >> (bsize - a % bsize)]);
		return t ? ret : a - ret;
	}
	int select(int a, bool t) {
		int l = 0, r = sz + 1;

		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (rank(mid, t) >= a) r = mid;
			else l = mid;
		}
		if (rank(r, t) < a) return -1;
		return r;
	}
	void clear() {
		free(st);
		free(blockrank);
	}
};
const int Bitvector::popc[256] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8 };

//???????????????(???????????) ??????????unsigned???????
template<typename T>
class WaveletMatrix {
#define tbitcheck(a,b)   (((T)a >> b) & 1)
#define tbitset(a,b)      ( a |= ((T)1 << b))
#define tbitunset(a,b)    (a &= ~((T)1 << b))
public:
	vector<T> data;
	vector<ll> rui;
	vector<vector<ll>> bitrui;
	vector<Bitvector> bitv;
	vector<int> border;
	int bitsize;

	WaveletMatrix(vector<T>& dat) : bitsize(sizeof(T) * 8), data(dat), border(sizeof(T) * 8 +1), rui(data.size()+1), bitrui(sizeof(T)*8) {
		bitv.reserve(bitsize);
		REP(i, bitsize + 1)
			bitv.push_back(Bitvector(data.size()));

		REP(j, data.size()) {
			bitv[0].set(j, tbitcheck(data[j], bitsize - 1));
			rui[j+1] = rui[j] + data[j];
		}
		bitv[0].calcblock();
		vector<T> buf[2];
		buf[0] = data;
		buf[1].resize(data.size());

		REP(i, bitsize - 1) {
			border[i + 1] = bitv[i].rank(data.size(), 0);
			int cou[2] = { 0, border[i + 1] };
			bitrui[i].resize(data.size()+1);
			REP(j, data.size()) {

				if(tbitcheck(buf[i % 2][j], bitsize - i - 1))
					bitrui[i][j + 1] = buf[i % 2][j];
				bitrui[i][j + 1] += bitrui[i][j];

				bitv[i + 1].set(cou[bitv[i].get(j)], tbitcheck(buf[i % 2][j], bitsize - i - 2));
				buf[1 - i % 2][cou[bitv[i].get(j)]] = tbitunset(buf[i % 2][j], (bitsize - i - 1));
				cou[bitv[i].get(j)]++;
			}
			bitv[i + 1].calcblock();
		}
		bitrui[bitsize-1].resize(data.size()+1);
		REP(j, data.size()) {
			if (tbitcheck(buf[(bitsize - 1) % 2][j], 0))
				bitrui[bitsize - 1][j + 1] = buf[(bitsize - 1) % 2][j];
			bitrui[bitsize-1][j+1] += bitrui[bitsize - 1][j];
		}
		border[bitsize] = bitv[bitsize - 1].rank(data.size(), 0);
	}

	pii search(int s, int e, unsigned int t, int b = 0) {
		if (b == bitsize) return{ s,e };
		bool cur = tbitcheck(t, bitsize - 1);
		return search(cur*border[b + 1] + bitv[b].rank(s, cur), cur*border[b + 1] + bitv[b].rank(e, cur), t << 1, b + 1);
	}
	int backward(int a, unsigned int t, int b = 0) {
		if (b == bitsize - 1) return a;
		backward(bitv[bitsize - b - 1].select(a + 1 - tbitcheck(t, 0) * border[bitsize - b], tbitcheck(t, 0)) - 1, t >> 1, b + 1);
	}

	int rank(int s, int e, T t) {
		pii r = search(s, e, t);
		return r.second - r.first;
	}

	int select(int a, T t) {
		pii r = search(0, data.size(), t);
		return  backward(r.first + a - 1, t);
	}

	T less_kthelement(int s, int e, int k, int b = 0) {//??????? 0??~
		int eo = bitv[b].rank(e, 0), so = bitv[b].rank(s, 0), cou = eo - so;
		if (b == bitsize - 1) return cou <= k;
		return (cou <= k ?
			less_kthelement(border[b + 1] + (s - so), border[b + 1] + (s - so) + (e - s - cou), k - cou, b + 1) :
			less_kthelement(so, so + cou, k, b + 1)) | ((cou <= k) << (bitsize - b - 1));
	}

	T more_kthelement(int s, int e, int k, int b = 0) {//???k??sum 0??~
		int eo = bitv[b].rank(e, 1), so = bitv[b].rank(s, 1), cou = eo - so;
		if (b == bitsize - 1) return cou > k;
		return (cou > k ?
			more_kthelement(border[b + 1]+so, border[b + 1]+ so + cou, k, b + 1) :
			more_kthelement(s-so, (s - so) + (e - s - cou), k - cou, b + 1)) | ((cou > k) << (bitsize - b - 1));
	}
	
	pair<ll, int> more_kthsum(int s, int e, int k, int b = 0) {//??????? 0??~
		if (k < 0) return { 0,0 };
		int eo = bitv[b].rank(e, 1), so = bitv[b].rank(s, 1), cou = eo - so;
		if (b == bitsize - 1) return { min(1 + k,cou),1 };

		if (cou > k) {
			pair<ll, int>  ret = more_kthsum(border[b + 1] + so, border[b + 1] + so + cou, k, b + 1);
			return {ret.first + (ll)min(k + 1, cou) * ret.second * 2, ret.second * 2};
		}
		else {
			pair<ll, int> ret = more_kthsum(s - so, (s - so) + (e - s - cou), k - cou, b + 1);
			return { ret.first + (bitrui[b][e] - bitrui[b][s]) + (ll)min(k + 1, max(0,cou - k)) * ret.second * 2, ret.second * 2};
		}
	}
	ll less_kthsum(int s, int e, int k, int b = 0) {//??????? 0??~

		return (rui[e] - rui[s]) - more_kthsum(s, e, (e - s) - k - 2).first;
	}

	int less(int s, int e, T t, int b = 0) {
		int eo = bitv[b].rank(e, 0), so = bitv[b].rank(s, 0), cou = (eo - so);
		if (b == bitsize) return e - s;
		return tbitcheck(t, bitsize - b - 1) ?
			less(border[b + 1] + (s - so), border[b + 1] + (s - so) + (e - s - cou), t, b + 1) + cou :
			less(so, so + cou, t, b + 1);
	}

	~WaveletMatrix() {
		REP(i, bitsize) bitv[i].clear();
	}
};

signed main() {
	int n;
	scanf("%d", &n);

	vector<int> num(n*3);
	REP(i, n*3) {
		scnaf("%d", &num[i]);
	}
	vector<int> buf(n*3);
	copy(ALL(num), buf.begin());
	WaveletMatrix<int> wv(num);

	ll Max = LLONG_MIN;

	rep(i, n, n*2+1) {
		ll b = wv.more_kthsum(0, i, n - 1).first, c = wv.less_kthsum(i, n * 3, n - 1);
		

		Max = max(Max, b - c);
	}
	printf("%lld\n", Max);
	return 0;

}