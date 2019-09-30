#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <array>
#include <tuple>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <cstdio>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORR(i,a,b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define rep(i,n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define OVERLAP(v) v.erase(unique(v.begin(),v.end()),v.end())
#define overlap(v) v.erase(unique(v.begin(),v.end()),v.end())
#define DEBUG(x) cout << #x <<": "<<x<<endl
#define debug(x) cout << #x <<": "<<x<<endl
#define pb(a) push_back(a)
#define INF 999999999

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    cin >> s;
    vi a(4);
    rep(i,4) cin >> a[i];
    VSORT(a);
    repr(i,3) s.insert(s.begin() + a[i], '"');
    cout << s <<endl;
    return 0;
}