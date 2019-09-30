#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <string.h>
#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
#define LL long long
#define eps 1e-6
using namespace std;
const double pi = 3.1415926535;
/*
https://codeforces.com/contest/1106/problems
https://codeforces.com/contest/1106/submit
*/
const ll mod = 1e9+7;
//??? (a^b)%mod
//???????b = mod-2;
ll pow_quick(ll a,ll b){
    ll r = 1,base = a;
    while(b){
        if(b & 1){
            r *= base;
            r %= mod;
        }
        base *= base;
        base %= mod;
        b >>= 1;
    }
    return r;
}

char a[1000000];
int main(){
    int h,w;
    s(h) s(w)
    gc
    for(int i = 0; i < h; i ++){
        ss(a) gc
        puts(a);
        puts(a);
    }
	return 0;
 }/*
int t[100000];
int main(){
    int n = 0;
    s(n)
    for(int i = 0; i < n ;i ++){
        s(t[i])
    }
    int m;
    s(m)


	return 0;
 }
*/