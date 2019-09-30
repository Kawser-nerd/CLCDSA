//Keep pluggin',this is your only outlet.
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cctype>
#define MM(x,y) memset(x,y,sizeof(x))
#define MCPY(a,b) memcpy(a,b,sizeof(b))
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,b,a) for(int i=b;i>=a;i--)
#define fi first
#define mp make_pair
#define se second
using namespace std;
#define int long long

inline int quickpow(int m,int n,int p){int b=1;while(n){if(n&1)b=b*m%p;n=n>>1;m=m*m%p;}return b;}
inline int quickmul(int x,int y,int mod){return (x*y-(int)((long double)x/mod*y)*mod+mod)%mod;}
inline int getinv(int x,int p){return quickpow(x,p-2,p);}
inline int read(void){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){f=ch=='-'?-1:1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x * f;
}

int a[100010],b[100010],cur = 0,n;

///------------------head------------------
signed main(signed argc, char *argv[]){
    n = read();
    rep(i,1,n) a[i]=read(),b[i]=read();
    per(i,n,1) {
        int d = (a[i] + cur) % b[i];
        if (d == 0) continue;
        cur += b[i] - d;
    }
    printf("%lld\n",cur);
    return 0;
}

/* Examples: */
/*

*/

/*

*/