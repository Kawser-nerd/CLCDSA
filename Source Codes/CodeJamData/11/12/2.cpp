#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
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

int n, m;
int f[10500][27];
string D[10500], p;
int ans, depth;

void go(int k, int cost, const vi &v) {
	if (sz(v) == 1) {
		if (cost > depth || cost == depth && v[0] < ans) {
			depth = cost;
			ans = v[0];
		}
		return;
	}
	if (k == sz(p)) return;
	map<int, vi> F;
	int x = p[k] - 'a';
	for (int i : v) 
		F[f[i][x]].pb(i);
	for (auto t : F) 
		go(k + 1, cost + (t.X == 0 && sz(F) > 1), t.Y);
}

int solve() {
	vi v(n);
	iota(all(v), 0);
	ans = -1u/2;
	depth = -1;
	go(0, 0, v);
	return ans;
}

void run() {
	CL(f, 0);
	cin >> n >> m;
	REP (i, n) {
		string s;
		cin >> s;
		REP (j, sz(s))
			f[i][s[j] - 'a'] |= 1 << j;
		f[i][26] = sz(s);
		D[i] = s;
	}
	REP (i, m) {
		if (i) cout << ' ';
		cin >> p;
		p = char('a' + 26) + p;
		cout << D[solve()];
	}
	cout << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	cout.precision(12);
	cout.setf(ios::fixed);
	int a = 0, b = 0;
	for(cin >> b; a++ < b ; run()) 
		printf("Case #%d: ", a);
	return 0;
}
