#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)

int cnts[210];
int main() { freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ":";
		
		int n;
		cin >> n;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> cnts[i];
			tot += cnts[i];
		}
		
		for (int i = 0; i < n; i++) {
			double lo = 0, hi = 1, mid;
			rep (it, 100) {
				mid = (lo + hi) / 2;
				double score = tot * mid + cnts[i];
				double sum = mid;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (score > cnts[j]) {
						sum += (score - cnts[j]) / tot;
					}
				}
				if (sum > 1) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			cout << ' ' << hi * 100;
		}
		
		cout << '\n';
	}
}
