#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define LL long long

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    static bool fr_f; static char fr_ch;
    fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || '9'<fr_ch) {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while('0'<=fr_ch && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}

template< typename T > inline void Max (T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min (T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a, T &b) {T c=a;a=b;b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double   pi = acos(-1.0) ;
const int     MOD = (int)1e9+7 ;
const int     INF = (int)0x3f3f3f3f ;
const LL     LINF = (LL)INF<<32|INF ;
const int    SINF = (uint)(-1)>>1 ;
const LL    SLINF = (ULL)(-1)>>1 ;
const double DINF = 1e50 ;
const double  eps = 1e-5 ;
const int    maxn = (int) 1e5+20 ;
const int    maxm = (int) 1e6+20 ;
const int    maxk = (int) 1000+20 ;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline LL fp(LL a,LL n,LL p) {LL res=1; for(;n;n>>=1,a=a*a%p) if(n&1) res=res*a%p; return res;}
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}

//--------------------start--------------------

int n, A, B;
bool vis[605][605];

void func(int x)
{
    int p = 0;
    while(!(x & 1))
    {
        x >>= 1;
        p++;
    }

    int nn = n << 1;

    if(p & 1)
    {
        int len = 1 << ((p - 1) / 2);

        for(int i = 0; i < (nn + len - 1) / len; i++)
        {
            if(i & 1)
            {
                int dx = i * len;
                for(int u = 0; u < len; u++)
                {
                    if(u + dx < nn)
                    {
                        for(int v = 0; v < nn; v++)
                        {
                            vis[u + dx][v] = 1;
                        }
                    }
                }
            }
        }
    }
    else
    {
        int len = 1 << (p / 2);
        for(int i = 0; i < (nn + len - 1) / len; i++)
        {
            for(int j = 0; j < (nn + len - 1) / len; j++)
            {
                if((i + j) & 1)
                {
//                    cout <<i <<" " <<j <<endl;
                    int dx = i * len;
                    int dy = j * len;

                    for(int u = 0; u < len; u++)
                    {
                        for(int v = 0; v < len; v++)
                        {
                            if(dx + u < nn && dy + v < nn)
                            {
//                                cout <<dx + u <<" " <<dy + v <<" !" <<endl;
                                vis[dx + u][dy + v] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void work()
{
    read(n);
    read(A);
    read(B);
    func(A);
    func(B);

//    for(int i = 0; i < n * 2; i++)
//    {
//        for(int j = 0; j < n * 2; j++)
//        {
//            cout <<vis[i][j];
//        }
//        cout <<endl;
//    }

    int cnt = 0;
    for(int i = 0; i < n * 2; i++)
    {
        for(int j = 0; j < n * 2; j++)
        {
            if(!vis[i][j])
            {
                printf("%d %d\n", i, j);
                cnt++;
            }

            if(cnt == n * n) break;
        }
        if(cnt == n * n) break;
    }
}

//---------------------end---------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
} ./Main.cpp:71:68: warning: for loop has empty body [-Wempty-body]
template<typename T>inline T gcd(T a,T b) {for(T c;b;c=a%b,a=b,b=c); return a;}
                                                                   ^
./Main.cpp:71:68: note: put the semicolon on a separate line to silence this warning
1 warning generated.