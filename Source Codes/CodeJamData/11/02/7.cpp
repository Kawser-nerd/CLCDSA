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

set<string> op;
map<string, string> a;
string s;

void solve(){
	op.clear();
	a.clear();
	int n,m,k;
	cin >> n;
	forn(i, n){
		string s, w;
		cin >> s;
		w = "a";
		w[0] = s[2];
		s = s.substr(0, 2);
		a[s] = w;
	}
	cin >> m;
	forn(i, m){
		string s;
		cin >> s;
		op.insert(s);
	}
	cin >> k;
	string s;
	cin >> s;
	string res = "";
	forn(i, s.size()){
		res += s[i];
		//cerr << res << endl;
		while (res.size() >= 2){
			string w = res.substr(res.size()-2, 2);
			string e = w;
			reverse(all(e));
				
			if (a[w] != "")
				res = res.substr(0, res.size()-2) + a[w];
			else
			if (a[e] != "")
				res = res.substr(0, res.size()-2) + a[e];
			else{
				forn(i, res.size()-1){
					w = "aa";
					w[0] = res[i];
					w[1] = res[res.size()-1];
					if (op.count(w))
						res = "";
					w = "aa";
					w[1] = res[i];
					w[0] = res[res.size()-1];
					if (op.count(w))
						res = "";
					}
				break;
			}
			
		}
	}	
	printf("[");
	forn(i, res.size()){
		cout << res[i];
		if (i + 1 < res.size())
			cout << ", ";
	}
	cout << "]" << endl;


}


int main ()
{
	int tst;
	cin >> tst;
	forn(i, tst){
		printf("Case #%d: ", i + 1);
		solve();
	}

		return 0;
}
