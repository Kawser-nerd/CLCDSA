#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
typedef long long ll;
#define rg register

template <typename _Tp> inline _Tp read(_Tp&x){
	char c11=getchar(),ob=0;x=0;
	while(c11^'-'&&!isdigit(c11))c11=getchar();if(c11=='-')ob=1,c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();if(ob)x=-x;return x;
}

const int N=101000;
int a[N],vis[N],st[N];
ll b[N],p[N],k;
int n,m,tp;

void init();void work();void print();
int main(){init();work();print();return 0;}

void work(){
	int x;
	for(rg int i=1;i<=m;++i)read(x),swap(a[x],a[x+1]);
	for(rg int i=1;i<=n;++i)if(!vis[i]){
		vis[st[0]=x=i]=tp=1;
		while(!vis[a[x]])
			vis[st[tp++]=x=a[x]]=1;
		int e=k%tp;
		for(rg int j=0;j<tp;++j)
			b[st[j]]=p[st[j+e<tp?j+e:j+e-tp]];
	}
}

void print(){
	ll sm(0ll);
	for(rg int i=1;i<=n;++i)
		printf("%lld\n",sm+=b[i]);
}

void init(){
	read(n);
	for(rg int i=1;i<=n;++i)read(p[i]),a[i]=i;
	for(rg int i=n;i;--i)p[i]-=p[i-1];
	read(m),read(k);
} ./Main.cpp:24:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(rg int i=1;i<=m;++i)read(x),swap(a[x],a[x+1]);
            ^~~
./Main.cpp:6:12: note: expanded from macro 'rg'
#define rg register
           ^
./Main.cpp:25:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(rg int i=1;i<=n;++i)if(!vis[i]){
            ^~~
./Main.cpp:6:12: note: expanded from macro 'rg'
#define rg register
           ^
./Main.cpp:30:7: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
                for(rg int j=0;j<tp;++j)
                    ^~~
./Main.cpp:6:12: note: expanded from macro 'rg'
#define rg register
           ^
./Main.cpp:37:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(rg int i=1;i<=n;++i)
            ^~~
./Main.cpp:6:12: note: ...