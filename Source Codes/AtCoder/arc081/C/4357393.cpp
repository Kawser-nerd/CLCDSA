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
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
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
pll Dir[8] = { //??
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

struct Edge {
	ll from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}


signed main(void) {
	string a;
	cin >> a;
	int nex[200021][26] = {};

	Fill(nex, -1);

	int dp[200021] = {}, fr[200021] = {};
	Fill(dp, INT_MAX/2);
	Fill(fr, -1);
	for (int i = a.length() - 2; -1 <= i; i--) {
		memcpy(nex[i], nex[i + 1], sizeof(int)*26);
		nex[i][a[i + 1] - 'a'] = i + 1;
	}
	for (int i = a.length() - 1; 0 <= i; i--) {
		REP(j, 26) {
			if (nex[i][j] != -1) {
				if (dp[i] > dp[nex[i][j]] + 1) {
					dp[i] = dp[nex[i][j]] + 1;
					fr[i] = nex[i][j];
				}
			}
			else if (dp[i] > 1) {
				dp[i] =  1;
				fr[i] = -1;
			}

		}
	}
	int nx[200021];
	memcpy(nx, nex[0], sizeof(int) * 26);

	nx[a[0] - 'a'] = 0;
	int cur, bef = -1,Min = INT_MAX;
	REP(j, 26) {
		if (nx[j] != -1) {
			if (Min > dp[nx[j]] + 1) {
				Min = dp[nx[j]] + 1;
				cur = nx[j];
			}
		}
		else if (Min > 1) {
			Min = 1;
			cur = -1;
		}
	}
	while (cur != -1) {
		printf("%c", a[cur]);
		bef = cur;
		cur = fr[cur];
	}
	REP(i, 26) {
		if (bef >= 0) {
			if (nex[bef][i] == -1) {
				printf("%c",i + 'a');
				break;
			}
		}
		else {
			if (nx[i] == -1) {
				printf("%c", i + 'a');
				break;
			}
		}
	}
	cout << endl;

	return 0;
}