#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
//#include <ext/hash_map>


using namespace std;
using namespace __gnu_cxx;



#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define REPV(i, n) for (int i = (n) - 1; (int)i >= 0; --i)
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)

#define FE(i,t) for (__typeof((t).begin())i=(t).begin();i!=(t).end();++i)
#define FEV(i,t) for (__typeof((t).rbegin())i=(t).rbegin();i!=(t).rend();++i)

#define two(x) (1LL << (x))
#define ALL(a) (a).begin(), (a).end()


#define pb push_back
#define ST first
#define ND second
#define MP(x,y) make_pair(x, y)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

template<class T> void checkmin(T &a, T b){if (b<a)a=b;}
template<class T> void checkmax(T &a, T b){if (b>a)a=b;}
template<class T> void out(T t[], int n){REP(i, n)cout<<t[i]<<" "; cout<<endl;}
template<class T> void out(vector<T> t, int n=-1){for (int i=0; i<(n==-1?t.size():n); ++i) cout<<t[i]<<" "; cout<<endl;}
inline int count_bit(int n){return (n==0)?0:1+count_bit(n&(n-1));}
inline int low_bit(int n){return (n^n-1)&n;}
inline int ctz(int n){return (n==0?-1:ctz(n>>1)+1);}
int toInt(string s){int a; istringstream(s)>>a; return a;}
string toStr(int a){ostringstream os; os<<a; return os.str();}

const int maxn=3333;
double dp[maxn][maxn];
int seen[maxn][maxn];

double go(int a, int b){
    if (!a) return 1;
    if (!b) return 0;
    double &r=dp[a][b];
    if (seen[a][b]) return r;
    seen[a][b]=1;
    r=0.5*go(a-1,b-1)+0.5*go(a,b-1);
    return r;
}


int cnt(int nx){return nx*(2*nx-1);}
int main(){
    int tn; cin>>tn;
    REP(ti,tn){
        int n,x,y;
        cin>>n>>x>>y;
        int layer=(y+abs(x))/2+1;
        int nx=0;
        for (; cnt(nx)<=n; ++nx);

        double p=0;
        if (layer<nx) p=1;
        else if (nx<layer) p=0;
        else{
            int m=n-cnt(nx-1);
            int lvl=y+1;
            int maxy=2*layer-2;
            if (maxy+lvl<=m) p=1;
            else if (!x) p=0;
            else p=go(lvl,m);
        }

        printf("Case #%d: ",ti+1);
        printf("%.15lf\n",p);
    }
    return 0;
}


