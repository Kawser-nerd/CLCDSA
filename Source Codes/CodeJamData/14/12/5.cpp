#include<bits/stdc++.h>
#include<sys/time.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n;
vector<vi> e;

int child[1000], dp[1000];

void rec(int c, int p){
	child[c] = 1;
	
	vi v;
	rep(i, e[c].size()) if(e[c][i] != p){
		rec(e[c][i], c);
		child[c] += child[e[c][i]];
		v.pb(dp[e[c][i]] - child[e[c][i]]);
	}
	sort(all(v));
	
	dp[c] = child[c] - 1;
	if(v.size() >= 2) dp[c] = min(dp[c], child[c] - 1 + v[0] + v[1]);
}

void run(){
	cin >> n;
	e.clear();
	e.resize(n);
	
	rep(i, n - 1){
		int a, b;
		cin >> a >> b; a--; b--;
		e[a].pb(b);
		e[b].pb(a);
	}
	int ans = inf;
	rep(r, n){
		rec(r, r);
		ans = min(ans, dp[r]);
	}
	cout << ans << endl;
}

int main(){
	int cs; cin >> cs;
	rep(i, cs){
		dbg(i);
		cout << "Case #" << i+1 << ": ";
		run();
	}
	return 0;
}
