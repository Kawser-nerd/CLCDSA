#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

//#define DEBUG 1

#define for0(i,n) for (int i=0; i<n; i++)
#define forr(i,n) for (int i=n-1; i>=0; i--)
#define fori(i,a,b) for (int i=a; i<=b; i++)
#define iter(c,x) for(x::iterator it=c.begin(); it!=c.end(); it++)
#define vec(x) vector< x >
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define sqr(x) 1LL*(x)*(x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define size(x) (int)(x).size()
#define read(x) int x; scanf("%d",&x);
#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<size(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define debug
#endif

using namespace std;

typedef long long ll;

const int INF = 999999999;
const long long INFL = 99999999999999999LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

int weights[105], values[105];
map<int,int> mem[105];
int N,W;

int solve(int i, int w_max)
{
    if (i == N)
        return 0;
    if (mem[i].find(w_max) != mem[i].end()) {
        return mem[i][w_max];
    }

    int v1=0,v2=0;
    if (w_max >= weights[i]) {
        v1 = solve(i+1, w_max-weights[i]) + values[i];
    }
    v2 = solve(i+1, w_max);
    int ans = max(v1,v2);
    //pr(i) pr(w_max) pr(ans) nl
    mem[i][w_max] = ans;
    return ans;
}

int main()
{
    #ifdef DEBUG
    freopen("B.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    scanf("%d %d",&N,&W);
    for0(i,N) {
        scanf("%d %d",&weights[i], &values[i]);
    }
    //printa(weights,N)
    //printa(values,N)

    int ans = solve(0,W);
    cout<<ans<<endl;
    return 0;
}