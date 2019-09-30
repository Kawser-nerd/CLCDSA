#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

#define   M             100005
#define   ll            long long
#define   PI            atan(1.0)*4
#define   mst(x,v)      memset(x,v,sizeof(x))
#define   inf           1e9
#define   rush()        int T;scanf("%d",&T);while(T--)
#define   debug         puts("debug")

typedef   pair<int,int> P;

int a[M];

int main() {
/*
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
	ll n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	sort(a,a+n);
	
	ll sum = 0,ans = 0;
	
	
	sum = a[0];
	for(int i=1;i<n;i++) {
		if(sum*2>=a[i]) {
			sum+=a[i];
		}
		else {
			sum = a[i]+sum;
			ans = i;
		}
	}
	
	printf("%lld\n",n-ans);
} ./Main.cpp:28:36: warning: format specifies type 'long long *' but the argument has type 'int *' [-Wformat]
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
                                    ~~~~  ^~~~~
                                    %d
1 warning generated.