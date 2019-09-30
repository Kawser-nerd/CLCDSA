#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
inline void read(int &x){
    x=0;static char ch;static bool flag;flag = false;
    while(ch=getchar(),ch<'!');if(ch == '-') ch=getchar(),flag = true;
    while(x=10*x+ch-'0',ch=getchar(),ch>'!');if(flag) x=-x;
}
#define rg register int
#define rep(i,a,b) for(rg i=(a);i<=(b);++i)
#define per(i,a,b) for(rg i=(a);i>=(b);--i)
const int maxn = 512;
const int zero = 250;
int fa[maxn],siz[maxn],oud[maxn],ind[maxn];bool h[maxn];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
inline void Union(int x,int y){
    x = find(x);y = find(y);
    if(x == y) {++siz[x];return ;}
    fa[x] = y;siz[y] += siz[x] + 1;
}
int main(){
    int n,H;read(n);read(H);
    rep(i,1,H)  fa[i+zero] = i+zero,siz[i+zero] = 1;
    rep(i,-H,-1)fa[i+zero] = i+zero,siz[i+zero] = 1;
    int a,b,c,d;
    rep(i,1,n){
        int x,y;
        read(a);read(b);read(c);read(d);
        if(c == 0) x = a;else x = -c;
        if(d == 0) y = -b;else y = d;
        ++ oud[x + zero];++ ind[y + zero];
        Union(x+zero,y+zero);
    }
    rep(i,1,H)  if(oud[i+zero] < ind[i+zero]) return puts("NO"),0;
    rep(i,-H,-1)if(ind[i+zero] < oud[i+zero]) return puts("NO"),0;
    rep(i,1,H)  h[find(i+zero)] |= (ind[i+zero]!=oud[i+zero]);
    rep(i,-H,-1)h[find(i+zero)] |= (ind[i+zero]!=oud[i+zero]);
    rep(i,1,H)  if(siz[find(i+zero)] > 1 && (find(i+zero) == i+zero) && (h[i+zero] == false)) return puts("NO"),0;
    rep(i,-H,-1)if(siz[find(i+zero)] > 1 && (find(i+zero) == i+zero) && (h[i+zero] == false)) return puts("NO"),0;
    puts("YES");
    return 0;
} ./Main.cpp:8:31: warning: while loop has empty body [-Wempty-body]
    while(ch=getchar(),ch<'!');if(ch == '-') ch=getchar(),flag = true;
                              ^
./Main.cpp:8:31: note: put the semicolon on a separate line to silence this warning
./Main.cpp:9:45: warning: while loop has empty body [-Wempty-body]
    while(x=10*x+ch-'0',ch=getchar(),ch>'!');if(flag) x=-x;
                                            ^
./Main.cpp:9:45: note: put the semicolon on a separate line to silence this warning
./Main.cpp:25:5: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    rep(i,1,H)  fa[i+zero] = i+zero,siz[i+zero] = 1;
    ^
./Main.cpp:12:24: note: expanded from macro 'rep'
#define rep(i,a,b) for(rg i=(a);i<=(b);++i)
                       ^
./Main.cpp:11:12: note: expanded from macro 'rg'
#define rg register int
           ^
./Main.cpp:26:5: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-regis...