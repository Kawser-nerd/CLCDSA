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

const int maxn=4444;
char s[maxn];
char buf[333];
int n;
int dp[maxn][6];

struct node{
    int next[26];
    int is;
}tb[(int)2e6];
int pos;

int go(int a, int b);


int dfs(int a, int x, int b){
    b=min(b,5);
    int res=maxn;
    if (tb[x].is) res=min(res,go(a,b));
    
    if (a==n) return res;

    REP(j,26) if (tb[x].next[j]){
        int f=j!=s[a];
        if (f && b!=5) continue;
        res=min(res,dfs(a+1,tb[x].next[j],(1-f)*b+1)+f);
    }
    return res;
}

int go(int a, int b){
    if (a>=n) return 0;
    b=min(b,5);
    int &r=dp[a][b];
    if (r!=-1) return r;
    r=dfs(a,1,b);
    return r;
}


int main(){
    FILE *f=fopen("dict.txt","r");
    int ml=0;

    pos=2;
    while(fscanf(f," %s",buf)>0){
        int x=1;
        int m=strlen(buf);
        REP(j,m){
            char c=buf[j]-'a';
            if (tb[x].next[c]==0) tb[x].next[c]=pos++;
            x=tb[x].next[c];
        }
        tb[x].is=1;
    }

    int tn; cin>>tn;
    REP(ti,tn){
        scanf(" %s",s);
        n=strlen(s);
        REP(j,n) s[j]-='a';

        printf("Case #%d: ",ti+1);
        memset(dp,-1,sizeof(dp));
        int res=go(0,5);
        printf("%d\n",res);
    }
    return 0;
}


