 #define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <vector> 
#include <sstream> 
#include <string> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <queue>
using namespace std; 
#pragma comment(linker, "/STACK:256000000") 
#define mp make_pair 
#define pb push_back 
#define all(C) (C).begin(), (C).end() 
#define sz(C) (int)(C).size() 
#define PRIME 1103 
#define PRIME1 31415 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef pair<int, int> pii; 
typedef vector<int> vi; 
typedef vector<vector<int> > vvi; 
//------------------------------------------------------------ 
const int N = 100001;
int64 a, b;
int al[26];
char ans[200];
double EPS = 1e-7;


double solve()
{
	int k, l, s;
	cin >> k >> l >> s;
	string ket, tar;
	cin >> ket >> tar;
	memset(al, 0, sizeof al);
	memset(ans, 0, sizeof ans);
	//cerr << al[0];
	for(int i = 0; i < ket.size(); ++i)
		al[ket[i] - 'A']++;
	double per = 1;
	int q = 0;
	for(int i = 0; i < tar.size(); ++i)
	{
		//cerr << al[tar[i] - 'A'] << ' ' << ket.size() << endl;
		per *= al[tar[i] - 'A'] / (double) ket.size();
		if (!al[tar[i] - 'A'])
			q = 1;
	}
	if (q)
		return 0;
	double mt = per * (s - tar.size() + 1);
	double p = 0;
	
	for(int i = 0; i + tar.size() <= s; ++i)
	{
		int q = 0;
		for(int j = 0; j < tar.size(); ++j)
		{
			if (ans[i + j] && ans[i + j] != tar[j])
				q = 1;
		}
		if (q)
			continue;
		for(int j = 0; j < tar.size(); ++j)
			ans[i + j] = tar[j];
		p++;
	}
	return p - mt;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
    cin >> t;
	cout.precision(8);
	for(int i = 0; i < t; ++i)
		cout << "Case #" << fixed << i + 1 << ": " << solve() << endl;

}