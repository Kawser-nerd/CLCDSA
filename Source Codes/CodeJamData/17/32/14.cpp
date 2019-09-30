#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;
 
const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg = 0;
	num = 0;
	char c;
	while ((c = getchar_unlocked()) && (!isdigit(c) && c != '-'));
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	do num = num * 10 + c - '0';
	while ((c = getchar_unlocked()) && isdigit(c));
	if (neg) num = -num;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in = "input.txt",string out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v3.1

int dp[725][725][2];
bitset<1445> bisa[2];
int n, a, b;

int f(int ta, int tb, int who) {
	int& res = dp[ta][tb][who];
	if (res != -1) return res;
	if (ta + tb == 1440) return res = (who == 0 ? 0 : 1);
	res = INF - 5;
	int t = ta + tb;
	int tnow = (who == 0 ? ta : tb);
	if (bisa[who].test(t) && tnow + 1 <= 720) {
		int nta = (who == 0 ? ta + 1 : ta);
		int ntb = (who == 1 ? tb + 1 : tb);
		res = min(res, f(nta, ntb, who));
	}
	tnow = (who == 0 ? tb : ta);
	if (bisa[who ^ 1].test(t) && tnow + 1 <= 720) {
		int nta = (who == 1 ? ta + 1 : ta);
		int ntb = (who == 0 ? tb + 1 : tb);
		res = min(res, f(nta, ntb, who ^ 1) + 1);
	}	
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n;
	FORN (tc, 1, n) {
		cin >> a >> b;
		bisa[0].set(); bisa[1].set();
		FOR (i, 0, a) {
			int x, y;
			cin >> x >> y;
			FOR (t, x, y) bisa[0].set(t, 0);
		}
		FOR (i, 0, b) {
			int x, y;
			cin >> x >> y;
			FOR (t, x, y) bisa[1].set(t, 0);
		}
		int ans = INF;
		RESET(dp, -1);
		ans = min(ans, f(0, 0, 0));
		swap(bisa[0], bisa[1]);
		RESET(dp, -1);
		ans = min(ans, f(0, 0, 0));
		cout << "Case #" << tc << ": " << ans << "\n";
	}
}
