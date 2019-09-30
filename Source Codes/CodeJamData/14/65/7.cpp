#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
typedef double D;
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define make(a) scanf("%d",&a)
template<typename A> void ma(A &a, A b){if(a<b)a=b;}
template<typename A> void mi(A &a, A b){if(a>b)a=b;}
#define MAX 1000001
LL dp[MAX];
LL n;
int a,b;
void test(){
	static int tes=0;tes++;
	printf("Case #%d: ",tes);
	scanf("%lld%d%d",&n,&a,&b);
	if(n==1){
		puts("0");
		return;
	}
	R(i,a)dp[i] = 1;
	F(i,a,b){
		dp[i] = dp[i-a]+1;
		if(dp[i]>=n){
			printf("%d\n",i);
			return;
		}
	}
	int i = b;
	while(1){
		dp[i] = dp[i-a]+dp[i-b];
		if(dp[i] >= n){
			printf("%d\n",i);
			return;
		}
		i++;
	}
}
main(){
	int _;make(_);while(_--)test();
}