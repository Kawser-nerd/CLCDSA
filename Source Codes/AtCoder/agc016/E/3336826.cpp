#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <bitset>
#define ll long long 
#define ri register int 
using std::min;
using std::bitset;
using std::max;
template <class T>inline void read(T &x){
    x=0;int ne=0;char c;
    while(!isdigit(c=getchar()))ne=c=='-';
    x=c-48;
    while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+c-48;
    x=ne?-x:x;return ;
}
const int maxn=405;
const int inf=0x7fffffff;
bitset <maxn> o[maxn];
bool ok[maxn];
int a[100005],b[100005],m,n;
int main(){
	int x,y;
    read(n),read(m);
    for(ri i=1;i<=m;i++)read(a[i]),read(b[i]);
    for(ri i=1;i<=n;i++){
        o[i][i]=1;
        for(ri j=m;j>=1;j--){
            x=o[i][a[j]],y=o[i][b[j]];
            if(x&y)ok[i]=1;
            else if(x)o[i][b[j]]=1;
            else if(y)o[i][a[j]]=1;
        }
    }
    ll ans=0;
    for(ri i=1;i<=n;i++){
        for(ri j=i+1;j<=n;j++){
            if(ok[i]||ok[j])continue;
            if(!((o[i]&o[j]).any()))ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
} ./Main.cpp:28:9: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    for(ri i=1;i<=m;i++)read(a[i]),read(b[i]);
        ^
./Main.cpp:9:12: note: expanded from macro 'ri'
#define ri register int 
           ^
./Main.cpp:29:9: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    for(ri i=1;i<=n;i++){
        ^
./Main.cpp:9:12: note: expanded from macro 'ri'
#define ri register int 
           ^
./Main.cpp:31:13: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(ri j=m;j>=1;j--){
            ^
./Main.cpp:9:12: note: expanded from macro 'ri'
#define ri register int 
           ^
./Main.cpp:39:9: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
    for(ri i=1;i<=n;i++){
        ^
./Main.cpp:9:12: note: expanded from macro 'ri'
#define ri register int 
           ...