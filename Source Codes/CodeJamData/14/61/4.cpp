#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
string s[2000];

int calc (string s) {
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < sz (s); i++) {
		int x = i & 1;
		int y = 1 - x;
		ans1 += int (s[i] - '0' != x);
		ans2 += int (s[i] - '0' != y);
	}
	re min (ans1, ans2) / 2;
}

int main (int argc, char **argv) {
	int procnum = 0, procall = 1;
	if (argc > 2) {
		procall = 0;
		for (int i = 0; argv[1][i]; i++) procnum = procnum * 10 + argv[1][i] - '0';
		for (int i = 0; argv[2][i]; i++) procall = procall * 10 + argv[2][i] - '0';
		freopen ((string (argv[1]) + ".in").c_str (), "r", stdin);
		freopen ((string (argv[1]) + ".out").c_str (), "w", stdout);
	}
	double start = clock ();
	int tt, CNT = 0;
	cin >> tt;
	int ALL = (tt + procall - 1) / procall;
	for (int it = 0; it < tt; it++) {
		double current = clock ();
		
		cin >> n; n *= 2;
		for (int i = 0; i < n; i++) cin >> s[i];
		                           
		if (it % procall != procnum) continue;

		string a = "", b = "";
		int bad = 0;
		int aones = 0, bones = 0;

		for (int i = 0; i < n; i++) {
        	int ok = 1;
        	for (int j = 0; j < n; j++)			
        		if (s[i][j] != s[0][j])
        			ok = 0;
        	if (ok) a += "0"; else {
				ok = 1;
        		for (int j = 0; j < n; j++)			
    	    		if (s[i][j] == s[0][j])
	        			ok = 0;
	        	if (ok) {
	        		a += "1";
	        		aones++;
	        	} else bad = 1;
        	}
		}

		for (int i = 0; i < n; i++) {
        	int ok = 1;
        	for (int j = 0; j < n; j++)			
        		if (s[j][i] != s[j][0])
        			ok = 0;
        	if (ok) b += "0"; else {
				ok = 1;
        		for (int j = 0; j < n; j++)			
    	    		if (s[j][i] == s[j][0])
	        			ok = 0;
	        	if (ok) {
	        		b += "1";
	        		bones++;
	        	} else bad = 1;
        	}
		}

		if (2 * aones != n || 2 * bones != n) bad = 1;

		cout << "Case #" << it + 1 << ": ";
		if (bad) cout << "IMPOSSIBLE"; else cout << calc (a) + calc (b);
		cout << endl;
		CNT++;
		cerr << it + 1 << " / " << tt << " = " << (clock () - current) / CLOCKS_PER_SEC << " " << (clock () - start) / CLOCKS_PER_SEC / CNT * ALL << endl;
	}
    return 0;
}