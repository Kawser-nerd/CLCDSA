#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int MAXN = 150 + 10;

int n,l;
tint a[MAXN], b[MAXN];

bool check(tint mask) {
	vt x,y;
	forn(i,n) x.pb(a[i]);
	forn(i,n) y.pb(b[i] ^ mask);
	sort(all(x)); sort(all(y));
	return x == y;
}

int main() {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ": ";
        	cin >> n >> l;
        	fill(a, a+n, 0);
        	fill(b, b+n, 0);

        	forn(i,n) {
        		string s; cin >> s;
        		forn(j,l) if (s[j] - '0') {
        			a[i] |= 1LL<<j;
        		}
        	}

        	forn(i,n) {
        		string s; cin >> s;
        		forn(j,l) if (s[j] - '0') {
        			b[i] |= 1LL<<j;
        		}
        	}

        	// forn(i,n) cerr << a[i] << ' '; cerr << endl;
        	// forn(i,n) cerr << b[i] << ' '; cerr << endl;

        	int res = 50;
        	forn(i,n) forn(j,n) {
        		tint mask = a[i] ^ b[j];
        		if (check(mask)) res = min(res, __builtin_popcountll(mask));

        	}

        	if (res == 50) cout << "NOT POSSIBLE" << endl;
        	else cout << res << endl;
        }

        return 0;
}
