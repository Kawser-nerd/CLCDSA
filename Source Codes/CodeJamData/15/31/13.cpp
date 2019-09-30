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
int n, k;
int mas[N];
int ris[N];
int solve()
{
	int r, c, w;
	cin >> r >> c >> w;
	int ans = r * (c / w) + w;
	if (!(c % w))
		ans--;
	return ans;
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
	for(int i = 0; i < t; ++i)
		cout << "Case #" << i + 1 << ": " << solve() << endl;

}