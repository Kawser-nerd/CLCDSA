#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

int n, h;
int a[1024], p[1024];

ll F[1024][16];

ll f(int x, int s, int l, int r) {
	if (l + 1 == r) return s >= a[l] ? 0 : -1ull/8;
	ll &res = F[x][s];
	if (res < 0) {
		int m = (l + r) / 2;
		res = f(x * 2, s, m, r) + f(x * 2 + 1, s, l, m);
		res <?= -1ull/8;
		res <?= p[x] + f(x * 2, s + 1, m, r) + f(x * 2 + 1, s + 1, l, m);
	}
	return res;
}

void Solve(){
	CL(F, -1);
	cin >> h;
	n = 1 << h;
	REP (i, n) cin >> a[i], a[i] = h - a[i];
	REP (i, n - 1) cin >> p[i];
	reverse(p, p + n);
	cout << f(1, 0, 0, n) << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
