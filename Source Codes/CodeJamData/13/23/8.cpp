#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <fstream>
#include <queue>


using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 1200500;

int next[nmax][26];
int fin[nmax];
int sz;
string s[nmax];
string t;
int m;
int dp[2][nmax][6];
queue<pii> q[5000];

void add(int n, int pos, int dst, int res) {
//	cerr << n << " " << pos << " " << dst << " " << res << endl;
	dst = min(dst, 4);
	if (dp[n & 1][pos][dst] == -1) {
		dp[n & 1][pos][dst] = res;
		q[n].push(mp(pos, dst));
	}
	dp[n & 1][pos][dst] = min(dp[n & 1][pos][dst], res);
	if (pos != 0 && fin[pos])
		add(n, 0, dst, res);
}

int solve() {
	cin >> t;
	memset(dp, 255, sizeof dp);
	add(0, 0, 4, 0);
	forn(i, t.size()) {
		int v = i & 1;
		memset(dp[v ^ 1], 255, sizeof dp[v ^ 1]);
		int cur = t[i] - 'a';
		while (!q[i].empty()) {
			pii now = q[i].front();
			q[i].pop();
			int pos = now.fs;
			int dst = now.sc;
			int res = dp[v][pos][dst];
			if (next[pos][cur] != -1)
				add(i + 1, next[pos][cur], dst + 1, res);
			if (dst >= 4)
				for (int j = 0; j < 26; j ++)
					if (next[pos][j] != -1)
						add(i + 1, next[pos][j], 0, res + 1);
		}
	}
	while (!q[t.size()].empty()) q[t.size()].pop();
	int rs = 1e9;
	forn(i, 6)
		if (dp[t.size() & 1][0][i] != -1)
		rs = min(rs, (int) dp[t.size() & 1][0][i]);
	cout << rs << endl;
	return 0;
}

void add(string s) {
	int now = 0;
	forn(i, s.size()) {
		int cur = s[i] - 'a';
		if (next[now][cur] == -1)
			next[now][cur] = sz ++;
		now = next[now][cur];	
	}
	fin[now] = 1;
}

char buf[10000];

void pre_calc() {
  	ifstream myfile ("text.txt");
  	sz = 1;
	memset(next, 255, sizeof next);
  	int len = 0;
  	m = 0;
  	while (myfile >> s[m]) {
	  	add(s[m]);
  		len = max(len, (int) s[m].size());
  		m ++;
  	}
//  	cerr << sz << " " << len <<  " " << m << endl;
}

int main ()
{
	pre_calc();
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
//	cerr << n << endl;

cerr << clock() << endl;
	forn(i, n){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << clock() << endl;
	}

	
	return 0;
}
