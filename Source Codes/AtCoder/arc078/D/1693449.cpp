#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std;

const int MAX=1e5+5;
const int INF=1e9;
int n,m;
int edge[20][20];
int total;
int cost[1<<16][16],dp[1<<16][16];//dp[s][x]???????s,??“??”??????????????x?????????????
int inner[1<<16];//????

inline int read() {
	int x = 0,f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1; ch = getchar(); }
	while(ch>='0'&&ch<='9') { x = x *10+ch-48 ; ch = getchar(); }
	return x * f ;
}

int main() {
	n = read() ; m = read() ; 
	For(i,1,m) {
		int x,y,price ; 
		x=read();y=read();price=read();
		x--;y--;
		edge[x][y]=edge[y][x]=price ; 		
	}
	
	total = 1<<n;
	For(i,0,total-1) 
	  For(a,0,n-1) 
	    if(i&(1<<a))  
	      For(b,0,a-1) 
	        if (i&(1<<b)) 
				inner[i]+=edge[a][b] ;  
				
	For(i,0,total-1) 
	  For(a,0,n-1) 
	    if(!(i&(1<<a))) 
	      For(b,0,n-1) 
	        if(i&(1<<b)) 
	          cost[i][a]+=edge[a][b] ; 
	
	memset(dp,-1,sizeof dp) ; 
	dp[1][0]=0 ; 
	For(i,0,total-1) {
		For(a,0,n-1) 
		  if((i&(1<<a)) && dp[i][a]!=-1 ) {
		  	 For(b,0,n-1) 
		  	   if(!(i&(1<<b))) 
		  	    if(edge[a][b])
		  	     dp[i| (1<<b) ][b] = max( dp[i| (1<<b)][b],dp[i][a]+edge[a][b] ) ;  
		  	     
		  	int left = total-i-1 ; 
		  	for(int now=left;now!=0;now=(now-1)&left) {
		  		int num = inner[now]+cost[now][a] ; 
		  		dp[i| now][a] = max(dp[i| now][a],dp[i][a]+num) ;  
			}
		  }
	} 
	printf("%d\n",inner[total-1]-dp[total-1][n-1]) ; 
	
	return 0 ; 
}