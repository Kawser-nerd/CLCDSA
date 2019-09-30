#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
#include <ctime>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> P;
 
#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-8)
#define PI (acos(-1))
const ll MOD = 1000000007ll;

int n;
ll a[112345];
ll sum[112345];

int main() {
	cin >> n;
	REP(i, n) scanf("%lld", a + i);
	sort(a, a + n);
	
	
	sum[0] = a[0];
	FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
	
	int ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i + 1] <= sum[i] * 2) {
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}