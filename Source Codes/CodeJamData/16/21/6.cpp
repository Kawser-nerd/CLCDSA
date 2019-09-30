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

string db[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

pair<char, int> exe[10] = {
	{'Z', 0}, 
	{'W', 2}, 
	{'X', 6}, 
	{'G', 8}, 
	{'T', 3}, 
	{'R', 4}, 
	{'F', 5}, 
	{'S', 7}, 
	{'O', 1}, 
	{'I', 9}
};

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> T;
	REPS(t, T){
		string s;
		cin >> s;
		vi c(26);
		vi ans(10);
		for(char x : s) c[x - 'A'] ++;
		for(auto it : exe){
			int x = c[it.first - 'A'];
			ans[it.second] = x;
			for(char y : db[it.second]) c[y - 'A'] -= x;
		}
		cout << "Case #" << t << ": ";
		REP(i, 10) if(ans[i]) cout << string(ans[i], '0' + i);
		cout << endl;
	}
	return 0;
}
