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

int n, l;
ll in[150], out[150];

int p[300];
bool e[300][300];
bool v[300];

bool rec(int s){
	if(s < 0) return 1;
	rep(i, 2*n) if(e[s][i] && !v[i]){
		v[i] = 1;
		if(rec(p[i])) return p[i] = s, p[s] = i, 1;
	}
	return 0;
}

void run(){
	memset(e, 0, sizeof(e));
	
	cin >> n >> l;
	rep(i, n){
		string s;
		cin >> s;
		in[i] = 0;
		rep(j, l) in[i] |= ll(s[j] - '0') << j;
	}
	rep(i, n){
		string s;
		cin >> s;
		out[i] = 0;
		rep(j, l) out[i] |= ll(s[j] - '0') << j;
	}
	int ans = inf;
	
	rep(a, n) rep(b, n){
		ll mask = in[a] ^ out[b];
		int match = 0;
		
		rep(i, n) rep(j, n) e[i][j + n] = e[j + n][i] = (in[i] ^ mask) == out[j];
		
		memset(p, -1, sizeof(p));
		
		rep(i, 2*n) if(p[i] < 0){
			memset(v, 0, sizeof(v));
			if(rec(i)) match++;
		}
		if(match == n) ans = min(ans, __builtin_popcountll(mask));
	}
	
	if(ans == inf) cout << "NOT POSSIBLE" << endl;
	else cout << ans << endl;
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
