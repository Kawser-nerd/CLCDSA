#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iterator>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef unsigned long long int llu;
typedef pair<lli, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

lli tt[64], ot[64];
lli m;

void init(void){
	tt[0] = 10%m; ot[0] = 1%m;
	rep(i, 63){
		tt[i+1] = (tt[i]*tt[i])%m;
		ot[i+1] = (ot[i] * (tt[i]+1))%m;
	}
	return;
}

lli f1(lli a){
	lli ret = 0;
	rep(i, 64) if((a>>i)&1 == 1) ret = (ret*tt[i] + ot[i])%m;
	return ret;
}

lli f2(lli a, lli z){
	lli zt[64], xt[64]; zt[0] = 1; xt[0] = 1;
	rep(i, 64) if((z>>i)&1 == 1) zt[0] = (zt[0]*tt[i])%m;
	rep(i, 63){
		zt[i+1] = (zt[i]*zt[i])%m;
		xt[i+1] = (xt[i] * (zt[i]+1))%m;
	}
	lli ret = 0;
	rep(i, 64) if((a>>i)&1 == 1) ret = (ret*zt[i] + xt[i])%m;
	return ret;
}

lli gcm(lli a, lli b){
	if(a<b) swap(a,b);
	if(a%b == 0) return b;
	return gcm(b, a%b);
}

int main(void){
	lli a, b, g; cin >> a >> b >> m;
	init();
	g = gcm(a,b);
	cout << (f1(a)*f2(b/g,g))%m << endl;
	
	return 0;
} ./Main.cpp:44:22: warning: & has lower precedence than ==; == will be evaluated first [-Wparentheses]
        rep(i, 64) if((a>>i)&1 == 1) ret = (ret*tt[i] + ot[i])%m;
                            ^~~~~~~
./Main.cpp:44:22: note: place parentheses around the '==' expression to silence this warning
        rep(i, 64) if((a>>i)&1 == 1) ret = (ret*tt[i] + ot[i])%m;
                            ^
                             (     )
./Main.cpp:44:22: note: place parentheses around the & expression to evaluate it first
        rep(i, 64) if((a>>i)&1 == 1) ret = (ret*tt[i] + ot[i])%m;
                            ^
                      (       )
./Main.cpp:50:22: warning: & has lower precedence than ==; == will be evaluated first [-Wparentheses]
        rep(i, 64) if((z>>i)&1 == 1) zt[0] = (zt[0]*tt[i])%m;
                            ^~~~~~~
./Main.cpp:50:22: note: place parentheses around the '==' expression to silence this warning
        rep(i, 64) if((z>>i)&1 == 1) zt[0] = (zt[0]*tt[i])%m;
                        ...