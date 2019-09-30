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

map<ll, ll> found;
int cur[6];
ll arr[500];
bool used[500];

void print(ll compr) {
	cout << endl;
	rep (i, 6) {
		if (i) cout << ' ';
		cout << arr[compr % 500];
		compr /= 500;
	}
}

int main() { freopen("test.in","r",stdin); freopen("test.out","w",stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ":";
		
		found.clear();
		
		int n;
		cin >> n;
		rep (i, 500) {
			cin >> arr[i];
		}
		while (true) {
			rep (i, 6) {
				int t;
				do {
					t = rand() % 500;
				} while (used[t]);
				used[t] = true;
				cur[i] = t;
			}
			sort(cur, cur + 6);
			ll sum = 0;
			ll compr = 0;
			rep (i, 6) {
				sum += arr[cur[i]];
				compr = compr * 500 + cur[i];
			}
			ll& t = found[sum];
			if (t && t != compr) {
				print(t);
				print(compr);
				break;
			} else {
				t = compr;
			}
			rep (i, 6) used[cur[i]] = false;
		}
		
		cout << '\n';
	}
}
