//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const int mx = 102;

int a[mx][mx], cur[mx][mx], n, m;

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("B-small-attempt0.in", "r", stdin); freopen("small0.txt", "w", stdout);
    freopen("B-large.in", "r", stdin); freopen("large.txt", "w", stdout);

    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        scanf("%d %d", &n, &m);
        fr(i, n) fr(j, m) scanf("%d", &a[i][j]);
        fr(i, n) fr(j, m) cur[i][j] = 100;
        
        fr(i, n) {
            int mx = 0;
            fr(j, m) mx = max(mx, a[i][j]);
            fr(j, m) cur[i][j] = min(cur[i][j], mx);
        }
        
        fr(j, m) {
            int mx = 0;
            fr(i, n) mx = max(mx, a[i][j]);
            fr(i, n) cur[i][j] = min(cur[i][j], mx);
        }
        
        string ans = "YES";
        fr(i, n) fr(j, m) if(cur[i][j] != a[i][j]) ans = "NO";
        
        printf("Case #%d: %s\n", _t, ans.c_str());
    }

	return 0;
}
