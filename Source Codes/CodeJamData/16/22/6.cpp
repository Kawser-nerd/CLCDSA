#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int T, n, m;

string s, t;
pair<ll, pll> ans;

void dfs(int i, ll A, ll B){
	if(i == n){
		ans = min(ans, mp(abs(A-B), mp(A, B)));
		return ;
	}
	
	
	if(s[i] != '?' && t[i] != '?'){
		dfs(i+1, A * 10 + s[i] - '0', B * 10 + t[i] - '0');
		return ;
	}
	if(A == B){
		[&](){
			REP(x, 10)if(s[i] == '?' || s[i] == x + '0'){
				REP(y, 10)if(t[i] == '?' || t[i] == y + '0'){
					if(x == y){
						dfs(i+1, A * 10 + x, B * 10 + y);
						return ;
					}
				}
			}
		}();
		[&](){
			REP(x, 10)if(s[i] == '?' || s[i] == x + '0'){
				REP(y, 10)if(t[i] == '?' || t[i] == y + '0'){
					if(x == y+1){
						dfs(i+1, A * 10 + x, B * 10 + y);
						return ;
					}
				}
			}
		}();
		[&](){
			REP(x, 10)if(s[i] == '?' || s[i] == x + '0'){
				REP(y, 10)if(t[i] == '?' || t[i] == y + '0'){
					if(x+1 == y){
						dfs(i+1, A * 10 + x, B * 10 + y);
						return ;
					}
				}
			}
		}();
	}
	if(A < B){
		ll x = s[i] == '?' ? 9 : s[i] - '0';
		ll y = t[i] == '?' ? 0 : t[i] - '0';
		dfs(i+1, A*10 + x, B*10 + y);
	}
	if(A > B){	// A > B
		ll x = s[i] == '?' ? 0 : s[i] - '0';
		ll y = t[i] == '?' ? 9 : t[i] - '0';
		dfs(i+1, A*10 + x, B*10 + y);
	}
}

string pad(ll x, int n){
	string res;
	REP(i, n){
		res.pb('0' + x % 10);
		x /= 10;
	}
	reverse(ALL(res));
	return res;
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> T;
	REPS(_, T){
		cin >> s >> t;
		n = s.size();
		ans.first = 1ll << 62;
		dfs(0, 0, 0);
		
		cout << "Case #" << _ << ": " << pad(ans.second.first, n) << " " << pad(ans.second.second, n) << endl;
	}
	return 0;
}
