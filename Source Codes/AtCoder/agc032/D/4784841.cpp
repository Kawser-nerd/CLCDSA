//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
using namespace std;
namespace mine
{
    typedef long long ll;
    #define double long double
    const int INF=0x3f3f3f3f;
    const ll LLINF=0x3f3f3f3f3f3f3f3fll;
    ll qread()
    {
        ll ans=0;char c=getchar();int f=1;
        while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
        while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
        return ans*f;
    }
    void write(ll num)
    {
        if(num<0) {num=-num;putchar('-');}
        if(num>9) write(num/10);
        putchar('0'+num%10);
    }
    void writeln(ll num){write(num);puts("");}
    #define FR first
    #define SE second
    #define MP make_pair
    #define pr pair<int,int>
    #define PB push_back
    #define vc vector
    void chmax(int &x,const int y) {x=x>y?x:y;}
    void chmin(ll &x,const ll y) {x=x<y?x:y;}
    const int MAX_N=5e3+10;
    const ll MOD=1e13;
    void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

    ll f[MAX_N];//???
    int a[MAX_N];
    void main()
    {
        int n=qread(),A=qread(),B=qread();
        for(int i=1;i<=n;i++) a[qread()]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=0;j--)
            {
                f[j]=f[j]+A*(a[i]<=j)+B*(a[i]>j);
                if(j==a[i]) chmin(f[j],f[j-1]);
                else if(j) chmin(f[j],f[j-1]+A*(a[i]<j)+B*(a[i]>j));
            }
            for(int j=1;j<=n;j++) chmin(f[j],f[j-1]);
            // puts("");
        }

        ll ans=LLINF;for(int j=0;j<=n;j++) chmin(ans,f[j]);write(ans);
    }
};
int main()
{
    srand(time(0));
    mine::main();
} ./Main.cpp:48:38: warning: comparison of constant 10000000000000 with expression of type 'int' is always false [-Wtautological-constant-out-of-range-compare]
    void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}
                                    ~^ ~~~
1 warning generated.