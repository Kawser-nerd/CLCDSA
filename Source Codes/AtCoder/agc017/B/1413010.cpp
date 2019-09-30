#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

const int INF=1e9;
const ll INFF=1e17;
const double EPS=1e-9;
const ll MOD=1e9+7;
ll n,a,b,c,d,curr=0;
bool check(ll p,ll q){return abs(p-q)>=c && abs(p-q)<=d;}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b >> c >> d;
	REP(i,n)if((c*(n-1-i)-d*i)<=(b-a) && (b-a)<=(-c*i+(n-1-i)*d)){cout << "YES" << '\n';return 0;}
	cout << "NO" << '\n';
	return 0;
}