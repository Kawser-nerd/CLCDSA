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
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
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


#define izryt bool

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);

}

int n;
ll dp[2000001], rui[2000001];

signed main() {
	scanf("%d", &n);

	dp[n - 1] = n;
	rui[n-1] = n;
	for (int i = 2000000; i >= n; i--) {
		rui[i] += 1;
		rui[i] += rui[i+1];
		dp[i] = 1;
	}
	rui[n - 1] += rui[n];

	for (int cur = n - 2; 0 <= cur; cur--) {
		dp[cur] = (dp[cur + 1] + (rui[cur + 3] - rui[cur + n + 2])%MODU)%MODU + ((ll)(n - 1)*(n - 1)%MODU);
		dp[cur] %= MODU;
		rui[cur] += dp[cur];
		rui[cur] += rui[cur+1];
		rui[cur] %= MODU;
	}
	if (dp[0] < 0) dp[0] += MODU;
	printf("%lld\n", dp[0]%MODU);
	return 0;
}