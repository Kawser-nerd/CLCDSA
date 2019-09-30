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
double EPS = 1e-7;
int de[200];

int solve()
{
	int mi = 0;
	int c, d, v;
	cin >> c >> d >> v;
	string ket, tar;
	for(int i = 0; i < d; ++i)
		cin >> de[i];
	sort(de, de + d);
	if (de[0] != 1)
		mi++;
	int64 r = c;
	int k = 0;
	if (de[0] == 1)
		k = 1;
	while(r < v)
	{
		//cerr << r << ' ' << mi << endl;
		if (k < d && de[k] <= r + 1)
		{
			r += de[k] *(int64) c;
			k++;
			continue;
		}
		//cerr << r << ' ' << mi << endl;
		mi++;
		r += (r + 1) *(int64) c;
	}
	return mi;
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