	#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;
typedef  double real;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())


struct ver{
	string s;
	real key;
	int h,l,r;
	ver(){
		h = l = r = -1;
	}
};

ver t[200];
map<string,int> h;
int m;
real res;

void read_tree(int v){
	char ch;
	cin >> ch;
	assert(ch == '(');
	cin >> t[v].key;
	cin >> ch;
	t[v].s = "";
	if (ch == ')'){
		t[v].l = t[v].r = -1;
		return;
	}
	getline(cin, t[v].s);
	t[v].s = ch + t[v].s;
	read_tree(t[v].l = m++);
	read_tree(t[v].r = m++);
	cin >> ch;
	assert(ch == ')');
}	

void read(){
	int len;
	scanf("%d",&len);
	m = 1;
	read_tree(0);
}

void go(int v, real now){
	now *= t[v].key;
	if (t[v].l == -1){
		res += now;
		return;
	}
	if (h[t[v].s] == 1)
		go(t[v].l, now);
	else
		go(t[v].r, now);
}

void solve(){
	int tst;
	cin >> tst;
	forn(i,tst){
		string s;
		cin >> s;
		h.clear();
		int n;
		cin >> n;
		forn(i,n){
			cin >> s;
			h[s] = 1;
		}
		res = 0;
		go(0,1);
		cerr << res << endl;
		printf("%0.7lf\n", res);
	}
}
	

int main(){
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	

	int tst;
	cin >> tst;
	forn(i,tst){
		printf("Case #%d:\n", i+1);
		read();
		solve();
	}

	return 0;
}
