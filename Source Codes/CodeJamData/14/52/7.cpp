#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define MAX 111
#define LIM 11111
int p,q,n,t[MAX],g[MAX],dp[MAX][LIM];
void ma(int &a,int b){
	if(a<b)a=b;
}
void test(){
	make(p);make(q);make(n);
	R(i,n){
		make(t[i]);
		make(g[i]);
	}
	R(i,n+1)R(j,LIM)dp[i][j] = - 1;
	dp[0][1] = 0;
	R(i,n){
		int wie = (t[i]+q-1)/q;
		R(j,LIM)if(dp[i][j]>=0)ma(dp[i+1][j+wie],dp[i][j]);
		wie--;
		int dia = (t[i] - q*(wie) + p-1)/p;
		R(j,LIM)if(j-dia+wie >= 0 && dp[i][j]>=0){
			ma(dp[i+1][j-dia+wie],dp[i][j] + g[i]);
		}
	}
	int wyn = -1;
	R(i,LIM)ma(wyn,dp[n][i]);
	static int test_nr = 0;test_nr++;
	printf("Case #%d: %d\n",test_nr,wyn);
}
main(){
	int _;make(_);while(_--)test();
}
