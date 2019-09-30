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
    void chmin(int &x,const int y) {x=x<y?x:y;}
    const int MAX_N=2e5+10;
    const ll MOD=1e9+7;
    void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

    int a[MAX_N];
    void main()
    {
        int n=qread(),M=qread();for(int i=1;i<=n*2;i++) a[i]=qread();sort(a+1,a+n+n+1);
        int l,r,A,B;
        l=1,r=n,A=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;bool bk=0;
            for(int tl=1,tr=2*mid;tl<=tr;tl++,tr--) if(a[tl]+a[tr]>=M) {bk=1;break;}
            if(!bk) A=mid,l=mid+1;
            else r=mid-1;
        }
        l=0,r=n-1,B=n;
        while(l<=r)
        {
            int mid=(l+r)>>1;bool bk=0;
            for(int tl=mid*2+1,tr=2*n;tl<=tr;tl++,tr--) if(a[tl]+a[tr]<M) {bk=1;break;}
            // printf("l=%d r=%d mid=%d bk=%d\n",l,r,mid,bk);
            if(!bk) B=mid,r=mid-1;
            else l=mid+1;
        }
        if(B>A)
        {
            printf("A=%d B=%d\n",A,B);
        }
        else
        {
            int mx=0;
            for(int tl=1,tr=2*B;tl<=tr;tl++,tr--) chmax(mx,a[tl]+a[tr]);
            for(int tl=2*B+1,tr=2*n;tl<=tr;tl++,tr--) chmax(mx,a[tl]+a[tr]-M);
            write(mx);
        }
    }
};
int main()
{
    srand(time(0));
    mine::main();
}